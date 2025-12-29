
#ifndef QGLM_Q_ROOT_TEMPLATE_H
#define QGLM_Q_ROOT_TEMPLATE_H

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

#endif // QGLM_Q_ROOT_TEMPLATE_H

