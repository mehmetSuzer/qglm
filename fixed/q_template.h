
#ifndef QGLM_Q_TEMPLATE_H
#define QGLM_Q_TEMPLATE_H

// -------------------------------- CONVERSION -------------------------------- //

#ifdef QGLM_SAFE_MATH
    #define Q_FROM_INT(x)       (((x) < (INT32_MIN >> Q_FRAC_BITS)) ? Q_MIN : \
                                 ((x) > (INT32_MAX >> Q_FRAC_BITS)) ? Q_MAX : \
                                 (Q_TYPE)((x) * (1 << Q_FRAC_BITS)))

    #define Q_FROM_FLOAT(x)     (((x) < (float)INT32_MIN / (float)(1 << Q_FRAC_BITS)) ? Q_MIN : \
                                 ((x) > (float)INT32_MAX / (float)(1 << Q_FRAC_BITS)) ? Q_MAX : \
                                 (Q_TYPE)((x) * (float)(1 << Q_FRAC_BITS)))

    #define Q_FROM_DOUBLE(x)    (((x) < (double)INT32_MIN / (double)(1 << Q_FRAC_BITS)) ? Q_MIN : \
                                 ((x) > (double)INT32_MAX / (double)(1 << Q_FRAC_BITS)) ? Q_MAX : \
                                 (Q_TYPE)((x) * (double)(1 << Q_FRAC_BITS)))
#else
    #define Q_FROM_INT(x)       ((Q_TYPE)((x) * (1 << Q_FRAC_BITS)))
    #define Q_FROM_FLOAT(x)     ((Q_TYPE)((x) * (float)(1 << Q_FRAC_BITS)))
    #define Q_FROM_DOUBLE(x)    ((Q_TYPE)((x) * (double)(1 << Q_FRAC_BITS)))
#endif

#define Q_TO_INT(q)         ((int32_t)((q) >> Q_FRAC_BITS))
#define Q_TO_FLOAT(q)       ((float)(q) / (float)(1 << Q_FRAC_BITS))
#define Q_TO_DOUBLE(q)      ((double)(q) / (double)(1 << Q_FRAC_BITS))

// -------------------------------- COMPARISON -------------------------------- //

static inline bool q_lt(Q_TYPE q1, Q_TYPE q2)
{
    return q1 < q2;
}

static inline bool q_le(Q_TYPE q1, Q_TYPE q2)
{
    return q1 <= q2;
}

static inline bool q_gt(Q_TYPE q1, Q_TYPE q2)
{
    return q1 > q2;
}

static inline bool q_ge(Q_TYPE q1, Q_TYPE q2)
{
    return q1 >= q2;
}

static inline bool q_eq(Q_TYPE q1, Q_TYPE q2)
{
    return q1 == q2;
}

static inline bool q_ne(Q_TYPE q1, Q_TYPE q2)
{
    return q1 != q2;
}


// -------------------------------- ARITHMETIC -------------------------------- //

static inline Q_TYPE q_negate(Q_TYPE q)
{
#ifdef QGLM_SAFE_MATH
    if (q_eq(q, Q_MIN)) return Q_MAX; 
#endif
    return -q;
}

static inline Q_TYPE q_add(Q_TYPE q1, Q_TYPE q2)
{
#ifdef QGLM_SAFE_MATH
    const Q_WIDE r = (Q_WIDE)q1 + (Q_WIDE)q2;
    if (r < Q_MIN) return Q_MIN;
    if (r > Q_MAX) return Q_MAX;
    return (Q_TYPE)r;
#else
    return q1 + q2;
#endif
}

static inline Q_TYPE q_sub(Q_TYPE q1, Q_TYPE q2)
{
#ifdef QGLM_SAFE_MATH
    const Q_WIDE r = (Q_WIDE)q1 - (Q_WIDE)q2;
    if (r < Q_MIN) return Q_MIN;
    if (r > Q_MAX) return Q_MAX;
    return (Q_TYPE)r;
#else
    return q1 - q2;
#endif
}

static inline Q_TYPE q_mul(Q_TYPE q1, Q_TYPE q2)
{
    const Q_WIDE r = ((Q_WIDE)q1 * (Q_WIDE)q2) >> Q_FRAC_BITS;
#ifdef QGLM_SAFE_MATH
    if (r < Q_MIN) return Q_MIN;
    if (r > Q_MAX) return Q_MAX;
#endif
    return (Q_TYPE)r;
}

