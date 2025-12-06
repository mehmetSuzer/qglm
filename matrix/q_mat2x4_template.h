
#ifndef __Q_MAT2X4_TEMPLATE_H__
#define __Q_MAT2X4_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz, xw;
        Q_TYPE yx, yy, yz, yw;
    };
    struct
    {
        Q_VEC4 x; // row 0
        Q_VEC4 y; // row 1
    };
    Q_TYPE raw[2][4];
} Q_MAT2X4;


#define Q_MAT2X4_ZERO ((Q_MAT2X4){{     \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO  Q_ZERO, \
}})

static inline Q_MAT2X4 q_mat2x4_negate(Q_MAT2X4 m) 
{
    return (Q_MAT2X4){{
        q_negate(m.xx), q_negate(m.xy), q_negate(m.xz), q_negate(m.xw),
        q_negate(m.yx), q_negate(m.yy), q_negate(m.yz), q_negate(m.yw),
    }};
}

static inline Q_MAT2X4 q_mat2x4_from_rows(Q_VEC4 row0, Q_VEC4 row1) 
{
    return (Q_MAT2X4){{
        row0.x, row0.y, row0.z, row0.w,
        row1.x, row1.y, row1.z, row1.w,
    }};
}

static inline Q_MAT2X4 q_mat2x4_from_cols(Q_VEC2 col0, Q_VEC2 col1, Q_VEC2 col2, Q_VEC2 col3) 
{
    return (Q_MAT2X4){{
        col0.x, col1.x, col2.x, col3.x,
        col0.y, col1.y, col2.y, col3.y,
    }};
}

static inline Q_MAT2X4 q_mat2x4_add(Q_MAT2X4 m1, Q_MAT2X4 m2) 
{
    return (Q_MAT2X4){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), q_add(m1.xz, m2.xz), q_add(m1.xw, m2.xw),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy), q_add(m1.yz, m2.yz), q_add(m1.yw, m2.yw),
    }};
}

static inline Q_MAT2X4 q_mat2x4_sub(Q_MAT2X4 m1, Q_MAT2X4 m2) 
{
    return (Q_MAT2X4){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), q_sub(m1.xz, m2.xz), q_sub(m1.xw, m2.xw),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy), q_sub(m1.yz, m2.yz), q_sub(m1.yw, m2.yw),
    }};
}

static inline Q_MAT2X4 q_mat2x4_scale(Q_MAT2X4 m, Q_TYPE scale) 
{
    return (Q_MAT2X4){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), q_mul(m.xz, scale), q_mul(m.xw, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale), q_mul(m.yz, scale), q_mul(m.yw, scale),
    }};
}

static inline Q_VEC2 q_mat2x4_mul_vec4(Q_MAT2X4 m, Q_VEC4 v) 
{
    return (Q_VEC2){{
        q_add(q_add(q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)), q_mul(m.xz, v.z)), q_mul(m.xw, v.w)),
        q_add(q_add(q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)), q_mul(m.yz, v.z)), q_mul(m.yw, v.w)),
    }};
}

#endif // __Q_MAT2X4_TEMPLATE_H__

