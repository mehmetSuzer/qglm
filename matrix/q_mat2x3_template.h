
#ifndef __Q_MAT2X3_TEMPLATE_H__
#define __Q_MAT2X3_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz;
        Q_TYPE yx, yy, yz;
    };
    struct
    {
        Q_VEC3 x; // row 0
        Q_VEC3 y; // row 1
    };
    Q_TYPE raw[2][3];
} Q_MAT2X3;


#define Q_MAT2X3_ZERO ((Q_MAT2X3){{ \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
}})

static inline Q_MAT2X3 q_mat2x3_negate(Q_MAT2X3 m) 
{
    return (Q_MAT2X3){{
        q_negate(m.xx), q_negate(m.xy), q_negate(m.xz),
        q_negate(m.yx), q_negate(m.yy), q_negate(m.yz),
    }};
}

static inline Q_MAT2X3 q_mat2x3_from_rows(Q_VEC3 row0, Q_VEC3 row1) 
{
    return (Q_MAT2X3){{
        row0.x, row0.y, row0.z,
        row1.x, row1.y, row1.z,
    }};
}

static inline Q_MAT2X3 q_mat2x3_from_cols(Q_VEC2 col0, Q_VEC2 col1, Q_VEC2 col2) 
{
    return (Q_MAT2X3){{
        col0.x, col1.x, col2.x,
        col0.y, col1.y, col2.y,
    }};
}

static inline Q_MAT2X3 q_mat2x3_add(Q_MAT2X3 m1, Q_MAT2X3 m2) 
{
    return (Q_MAT2X3){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), q_add(m1.xz, m2.xz),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy), q_add(m1.yz, m2.yz),
    }};
}

static inline Q_MAT2X3 q_mat2x3_sub(Q_MAT2X3 m1, Q_MAT2X3 m2) 
{
    return (Q_MAT2X3){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), q_sub(m1.xz, m2.xz),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy), q_sub(m1.yz, m2.yz),
    }};
}

static inline Q_MAT2X3 q_mat2x3_scale(Q_MAT2X3 m, Q_TYPE scale) 
{
    return (Q_MAT2X3){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), q_mul(m.xz, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale), q_mul(m.yz, scale),
    }};
}

static inline Q_VEC2 q_mat2x3_mul_vec3(Q_MAT2X3 m, Q_VEC3 v) 
{
    return (Q_VEC2){{
        q_add(q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)), q_mul(m.xz, v.z)),
        q_add(q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)), q_mul(m.yz, v.z)),
    }};
}

#endif // __Q_MAT2X3_TEMPLATE_H__

