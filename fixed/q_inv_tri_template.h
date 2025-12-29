
#ifndef QGLM_Q_INV_TRI_TEMPLATE_H
#define QGLM_Q_INV_TRI_TEMPLATE_H

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

#endif // QGLM_Q_INV_TRI_TEMPLATE_H

