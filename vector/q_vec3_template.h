
#ifndef QGLM_Q_VEC3_TEMPLATE_H
#define QGLM_Q_VEC3_TEMPLATE_H

typedef union 
{
    struct 
    {
        Q_TYPE x;
        Q_TYPE y;
        Q_TYPE z;
    };
    struct 
    {
        Q_TYPE r;
        Q_TYPE g;
        Q_TYPE b;
    };
    struct 
    {
        Q_TYPE u;
        Q_TYPE v;
        Q_TYPE w;
    };
    Q_TYPE raw[3];
} Q_VEC3;

#define Q_VEC3_ZERO     ((Q_VEC3){{ Q_ZERO,  Q_ZERO,  Q_ZERO}})
#define Q_VEC3_ONE      ((Q_VEC3){{  Q_ONE,   Q_ONE,   Q_ONE}})

#define Q_VEC3_RIGHT    ((Q_VEC3){{  Q_ONE,  Q_ZERO,  Q_ZERO}})
#define Q_VEC3_LEFT     ((Q_VEC3){{Q_M_ONE,  Q_ZERO,  Q_ZERO}})
#define Q_VEC3_UP       ((Q_VEC3){{ Q_ZERO,   Q_ONE,  Q_ZERO}})
#define Q_VEC3_DOWN     ((Q_VEC3){{ Q_ZERO, Q_M_ONE,  Q_ZERO}})
#define Q_VEC3_BACKWARD ((Q_VEC3){{ Q_ZERO,  Q_ZERO,   Q_ONE}})
#define Q_VEC3_FORWARD  ((Q_VEC3){{ Q_ZERO,  Q_ZERO, Q_M_ONE}})

// -------------------------------- ARITHMETIC -------------------------------- //

static inline Q_VEC3 q_vec3_negate(Q_VEC3 v) 
{
    return (Q_VEC3){{
        q_negate(v.x),
        q_negate(v.y),
        q_negate(v.z),
    }};
}

