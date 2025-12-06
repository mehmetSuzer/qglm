
#ifndef __Q_MAT4X3_TEMPLATE_H__
#define __Q_MAT4X3_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz;
        Q_TYPE yx, yy, yz;
        Q_TYPE zx, zy, zz;
        Q_TYPE wx, wy, wz;
    };
    Q_TYPE raw[4][3];
    Q_VEC3 rows[4];
} Q_MAT4X3;


#define Q_MAT4X3_ZERO ((Q_MAT4X3){{ \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
}})

static inline Q_MAT4X3 q_mat4x3_negate(Q_MAT4X3 m) 
{
    return (Q_MAT4X3){{
        q_negate(m.xx), q_negate(m.xy), q_negate(m.xz),
        q_negate(m.yx), q_negate(m.yy), q_negate(m.yz),
        q_negate(m.zx), q_negate(m.zy), q_negate(m.zz),
        q_negate(m.wx), q_negate(m.wy), q_negate(m.wz),
    }};
}

static inline Q_MAT4X3 q_mat4x3_from_rows(Q_VEC3 row0, Q_VEC3 row1, Q_VEC3 row2, Q_VEC3 row3) 
{
    return (Q_MAT4X3){{
        row0.x, row0.y, row0.z,
        row1.x, row1.y, row1.z,
        row2.x, row2.y, row2.z,
        row3.x, row3.y, row3.z,
    }};
}

static inline Q_MAT4X3 q_mat4x3_from_cols(Q_VEC4 col0, Q_VEC4 col1, Q_VEC4 col2) 
{
    return (Q_MAT4X3){{
        col0.x, col1.x, col2.x,
        col0.y, col1.y, col2.y,
        col0.z, col1.z, col2.z,
        col0.w, col1.w, col2.w,
    }};
}

static inline Q_MAT4X3 q_mat4x3_add(Q_MAT4X3 m1, Q_MAT4X3 m2) 
{
    return (Q_MAT4X3){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), q_add(m1.xz, m2.xz),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy), q_add(m1.yz, m2.yz),
        q_add(m1.zx, m2.zx), q_add(m1.zy, m2.zy), q_add(m1.zz, m2.zz),
        q_add(m1.wx, m2.wx), q_add(m1.wy, m2.wy), q_add(m1.wz, m2.wz),
    }};
}

static inline Q_MAT4X3 q_mat4x3_sub(Q_MAT4X3 m1, Q_MAT4X3 m2) 
{
    return (Q_MAT4X3){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), q_sub(m1.xz, m2.xz),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy), q_sub(m1.yz, m2.yz),
        q_sub(m1.zx, m2.zx), q_sub(m1.zy, m2.zy), q_sub(m1.zz, m2.zz),
        q_sub(m1.wx, m2.wx), q_sub(m1.wy, m2.wy), q_sub(m1.wz, m2.wz),
    }};
}

static inline Q_MAT4X3 q_mat4x3_scale(Q_MAT4X3 m, Q_TYPE scale) 
{
    return (Q_MAT4X3){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), q_mul(m.xz, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale), q_mul(m.yz, scale),
        q_mul(m.zx, scale), q_mul(m.zy, scale), q_mul(m.zz, scale),
        q_mul(m.wx, scale), q_mul(m.wy, scale), q_mul(m.wz, scale),
    }};
}

static inline Q_VEC4 q_mat4x3_mul_vec3(Q_MAT4X3 m, Q_VEC3 v) 
{
    return (Q_VEC4){{
        q_add(q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)), q_mul(m.xz, v.z)),
        q_add(q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)), q_mul(m.yz, v.z)),
        q_add(q_add(q_mul(m.zx, v.x), q_mul(m.zy, v.y)), q_mul(m.zz, v.z)),
        q_add(q_add(q_mul(m.wx, v.x), q_mul(m.wy, v.y)), q_mul(m.wz, v.z)),
    }};
}

#endif // __Q_MAT4X3_TEMPLATE_H__

