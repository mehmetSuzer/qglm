
#ifndef __Q16_16_H__
#define __Q16_16_H__

#include <stdint.h>
#include <stdbool.h>

typedef int32_t q16_16;

#define QGLM_BRANCHLESS
#define QGLM_FAST_MATH

#define Q16_16_INTEGER_BITS  0xFFFF0000
#define Q16_16_FRACTION_BITS 0x0000FFFF

// -------------------------------- CONSTANTS -------------------------------- //

#define Q16_16_MIN          ((q16_16)INT32_MIN) // -32768.0
#define Q16_16_MAX          ((q16_16)INT32_MAX) // +32768.0 - 2^(-16)
#define Q16_16_ZERO         ((q16_16)0)         // 0.0
#define Q16_16_HALF         ((q16_16)(1 << 15)) // 0.5
#define Q16_16_ONE          ((q16_16)(1 << 16)) // 1.0
#define Q16_16_TWO          ((q16_16)(2 << 16)) // 2.0
#define Q16_16_PI           ((q16_16)205887)    // pi
#define Q16_16_2PI          ((q16_16)411775)    // pi * 2.0
#define Q16_16_HALFPI       ((q16_16)102943)    // pi / 2.0
#define Q16_16_THIRDPI      ((q16_16)68629)     // pi / 3.0
#define Q16_16_FOURTHPI     ((q16_16)51471)     // pi / 4.0
#define Q16_16_1_PI         ((q16_16)20860)     // 1.0 / pi
#define Q16_16_2_PI         ((q16_16)41721)     // 2.0 / pi
#define Q16_16_3_PI         ((q16_16)62582)     // 3.0 / pi
#define Q16_16_4_PI         ((q16_16)83443)     // 4.0 / pi
#define Q16_16_SQRTPI       ((q16_16)116159)    // sqrt(pi)
#define Q16_16_1_SQRTPI     ((q16_16)36974)     // 1.0 / sqrt(pi)
#define Q16_16_2_SQRTPI     ((q16_16)73949)     // 2.0 / sqrt(pi)
#define Q16_16_3_SQRTPI     ((q16_16)110924)    // 3.0 / sqrt(pi)
#define Q16_16_E            ((q16_16)178145)    // e
#define Q16_16_LOG2E        ((q16_16)94548)     // log2(e)
#define Q16_16_LOG10E       ((q16_16)28461)     // log10(e)
#define Q16_16_LN2          ((q16_16)45426)     // ln(2.0)
#define Q16_16_LN10         ((q16_16)150902)    // ln(10.0)
#define Q16_16_SQRT2        ((q16_16)92681)     // sqrt(2.0)
#define Q16_16_SQRT3        ((q16_16)113511)    // sqrt(3.0)
#define Q16_16_1_SQRT2      ((q16_16)46340)     // 1.0 / sqrt(2.0)
#define Q16_16_1_SQRT3      ((q16_16)37837)     // 1.0 / sqrt(3.0)
#define Q16_16_HALFSQRT3    ((q16_16)56755)     // 0.5 * sqrt(3.0)
#define Q16_16_1_2SQRT3     ((q16_16)18918)     // 0.5 / sqrt(3.0)

// -------------------------------- CONVERSION -------------------------------- //

#define Q16_16_FROM_INT(x)      ((q16_16)((x) << 16))
#define Q16_16_TO_INT(q)        ((int32_t)((q) >> 16))
#define Q16_16_FROM_FLOAT(x)    ((q16_16)((x) * (float)(1 << 16)))
#define Q16_16_TO_FLOAT(q)      ((float)(q) / (float)(1 << 16))

// -------------------------------- BASIC ARITHMETIC -------------------------------- //

// TODO: Add comments about the restrictions on the parameters of functions

static inline q16_16 q16_16_negate(q16_16 q)
{
    return -q;
}

static inline q16_16 q16_16_add(q16_16 q1, q16_16 q2)
{
    return q1 + q2;
}

static inline q16_16 q16_16_sub(q16_16 q1, q16_16 q2)
{
    return q1 - q2;
}

static inline q16_16 q16_16_mul(q16_16 q1, q16_16 q2)
{
    return (q16_16)(((int64_t)q1 * (int64_t)q2) >> 16);
}

