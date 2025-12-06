
#ifndef __Q_MAT3_TEMPLATE_H__
#define __Q_MAT3_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz;
        Q_TYPE yx, yy, yz;
        Q_TYPE zx, zy, zz;
    };
    struct
    {
        Q_VEC3 x; // row 0
        Q_VEC3 y; // row 1
        Q_VEC3 z; // row 2
    };
    Q_TYPE raw[3][3];
} Q_MAT3;


#define Q_MAT3_ZERO ((Q_MAT3){{ \
        Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, \
}})

#define Q_MAT3_IDENTITY ((Q_MAT3){{ \
         Q_ONE, Q_ZERO, Q_ZERO,     \
        Q_ZERO,  Q_ONE, Q_ZERO,     \
        Q_ZERO, Q_ZERO,  Q_ONE,     \
}})

static inline Q_MAT3 q_mat3_diagonal(Q_VEC3 v) 
{
    return (Q_MAT3){{
         v.x, 0.0f, 0.0f,
        0.0f,  v.y, 0.0f,
        0.0f, 0.0f,  v.z,
    }};
}

static inline Q_MAT3 q_mat3_negate(Q_MAT3 m) 
{
    return (Q_MAT3){{
        q_negate(m.xx), q_negate(m.xy), q_negate(m.xz),
        q_negate(m.yx), q_negate(m.yy), q_negate(m.yz),
        q_negate(m.zx), q_negate(m.zy), q_negate(m.zz),
    }};
}

static inline Q_MAT3 q_mat3_from_rows(Q_VEC3 row0, Q_VEC3 row1, Q_VEC3 row2) 
{
    return (Q_MAT3){{
        row0.x, row0.y, row0.z,
        row1.x, row1.y, row1.z,
        row2.x, row2.y, row2.z,
    }};
}

static inline Q_MAT3 q_mat3_from_cols(Q_VEC3 col0, Q_VEC3 col1, Q_VEC3 col2) 
{
    return (Q_MAT3){{
        col0.x, col1.x, col2.x,
        col0.y, col1.y, col2.y,
        col0.z, col1.z, col2.z,
    }};
}

static inline Q_MAT3 q_mat3_add(Q_MAT3 m1, Q_MAT3 m2) 
{
    return (Q_MAT3){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), q_add(m1.xz, m2.xz),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy), q_add(m1.yz, m2.yz),
        q_add(m1.zx, m2.zx), q_add(m1.zy, m2.zy), q_add(m1.zz, m2.zz),
    }};
}

static inline Q_MAT3 q_mat3_sub(Q_MAT3 m1, Q_MAT3 m2) 
{
    return (Q_MAT3){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), q_sub(m1.xz, m2.xz),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy), q_sub(m1.yz, m2.yz),
        q_sub(m1.zx, m2.zx), q_sub(m1.zy, m2.zy), q_sub(m1.zz, m2.zz),
    }};
}

static inline Q_MAT3 q_mat3_scale(Q_MAT3 m, Q_TYPE scale) 
{
    return (Q_MAT3){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), q_mul(m.xz, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale), q_mul(m.yz, scale),
        q_mul(m.zx, scale), q_mul(m.zy, scale), q_mul(m.zz, scale),
    }};
}

static inline Q_VEC3 q_mat3_mul_vec3(Q_MAT3 m, Q_VEC3 v) 
{
    return (Q_VEC3){{
        q_add(q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)), q_mul(m.xz, v.z)),
        q_add(q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)), q_mul(m.yz, v.z)),
        q_add(q_add(q_mul(m.zx, v.x), q_mul(m.zy, v.y)), q_mul(m.zz, v.z)),
    }};
}

static inline Q_TYPE q_mat3_det(Q_MAT3 m) 
{
    const Q_TYPE x = q_mul(m.xx, q_sub(q_mul(m.yy, m.zz), q_mul(m.yz, m.zy)));
    const Q_TYPE y = q_mul(m.xy, q_sub(q_mul(m.yx, m.zz), q_mul(m.yz, m.zx)));
    const Q_TYPE z = q_mul(m.xz, q_sub(q_mul(m.yx, m.zy), q_mul(m.yy, m.zx)));
           
    const Q_TYPE det = q_add(q_sub(x, y), z);

    return det;
}

// REQUIREMENT: det(m) != 0
static inline Q_MAT3 q_mat3_inv(Q_MAT3 m) 
{
    const Q_TYPE inv_det = q_div(Q_ONE, q_mat3_det(m));

    return (Q_MAT3){{
        q_mul(q_sub(q_mul(m.yy, m.zz), q_mul(m.yz, m.zy)), inv_det),
        q_mul(q_sub(q_mul(m.xz, m.zy), q_mul(m.xy, m.zz)), inv_det),
        q_mul(q_sub(q_mul(m.xy, m.yz), q_mul(m.xz, m.yy)), inv_det),
        
        q_mul(q_sub(q_mul(m.yz, m.zx), q_mul(m.yx, m.zz)), inv_det),
        q_mul(q_sub(q_mul(m.xx, m.zz), q_mul(m.xz, m.zx)), inv_det),
        q_mul(q_sub(q_mul(m.xz, m.yx), q_mul(m.xx, m.yz)), inv_det),
        
        q_mul(q_sub(q_mul(m.yx, m.zy), q_mul(m.yy, m.zx)), inv_det),
        q_mul(q_sub(q_mul(m.xy, m.zx), q_mul(m.xx, m.zy)), inv_det),
        q_mul(q_sub(q_mul(m.xx, m.yy), q_mul(m.xy, m.yx)), inv_det),
    }};
}

// REQUIREMENT: det(m) != 0
static inline Q_VEC3 q_mat3_solve(Q_MAT3 m, Q_VEC3 v) 
{
    const Q_TYPE factor0 = q_sub(q_mul(m.yy, m.zz), q_mul(m.yz, m.zy));
    const Q_TYPE factor1 = q_sub(q_mul(m.yx, m.zz), q_mul(m.yz, m.zx));
    const Q_TYPE factor2 = q_sub(q_mul(m.yx, m.zy), q_mul(m.yy, m.zx));
    const Q_TYPE factor3 = q_sub(q_mul(m.zz,  v.y), q_mul(m.yz,  v.z));
    const Q_TYPE factor4 = q_sub(q_mul(m.yx,  v.z), q_mul(m.zx,  v.y));
    const Q_TYPE factor5 = q_sub(q_mul(m.zy,  v.y), q_mul(m.yy,  v.z));

    const Q_TYPE det = q_add(q_sub(q_mul(m.xx, factor0), q_mul(m.xy, factor1)), q_mul(m.xz, factor2));
    const Q_TYPE inv_det = q_div(Q_ONE, det);

    const Q_TYPE detx = q_add(q_sub(q_mul( v.x, factor0), q_mul(m.xy, factor3)), q_mul(m.xz, factor5));
    const Q_TYPE dety = q_add(q_sub(q_mul(m.xx, factor3), q_mul( v.x, factor1)), q_mul(m.xz, factor4));
    const Q_TYPE detz = q_sub(q_sub(q_mul( v.x, factor2), q_mul(m.xx, factor5)), q_mul(m.xy, factor4));

    return (Q_VEC3){{
        q_mul(detx, inv_det),
        q_mul(dety, inv_det),
        q_mul(detz, inv_det),
    }};
}

#endif // __Q_MAT3_TEMPLATE_H__

