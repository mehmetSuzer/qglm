
#ifndef QGLM_Q_ARITHMETIC_TEMPLATE_H
#define QGLM_Q_ARITHMETIC_TEMPLATE_H

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

#endif // QGLM_Q_ARITHMETIC_TEMPLATE_H

