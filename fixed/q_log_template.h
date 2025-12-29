
#ifndef QGLM_Q_LOG_TEMPLATE_H
#define QGLM_Q_LOG_TEMPLATE_H

static inline Q_TYPE q_log2(Q_TYPE q)
{
    int32_t power = 0;

    // log2(q) = m * 2^power
    // Normalise q into [1.0, 2.0)
    while (q_ge(q, Q_TWO)) { q = q_div_pow_2(q, 1); power++; }
    while (q_lt(q, Q_ONE)) { q = q_mul_pow_2(q, 1); power--; }

    // log2(m) = ln(m) / ln2
    // ln(m) = 2.0 * atanh((m-1)/(m+1))
    // atanh(x) = x + x^3/3 + x^5/5 + x^7/7 + ...

    // x = (m-1) / (m+1)
    const Q_TYPE x = q_div(q_sub(q, Q_ONE), q_add(q, Q_ONE));
    const Q_TYPE x2 = q_mul(x, x);

    const Q_TYPE factor3 = q_add(Q_FROM_DOUBLE(1.0 / 5.0), q_div(x2, Q_FROM_INT(7)));
    const Q_TYPE factor2 = q_add(Q_FROM_DOUBLE(1.0 / 3.0), q_mul(x2, factor3));
    const Q_TYPE factor1 = q_add(Q_ONE, q_mul(x2, factor2));
    const Q_TYPE factor0 = q_mul(x, factor1);

    const Q_TYPE ln_m = q_mul_pow_2(factor0, 1);
    const Q_TYPE log2_m = q_div(ln_m, Q_LN2);

    return q_add(log2_m, Q_FROM_INT(power));
}

static inline Q_TYPE q_log(Q_TYPE q)
{
    return q_mul(q_log2(q), Q_LN2);
}

#endif // QGLM_Q_LOG_TEMPLATE_H

