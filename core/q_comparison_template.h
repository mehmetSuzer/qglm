
#ifndef QGLM_Q_COMPARISON_TEMPLATE_H
#define QGLM_Q_COMPARISON_TEMPLATE_H

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

#endif // QGLM_Q_COMPARISON_TEMPLATE_H

