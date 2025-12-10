
#ifndef __Q_TRANSFORM_3D_TEMPLATE_H__
#define __Q_TRANSFORM_3D_TEMPLATE_H__

static inline Q_MAT4 q_translate_mat4(Q_VEC3 v)
{
    return (Q_MAT4){{
         Q_ONE, Q_ZERO, Q_ZERO,   v.x,
        Q_ZERO,  Q_ONE, Q_ZERO,   v.y,
        Q_ZERO, Q_ZERO,  Q_ONE,   v.z,
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ONE,
    }};
}

static inline void q_translate_3d(Q_MAT4* m, Q_VEC3 v)
{
    const Q_TYPE dx = q_add(q_add(q_mul(m->xx, v.x), q_mul(m->xy, v.y)), q_mul(m->xz, v.z));
    const Q_TYPE dy = q_add(q_add(q_mul(m->yx, v.x), q_mul(m->yy, v.y)), q_mul(m->yz, v.z));
    const Q_TYPE dz = q_add(q_add(q_mul(m->zx, v.x), q_mul(m->zy, v.y)), q_mul(m->zz, v.z));
    const Q_TYPE dw = q_add(q_add(q_mul(m->wx, v.x), q_mul(m->wy, v.y)), q_mul(m->wz, v.z));

    m->xw = q_add(m->xw, dx);
    m->yw = q_add(m->yw, dy);
    m->zw = q_add(m->zw, dz);
    m->ww = q_add(m->ww, dw);
}

// REQUIREMENT: angle must be in radians.
// REQUIREMENT: axis must be a unit vector.
static inline Q_MAT4 q_rotate_mat4(Q_TYPE angle, Q_VEC3 axis)
{
    const Q_TYPE s = q_sin(angle);
    const Q_TYPE c = q_cos(angle);
    const Q_TYPE t = q_sub(Q_ONE, c);

    const Q_TYPE x = axis.x;
    const Q_TYPE y = axis.y;
    const Q_TYPE z = axis.z;

    const Q_TYPE xx = q_mul(axis.x, axis.x);
    const Q_TYPE xy = q_mul(axis.x, axis.y);
    const Q_TYPE xz = q_mul(axis.x, axis.z);
    const Q_TYPE yy = q_mul(axis.y, axis.y);
    const Q_TYPE yz = q_mul(axis.y, axis.z);
    const Q_TYPE zz = q_mul(axis.z, axis.z);

    return (Q_MAT4){{
        q_add(q_mul(xx, t),           c), q_sub(q_mul(xy, t), q_mul(z, s)), q_add(q_mul(xz, t), q_mul(y, s)), Q_ZERO,
        q_add(q_mul(xy, t), q_mul(z, s)), q_add(q_mul(yy, t),           c), q_sub(q_mul(yz, t), q_mul(x, s)), Q_ZERO,
        q_sub(q_mul(xz, t), q_mul(y, s)), q_add(q_mul(yz, t), q_mul(x, s)), q_add(q_mul(zz, t),           c), Q_ZERO,
                                  Q_ZERO,                           Q_ZERO,                           Q_ZERO,  Q_ONE,
    }};
}

// REQUIREMENT: angle must be in radians.
// REQUIREMENT: axis must be a unit vector.
static inline void q_rotate_3d(Q_MAT4* m, Q_TYPE angle, Q_VEC3 axis)
{
    const Q_MAT4 rotation = q_rotate_mat4(angle, axis);
    *m = q_mat4_mul_mat4(*m, rotation);
}

static inline Q_MAT4 q_scale_mat4(Q_VEC3 v)
{
    return (Q_MAT4){{
           v.x, Q_ZERO, Q_ZERO, Q_ZERO,
        Q_ZERO,    v.y, Q_ZERO, Q_ZERO,
        Q_ZERO, Q_ZERO,    v.z, Q_ZERO,
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

static inline void q_scale_3d(Q_MAT4* m, Q_VEC3 v)
{
    m->xx = q_mul(m->xx, v.x);
    m->xy = q_mul(m->xy, v.y);
    m->xz = q_mul(m->xz, v.z);
    m->yx = q_mul(m->yx, v.x);
    m->yy = q_mul(m->yy, v.y);
    m->yz = q_mul(m->yz, v.z);
    m->zx = q_mul(m->zx, v.x);
    m->zy = q_mul(m->zy, v.y);
    m->zz = q_mul(m->zz, v.z);
    m->wx = q_mul(m->wx, v.x);
    m->wy = q_mul(m->wy, v.y);
    m->wz = q_mul(m->wz, v.z);
}

#endif // __Q_TRANSFORM_3D_TEMPLATE_H__