static inline Q_TYPE q_div(Q_TYPE q1, Q_TYPE q2)
{
#ifdef QGLM_SAFE_MATH
    if (q_eq(q2, Q_ZERO)) 
        return (q_lt(q1, Q_ZERO)) ? Q_MIN : Q_MAX;
#endif
    const Q_WIDE r = ((Q_WIDE)q1 << Q_FRAC_BITS) / q2;
#ifdef QGLM_SAFE_MATH
    if (r < Q_MIN) return Q_MIN;
    if (r > Q_MAX) return Q_MAX;
#endif
    return (Q_TYPE)r;
}

static inline Q_TYPE q_mod(Q_TYPE q1, Q_TYPE q2)
{
#ifdef QGLM_SAFE_MATH
    if (q_eq(q2, Q_ZERO)) return Q_ZERO;
#endif
    return q1 % q2;
}

// -------------------------------- ACCELERATED ARITHMETIC -------------------------------- //

static inline Q_TYPE q_mul_pow_2(Q_TYPE q, uint32_t power)
{
#ifdef QGLM_SAFE_MATH
    if (q_gt(q, (Q_MAX >> power))) return Q_MAX;
    if (q_lt(q, (Q_MIN >> power))) return Q_MIN;
#endif
    return q << power;
}

static inline Q_TYPE q_div_pow_2(Q_TYPE q, uint32_t power)
{
    return q >> power;
}

static inline Q_TYPE q_mul_int(Q_TYPE q, int32_t n)
{
#ifdef QGLM_SAFE_MATH
    const Q_WIDE r = (Q_WIDE)q * n;
    if (r < Q_MIN) return Q_MIN;
    if (r > Q_MAX) return Q_MAX;
    return (Q_TYPE)r;
#else
    return q * n;
#endif
}

static inline Q_TYPE q_div_int(Q_TYPE q, int32_t n)
{
#ifdef QGLM_SAFE_MATH
    if (n == 0)
        return (q_lt(q, Q_ZERO)) ? Q_MIN : Q_MAX;
#endif
    return q / n;
}

// -------------------------------- UTILITY -------------------------------- //

static inline Q_TYPE q_sign(Q_TYPE q)
{
    return (q_gt(q, Q_ZERO) - q_lt(q, Q_ZERO)) * (1 << Q_FRAC_BITS);
}

static inline Q_TYPE q_smaller(Q_TYPE q1, Q_TYPE q2)
{
    return q_lt(q1, q2) ? q1 : q2;
}

static inline Q_TYPE q_greater(Q_TYPE q1, Q_TYPE q2)
{
    return q_gt(q1, q2) ? q1 : q2;
}

static inline Q_TYPE q_abs(Q_TYPE q)
{
    return q_ge(q, Q_ZERO) ? q : q_negate(q);
}

static inline Q_TYPE q_interp(Q_TYPE q1, Q_TYPE q2, Q_TYPE alpha)
{
    return q_add(q2, q_mul(alpha, q_sub(q1, q2)));
}

static inline Q_TYPE q_clamp(Q_TYPE q, Q_TYPE min, Q_TYPE max)
{
    return q_lt(q, min) ? min : q_gt(q, max) ? max : q;
}

static inline void q_swap(Q_TYPE* pq1, Q_TYPE* pq2)
{
    const Q_TYPE temp = *pq1;
    *pq1 = *pq2;
    *pq2 = temp;
}

// -------------------------------- ROUND -------------------------------- //

static inline Q_TYPE q_round(Q_TYPE q)
{
    return q_add(q, Q_HALF) & Q_INT_MASK;
}

static inline Q_TYPE q_floor(Q_TYPE q)
{
    return q & Q_INT_MASK;
}

static inline Q_TYPE q_ceil(Q_TYPE q)
{
    return q_add(q, Q_FRAC_MASK) & Q_INT_MASK;
}

// -------------------------------- SQUAREROOT -------------------------------- //

