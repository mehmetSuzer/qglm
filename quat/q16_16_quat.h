
#ifndef __Q16_16_QUAT_H__
#define __Q16_16_QUAT_H__

#include "../vector/q16_16_vec3.h"

typedef struct
{
    q16_16_vec3 v;
    q16_16      w;    
} q16_16_quat;

#define Q16_16_QUAT_IDENTITY ((q16_16_quat){Q16_16_VEC3_ZERO, Q16_16_ONE})
 
// TODO: Implement functions

static inline q16_16_quat q16_16_quat_euler_angles(q16_16_vec3 angles)
{
    const q16_16_vec3 half_angles = {{
        q16_16_shift_left(angles.x, 1),
        q16_16_shift_left(angles.y, 1),
        q16_16_shift_left(angles.z, 1),
    }};
    
    const q16_16_vec3 c = {{
        q16_16_cos(half_angles.x),
        q16_16_cos(half_angles.y),
        q16_16_cos(half_angles.z),
    }};
    const q16_16_vec3 s = {{
        q16_16_sin(half_angles.x),
        q16_16_sin(half_angles.y),
        q16_16_sin(half_angles.z),
    }};

    const q16_16 x = q16_16_sub(q16_16_mul(q16_16_mul(s.x, c.y), c.z), q16_16_mul(q16_16_mul(c.x, s.y), s.z));
    const q16_16 y = q16_16_add(q16_16_mul(q16_16_mul(c.x, s.y), c.z), q16_16_mul(q16_16_mul(s.x, c.y), s.z));
    const q16_16 z = q16_16_sub(q16_16_mul(q16_16_mul(c.x, c.y), s.z), q16_16_mul(q16_16_mul(s.x, s.y), c.z));
    const q16_16 w = q16_16_add(q16_16_mul(q16_16_mul(c.x, c.y), c.z), q16_16_mul(q16_16_mul(s.x, s.y), s.z));
    
    const q16_16_vec3 v = {{x, y, z}};

    return (q16_16_quat){v, w};
}

// axis is a unit vector.
static inline q16_16_quat q16_16_quat_angle_axis(q16_16_vec3 axis, q16_16 angle)
{
    const q16_16 half_angle = q16_16_shift_left(angle, 1);
    const q16_16 c = q16_16_cos(half_angle);
    const q16_16 s = q16_16_sin(half_angle);

    return (q16_16_quat){q16_16_vec3_scale(axis, s), c};
}

static inline q16_16_quat q16_16_quat_negate(q16_16_quat q)
{
    return (q16_16_quat){q16_16_vec3_negate(q.v), q16_16_negate(q.w)};
}

static inline q16_16_quat q16_16_quat_add(q16_16_quat q1, q16_16_quat q2)
{
    const q16_16_vec3 v = q16_16_vec3_add(q1.v, q2.v);
    const q16_16 w = q16_16_add(q1.w, q2.w);

    return (q16_16_quat){v, w};
}

static inline q16_16_quat q16_16_quat_sub(q16_16_quat q1, q16_16_quat q2)
{
    const q16_16_vec3 v = q16_16_vec3_sub(q1.v, q2.v);
    const q16_16 w = q16_16_sub(q1.w, q2.w);

    return (q16_16_quat){v, w};
}

static inline q16_16_quat q16_16_quat_scale(q16_16_quat q, q16_16 scale)
{
    const q16_16_vec3 v = q16_16_vec3_scale(q.v, scale);
    const q16_16 w = q16_16_mul(q.w, scale);

    return (q16_16_quat){v, w};
}

static inline q16_16_quat q16_16_quat_conjugate(q16_16_quat q)
{
    return (q16_16_quat){q16_16_vec3_negate(q.v), q.w};
}

static inline q16_16 q16_16_quat_norm2(q16_16_quat q)
{
    return q.v.x * q.v.x +
           q.v.y * q.v.y +
           q.v.z * q.v.z +
           q.w   * q.w;
}

static inline q16_16 q16_16_quat_norm(q16_16_quat q)
{
    return q16_16_sqrt(q16_16_quat_norm2(q));
}

static inline q16_16_quat q16_16_quat_normalise(q16_16_quat q)
{
    const q16_16 inv_norm = q16_16_div(Q16_16_ONE, q16_16_quat_norm(q));
    const q16_16_quat normalised = q16_16_quat_scale(q, inv_norm);

    return normalised;
}

static inline q16_16_quat q16_16_quat_inv(q16_16_quat q)
{
    const q16_16 inv_norm2 = q16_16_div(Q16_16_ONE, q16_16_quat_norm2(q));
    const q16_16_quat conjugate = q16_16_quat_conjugate(q);
    const q16_16_quat inverse = q16_16_quat_scale(conjugate, inv_norm2);

    return inverse;
}

static inline q16_16_quat q16_16_quat_mul_quat(q16_16_quat q1, q16_16_quat q2)
{
    const q16_16_vec3 w1v2 = q16_16_vec3_scale(q2.v, q1.w);
    const q16_16_vec3 w2v1 = q16_16_vec3_scale(q1.v, q2.w);
    const q16_16_vec3 v1v2 = q16_16_vec3_cross(q1.v, q2.v);
    const q16_16_vec3 xyz = q16_16_vec3_add(q16_16_vec3_add(w1v2, w2v1), v1v2);
    const q16_16 w = q16_16_sub(q16_16_mul(q1.w, q2.w), q16_16_vec3_dot(q1.v, q2.v));

    return (q16_16_quat){xyz, w};
}

static inline q16_16_quat q16_16_quat_mul_vec3(q16_16_quat q, q16_16_vec3 v)
{
    const q16_16_vec3 v1 = q16_16_vec3_scale(v, q.w);
    const q16_16_vec3 v2 = q16_16_vec3_cross(q.v, v);
    const q16_16_vec3 xyz = q16_16_vec3_add(v1, v2);
    const q16_16 w = q16_16_negate(q16_16_vec3_dot(q.v, v));

    return (q16_16_quat){xyz, w};
}

static inline q16_16_quat q16_16_vec3_mul_quat(q16_16_vec3 v, q16_16_quat q)
{
    const q16_16_vec3 v1 = q16_16_vec3_scale(v, q.w);
    const q16_16_vec3 v2 = q16_16_vec3_cross(v, q.v);
    const q16_16_vec3 xyz = q16_16_vec3_add(v1, v2);
    const q16_16 w = q16_16_negate(q16_16_vec3_dot(v, q.v));

    return (q16_16_quat){xyz, w};
}

// q is a unit quaternion.
static inline q16_16_vec3 q16_16_quat_rotate_vec3(q16_16_quat q, q16_16_vec3 v)
{
    const q16_16_vec3 uv  = q16_16_vec3_cross(q.v, v);
    const q16_16_vec3 uuv = q16_16_vec3_cross(q.v, uv);
    const q16_16_vec3 wuv = q16_16_vec3_scale(uv, q.w);
    const q16_16_vec3 two_sum = q16_16_vec3_scale(q16_16_vec3_add(wuv, uuv), Q16_16_TWO);
    const q16_16_vec3 rotated = q16_16_vec3_add(v, two_sum);

    return rotated;
}

#endif // __Q16_16_QUAT_H__

