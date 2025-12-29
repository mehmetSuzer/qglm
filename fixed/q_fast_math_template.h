
#ifndef QGLM_Q_FAST_MATH_TEMPLATE_H
#define QGLM_Q_FAST_MATH_TEMPLATE_H

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

#endif // QGLM_Q_FAST_MATH_TEMPLATE_H

