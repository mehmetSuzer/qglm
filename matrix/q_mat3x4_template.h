
#ifndef __Q_MAT3X4_TEMPLATE_H__
#define __Q_MAT3X4_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz, xw;
        Q_TYPE yx, yy, yz, yw;
        Q_TYPE zx, zy, zz, zw;
    };
    Q_TYPE raw[3][4];
    Q_VEC4 rows[3];
} Q_MAT3X4;


#define Q_MAT3X4_ZERO ((Q_MAT3X4){{     \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO  Q_ZERO, Q_ZERO, \
}})

static inline Q_MAT3X4 q_mat3x4_negate(Q_MAT3X4 m) 
{
    return (Q_MAT3X4){{
        q_negate(m.xx), q_negate(m.xy), q_negate(m.xz), q_negate(m.xw),
        q_negate(m.yx), q_negate(m.yy), q_negate(m.yz), q_negate(m.yw),
        q_negate(m.zx), q_negate(m.zy), q_negate(m.zz), q_negate(m.zw),
    }};
}

static inline Q_MAT3X4 q_mat3x4_from_rows(Q_VEC4 row0, Q_VEC4 row1, Q_VEC4 row2) 
{
    return (Q_MAT3X4){{
        row0.x, row0.y, row0.z, row0.w,
        row1.x, row1.y, row1.z, row1.w,
        row2.x, row2.y, row2.z, row2.w,
    }};
}

static inline Q_MAT3X4 q_mat3x4_from_cols(Q_VEC3 col0, Q_VEC3 col1, Q_VEC3 col2, Q_VEC3 col3) 
{
    return (Q_MAT3X4){{
        col0.x, col1.x, col2.x, col3.x,
        col0.y, col1.y, col2.y, col3.y,
        col0.z, col1.z, col2.z, col3.z,
    }};
}

static inline Q_MAT3X4 q_mat3x4_add(Q_MAT3X4 m1, Q_MAT3X4 m2) 
{
    return (Q_MAT3X4){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), q_add(m1.xz, m2.xz), q_add(m1.xw, m2.xw),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy), q_add(m1.yz, m2.yz), q_add(m1.yw, m2.yw),
        q_add(m1.zx, m2.zx), q_add(m1.zy, m2.zy), q_add(m1.zz, m2.zz), q_add(m1.zw, m2.zw),
    }};
}

static inline Q_MAT3X4 q_mat3x4_sub(Q_MAT3X4 m1, Q_MAT3X4 m2) 
{
    return (Q_MAT3X4){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), q_sub(m1.xz, m2.xz), q_sub(m1.xw, m2.xw),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy), q_sub(m1.yz, m2.yz), q_sub(m1.yw, m2.yw),
        q_sub(m1.zx, m2.zx), q_sub(m1.zy, m2.zy), q_sub(m1.zz, m2.zz), q_sub(m1.zw, m2.zw),
    }};
}

static inline Q_MAT3X4 q_mat3x4_scale(Q_MAT3X4 m, Q_TYPE scale) 
{
    return (Q_MAT3X4){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), q_mul(m.xz, scale), q_mul(m.xw, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale), q_mul(m.yz, scale), q_mul(m.yw, scale),
        q_mul(m.zx, scale), q_mul(m.zy, scale), q_mul(m.zz, scale), q_mul(m.zw, scale),
    }};
}

static inline Q_VEC3 q_mat3x4_mul_vec4(Q_MAT3X4 m, Q_VEC4 v) 
{
    return (Q_VEC3){{
        q_add(q_add(q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)), q_mul(m.xz, v.z)), q_mul(m.xw, v.w)),
        q_add(q_add(q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)), q_mul(m.yz, v.z)), q_mul(m.yw, v.w)),
        q_add(q_add(q_add(q_mul(m.zx, v.x), q_mul(m.zy, v.y)), q_mul(m.zz, v.z)), q_mul(m.zw, v.w)),
    }};
}

#endif // __Q_MAT3X4_TEMPLATE_H__

