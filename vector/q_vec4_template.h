
#ifndef QGLM_Q_VEC4_TEMPLATE_H
#define QGLM_Q_VEC4_TEMPLATE_H

typedef union 
{
    struct 
    {
        Q_TYPE x;
        Q_TYPE y;
        Q_TYPE z;
        Q_TYPE w;
    };
    struct 
    {
        Q_TYPE r;
        Q_TYPE g;
        Q_TYPE b;
        Q_TYPE a;
    };
    Q_TYPE raw[4];
} Q_VEC4;

#define Q_VEC4_ZERO            ((Q_VEC4){{ Q_ZERO,  Q_ZERO,  Q_ZERO,  Q_ZERO}})
#define Q_VEC4_ONE             ((Q_VEC4){{  Q_ONE,   Q_ONE,   Q_ONE,   Q_ONE}})
#define Q_VEC4_M_ONE           ((Q_VEC4){{Q_M_ONE, Q_M_ONE, Q_M_ONE, Q_M_ONE}})

#define Q_VEC4_RIGHT_VECTOR    ((Q_VEC4){{  Q_ONE,  Q_ZERO,  Q_ZERO,  Q_ZERO}})
#define Q_VEC4_LEFT_VECTOR     ((Q_VEC4){{Q_M_ONE,  Q_ZERO,  Q_ZERO,  Q_ZERO}})
#define Q_VEC4_UP_VECTOR       ((Q_VEC4){{ Q_ZERO,   Q_ONE,  Q_ZERO,  Q_ZERO}})
#define Q_VEC4_DOWN_VECTOR     ((Q_VEC4){{ Q_ZERO, Q_M_ONE,  Q_ZERO,  Q_ZERO}})
#define Q_VEC4_BACKWARD_VECTOR ((Q_VEC4){{ Q_ZERO,  Q_ZERO,   Q_ONE,  Q_ZERO}})
#define Q_VEC4_FORWARD_VECTOR  ((Q_VEC4){{ Q_ZERO,  Q_ZERO, Q_M_ONE,  Q_ZERO}})

#define Q_VEC4_RIGHT_POINT     ((Q_VEC4){{  Q_ONE,  Q_ZERO,  Q_ZERO,   Q_ONE}})
#define Q_VEC4_LEFT_POINT      ((Q_VEC4){{Q_M_ONE,  Q_ZERO,  Q_ZERO,   Q_ONE}})
#define Q_VEC4_UP_POINT        ((Q_VEC4){{ Q_ZERO,   Q_ONE,  Q_ZERO,   Q_ONE}})
#define Q_VEC4_DOWN_POINT      ((Q_VEC4){{ Q_ZERO, Q_M_ONE,  Q_ZERO,   Q_ONE}})
#define Q_VEC4_BACKWARD_POINT  ((Q_VEC4){{ Q_ZERO,  Q_ZERO,   Q_ONE,   Q_ONE}})
#define Q_VEC4_FORWARD_POINT   ((Q_VEC4){{ Q_ZERO,  Q_ZERO, Q_M_ONE,   Q_ONE}})

// -------------------------------- ARITHMETIC -------------------------------- //

static inline Q_VEC4 q_vec4_negate(Q_VEC4 v) 
{
    return (Q_VEC4){{
        q_negate(v.x),
        q_negate(v.y),
        q_negate(v.z),
        q_negate(v.w),
    }};
}

