
#ifndef QGLM_Q_EPSILON_TEMPLATE_H
#define QGLM_Q_EPSILON_TEMPLATE_H

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

#endif // QGLM_Q_EPSILON_TEMPLATE_H