static inline Q_TYPE q_sqrt(Q_TYPE q)
{
    if (q_le(q, Q_ZERO))
        return Q_ZERO;

    int32_t power = 0;

    // Normalise q into [0.5, 2.0)
    while (q_ge(q,  Q_TWO)) { q = q_div_pow_2(q, 2); power++; }
    while (q_lt(q, Q_HALF)) { q = q_mul_pow_2(q, 2); power--; }

    // Initial guess
    // sqrt(q) = (q + 1.0) / 2.0 is a good approximation for q in [0.5, 2.0)
    Q_TYPE x = q_div_pow_2(q_add(q, Q_ONE), 1);

    // Newton iteration(s)
    // x_(k+1) = (x_k + q/x_k) / 2.0
    x = q_div_pow_2(q_add(x, q_div(q, x)), 1); 

    // Undo scaling
    if (power > 0) x = q_mul_pow_2(x,  power);
    if (power < 0) x = q_div_pow_2(x, -power);

    return x;
}

// -------------------------------- TRIGONOMETRY -------------------------------- //

static inline Q_TYPE q_to_radian(Q_TYPE degree)
{
    return q_mul(degree, Q_TO_RADIAN);
}

static inline Q_TYPE q_to_degree(Q_TYPE radian)
{
    return q_mul(radian, Q_TO_DEGREE);
}

// Wraps the angle to [-pi, pi)
static inline Q_TYPE q_wrap_pi(Q_TYPE q)
{
    q = q_add(q, Q_PI);
    q = q_mod(q, Q_2PI);
    q = q_sub(q, Q_PI);
    return q;
}

// TODO: Check the CORDIC implementations of sin, cos, tan, atan, vector magnitude, and vector rotations
// TODO: Implement a function that calculates sin and cos at the same time
// TODO: Implement inverse trigonometric functions
// TODO: Implement exponential functions
// TODO: Implement logarithmic functions

// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - ...
static inline Q_TYPE q_sin(Q_TYPE q)
{
    q = q_wrap_pi(q);
    const Q_TYPE q2 = q_mul(q, q);

    const Q_TYPE factor3 = q_sub(Q_ONE, q_div_int(q2, 72));
    const Q_TYPE factor2 = q_sub(Q_ONE, q_mul(q_div_int(q2, 42), factor3));
    const Q_TYPE factor1 = q_sub(Q_ONE, q_mul(q_div_int(q2, 20), factor2));
    const Q_TYPE factor0 = q_sub(Q_ONE, q_mul(q_div_int(q2,  6), factor1));

    return q_mul(q, factor0);
}

// cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - ...
static inline Q_TYPE q_cos(Q_TYPE q)
{
    q = q_wrap_pi(q);
    const Q_TYPE q2 = q_mul(q, q);

    const Q_TYPE factor3 = q_sub(Q_ONE, q_div_int(q2, 56));
    const Q_TYPE factor2 = q_sub(Q_ONE, q_mul(q_div_int(q2, 30), factor3));
    const Q_TYPE factor1 = q_sub(Q_ONE, q_mul(q_div_int(q2, 12), factor2));
    const Q_TYPE factor0 = q_sub(Q_ONE, q_mul(q_div_int(q2,  2), factor1));
    
    return factor0;
}

// tan(x) = sin(x) / cos(x)
static inline Q_TYPE q_tan(Q_TYPE q)
{
    const Q_TYPE s = q_sin(q);
    const Q_TYPE c = q_cos(q);
#ifdef QGLM_SAFE_MATH
    if (q_eq(c, Q_ZERO))
        return q_lt(s, Q_ZERO) ? Q_MIN : Q_MAX;
#endif
    return q_div(s, c);
}

// cot(x) = cos(x) / sin(x)
static inline Q_TYPE q_cot(Q_TYPE q)
{
    const Q_TYPE s = q_sin(q);
    const Q_TYPE c = q_cos(q);
#ifdef QGLM_SAFE_MATH
    if (q_eq(s, Q_ZERO))
        return q_lt(c, Q_ZERO) ? Q_MIN : Q_MAX;
#endif
    return q_div(c, s);
}

// -------------------------------- EPSILON -------------------------------- //

static inline bool q_epsilon_eq(Q_TYPE q1, Q_TYPE q2, Q_TYPE epsilon)
{
    const Q_TYPE abs_diff = q_abs(q_sub(q1, q2));
    return q_lt(abs_diff, epsilon);
}

static inline bool q_epsilon_ne(Q_TYPE q1, Q_TYPE q2, Q_TYPE epsilon)
{
    const Q_TYPE abs_diff = q_abs(q_sub(q1, q2));
    return q_ge(abs_diff, epsilon);
}

#endif // QGLM_Q_TEMPLATE_H

