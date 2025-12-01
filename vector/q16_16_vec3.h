
#ifndef __Q16_16_VEC3_H__
#define __Q16_16_VEC3_H__

#include "../fixed/q16_16.h"

typedef union 
{
    struct 
    {
        q16_16 x;
        q16_16 y;
        q16_16 z;
    };
    struct 
    {
        q16_16 r;
        q16_16 g;
        q16_16 b;
    };
    struct 
    {
        q16_16 u;
        q16_16 v;
        q16_16 w;
    };
    q16_16 raw[3];
} q16_16_vec3;

#define Q16_16_VEC3_ZERO     ((q16_16_vec3){{Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC3_ONE      ((q16_16_vec3){{ Q16_16_ONE,  Q16_16_ONE,  Q16_16_ONE}})

#define Q16_16_VEC3_RIGHT    ((q16_16_vec3){{ Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC3_LEFT     ((q16_16_vec3){{-Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO}})
#define Q16_16_VEC3_UP       ((q16_16_vec3){{Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO}})
#define Q16_16_VEC3_DOWN     ((q16_16_vec3){{Q16_16_ZERO, -Q16_16_ONE, Q16_16_ZERO}})
#define Q16_16_VEC3_BACKWARD ((q16_16_vec3){{Q16_16_ZERO, Q16_16_ZERO,  Q16_16_ONE}})
#define Q16_16_VEC3_FORWARD  ((q16_16_vec3){{Q16_16_ZERO, Q16_16_ZERO, -Q16_16_ONE}})

static inline q16_16_vec3 q16_16_vec3_negate(q16_16_vec3 v) 
{
    return (q16_16_vec3){{
        -v.x,
        -v.y,
        -v.z,
    }};
}

static inline q16_16_vec3 q16_16_vec3_add(q16_16_vec3 v1, q16_16_vec3 v2) 
{
    return (q16_16_vec3){{
        q16_16_add(v1.x, v2.x), 
        q16_16_add(v1.y, v2.y),
        q16_16_add(v1.z, v2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_sub(q16_16_vec3 v1, q16_16_vec3 v2) 
{
    return (q16_16_vec3){{
        q16_16_sub(v1.x, v2.x), 
        q16_16_sub(v1.y, v2.y),
        q16_16_sub(v1.z, v2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_mul(q16_16_vec3 v1, q16_16_vec3 v2) 
{
    return (q16_16_vec3){{
        q16_16_mul(v1.x, v2.x), 
        q16_16_mul(v1.y, v2.y),
        q16_16_mul(v1.z, v2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_div(q16_16_vec3 v1, q16_16_vec3 v2) 
{
    return (q16_16_vec3){{
        q16_16_div(v1.x, v2.x), 
        q16_16_div(v1.y, v2.y),
        q16_16_div(v1.z, v2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_scale(q16_16_vec3 v, q16_16 q) 
{
    return (q16_16_vec3){{
        q16_16_mul(v.x, q), 
        q16_16_mul(v.y, q),
        q16_16_mul(v.z, q),
    }};
}

static inline q16_16 q16_16_vec3_dot(q16_16_vec3 v1, q16_16_vec3 v2)
{
    const q16_16 x2 = q16_16_mul(v1.x, v2.x);
    const q16_16 y2 = q16_16_mul(v1.y, v2.y);
    const q16_16 z2 = q16_16_mul(v1.z, v2.z);
    const q16_16 dot = q16_16_add(q16_16_add(x2, y2), z2);

    return dot;
}

static inline q16_16 q16_16_vec3_mag2(q16_16_vec3 v)
{
    return q16_16_vec3_dot(v, v);
}

static inline q16_16 q16_16_vec3_mag(q16_16_vec3 v) 
{
    const q16_16 mag2 = q16_16_vec3_mag2(v);
    const q16_16 mag = q16_16_sqrt(mag2);

    return mag;
}

static inline q16_16_vec3 q16_16_vec3_interp(q16_16_vec3 v1, q16_16_vec3 v2, q16_16 alpha) 
{
    return (q16_16_vec3){{
        q16_16_interp(v1.x, v2.x, alpha),
        q16_16_interp(v1.y, v2.y, alpha),
        q16_16_interp(v1.z, v2.z, alpha),
    }};
}

static inline q16_16_vec3 q16_16_vec3_normalise(q16_16_vec3 v) 
{
    const q16_16 inv_mag = q16_16_div(Q16_16_ONE, q16_16_vec3_mag(v));
    const q16_16_vec3 normalised = q16_16_vec3_scale(v, inv_mag);

    return normalised;
}

static inline q16_16_vec3 q16_16_vec3_cross(q16_16_vec3 v1, q16_16_vec3 v2)
{
    const q16_16 x = q16_16_sub(q16_16_mul(v1.y, v2.z), q16_16_mul(v1.z, v2.y));
    const q16_16 y = q16_16_sub(q16_16_mul(v1.z, v2.x), q16_16_mul(v1.x, v2.z));
    const q16_16 z = q16_16_sub(q16_16_mul(v1.x, v2.y), q16_16_mul(v1.y, v2.x));

    return (q16_16_vec3){{x, y, z}};
}

// u is a unit vector.
// n is a unit normal.
static inline q16_16_vec3 q16_16_vec3_reflect(q16_16_vec3 u, q16_16_vec3 n)
{
    const q16_16 scale = q16_16_mul(Q16_16_TWO, q16_16_vec3_dot(n, u));
    const q16_16_vec3 scaled_n = q16_16_vec3_scale(n, scale);
    const q16_16_vec3 reflect = q16_16_vec3_sub(u, scaled_n);
    
    return reflect;
}

// u1 and u2 are unit vectors.
static inline q16_16_vec3 q16_16_vec3_bisector(q16_16_vec3 u1, q16_16_vec3 u2)
{
    const q16_16_vec3 sum = q16_16_vec3_add(u1, u2);
    const q16_16_vec3 bisector = q16_16_vec3_normalise(sum);

    return bisector;
}

#endif // __Q16_16_VEC3_H__

