
#ifndef __Q_TRANSFORM_2D_TEMPLATE_H__
#define __Q_TRANSFORM_2D_TEMPLATE_H__

static inline Q_MAT3 q_translate_mat3(Q_VEC2 v)
{
    return (Q_MAT3){{
         Q_ONE, Q_ZERO,   v.x,
        Q_ZERO,  Q_ONE,   v.y,
        Q_ZERO, Q_ZERO, Q_ONE,
    }};
}

static inline void q_translate_2d(Q_MAT3* m, Q_VEC2 v)
{
    const Q_TYPE dx = q_add(q_mul(m->xx, v.x), q_mul(m->xy, v.y));
    const Q_TYPE dy = q_add(q_mul(m->yx, v.x), q_mul(m->yy, v.y));
    const Q_TYPE dz = q_add(q_mul(m->zx, v.x), q_mul(m->zy, v.y));

    m->xz = q_add(m->xz, dx);
    m->yz = q_add(m->yz, dy);
    m->zz = q_add(m->zz, dz);
}

// REQUIREMENT: angle must be in radians.
static inline Q_MAT3 q_rotate_mat3(Q_TYPE angle)
{
    const Q_TYPE p_s = q_sin(angle);
    const Q_TYPE n_s = q_negate(p_s);
    const Q_TYPE p_c = q_cos(angle);

    return (Q_MAT3){{
           p_c,    n_s, Q_ZERO,
           p_s,    p_c, Q_ZERO,
        Q_ZERO, Q_ZERO,  Q_ONE,    
    }};
}

// REQUIREMENT: angle must be in radians.
static inline void q_rotate_2d(Q_MAT3* m, Q_TYPE angle)
{
    const Q_MAT3 rotation = q_rotate_mat3(angle);
    *m = q_mat3_mul_mat3(*m, rotation);
}

static inline Q_MAT3 q_scale_mat3(Q_VEC2 v)
{
    return (Q_MAT3){{
           v.x, Q_ZERO, Q_ZERO,
        Q_ZERO,    v.y, Q_ZERO,
        Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

static inline void q_scale_2d(Q_MAT3* m, Q_VEC2 v)
{
    m->xx = q_mul(m->xx, v.x);
    m->xy = q_mul(m->xy, v.y);
    m->yx = q_mul(m->yx, v.x);
    m->yy = q_mul(m->yy, v.y);
    m->zx = q_mul(m->zx, v.x);
    m->zy = q_mul(m->zy, v.y);
}

#endif // __Q_TRANSFORM_2D_TEMPLATE_H__