static inline q16_16 q16_16_div(q16_16 q1, q16_16 q2)
{
    return (q16_16)((((int64_t)q1) << 16) / q2);
}

static inline q16_16 q16_16_interp(q16_16 q1, q16_16 q2, q16_16 alpha)
{
    return q16_16_add(q2, q16_16_mul(alpha, q16_16_sub(q1, q2)));
}

// TODO: Try to accelerate multiplications and divisions by powers of two in the library
// q * 2^shift
static inline q16_16 q16_16_shift_right(q16_16 q, uint32_t shift)
{
    return q << shift;
}

// q / 2^shift
static inline q16_16 q16_16_shift_left(q16_16 q, uint32_t shift)
{
    return q >> shift;
}

// -------------------------------- ROUNDING -------------------------------- //

static inline q16_16 q16_16_round(q16_16 q)
{
    return (q + Q16_16_HALF) & Q16_16_INTEGER_BITS;
}

static inline q16_16 q16_16_floor(q16_16 q)
{
    return q & Q16_16_INTEGER_BITS;
}

static inline q16_16 q16_16_ceil(q16_16 q)
{
    return (q + Q16_16_FRACTION_BITS) & Q16_16_INTEGER_BITS;
}

// -------------------------------- SATURATION -------------------------------- //

// TODO: Review Saturation functions

static inline q16_16 q16_16_neg_sat(q16_16 q)
{
#ifndef QGLM_BRANCHLESS
    const int32_t over = (x == INT32_MIN);
    return (q16_16)((-q & ~over) | (INT32_MAX & over));
#else
    return (q == INT32_MIN) ? INT32_MAX : -q;
#endif
}

static inline q16_16 q16_16_add_sat(q16_16 q1, q16_16 q2)
{
    const int32_t qr = q1 + q2;

#ifdef QGLM_BRANCHLESS
    const int32_t s1 = q1 >> 31;
    const int32_t s2 = q2 >> 31;
    const int32_t sr = qr >> 31;

    // overflow occurs if sign(q1) == sign(q2) and sign(q1) != sign(qr)
    const int32_t overflow = ~(s1 ^ s2) & (s1 ^ sr);
    
    // if overflow occurs, return (q1 ? INT32_MIN : INT_MAX)
    const int32_t saturation = s1 ^ INT32_MAX;

    return (qr & ~overflow) | (saturation & overflow);
#else
    if (((q1 ^ qr) & (q2 ^ qr)) < 0)
        return (q1 < 0) ? INT32_MIN : INT_MAX;
    return qr;
#endif
}

static inline q16_16 q16_16_sub_sat(q16_16 q1, q16_16 q2)
{
    const int32_t qr = q1 - q2;

#ifndef QGLM_BRANCHLESS
    const int32_t s1 =    q1 >> 31;
    const int32_t s2 = (~q2) >> 31; // subtract = q1 + (-q2)
    const int32_t qr =    qr >> 31;

    const int32_t overflow = ~(q1 ^ q2) & (q1 ^ qr);
    const int32_t saturation = s1 ^ INT_MAX;

    return (qr & ~overflow) | (saturation & overflow);
#else
    if (((q1 ^ qr) & ((~q2) ^ qr)) < 0)
        return (q1 < 0) ? INT32_MIN : INT32_MAX;
    return qr;
#endif
}

static inline q16_16 q16_16_mul_sat(q16_16 q1, q16_16 q2)
{
    const int64_t qr = ((int64_t)q1 * q2) >> 16;

#ifdef QGLM_BRANCHLESS
    const int64_t over  = qr > INT32_MAX;
    const int64_t under = qr < INT32_MIN;

    return (q16_16)(
        (qr & ~(over | under)) |
        (INT32_MAX & -over)    |
        (INT32_MIN & -under)
    );
#else
    if (qr > INT32_MAX) return INT32_MAX;
    if (qr < INT32_MIN) return INT32_MIN;
    return (q16_16)qr;
#endif
}

