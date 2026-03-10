
#ifndef QGLM_Q_VIEWPORT_TEMPLATE_H
#define QGLM_Q_VIEWPORT_TEMPLATE_H

// The origin of the window is the top left corner of the window.
// If QGLM_DEPTH_ZERO_TO_ONE is defined, the near plane is mapped to Q_ZERO, while the far plane is mapped to Q_ONE.
// Otherwise, they are mapped to Q_M_ONE and Q_ONE respectively.
static inline Q_MAT4 q_viewport(int32_t x, int32_t y, uint32_t width, uint32_t height)
{
    const int32_t half_w = width  >> 1;
    const int32_t half_h = height >> 1;

    const Q_TYPE xx = Q_FROM_INT(half_w);
    const Q_TYPE xw = Q_FROM_INT(x + half_w);
    const Q_TYPE yy = Q_FROM_INT(-half_h);
    const Q_TYPE yw = Q_FROM_INT(y + half_h);

#if QGLM_DEPTH_ZERO_TO_ONE
    const Q_TYPE zz = Q_HALF;
    const Q_TYPE zw = Q_HALF;
#else
    const Q_TYPE zz = Q_ONE;
    const Q_TYPE zw = Q_ZERO;
#endif

    const Q_TYPE ww = Q_ONE;

    return (Q_MAT4){{
            xx, Q_ZERO, Q_ZERO, xw,
        Q_ZERO,     yy, Q_ZERO, yw,
        Q_ZERO, Q_ZERO,     zz, zw,
        Q_ZERO, Q_ZERO, Q_ZERO, ww,
    }};
}

#endif // QGLM_Q_VIEWPORT_TEMPLATE_H