static inline Q_VEC4 q_vec4_add(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_add(v1.x, v2.x), 
        q_add(v1.y, v2.y),
        q_add(v1.z, v2.z),
        q_add(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_sub(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_sub(v1.x, v2.x), 
        q_sub(v1.y, v2.y),
        q_sub(v1.z, v2.z),
        q_sub(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_mul(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_mul(v1.x, v2.x), 
        q_mul(v1.y, v2.y),
        q_mul(v1.z, v2.z),
        q_mul(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_div(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_div(v1.x, v2.x), 
        q_div(v1.y, v2.y),
        q_div(v1.z, v2.z),
        q_div(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_scale(Q_VEC4 v, Q_TYPE q) 
{
    return (Q_VEC4){{
        q_mul(v.x, q), 
        q_mul(v.y, q),
        q_mul(v.z, q),
        q_mul(v.w, q),
    }};
}

// -------------------------------- FAST ARITHMETIC -------------------------------- //

static inline Q_VEC4 q_vec4_upscale_pow_2(Q_VEC4 v, uint32_t power)
{
    return (Q_VEC4){{
        q_mul_pow_2(v.x, power),
        q_mul_pow_2(v.y, power),
        q_mul_pow_2(v.z, power),
        q_mul_pow_2(v.w, power),
    }};
}

static inline Q_VEC4 q_vec4_downscale_pow_2(Q_VEC4 v, uint32_t power)
{
    return (Q_VEC4){{
        q_div_pow_2(v.x, power),
        q_div_pow_2(v.y, power),
        q_div_pow_2(v.z, power),
        q_div_pow_2(v.w, power),
    }};
}

static inline Q_VEC4 q_vec4_upscale_int(Q_VEC4 v, int32_t n)
{
    return (Q_VEC4){{
        q_mul_int(v.x, n),
        q_mul_int(v.y, n),
        q_mul_int(v.z, n),
        q_mul_int(v.w, n),
    }};
}

static inline Q_VEC4 q_vec4_downscale_int(Q_VEC4 v, int32_t n)
{
    return (Q_VEC4){{
        q_div_int(v.x, n),
        q_div_int(v.y, n),
        q_div_int(v.z, n),
        q_div_int(v.w, n),
    }};
}

// -------------------------------- UTILITY -------------------------------- //

static inline Q_TYPE q_vec4_dot(Q_VEC4 v1, Q_VEC4 v2)
{
    const Q_TYPE x2 = q_mul(v1.x, v2.x);
    const Q_TYPE y2 = q_mul(v1.y, v2.y);
    const Q_TYPE z2 = q_mul(v1.z, v2.z);
    const Q_TYPE w2 = q_mul(v1.w, v2.w);
    const Q_TYPE dot = q_add(q_add(q_add(x2, y2), z2), w2);
    return dot;
}

static inline Q_TYPE q_vec4_length2(Q_VEC4 v)
{
    return q_vec4_dot(v, v);
}

static inline Q_TYPE q_vec4_length(Q_VEC4 v) 
{
    const Q_TYPE length2 = q_vec4_length2(v);
    const Q_TYPE length = q_sqrt(length2);
    return length;
}

static inline Q_TYPE q_vec4_distance2(Q_VEC4 v1, Q_VEC4 v2)
{
    const Q_VEC4 diff = q_vec4_sub(v1, v2);
    const Q_TYPE distance2 = q_vec4_length2(diff);
    return distance2;
}

static inline Q_TYPE q_vec4_distance(Q_VEC4 v1, Q_VEC4 v2)
{
    const Q_TYPE distance2 = q_vec4_distance2(v1, v2);
    const Q_TYPE distance = q_sqrt(distance2);
    return distance;
}

static inline Q_VEC4 q_vec4_interp(Q_VEC4 v1, Q_VEC4 v2, Q_TYPE alpha) 
{
    return (Q_VEC4){{
        q_interp(v1.x, v2.x, alpha),
        q_interp(v1.y, v2.y, alpha),
        q_interp(v1.z, v2.z, alpha),
        q_interp(v1.w, v2.w, alpha),
    }};
}

static inline Q_VEC4 q_vec4_normalise(Q_VEC4 v) 
{
    const Q_TYPE inv_length = q_div(Q_ONE, q_vec4_length(v));
    const Q_VEC4 normalised = q_vec4_scale(v, inv_length);
    return normalised;
}

// -------------------------------- COMPARISON -------------------------------- //

static inline bool q_vec4_epsilon_is_normalised(Q_VEC4 v, Q_TYPE epsilon)
{
    const Q_TYPE length2 = q_vec4_length2(v);
    return q_epsilon_eq(length2, Q_ONE, epsilon);
}

static inline bool q_vec4_epsilon_eq(Q_VEC4 v1, Q_VEC4 v2, Q_TYPE epsilon)
{
    return q_epsilon_eq(v1.x, v2.x, epsilon) &&
           q_epsilon_eq(v1.y, v2.y, epsilon) &&
           q_epsilon_eq(v1.z, v2.z, epsilon) &&
           q_epsilon_eq(v1.w, v2.w, epsilon);
}

static inline bool q_vec4_epsilon_ne(Q_VEC4 v1, Q_VEC4 v2, Q_TYPE epsilon)
{
    return q_epsilon_ne(v1.x, v2.x, epsilon) ||
           q_epsilon_ne(v1.y, v2.y, epsilon) ||
           q_epsilon_ne(v1.z, v2.z, epsilon) ||
           q_epsilon_ne(v1.w, v2.w, epsilon);
}

#endif // QGLM_Q_VEC4_TEMPLATE_H