static inline q16_16 q16_16_div_sat(q16_16 q1, q16_16 q2)
{
#ifdef QGLM_BRANCHLESS
    const int64_t qr = ((int64_t)q1 << 16) / q2;

    // avoid /0 and INT32_MIN/-1
    const int32_t special = (q2 == 0) | ((q1 == INT32_MIN) & (q2 == -1));

    const int64_t over  = qr > INT32_MAX;
    const int64_t under = qr < INT32_MIN;

    const q16_16 sat0 = (q1 >= 0) ? INT32_MAX : INT32_MIN;
    const q16_16 sat1 = INT32_MAX;

    const q16_16 normal = (q16_16)(
        (qr & ~(over | under)) |
        (INT32_MAX & -over)    |
        (INT32_MIN & -under)
    );

    return special ? sat1 | (sat0 & (q2 == 0)) : normal;
#else
    if (q2 == 0)
        return (q1 >= 0) INT32_MAX : INT32_MIN;

    if (q1 == INT_MIN && q2 == -1)
        return INT32_MAX;

    const int64_t qr = ((int64_t)q1 << 16) / q2;

    if (qr > INT32_MAX) return INT32_MAX;
    if (qr < INT32_MIN) return INT32_MIN;
    return (q16_16)qr;
#endif
} 

// -------------------------------- SQUAREROOT -------------------------------- //

static inline q16_16 q16_16_sqrt(q16_16 q)
{
    if (q <= Q16_16_ZERO) return Q16_16_ZERO;

    int32_t shift = 0;

    // Normalise q into [0.5, 2.0)
    while (q >= Q16_16_TWO) { q >>= 2; shift++; }
    while (q < Q16_16_HALF) { q <<= 2; shift--; }

    // Initial guess
    // sqrt(q) = (q + 1.0) / 2.0 is a good approximation for q in [0.5, 2.0)
    q16_16 x = (q + Q16_16_ONE) >> 1;

    // Newton iteration(s)
    // x_(n+1) = (x_n + q/x_n) / 2.0
    x = (x + q16_16_div(q, x)) >> 1; 

    // Undo scaling
    if (shift > 0) x <<=  shift;
    if (shift < 0) x >>= -shift;

    return x;
}

// -------------------------------- TRIGONOMETRY -------------------------------- //

static inline q16_16 q16_16_wrap_pi(q16_16 q)
{
    // q = fmod(q + pi, 2*pi) - pi;
    q += Q16_16_PI;
    q %= Q16_16_2PI;
    q -= Q16_16_PI;

    return q; // q in [-pi, pi)
}

// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
static inline q16_16 q16_16_sin(q16_16 q)
{
    q = q16_16_wrap_pi(q);
    const q16_16 q2 = q16_16_mul(q, q);

#ifndef QGLM_FAST_MATH
    const q16_16 factor0 = q16_16_sub(Q16_16_ONE, q16_16_div(q2, Q16_16_FROM_INT(6)));
#else
    const q16_16 factor2 = q16_16_sub(Q16_16_ONE, q16_16_div(q2, Q16_16_FROM_INT(42)));
    const q16_16 factor1 = q16_16_sub(Q16_16_ONE, q16_16_mul(q16_16_div(q2, Q16_16_FROM_INT(20)), factor2));
    const q16_16 factor0 = q16_16_sub(Q16_16_ONE, q16_16_mul(q16_16_div(q2, Q16_16_FROM_INT(6)), factor1));
#endif

    return q16_16_mul(q, factor0);
}

// cos(x) = sin(x + pi/2)
static inline q16_16 q16_16_cos(q16_16 q)
{
    return q16_16_sin(q16_16_add(q, Q16_16_HALFPI)); 
}

// tan(x) = sin(x) / cos(x)
static inline q16_16 q16_16_tan(q16_16 q)
{
    const q16_16 s = q16_16_sin(q);
    const q16_16 c = q16_16_cos(q);

    if (c == Q16_16_ZERO)
        return (s >= Q16_16_ZERO) ? Q16_16_MAX : Q16_16_MIN;

    return q16_16_div(s, c);
}

// cot(x) = cos(x) / sin(x)
static inline q16_16 q16_16_cot(q16_16 q)
{
    const q16_16 s = q16_16_sin(q);
    const q16_16 c = q16_16_cos(q);

    if (s == Q16_16_ZERO)
        return (c >= Q16_16_ZERO) ? Q16_16_MAX : Q16_16_MIN;

    return q16_16_div(c, s);
}

#endif // __Q16_16_H__

