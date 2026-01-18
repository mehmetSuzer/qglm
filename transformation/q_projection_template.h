
#ifndef QGLM_Q_PROJECTION_TEMPLATE_H
#define QGLM_Q_PROJECTION_TEMPLATE_H

static inline Q_MAT4 q_orthographic(Q_TYPE width, Q_TYPE height, Q_TYPE near, Q_TYPE far)
{
    const Q_TYPE inv_far_minus_near = q_div(Q_ONE, q_sub(far, near));

    const Q_TYPE xx = q_div(Q_TWO, width);
    const Q_TYPE yy = q_div(Q_TWO, height);
    const Q_TYPE zz = q_negate(q_mul_pow_2(inv_far_minus_near, 1));
    const Q_TYPE zw = q_negate(q_mul(q_add(far, near), inv_far_minus_near));

    return (Q_MAT4){{
            xx, Q_ZERO, Q_ZERO, Q_ZERO,
        Q_ZERO,     yy, Q_ZERO, Q_ZERO,
        Q_ZERO, Q_ZERO,     zz,     zw,
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

static inline Q_MAT4 q_perspective(Q_TYPE fovw, Q_TYPE aspect_ratio, Q_TYPE near, Q_TYPE far)
{
    const Q_TYPE cot_half_fovw = q_cot(q_div_pow_2(fovw, 1));
    const Q_TYPE inv_far_minus_near = q_div(Q_ONE, q_sub(far, near));

    const Q_TYPE xx = cot_half_fovw;
    const Q_TYPE yy = q_mul(cot_half_fovw, aspect_ratio);
    const Q_TYPE zz = q_negate(q_mul(q_add(far, near), inv_far_minus_near));
    const Q_TYPE zw = q_negate(q_mul_pow_2(q_mul(q_mul(far, near), inv_far_minus_near), 1));
    const Q_TYPE wz = Q_M_ONE;

    return (Q_MAT4){{
            xx, Q_ZERO, Q_ZERO, Q_ZERO,
        Q_ZERO,     yy, Q_ZERO, Q_ZERO,
        Q_ZERO, Q_ZERO,     zz,     zw,
        Q_ZERO, Q_ZERO,     wz, Q_ZERO,
    }};
}

#endif // QGLM_Q_PROJECTION_TEMPLATE_H