static inline Q_VEC3 q_vec3_add(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_add(v1.x, v2.x), 
        q_add(v1.y, v2.y),
        q_add(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_sub(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_sub(v1.x, v2.x), 
        q_sub(v1.y, v2.y),
        q_sub(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_mul(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_mul(v1.x, v2.x), 
        q_mul(v1.y, v2.y),
        q_mul(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_div(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_div(v1.x, v2.x), 
        q_div(v1.y, v2.y),
        q_div(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_scale(Q_VEC3 v, Q_TYPE q) 
{
    return (Q_VEC3){{
        q_mul(v.x, q), 
        q_mul(v.y, q),
        q_mul(v.z, q),
    }};
}

// -------------------------------- ACCELERATED ARITHMETIC -------------------------------- //

static inline Q_VEC3 q_vec3_upscale_pow_2(Q_VEC3 v, uint32_t power)
{
    return (Q_VEC3){{
        q_mul_pow_2(v.x, power),
        q_mul_pow_2(v.y, power),
        q_mul_pow_2(v.z, power),
    }};
}

static inline Q_VEC3 q_vec3_downscale_pow_2(Q_VEC3 v, uint32_t power)
{
    return (Q_VEC3){{
        q_div_pow_2(v.x, power),
        q_div_pow_2(v.y, power),
        q_div_pow_2(v.z, power),
    }};
}

static inline Q_VEC3 q_vec3_upscale_int(Q_VEC3 v, int32_t n)
{
    return (Q_VEC3){{
        q_mul_int(v.x, n),
        q_mul_int(v.y, n),
        q_mul_int(v.z, n),
    }};
}

static inline Q_VEC3 q_vec3_downscale_int(Q_VEC3 v, int32_t n)
{
    return (Q_VEC3){{
        q_div_int(v.x, n),
        q_div_int(v.y, n),
        q_div_int(v.z, n),
    }};
}

// -------------------------------- UTILITY -------------------------------- //

static inline Q_TYPE q_vec3_dot(Q_VEC3 v1, Q_VEC3 v2)
{
    const Q_TYPE x2 = q_mul(v1.x, v2.x);
    const Q_TYPE y2 = q_mul(v1.y, v2.y);
    const Q_TYPE z2 = q_mul(v1.z, v2.z);
    const Q_TYPE dot = q_add(q_add(x2, y2), z2);
    return dot;
}

static inline Q_TYPE q_vec3_length2(Q_VEC3 v)
{
    return q_vec3_dot(v, v);
}

static inline Q_TYPE q_vec3_length(Q_VEC3 v) 
{
    const Q_TYPE length2 = q_vec3_length2(v);
    const Q_TYPE length = q_sqrt(length2);
    return length;
}

static inline Q_TYPE q_vec3_distance2(Q_VEC3 v1, Q_VEC3 v2)
{
    const Q_VEC3 diff = q_vec3_sub(v1, v2);
    const Q_TYPE distance2 = q_vec3_length2(diff);
    return distance2;
}

static inline Q_TYPE q_vec3_distance(Q_VEC3 v1, Q_VEC3 v2)
{
    const Q_TYPE distance2 = q_vec3_distance2(v1, v2);
    const Q_TYPE distance = q_sqrt(distance2);
    return distance;
}

static inline Q_VEC3 q_vec3_interp(Q_VEC3 v1, Q_VEC3 v2, Q_TYPE alpha) 
{
    return (Q_VEC3){{
        q_interp(v1.x, v2.x, alpha),
        q_interp(v1.y, v2.y, alpha),
        q_interp(v1.z, v2.z, alpha),
    }};
}

static inline Q_VEC3 q_vec3_normalise(Q_VEC3 v) 
{
    const Q_TYPE inv_length = q_div(Q_ONE, q_vec3_length(v));
    const Q_VEC3 normalised = q_vec3_scale(v, inv_length);
    return normalised;
}

static inline Q_VEC3 q_vec3_cross(Q_VEC3 v1, Q_VEC3 v2)
{
    const Q_TYPE x = q_sub(q_mul(v1.y, v2.z), q_mul(v1.z, v2.y));
    const Q_TYPE y = q_sub(q_mul(v1.z, v2.x), q_mul(v1.x, v2.z));
    const Q_TYPE z = q_sub(q_mul(v1.x, v2.y), q_mul(v1.y, v2.x));
    return (Q_VEC3){{x, y, z}};
}

// REQUIREMENT: u must be a unit vector.
// REQUIREMENT: n must be a unit normal.
static inline Q_VEC3 q_vec3_reflect(Q_VEC3 u, Q_VEC3 n)
{
    const Q_TYPE scale = q_mul_pow_2(q_vec3_dot(n, u), 1);
    const Q_VEC3 scaled_n = q_vec3_scale(n, scale);
    const Q_VEC3 reflect = q_vec3_sub(u, scaled_n);
    return reflect;
}

// REQUREMENT: u1 and u2 must be unit vectors.
static inline Q_VEC3 q_vec3_bisector(Q_VEC3 u1, Q_VEC3 u2)
{
    const Q_VEC3 sum = q_vec3_add(u1, u2);
    const Q_VEC3 bisector = q_vec3_normalise(sum);
    return bisector;
}

static inline Q_VEC3 q_vec3_spherical(Q_TYPE radius, Q_TYPE polar, Q_TYPE azimuth)
{
    const Q_TYPE sp = q_sin(polar);
    const Q_TYPE cp = q_cos(polar);
    const Q_TYPE sa = q_sin(azimuth);
    const Q_TYPE ca = q_cos(azimuth);

    const Q_TYPE x = q_mul(q_mul(radius, sp), ca);
    const Q_TYPE y = q_mul(q_mul(radius, sp), sa);
    const Q_TYPE z = q_mul(radius, cp);
    return (Q_VEC3){{x, y, z}};
}

static inline Q_VEC3 q_vec3_cylindrical(Q_TYPE radius, Q_TYPE azimuth, Q_TYPE height)
{
    const Q_TYPE x = q_mul(radius, q_cos(azimuth));
    const Q_TYPE y = q_mul(radius, q_sin(azimuth));
    const Q_TYPE z = height;
    return (Q_VEC3){{x, y, z}};
}

// -------------------------------- COMPARISON -------------------------------- //

static inline bool q_vec3_epsilon_is_normalised(Q_VEC3 v, Q_TYPE epsilon)
{
    const Q_TYPE length2 = q_vec3_length2(v);
    return q_epsilon_eq(length2, Q_ONE, epsilon);
}

static inline bool q_vec3_epsilon_eq(Q_VEC3 v1, Q_VEC3 v2, Q_TYPE epsilon)
{
    return q_epsilon_eq(v1.x, v2.x, epsilon) &&
           q_epsilon_eq(v1.y, v2.y, epsilon) &&
           q_epsilon_eq(v1.z, v2.z, epsilon);
}

static inline bool q_vec3_epsilon_ne(Q_VEC3 v1, Q_VEC3 v2, Q_TYPE epsilon)
{
    return q_epsilon_ne(v1.x, v2.x, epsilon) ||
           q_epsilon_ne(v1.y, v2.y, epsilon) ||
           q_epsilon_ne(v1.z, v2.z, epsilon);
}

#endif // QGLM_Q_VEC3_TEMPLATE_H

