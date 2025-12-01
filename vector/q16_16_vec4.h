
#ifndef __Q16_16_VEC4_H__
#define __Q16_16_VEC4_H__

#include "../fixed/q16_16.h"

typedef union 
{
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
    q16_16 raw[4];
} q16_16_vec4;

#define Q16_16_VEC4_ZERO ((q16_16_vec4){{Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC4_ONE  ((q16_16_vec4){{ Q16_16_ONE,  Q16_16_ONE,  Q16_16_ONE,  Q16_16_ONE}})

#define Q16_16_VEC4_RIGHT    ((q16_16_vec4){{ Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC4_LEFT     ((q16_16_vec4){{-Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC4_UP       ((q16_16_vec4){{Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC4_DOWN     ((q16_16_vec4){{Q16_16_ZERO, -Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC4_BACKWARD ((q16_16_vec4){{Q16_16_ZERO, Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO}})
#define Q16_16_VEC4_FORWARD  ((q16_16_vec4){{Q16_16_ZERO, Q16_16_ZERO, -Q16_16_ONE, Q16_16_ZERO}})

static inline q16_16_vec4 q16_16_vec4_negate(q16_16_vec4 v) 
{
    return (q16_16_vec4){{
        -v.x,
        -v.y,
        -v.z,
        -v.w,
    }};
}

static inline q16_16_vec4 q16_16_vec4_add(q16_16_vec4 v1, q16_16_vec4 v2) 
{
    return (q16_16_vec4){{
        q16_16_add(v1.x, v2.x), 
        q16_16_add(v1.y, v2.y),
        q16_16_add(v1.z, v2.z),
        q16_16_add(v1.w, v2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_sub(q16_16_vec4 v1, q16_16_vec4 v2) 
{
    return (q16_16_vec4){{
        q16_16_sub(v1.x, v2.x), 
        q16_16_sub(v1.y, v2.y),
        q16_16_sub(v1.z, v2.z),
        q16_16_sub(v1.w, v2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_mul(q16_16_vec4 v1, q16_16_vec4 v2) 
{
    return (q16_16_vec4){{
        q16_16_mul(v1.x, v2.x), 
        q16_16_mul(v1.y, v2.y),
        q16_16_mul(v1.z, v2.z),
        q16_16_mul(v1.w, v2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_div(q16_16_vec4 v1, q16_16_vec4 v2) 
{
    return (q16_16_vec4){{
        q16_16_div(v1.x, v2.x), 
        q16_16_div(v1.y, v2.y),
        q16_16_div(v1.z, v2.z),
        q16_16_div(v1.w, v2.w),
    }};
}

static inline q16_16_vec4 q16_16_vec4_scale(q16_16_vec4 v, q16_16 q) 
{
    return (q16_16_vec4){{
        q16_16_mul(v.x, q), 
        q16_16_mul(v.y, q),
        q16_16_mul(v.z, q),
        q16_16_mul(v.w, q),
    }};
}

static inline q16_16 q16_16_vec4_dot(q16_16_vec4 v1, q16_16_vec4 v2)
{
    const q16_16 x2 = q16_16_mul(v1.x, v2.x);
    const q16_16 y2 = q16_16_mul(v1.y, v2.y);
    const q16_16 z2 = q16_16_mul(v1.z, v2.z);
    const q16_16 w2 = q16_16_mul(v1.w, v2.w);
    const q16_16 dot = q16_16_add(q16_16_add(q16_16_add(x2, y2), z2), w2);

    return dot;
}

static inline q16_16 q16_16_vec4_mag2(q16_16_vec4 v)
{
    return q16_16_vec4_dot(v, v);
}

static inline q16_16 q16_16_vec4_mag(q16_16_vec4 v) 
{
    const q16_16 mag2 = q16_16_vec4_mag2(v);
    const q16_16 mag = q16_16_sqrt(mag2);

    return mag;
}

static inline q16_16_vec4 q16_16_vec4_interp(q16_16_vec4 v1, q16_16_vec4 v2, q16_16 alpha) 
{
    return (q16_16_vec4){{
        q16_16_interp(v1.x, v2.x, alpha),
        q16_16_interp(v1.y, v2.y, alpha),
        q16_16_interp(v1.z, v2.z, alpha),
        q16_16_interp(v1.w, v2.w, alpha),
    }};
}

static inline q16_16_vec4 q16_16_vec4_normalise(q16_16_vec4 v) 
{
    const q16_16 inv_mag = q16_16_div(Q16_16_ONE, q16_16_vec4_mag(v));
    const q16_16_vec4 normalised = q16_16_vec4_scale(v, inv_mag);

    return normalised;
}

#endif // __Q16_16_VEC4_H__

