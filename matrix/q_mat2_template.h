
#ifndef QGLM_Q_MAT2_TEMPLATE_H
#define QGLM_Q_MAT2_TEMPLATE_H

typedef union
{
    struct
    {
        Q_TYPE xx, xy;
        Q_TYPE yx, yy;
    };
    struct
    {
        Q_VEC2 x; // row 0
        Q_VEC2 y; // row 1
    };
    Q_TYPE raw[2][2];
} Q_MAT2;


#define Q_MAT2_ZERO ((Q_MAT2){{     \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
}})

#define Q_MAT2_IDENTITY ((Q_MAT2){{ \
         Q_ONE, Q_ZERO,             \
        Q_ZERO,  Q_ONE,             \
}})

static inline Q_MAT2 q_mat2_diagonal(Q_VEC2 v)
{
    return (Q_MAT2){{
           v.x, Q_ZERO,
        Q_ZERO,    v.y,
    }};  
}

static inline Q_MAT2 q_mat2_negate(Q_MAT2 m)
{
    return (Q_MAT2){{
        q_negate(m.xx), q_negate(m.xy),
        q_negate(m.yx), q_negate(m.yy),
    }};
}

static inline Q_MAT2 q_mat2_from_rows(Q_VEC2 row0, Q_VEC2 row1) 
{
    return (Q_MAT2){{
        row0.x, row0.y,
        row1.x, row1.y,
    }};
}

static inline Q_MAT2 q_mat2_from_cols(Q_VEC2 col0, Q_VEC2 col1) 
{
    return (Q_MAT2){{
        col0.x, col1.x,
        col0.y, col1.y,
    }};
}

static inline Q_MAT2 q_mat2_add(Q_MAT2 m1, Q_MAT2 m2) 
{
    return (Q_MAT2){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), 
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy),
    }};
}

static inline Q_MAT2 q_mat2_sub(Q_MAT2 m1, Q_MAT2 m2) 
{
    return (Q_MAT2){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), 
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy),
    }};
}

static inline Q_MAT2 q_mat2_scale(Q_MAT2 m, Q_TYPE scale) 
{
    return (Q_MAT2){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), 
        q_mul(m.yx, scale), q_mul(m.yy, scale),
    }};
}

static inline Q_VEC2 q_mat2_mul_vec2(Q_MAT2 m, Q_VEC2 v) 
{
    return (Q_VEC2){{
        q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)),
        q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)),
    }};
}

static inline Q_TYPE q_mat2_det(Q_MAT2 m) 
{
    const Q_TYPE det = q_sub(q_mul(m.xx, m.yy), q_mul(m.xy, m.yx));
    return det;
}

// REQUIREMENT: det(m) != 0
static inline Q_MAT2 q_mat2_inv(Q_MAT2 m) 
{
    const Q_TYPE inv_det = q_div(Q_ONE, q_mat2_det(m));

    return (Q_MAT2){{
                 q_mul(m.yy, inv_det), q_negate(q_mul(m.xy, inv_det)), 
        q_negate(q_mul(m.yx, inv_det)),         q_mul(m.xx, inv_det),
    }};
}

// REQUIREMENT: det(m) != 0
static inline Q_VEC2 q_mat2_solve(Q_MAT2 m, Q_VEC2 v) 
{
    const Q_TYPE inv_det = q_div(Q_ONE, q_mat2_det(m));
    const Q_TYPE detx = q_sub(q_mul(m.yy, v.x), q_mul(m.xy, v.y));
    const Q_TYPE dety = q_sub(q_mul(m.xx, v.y), q_mul(m.yx, v.x));

    return (Q_VEC2){{
        q_mul(detx, inv_det),
        q_mul(dety, inv_det),
    }};
}

#endif // QGLM_Q_MAT2_TEMPLATE_H

