
#ifndef QGLM_Q_UTIL_TEMPLATE_H
#define QGLM_Q_UTIL_TEMPLATE_H

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

static inline Q_TYPE q_frac(Q_TYPE q)
{
    return q_sub(q, q_floor(q));
}

#endif // QGLM_Q_UTIL_TEMPLATE_H

