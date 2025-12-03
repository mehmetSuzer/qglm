
#ifndef __Q_QUAT_TEMPLATE_H__
#define __Q_QUAT_TEMPLATE_H__

typedef struct
{
    Q_VEC3 v;
    Q_TYPE w;    
} Q_QUAT;

#define Q_QUAT_IDENTITY ((Q_QUAT){Q_VEC3_ZERO, Q_ONE})
 
static inline Q_QUAT q_quat_euler_angles(Q_VEC3 angles)
{
    const Q_VEC3 half_angles = {{
        q_div_pow_2(angles.x, 1),
        q_div_pow_2(angles.y, 1),
        q_div_pow_2(angles.z, 1),
    }};
    
    const Q_VEC3 c = {{
        q_cos(half_angles.x),
        q_cos(half_angles.y),
        q_cos(half_angles.z),
    }};
    const Q_VEC3 s = {{
        q_sin(half_angles.x),
        q_sin(half_angles.y),
        q_sin(half_angles.z),
    }};

    const Q_TYPE x = q_sub(q_mul(q_mul(s.x, c.y), c.z), q_mul(q_mul(c.x, s.y), s.z));
    const Q_TYPE y = q_add(q_mul(q_mul(c.x, s.y), c.z), q_mul(q_mul(s.x, c.y), s.z));
    const Q_TYPE z = q_sub(q_mul(q_mul(c.x, c.y), s.z), q_mul(q_mul(s.x, s.y), c.z));
    const Q_TYPE w = q_add(q_mul(q_mul(c.x, c.y), c.z), q_mul(q_mul(s.x, s.y), s.z));
    
    const Q_VEC3 v = {{x, y, z}};

    return (Q_QUAT){v, w};
}

// axis is a unit vector.
static inline Q_QUAT q_quat_angle_axis(Q_VEC3 axis, Q_TYPE angle)
{
    const Q_TYPE half_angle = q_div_pow_2(angle, 1);
    const Q_TYPE c = q_cos(half_angle);
    const Q_TYPE s = q_sin(half_angle);

    return (Q_QUAT){q_vec3_scale(axis, s), c};
}

static inline Q_QUAT q_quat_negate(Q_QUAT q)
{
    return (Q_QUAT){q_vec3_negate(q.v), q_negate(q.w)};
}

static inline Q_QUAT q_quat_add(Q_QUAT q1, Q_QUAT q2)
{
    const Q_VEC3 v = q_vec3_add(q1.v, q2.v);
    const Q_TYPE w = q_add(q1.w, q2.w);

    return (Q_QUAT){v, w};
}

static inline Q_QUAT q_quat_sub(Q_QUAT q1, Q_QUAT q2)
{
    const Q_VEC3 v = q_vec3_sub(q1.v, q2.v);
    const Q_TYPE w = q_sub(q1.w, q2.w);

    return (Q_QUAT){v, w};
}

static inline Q_QUAT q_quat_scale(Q_QUAT q, Q_TYPE scale)
{
    const Q_VEC3 v = q_vec3_scale(q.v, scale);
    const Q_TYPE w = q_mul(q.w, scale);

    return (Q_QUAT){v, w};
}

static inline Q_QUAT q_quat_conjugate(Q_QUAT q)
{
    return (Q_QUAT){q_vec3_negate(q.v), q.w};
}

static inline Q_TYPE q_quat_norm2(Q_QUAT q)
{
    return q.v.x * q.v.x +
           q.v.y * q.v.y +
           q.v.z * q.v.z +
           q.w   * q.w;
}

static inline Q_TYPE q_quat_norm(Q_QUAT q)
{
    return q_sqrt(q_quat_norm2(q));
}

static inline Q_QUAT q_quat_normalise(Q_QUAT q)
{
    const Q_TYPE inv_norm = q_div(Q_ONE, q_quat_norm(q));
    const Q_QUAT normalised = q_quat_scale(q, inv_norm);

    return normalised;
}

static inline Q_QUAT q_quat_inv(Q_QUAT q)
{
    const Q_TYPE inv_norm2 = q_div(Q_ONE, q_quat_norm2(q));
    const Q_QUAT conjugate = q_quat_conjugate(q);
    const Q_QUAT inverse = q_quat_scale(conjugate, inv_norm2);

    return inverse;
}

static inline Q_QUAT q_quat_mul_quat(Q_QUAT q1, Q_QUAT q2)
{
    const Q_VEC3 w1v2 = q_vec3_scale(q2.v, q1.w);
    const Q_VEC3 w2v1 = q_vec3_scale(q1.v, q2.w);
    const Q_VEC3 v1v2 = q_vec3_cross(q1.v, q2.v);
    const Q_VEC3 xyz  = q_vec3_add(q_vec3_add(w1v2, w2v1), v1v2);
    const Q_TYPE w    = q_sub(q_mul(q1.w, q2.w), q_vec3_dot(q1.v, q2.v));

    return (Q_QUAT){xyz, w};
}

static inline Q_QUAT q_quat_mul_vec3(Q_QUAT q, Q_VEC3 v)
{
    const Q_VEC3 v1  = q_vec3_scale(v, q.w);
    const Q_VEC3 v2  = q_vec3_cross(q.v, v);
    const Q_VEC3 xyz = q_vec3_add(v1, v2);
    const Q_TYPE w   = q_negate(q_vec3_dot(q.v, v));

    return (Q_QUAT){xyz, w};
}

static inline Q_QUAT q_vec3_mul_quat(Q_VEC3 v, Q_QUAT q)
{
    const Q_VEC3 v1  = q_vec3_scale(v, q.w);
    const Q_VEC3 v2  = q_vec3_cross(v, q.v);
    const Q_VEC3 xyz = q_vec3_add(v1, v2);
    const Q_TYPE w   = q_negate(q_vec3_dot(v, q.v));

    return (Q_QUAT){xyz, w};
}

// q is a unit quaternion.
static inline Q_VEC3 q_quat_rotate_vec3(Q_QUAT q, Q_VEC3 v)
{
    const Q_VEC3 uv  = q_vec3_cross(q.v, v);
    const Q_VEC3 uuv = q_vec3_cross(q.v, uv);
    const Q_VEC3 wuv = q_vec3_scale(uv, q.w);
    const Q_VEC3 two_sum = q_vec3_scale(q_vec3_add(wuv, uuv), Q_TWO);
    const Q_VEC3 rotated = q_vec3_add(v, two_sum);

    return rotated;
}

#endif // __Q_QUAT_TEMPLATE_H__

