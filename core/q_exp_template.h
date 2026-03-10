
#ifndef QGLM_Q_EXP_TEMPLATE_H
#define QGLM_Q_EXP_TEMPLATE_H

static inline Q_TYPE q_exp2(Q_TYPE q)
{
    const Q_TYPE i = q_floor(q);
    const int32_t k = Q_TO_INT(i);
    const Q_TYPE f = q_sub(q, i);
    const Q_TYPE f_ln2 = q_mul(f, Q_LN2);
    
    // 2^f = e^(f.ln2) = 1 + f.ln2 + (f.ln2)^2/2! + (f.ln2)^3/3! + (f.ln2)^4/4! + (f.ln2)^5/5! + ...
    const Q_TYPE factor4 = q_add(Q_FROM_DOUBLE(1.0 / 24.0), q_mul(f_ln2, Q_FROM_DOUBLE(1.0 / 120.0)));
    const Q_TYPE factor3 = q_add(Q_FROM_DOUBLE(1.0 /  6.0), q_mul(f_ln2, factor4));
    const Q_TYPE factor2 = q_add(Q_HALF, q_mul(f_ln2, factor3));
    const Q_TYPE factor1 = q_add(Q_ONE, q_mul(f_ln2, factor2));
    const Q_TYPE factor0 = q_add(Q_ONE, q_mul(f_ln2, factor1));

    const Q_TYPE value = (k < 0) ? q_div_pow_2(factor0, -k) : q_mul_pow_2(factor0, k);
    return value;
}

static inline Q_TYPE q_exp(Q_TYPE q)
{
    const int32_t k = q_add(q, q_div_pow_2(Q_LN2, 1)) / Q_LN2;
    const Q_TYPE r = q_sub(q, q_mul_int(Q_LN2, k));
    
    // e^r = 1 + r + r^2/2! + r^3/3! + r^4/4! + r^5/5! + ...
    const Q_TYPE factor4 = q_add(Q_FROM_DOUBLE(1.0 / 24.0), q_mul(r, Q_FROM_DOUBLE(1.0 / 120.0)));
    const Q_TYPE factor3 = q_add(Q_FROM_DOUBLE(1.0 /  6.0), q_mul(r, factor4));
    const Q_TYPE factor2 = q_add(Q_HALF, q_mul(r, factor3));
    const Q_TYPE factor1 = q_add(Q_ONE, q_mul(r, factor2));
    const Q_TYPE factor0 = q_add(Q_ONE, q_mul(r, factor1));

    const Q_TYPE value = (k < 0) ? q_div_pow_2(factor0, -k) : q_mul_pow_2(factor0, k);
    return value;
}

static inline Q_TYPE q_pow(Q_TYPE q1, Q_TYPE q2)
{
    return q_exp(q_mul(q2, q_log(q1)));
}

#endif // QGLM_Q_EXP_TEMPLATE_H

