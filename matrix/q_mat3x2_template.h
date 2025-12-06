
#ifndef __Q_MAT3X2_TEMPLATE_H__
#define __Q_MAT3X2_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy;
        Q_TYPE yx, yy;
        Q_TYPE zx, zy;
    };
    struct
    {
        Q_VEC2 x; // row 0
        Q_VEC2 y; // row 1
        Q_VEC2 z; // row 2
    };
    Q_TYPE raw[3][2];
} Q_MAT3X2;


#define Q_MAT3X2_ZERO ((Q_MAT3X2){{ \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
}})

static inline Q_MAT3X2 q_mat3x2_negate(Q_MAT3X2 m) 
{
    return (Q_MAT3X2){{
        q_negate(m.xx), q_negate(m.xy),
        q_negate(m.yx), q_negate(m.yy),
        q_negate(m.zx), q_negate(m.zy),
    }};
}

static inline Q_MAT3X2 q_mat3x2_from_rows(Q_VEC2 row0, Q_VEC2 row1, Q_VEC2 row2) 
{
    return (Q_MAT3X2){{
        row0.x, row0.y,
        row1.x, row1.y,
        row2.x, row2.y,
    }};
}

static inline Q_MAT3X2 q_mat3x2_from_cols(Q_VEC3 col0, Q_VEC3 col1) 
{
    return (Q_MAT3X2){{
        col0.x, col1.x,
        col0.y, col1.y,
        col0.z, col1.z,
    }};
}

static inline Q_MAT3X2 q_mat3x2_add(Q_MAT3X2 m1, Q_MAT3X2 m2) 
{
    return (Q_MAT3X2){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy),
        q_add(m1.zx, m2.zx), q_add(m1.zy, m2.zy),
    }};
}

static inline Q_MAT3X2 q_mat3x2_sub(Q_MAT3X2 m1, Q_MAT3X2 m2) 
{
    return (Q_MAT3X2){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy),
        q_sub(m1.zx, m2.zx), q_sub(m1.zy, m2.zy),
    }};
}

static inline Q_MAT3X2 q_mat3x2_scale(Q_MAT3X2 m, Q_TYPE scale) 
{
    return (Q_MAT3X2){{
        q_mul(m.xx, scale), q_mul(m.xy, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale),
        q_mul(m.zx, scale), q_mul(m.zy, scale),
    }};
}

static inline Q_VEC3 q_mat3x2_mul_vec2(Q_MAT3X2 m, Q_VEC2 v) 
{
    return (Q_VEC3){{
        q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)),
        q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)),
        q_add(q_mul(m.zx, v.x), q_mul(m.zy, v.y)),
    }};
}

#endif // __Q_MAT3X2_TEMPLATE_H__

