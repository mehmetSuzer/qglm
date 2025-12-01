
#ifndef __Q16_16_VEC2_H__
#define __Q16_16_VEC2_H__

#include "../fixed/q16_16.h"

typedef union 
{
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
    q16_16 raw[2];
} q16_16_vec2;

#define Q16_16_VEC2_ZERO    ((q16_16_vec2){{Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC2_ONE     ((q16_16_vec2){{ Q16_16_ONE,  Q16_16_ONE}})

#define Q16_16_VEC2_RIGHT   ((q16_16_vec2){{ Q16_16_ONE, Q16_16_ZERO}})
#define Q16_16_VEC2_LEFT    ((q16_16_vec2){{-Q16_16_ONE, Q16_16_ZERO}})
#define Q16_16_VEC2_UP      ((q16_16_vec2){{Q16_16_ZERO,  Q16_16_ONE}})
#define Q16_16_VEC2_DOWN    ((q16_16_vec2){{Q16_16_ZERO, -Q16_16_ONE}})

static inline q16_16_vec2 q16_16_vec2_negate(q16_16_vec2 v) 
{
    return (q16_16_vec2){{
        -v.x,
        -v.y,
    }};
}

static inline q16_16_vec2 q16_16_vec2_add(q16_16_vec2 v1, q16_16_vec2 v2) 
{
    return (q16_16_vec2){{
        q16_16_add(v1.x, v2.x), 
        q16_16_add(v1.y, v2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_sub(q16_16_vec2 v1, q16_16_vec2 v2) 
{
    return (q16_16_vec2){{
        q16_16_sub(v1.x, v2.x), 
        q16_16_sub(v1.y, v2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_mul(q16_16_vec2 v1, q16_16_vec2 v2) 
{
    return (q16_16_vec2){{
        q16_16_mul(v1.x, v2.x), 
        q16_16_mul(v1.y, v2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_div(q16_16_vec2 v1, q16_16_vec2 v2) 
{
    return (q16_16_vec2){{
        q16_16_div(v1.x, v2.x), 
        q16_16_div(v1.y, v2.y),
    }};
}

static inline q16_16_vec2 q16_16_vec2_scale(q16_16_vec2 v, q16_16 q) 
{
    return (q16_16_vec2){{
        q16_16_mul(v.x, q), 
        q16_16_mul(v.y, q),
    }};
}

static inline q16_16 q16_16_vec2_dot(q16_16_vec2 v1, q16_16_vec2 v2)
{
    const q16_16 x2 = q16_16_mul(v1.x, v2.x);
    const q16_16 y2 = q16_16_mul(v1.y, v2.y);
    const q16_16 dot = q16_16_add(x2, y2);

    return dot;
}

static inline q16_16 q16_16_vec2_mag2(q16_16_vec2 v)
{
    return q16_16_vec2_dot(v, v);
}

static inline q16_16 q16_16_vec2_mag(q16_16_vec2 v) 
{
    const q16_16 mag2 = q16_16_vec2_mag2(v);
    const q16_16 mag = q16_16_sqrt(mag2);

    return mag;
}

static inline q16_16_vec2 q16_16_vec2_interp(q16_16_vec2 v1, q16_16_vec2 v2, q16_16 alpha) 
{
    return (q16_16_vec2){{
        q16_16_interp(v1.x, v2.x, alpha),
        q16_16_interp(v1.y, v2.y, alpha),
    }};
}

static inline q16_16_vec2 q16_16_vec2_normalise(q16_16_vec2 v) 
{
    const q16_16 inv_mag = q16_16_div(Q16_16_ONE, q16_16_vec2_mag(v));
    const q16_16_vec2 normalised = q16_16_vec2_scale(v, inv_mag);

    return normalised;
}

#endif // __Q16_16_VEC2_H__

