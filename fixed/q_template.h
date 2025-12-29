
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
    const int32_t sign = q_gt(q, Q_ZERO) - q_lt(q, Q_ZERO);
    return sign * (1 << Q_FRAC_BITS);
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
    x = q_div_pow_2(q_add(x, q_div(q, x)), 1); 

    // Undo scaling
    if (power > 0) x = q_mul_pow_2(x,  power);
    if (power < 0) x = q_div_pow_2(x, -power);

    return x;
}

static inline Q_TYPE q_invsqrt(Q_TYPE q)
{
    if (q_le(q, Q_ZERO))
        return Q_MAX;

    int32_t power = 0;

    // Normalise q into [0.5, 2.0)
    while (q_ge(q,  Q_TWO)) { q = q_div_pow_2(q, 2); power--; }
    while (q_lt(q, Q_HALF)) { q = q_mul_pow_2(q, 2); power++; }

    // Initial guess
    // invsqrt(q) = (3.2 - q) / 2.0 is a good approximation for q in [0.5, 2.0)
    Q_TYPE x = q_div_pow_2(q_sub(Q_FROM_DOUBLE(3.2), q), 1);

    // Newton iteration(s)
    // x_k+1 = x_k * (3.0 - q * x_k * x_k) / 2.0
    x = q_div_pow_2(q_mul(x, q_sub(Q_THREE, q_mul(q, q_mul(x, x)))), 1);
    x = q_div_pow_2(q_mul(x, q_sub(Q_THREE, q_mul(q, q_mul(x, x)))), 1);

    // Undo scaling
    if (power > 0) x = q_mul_pow_2(x,  power);
    if (power < 0) x = q_div_pow_2(x, -power);

    return x;
}

// -------------------------------- TRIGONOMETRY -------------------------------- //

// Product for i in 0...31 (1.0 / sqrt(1.0 + pow(2.0, -2.0 * i)))
#define Q_CORDIC_K  Q_FROM_DOUBLE(0.60725293500888122277814318294986)

#define Q_CORDIC_ITER (Q_FRAC_BITS + 1)

static const Q_TYPE q_cordic_atan_table[] = {
    Q_FROM_DOUBLE(0.78539816339744827899949086713605), // atan(2^-00)
    Q_FROM_DOUBLE(0.46364760900080609351547877849953), // atan(2^-01)
    Q_FROM_DOUBLE(0.24497866312686414347332686247682), // atan(2^-02)
    Q_FROM_DOUBLE(0.12435499454676143815667899161781), // atan(2^-03)
    Q_FROM_DOUBLE(0.06241880999595735002305474381501), // atan(2^-04)
    Q_FROM_DOUBLE(0.03123983343026827744215445648024), // atan(2^-05)
    Q_FROM_DOUBLE(0.01562372862047683129416153491320), // atan(2^-06)
    Q_FROM_DOUBLE(0.00781234106010111114398730691732), // atan(2^-07)
    Q_FROM_DOUBLE(0.00390623013196697175739013907503), // atan(2^-08)
    Q_FROM_DOUBLE(0.00195312251647881875843415500071), // atan(2^-09)
    Q_FROM_DOUBLE(0.00097656218955931945943649274966), // atan(2^-10)
    Q_FROM_DOUBLE(0.00048828121119489828992621394121), // atan(2^-11)
    Q_FROM_DOUBLE(0.00024414062014936177124474481204), // atan(2^-12)
    Q_FROM_DOUBLE(0.00012207031189367020785306594544), // atan(2^-13)
    Q_FROM_DOUBLE(0.00006103515617420877259350145416), // atan(2^-14)
    Q_FROM_DOUBLE(0.00003051757811552609572715473452), // atan(2^-15)
    Q_FROM_DOUBLE(0.00001525878906131576154237786819), // atan(2^-16)
    Q_FROM_DOUBLE(0.00000762939453110196998103899671), // atan(2^-17)
    Q_FROM_DOUBLE(0.00000381469726560649614175075618), // atan(2^-18)
    Q_FROM_DOUBLE(0.00000190734863281018696477928532), // atan(2^-19)
    Q_FROM_DOUBLE(0.00000095367431640596084412763106), // atan(2^-20)
    Q_FROM_DOUBLE(0.00000047683715820308884228106408), // atan(2^-21)
    Q_FROM_DOUBLE(0.00000023841857910155797366768811), // atan(2^-22)
    Q_FROM_DOUBLE(0.00000011920928955078068089973856), // atan(2^-23)
    Q_FROM_DOUBLE(0.00000005960464477539055220810610), // atan(2^-24)
    Q_FROM_DOUBLE(0.00000002980232238769530257383265), // atan(2^-25)
    Q_FROM_DOUBLE(0.00000001490116119384765459563877), // atan(2^-26)
    Q_FROM_DOUBLE(0.00000000745058059692382812500000), // atan(2^-27)
    Q_FROM_DOUBLE(0.00000000372529029846191406250000), // atan(2^-28)
    Q_FROM_DOUBLE(0.00000000186264514923095703125000), // atan(2^-29)
    Q_FROM_DOUBLE(0.00000000093132257461547851562500), // atan(2^-30)
    Q_FROM_DOUBLE(0.00000000046566128730773925781250), // atan(2^-31)
};

