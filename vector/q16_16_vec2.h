
#ifndef __Q16_16_VEC2_H__
#define __Q16_16_VEC2_H__

#include "../fixed/q16_16.h"

typedef union 
{
    q16_16 raw[2];
    struct 
    {
        q16_16 x;
        q16_16 y;
    };
    struct 
    {
        q16_16 r;
        q16_16 i;
    };
    struct 
    {
        q16_16 u;
        q16_16 v;
    };
    struct 
    {
        q16_16 s;
        q16_16 t;
    };
} q16_16_vec2;

#define q16_16_vec2_zero ((q16_16_vec2){{Q16_16_ZERO, Q16_16_ZERO}})

static inline q16_16_vec2 q16_16_vec2_negate(q16_16_vec2 qv) 
{
    return (q16_16_vec2){{
        -qv.x,
        -qv.y,
    }};
}

static inline q16_16_vec2 q16_16_vec2_add(q16_16_vec2 qv1, q16_16_vec2 qv2) 
{
    return (q16_16_vec2){{
        q16_16_add(qv1.x, qv2.x), 
        q16_16_add(qv1.y, qv2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_sub(q16_16_vec2 qv1, q16_16_vec2 qv2) 
{
    return (q16_16_vec2){{
        q16_16_sub(qv1.x, qv2.x), 
        q16_16_sub(qv1.y, qv2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_mul(q16_16_vec2 qv1, q16_16_vec2 qv2) 
{
    return (q16_16_vec2){{
        q16_16_mul(qv1.x, qv2.x), 
        q16_16_mul(qv1.y, qv2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_div(q16_16_vec2 qv1, q16_16_vec2 qv2) 
{
    return (q16_16_vec2){{
        q16_16_div(qv1.x, qv2.x), 
        q16_16_div(qv1.y, qv2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_scale(q16_16_vec2 qv, q16_16 q) 
{
    return (q16_16_vec2){{
        q16_16_mul(qv.x, q), 
        q16_16_mul(qv.y, q),
    }};
}

static inline q16_16 q16_16_vec2_dot(q16_16_vec2 qv1, q16_16_vec2 qv2)
{
    const q16_16 x2 = q16_16_mul(qv1.x, qv2.x);
    const q16_16 y2 = q16_16_mul(qv1.y, qv2.y);
    const q16_16 dot = q16_16_add(x2, y2);

    return dot;
}

static inline q16_16 q16_16_vec2_mag2(q16_16_vec2 qv)
{
    return q16_16_vec2_dot(qv, qv);
}

static inline q16_16 q16_16_vec2_mag(q16_16_vec2 qv) 
{
    const q16_16 mag2 = q16_16_vec2_mag2(qv);
    const q16_16 mag = q16_16_sqrt(mag2);

    return mag;
}

static inline q16_16_vec2 q16_16_vec2_interp(q16_16_vec2 qv1, q16_16_vec2 qv2, q16_16 alpha) 
{
    return (q16_16_vec2){{
        q16_16_interp(qv1.x, qv2.x, alpha),
        q16_16_interp(qv1.y, qv2.y, alpha),
    }};
}

static inline q16_16_vec2 q16_16_vec2_normalise(q16_16_vec2 qv) 
{
    const q16_16 inv_mag = q16_16_div(Q16_16_ONE, q16_16_vec2_mag(qv));
    const q16_16_vec2 normalised = q16_16_vec2_scale(qv, inv_mag);

    return normalised;
}

#endif // __Q16_16_VEC2_H__

