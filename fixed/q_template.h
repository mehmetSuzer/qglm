
#ifndef __Q_TEMPLATE_H__
#define __Q_TEMPLATE_H__

// TODO: implement safe versions of these functions

// -------------------------------- CONVERSION -------------------------------- //

#define Q_FROM_INT(x)   ((Q_TYPE)((x) << Q_FRAC_BITS))
#define Q_TO_INT(q)     ((int32_t)((q) >> Q_FRAC_BITS))
#define Q_FROM_FLOAT(x) ((Q_TYPE)((x) * (float)(1 << Q_FRAC_BITS)))
#define Q_TO_FLOAT(q)   ((float)(q) / (float)(1 << Q_FRAC_BITS))

// -------------------------------- ARITHMETIC -------------------------------- //

static inline Q_TYPE q_add(Q_TYPE q1, Q_TYPE q2)
{
    return q1 + q2;
}

static inline Q_TYPE q_sub(Q_TYPE q1, Q_TYPE q2)
{
    return q1 - q2;
}

static inline Q_TYPE q_mul(Q_TYPE q1, Q_TYPE q2)
{
    const Q_WIDE wide = (Q_WIDE)q1 * (Q_WIDE)q2;
    return (Q_TYPE)(wide >> Q_FRAC_BITS);
}

static inline Q_TYPE q_div(Q_TYPE q1, Q_TYPE q2)
{
    const Q_WIDE wide = ((Q_WIDE)q1) << Q_FRAC_BITS;
    return (Q_TYPE)(wide / q2);
}

static inline Q_TYPE q_mul_pow_2(Q_TYPE q, uint32_t power)
{
    return q << power;
}

static inline Q_TYPE q_div_pow_2(Q_TYPE q, uint32_t power)
{
    return q >> power;
}

// -------------------------------- LOGICAL -------------------------------- //

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

// -------------------------------- UTILITY -------------------------------- //

static inline Q_TYPE q_negate(Q_TYPE q)
{
    return -q;
}

static inline Q_TYPE q_sign(Q_TYPE q)
{
    return q_gt(q, Q_ZERO) - q_lt(q, Q_ZERO);
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
    return q_ge(q, Q_ZERO) ? q : -q;
}

static inline Q_TYPE q_interp(Q_TYPE q1, Q_TYPE q2, Q_TYPE alpha)
{
    return q_add(q2, q_mul(alpha, q_sub(q1, q2)));
}

static inline Q_TYPE q_clamp(Q_TYPE q, Q_TYPE min, Q_TYPE max)
{
    return q_lt(q, min) ? min : q_gt(q, max) ? max : q;
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
    // x_(n+1) = (x_n + q/x_n) / 2.0
    x = q_div_pow_2(q_add(x, q_div(q, x)), 1); 

    // Undo scaling
    if (power > 0) x = q_mul_pow_2(x,  power);
    if (power < 0) x = q_div_pow_2(x, -power);

    return x;
}

// -------------------------------- TRIGONOMETRY -------------------------------- //

static inline Q_TYPE q_wrap_pi(Q_TYPE q)
{
    // q = fmod(q + pi, 2*pi) - pi;
    q += Q_PI;
    q %= Q_2PI;
    q -= Q_PI;

    return q; // q in [-pi, pi)
}

// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
static inline Q_TYPE q_sin(Q_TYPE q)
{
    q = q_wrap_pi(q);
    const Q_TYPE q2 = q_mul(q, q);

#ifndef QGLM_FAST_MATH
    const Q_TYPE factor0 = q_sub(Q_ONE, q_div(q2, Q_FROM_INT(6)));
#else
    const Q_TYPE factor2 = q_sub(Q_ONE, q_div(q2, Q_FROM_INT(42)));
    const Q_TYPE factor1 = q_sub(Q_ONE, q_mul(q_div(q2, Q_FROM_INT(20)), factor2));
    const Q_TYPE factor0 = q_sub(Q_ONE, q_mul(q_div(q2, Q_FROM_INT(6)), factor1));
#endif

    return q_mul(q, factor0);
}

// cos(x) = sin(x + pi/2)
static inline Q_TYPE q_cos(Q_TYPE q)
{
    return q_sin(q_add(q, Q_HALFPI)); 
}

// tan(x) = sin(x) / cos(x)
static inline Q_TYPE q_tan(Q_TYPE q)
{
    const Q_TYPE s = q_sin(q);
    const Q_TYPE c = q_cos(q);

#ifdef QGLM_SAFE_MATH
    if (q_eq(c, Q_ZERO))
        return q_ge(s, Q_ZERO) ? Q_MAX : Q_MIN;
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
        return q_ge(c, Q_ZERO) ? Q_MAX : Q_MIN;
#endif

    return q_div(c, s);
}

// -------------------------------- EPSILON -------------------------------- //

#define Q_EPSILON  ((Q_TYPE)1) // The smallest fraction that be represented

static inline bool q_epsilon_equal(Q_TYPE q1, Q_TYPE q2, Q_TYPE epsilon)
{
    const Q_TYPE abs_diff = q_abs(q_sub(q1, q2));
    return q_lt(abs_diff, epsilon);
}

static inline bool q_epsilon_not_equal(Q_TYPE q1, Q_TYPE q2, Q_TYPE epsilon)
{
    const Q_TYPE abs_diff = q_abs(q_sub(q1, q2));
    return q_ge(abs_diff, epsilon);
}

#endif // __Q_TEMPLATE_H__

