
#ifndef QGLM_Q_VEC2_TEMPLATE_H
#define QGLM_Q_VEC2_TEMPLATE_H

typedef union 
{
    struct 
    {
        Q_TYPE x;
        Q_TYPE y;
    };
    struct 
    {
        Q_TYPE r;
        Q_TYPE i;
    };
    struct 
    {
        Q_TYPE u;
        Q_TYPE v;
    };
    struct 
    {
        Q_TYPE s;
        Q_TYPE t;
    };
    Q_TYPE raw[2];
} Q_VEC2;

#define Q_VEC2_ZERO    ((Q_VEC2){{ Q_ZERO,  Q_ZERO}})
#define Q_VEC2_ONE     ((Q_VEC2){{  Q_ONE,   Q_ONE}})

#define Q_VEC2_RIGHT   ((Q_VEC2){{  Q_ONE,  Q_ZERO}})
#define Q_VEC2_LEFT    ((Q_VEC2){{Q_M_ONE,  Q_ZERO}})
#define Q_VEC2_UP      ((Q_VEC2){{ Q_ZERO,   Q_ONE}})
#define Q_VEC2_DOWN    ((Q_VEC2){{ Q_ZERO, Q_M_ONE}})

// -------------------------------- ARITHMETIC -------------------------------- //

static inline Q_VEC2 q_vec2_negate(Q_VEC2 v) 
{
    return (Q_VEC2){{
        q_negate(v.x),
        q_negate(v.y),
    }};
}

static inline Q_VEC2 q_vec2_add(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_add(v1.x, v2.x), 
        q_add(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_sub(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_sub(v1.x, v2.x), 
        q_sub(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_mul(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_mul(v1.x, v2.x), 
        q_mul(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_div(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_div(v1.x, v2.x), 
        q_div(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_scale(Q_VEC2 v, Q_TYPE q) 
{
    return (Q_VEC2){{
        q_mul(v.x, q), 
        q_mul(v.y, q),
    }};
}

// -------------------------------- ACCELERATED ARITHMETIC -------------------------------- //

static inline Q_VEC2 q_vec2_upscale_pow_2(Q_VEC2 v, uint32_t power)
{
    return (Q_VEC2){{
        q_mul_pow_2(v.x, power),
        q_mul_pow_2(v.y, power),
    }};
}

static inline Q_VEC2 q_vec2_downscale_pow_2(Q_VEC2 v, uint32_t power)
{
    return (Q_VEC2){{
        q_div_pow_2(v.x, power),
        q_div_pow_2(v.y, power),
    }};
}

static inline Q_VEC2 q_vec2_upscale_int(Q_VEC2 v, int32_t n)
{
    return (Q_VEC2){{
        q_mul_int(v.x, n),
        q_mul_int(v.y, n),
    }};
}

static inline Q_VEC2 q_vec2_downscale_int(Q_VEC2 v, int32_t n)
{
    return (Q_VEC2){{
        q_div_int(v.x, n),
        q_div_int(v.y, n),
    }};
}

// -------------------------------- UTILITY -------------------------------- //

static inline Q_TYPE q_vec2_dot(Q_VEC2 v1, Q_VEC2 v2)
{
    const Q_TYPE x2 = q_mul(v1.x, v2.x);
    const Q_TYPE y2 = q_mul(v1.y, v2.y);
    const Q_TYPE dot = q_add(x2, y2);
    return dot;
}

static inline Q_TYPE q_vec2_length2(Q_VEC2 v)
{
    return q_vec2_dot(v, v);
}

static inline Q_TYPE q_vec2_length(Q_VEC2 v) 
{
    const Q_TYPE length2 = q_vec2_length2(v);
    const Q_TYPE length = q_sqrt(length2);
    return length;
}

static inline Q_TYPE q_vec2_distance2(Q_VEC2 v1, Q_VEC2 v2)
{
    const Q_VEC2 diff = q_vec2_sub(v1, v2);
    const Q_TYPE distance2 = q_vec2_length2(diff);
    return distance2;
}

static inline Q_TYPE q_vec2_distance(Q_VEC2 v1, Q_VEC2 v2)
{
    const Q_TYPE distance2 = q_vec2_distance2(v1, v2);
    const Q_TYPE distance = q_sqrt(distance2);
    return distance;
}

static inline Q_VEC2 q_vec2_interp(Q_VEC2 v1, Q_VEC2 v2, Q_TYPE alpha) 
{
    return (Q_VEC2){{
        q_interp(v1.x, v2.x, alpha),
        q_interp(v1.y, v2.y, alpha),
    }};
}

static inline Q_VEC2 q_vec2_normalise(Q_VEC2 v) 
{
    const Q_TYPE inv_length = q_div(Q_ONE, q_vec2_length(v));
    const Q_VEC2 normalised = q_vec2_scale(v, inv_length);
    return normalised;
}

static inline Q_TYPE q_vec2_cross(Q_VEC2 v1, Q_VEC2 v2)
{
    const Q_TYPE cross = q_sub(q_mul(v1.x, v2.y), q_mul(v1.y, v2.x));
    return cross;
}

// REQUIREMENT: u must be a unit vector.
// REQUIREMENT: n must be a unit normal.
// Result is a unit vector.
static inline Q_VEC2 q_vec2_reflect(Q_VEC2 u, Q_VEC2 n)
{
    const Q_TYPE scale = q_mul_pow_2(q_vec2_dot(n, u), 1);
    const Q_VEC2 scaled_n = q_vec2_scale(n, scale);
    const Q_VEC2 reflect = q_vec2_sub(u, scaled_n);
    return reflect;
}

// REQUREMENT: u1 and u2 must be unit vectors.
// Result is a unit vector.
static inline Q_VEC2 q_vec2_bisector(Q_VEC2 u1, Q_VEC2 u2)
{
    const Q_VEC2 sum = q_vec2_add(u1, u2);
    const Q_VEC2 bisector = q_vec2_normalise(sum);
    return bisector;
}

// REQUIREMENT: angle must be in radians.
static inline Q_VEC2 q_vec2_from_polar(Q_TYPE radius, Q_TYPE angle)
{
    const Q_TYPE x = q_mul(radius, q_cos(angle));
    const Q_TYPE y = q_mul(radius, q_sin(angle));
    return (Q_VEC2){{x, y}};
}

// -------------------------------- COMPARISON -------------------------------- //

static inline bool q_vec2_epsilon_is_normalised(Q_VEC2 v, Q_TYPE epsilon)
{
    const Q_TYPE length2 = q_vec2_length2(v);
    return q_epsilon_eq(length2, Q_ONE, epsilon);
}

static inline bool q_vec2_epsilon_eq(Q_VEC2 v1, Q_VEC2 v2, Q_TYPE epsilon)
{
    return q_epsilon_eq(v1.x, v2.x, epsilon) &&
           q_epsilon_eq(v1.y, v2.y, epsilon);
}

static inline bool q_vec2_epsilon_ne(Q_VEC2 v1, Q_VEC2 v2, Q_TYPE epsilon)
{
    return q_epsilon_ne(v1.x, v2.x, epsilon) ||
           q_epsilon_ne(v1.y, v2.y, epsilon);
}

#endif // QGLM_Q_VEC2_TEMPLATE_H

