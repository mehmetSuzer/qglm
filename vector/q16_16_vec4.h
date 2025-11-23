
#ifndef __Q16_16_VEC4_H__
#define __Q16_16_VEC4_H__

#include "../fixed/q16_16.h"

typedef union 
{
    q16_16 raw[4];
    struct 
    {
        q16_16 x;
        q16_16 y;
        q16_16 z;
        q16_16 w;
    };
    struct 
    {
        q16_16 r;
        q16_16 g;
        q16_16 b;
        q16_16 a;
    };
} q16_16_vec4;

#define q16_16_vec4_zero ((q16_16_vec4){{Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO}})

static inline q16_16_vec4 q16_16_vec4_negate(q16_16_vec4 qv) 
{
    return (q16_16_vec4){{
        -qv.x,
        -qv.y,
        -qv.z,
        -qv.w,
    }};
}

static inline q16_16_vec4 q16_16_vec4_add(q16_16_vec4 qv1, q16_16_vec4 qv2) 
{
    return (q16_16_vec4){{
        q16_16_add(qv1.x, qv2.x), 
        q16_16_add(qv1.y, qv2.y),
        q16_16_add(qv1.z, qv2.z),
        q16_16_add(qv1.w, qv2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_sub(q16_16_vec4 qv1, q16_16_vec4 qv2) 
{
    return (q16_16_vec4){{
        q16_16_sub(qv1.x, qv2.x), 
        q16_16_sub(qv1.y, qv2.y),
        q16_16_sub(qv1.z, qv2.z),
        q16_16_sub(qv1.w, qv2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_mul(q16_16_vec4 qv1, q16_16_vec4 qv2) 
{
    return (q16_16_vec4){{
        q16_16_mul(qv1.x, qv2.x), 
        q16_16_mul(qv1.y, qv2.y),
        q16_16_mul(qv1.z, qv2.z),
        q16_16_mul(qv1.w, qv2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_div(q16_16_vec4 qv1, q16_16_vec4 qv2) 
{
    return (q16_16_vec4){{
        q16_16_div(qv1.x, qv2.x), 
        q16_16_div(qv1.y, qv2.y),
        q16_16_div(qv1.z, qv2.z),
        q16_16_div(qv1.w, qv2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_scale(q16_16_vec4 qv, q16_16 q) 
{
    return (q16_16_vec4){{
        q16_16_mul(qv.x, q), 
        q16_16_mul(qv.y, q),
        q16_16_mul(qv.z, q),
        q16_16_mul(qv.w, q),
    }};
}

static inline q16_16 q16_16_vec4_dot(q16_16_vec4 qv1, q16_16_vec4 qv2)
{
    const q16_16 x2 = q16_16_mul(qv1.x, qv2.x);
    const q16_16 y2 = q16_16_mul(qv1.y, qv2.y);
    const q16_16 z2 = q16_16_mul(qv1.z, qv2.z);
    const q16_16 w2 = q16_16_mul(qv1.w, qv2.w);
    const q16_16 dot = q16_16_add(q16_16_add(q16_16_add(x2, y2), z2), w2);

    return dot;
}

static inline q16_16 q16_16_vec4_mag2(q16_16_vec4 qv)
{
    return q16_16_vec4_dot(qv, qv);
}

static inline q16_16 q16_16_vec4_mag(q16_16_vec4 qv) 
{
    const q16_16 mag2 = q16_16_vec4_mag2(qv);
    const q16_16 mag = q16_16_sqrt(mag2);

    return mag;
}

static inline q16_16_vec4 q16_16_vec4_interp(q16_16_vec4 qv1, q16_16_vec4 qv2, q16_16 alpha) 
{
    return (q16_16_vec4){{
        q16_16_interp(qv1.x, qv2.x, alpha),
        q16_16_interp(qv1.y, qv2.y, alpha),
        q16_16_interp(qv1.z, qv2.z, alpha),
        q16_16_interp(qv1.w, qv2.w, alpha),
    }};
}

static inline q16_16_vec4 q16_16_vec4_normalise(q16_16_vec4 qv) 
{
    const q16_16 inv_mag = q16_16_div(Q16_16_ONE, q16_16_vec4_mag(qv));
    const q16_16_vec4 normalised = q16_16_vec4_scale(qv, inv_mag);

    return normalised;
}

#endif // __Q16_16_VEC4_H__