static inline Q_TYPE q_to_radian(Q_TYPE degree)
{
    return q_mul(degree, Q_TO_RADIAN);
}

static inline Q_TYPE q_to_degree(Q_TYPE radian)
{
    return q_mul(radian, Q_TO_DEGREE);
}

// Wraps the angle to [-pi, pi)
static inline Q_TYPE q_wrap_pi(Q_TYPE theta)
{
    theta = q_add(theta, Q_PI);
    theta = q_mod(theta, Q_2PI);
    theta = q_sub(theta, Q_PI);
    return theta;
}

static inline void q_sincos(Q_TYPE theta, Q_TYPE* sin_out, Q_TYPE* cos_out)
{
    Q_TYPE x = Q_CORDIC_K;
    Q_TYPE y = Q_ZERO;
    Q_TYPE z = q_wrap_pi(theta);

    int sin_sign = 1;
    int cos_sign = 1;

    if (q_gt(z, Q_HALFPI))
    {
        z = q_sub(Q_PI, z);
        cos_sign = -1;
    }
    else if (q_lt(z, q_negate(Q_HALFPI)))
    {
        z = q_add(Q_PI, z);
        sin_sign = -1;
        cos_sign = -1;
    }

    for (uint32_t i = 0; i < Q_CORDIC_ITER; ++i)
    {
        const Q_TYPE dx = q_div_pow_2(y, i);
        const Q_TYPE dy = q_div_pow_2(x, i);

        if (q_ge(z, Q_ZERO))
        {
            x = q_sub(x, dx);
            y = q_add(y, dy);
            z = q_sub(z, q_cordic_atan_table[i]);
        }
        else
        {
            x = q_add(x, dx);
            y = q_sub(y, dy);
            z = q_add(z, q_cordic_atan_table[i]);
        }
    }

    *cos_out = (cos_sign > 0) ? x : q_negate(x);
    *sin_out = (sin_sign > 0) ? y : q_negate(y);
}

static inline Q_TYPE q_sin(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);
    return s;
}

static inline Q_TYPE q_cos(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);
    return c;
}

// TODO: Check the CORDIC implementations of vector magnitude, and vector rotations
// TODO: Implement exponential functions
// TODO: Implement logarithmic functions

// tan(x) = sin(x) / cos(x)
static inline Q_TYPE q_tan(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);

#ifdef QGLM_SAFE_MATH
    if (q_eq(c, Q_ZERO))
        return q_lt(s, Q_ZERO) ? Q_MIN : Q_MAX;
#endif
    return q_div(s, c);
}

// cot(x) = cos(x) / sin(x)
static inline Q_TYPE q_cot(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);

#ifdef QGLM_SAFE_MATH
    if (q_eq(s, Q_ZERO))
        return q_lt(c, Q_ZERO) ? Q_MIN : Q_MAX;
#endif
    return q_div(c, s);
}

// -------------------------------- INVERSE TRIGONOMETRY -------------------------------- //

static inline Q_TYPE q_atan(Q_TYPE q)
{
    if (q_eq(q, Q_ZERO))
        return Q_ZERO;

    Q_TYPE x = Q_ONE;
    Q_TYPE y = x;
    Q_TYPE z = Q_ZERO;

    for (uint32_t i = 0; i < Q_CORDIC_ITER; ++i)
    {
        const Q_TYPE dx = q_div_pow_2(y, i);
        const Q_TYPE dy = q_div_pow_2(x, i);

        if (q_ge(y, Q_ZERO))
        {
            x = q_add(x, dx);
            y = q_sub(y, dy);
            z = q_add(z, q_cordic_atan_table[i]);
        }
        else
        {
            x = q_sub(x, dx);
            y = q_add(y, dy);
            z = q_sub(z, q_cordic_atan_table[i]);
        }
    }

    return z;
}

static inline Q_TYPE q_acot(Q_TYPE q)
{
    const Q_TYPE value = q_div(Q_ONE, q);
    return q_atan(value);
}

static inline Q_TYPE q_asin(Q_TYPE q)
{
    const Q_TYPE q2 = q_mul(q, q);
    const Q_TYPE value = q_div(q, q_sqrt(q_sub(Q_ONE, q2)));
    return q_atan(value);

}

static inline Q_TYPE q_acos(Q_TYPE q)
{
    const Q_TYPE angle = q_asin(q);
    return q_sub(Q_HALFPI, angle);
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

