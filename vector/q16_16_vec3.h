
#ifndef __Q16_16_VEC3_H__
#define __Q16_16_VEC3_H__

#include "../fixed/q16_16.h"

typedef union 
{
    q16_16 raw[3];
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
} q16_16_vec3;

#define q16_16_vec3_zero     ((q16_16_vec3){{Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO}})
#define q16_16_vec3_right    ((q16_16_vec3){{ Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO}})
#define q16_16_vec3_up       ((q16_16_vec3){{Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO}})
#define q16_16_vec3_backward ((q16_16_vec3){{Q16_16_ZERO, Q16_16_ZERO,  Q16_16_ONE}})
#define q16_16_vec3_left     ((q16_16_vec3){{-Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO}})
#define q16_16_vec3_down     ((q16_16_vec3){{Q16_16_ZERO, -Q16_16_ONE, Q16_16_ZERO}})
#define q16_16_vec3_forward  ((q16_16_vec3){{Q16_16_ZERO, Q16_16_ZERO, -Q16_16_ONE}})

static inline q16_16_vec3 q16_16_vec3_negate(q16_16_vec3 qv) 
{
    return (q16_16_vec3){{
        -qv.x,
        -qv.y,
        -qv.z,
    }};
}

static inline q16_16_vec3 q16_16_vec3_add(q16_16_vec3 qv1, q16_16_vec3 qv2) 
{
    return (q16_16_vec3){{
        q16_16_add(qv1.x, qv2.x), 
        q16_16_add(qv1.y, qv2.y),
        q16_16_add(qv1.z, qv2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_sub(q16_16_vec3 qv1, q16_16_vec3 qv2) 
{
    return (q16_16_vec3){{
        q16_16_sub(qv1.x, qv2.x), 
        q16_16_sub(qv1.y, qv2.y),
        q16_16_sub(qv1.z, qv2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_mul(q16_16_vec3 qv1, q16_16_vec3 qv2) 
{
    return (q16_16_vec3){{
        q16_16_mul(qv1.x, qv2.x), 
        q16_16_mul(qv1.y, qv2.y),
        q16_16_mul(qv1.z, qv2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_div(q16_16_vec3 qv1, q16_16_vec3 qv2) 
{
    return (q16_16_vec3){{
        q16_16_div(qv1.x, qv2.x), 
        q16_16_div(qv1.y, qv2.y),
        q16_16_div(qv1.z, qv2.z),
    }};
}

static inline q16_16_vec3 q16_16_vec3_scale(q16_16_vec3 qv, q16_16 q) 
{
    return (q16_16_vec3){{
        q16_16_mul(qv.x, q), 
        q16_16_mul(qv.y, q),
        q16_16_mul(qv.z, q),
    }};
}

static inline q16_16 q16_16_vec3_dot(q16_16_vec3 qv1, q16_16_vec3 qv2)
{
    const q16_16 x2 = q16_16_mul(qv1.x, qv2.x);
    const q16_16 y2 = q16_16_mul(qv1.y, qv2.y);
    const q16_16 z2 = q16_16_mul(qv1.z, qv2.z);
    const q16_16 dot = q16_16_add(q16_16_add(x2, y2), z2);

    return dot;
}

static inline q16_16 q16_16_vec3_mag2(q16_16_vec3 qv)
{
    return q16_16_vec3_dot(qv, qv);
}

static inline q16_16 q16_16_vec3_mag(q16_16_vec3 qv) 
{
    const q16_16 mag2 = q16_16_vec3_mag2(qv);
    const q16_16 mag = q16_16_sqrt(mag2);

    return mag;
}

static inline q16_16_vec3 q16_16_vec3_interp(q16_16_vec3 qv1, q16_16_vec3 qv2, q16_16 alpha) 
{
    return (q16_16_vec3){{
        q16_16_interp(qv1.x, qv2.x, alpha),
        q16_16_interp(qv1.y, qv2.y, alpha),
        q16_16_interp(qv1.z, qv2.z, alpha),
    }};
}

static inline q16_16_vec3 q16_16_vec3_normalise(q16_16_vec3 qv) 
{
    const q16_16 inv_mag = q16_16_div(Q16_16_ONE, q16_16_vec3_mag(qv));
    const q16_16_vec3 normalised = q16_16_vec3_scale(qv, inv_mag);

    return normalised;
}

static inline q16_16_vec3 q16_16_vec3_cross(q16_16_vec3 qv1, q16_16_vec3 qv2)
{
    const q16_16 x = q16_16_sub(q16_16_mul(qv1.y, qv2.z), q16_16_mul(qv1.z, qv2.y));
    const q16_16 y = q16_16_sub(q16_16_mul(qv1.z, qv2.x), q16_16_mul(qv1.x, qv2.z));
    const q16_16 z = q16_16_sub(q16_16_mul(qv1.x, qv2.y), q16_16_mul(qv1.y, qv2.x));

    return (q16_16_vec3){{x, y, z}};
}

// qu is a unit vector.
// qn is a unit normal.
static inline q16_16_vec3 q16_16_vec3_reflect(q16_16_vec3 qu, q16_16_vec3 qn)
{
    const q16_16 scale = q16_16_mul(Q16_16_TWO, q16_16_vec3_dot(qn, qu));
    const q16_16_vec3 scaled_qn = q16_16_vec3_scale(qn, scale);
    const q16_16_vec3 reflect = q16_16_vec3_sub(qu, scaled_qn);
    
    return reflect;
}

static inline q16_16_vec3 q16_16_vec3_bisector(q16_16_vec3 qu1, q16_16_vec3 qu2)
{
    const q16_16_vec3 sum = q16_16_vec3_add(qu1, qu2);
    const q16_16_vec3 bisector = q16_16_vec3_normalise(sum);

    return bisector;
}

#endif // __Q16_16_VEC3_H__

