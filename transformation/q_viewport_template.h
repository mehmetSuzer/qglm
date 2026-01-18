
#ifndef QGLM_Q_VIEWPORT_TEMPLATE_H
#define QGLM_Q_VIEWPORT_TEMPLATE_H

// The origin of the window is the top left corner of the window.
// The near plane is mapped to Q_ZERO, while the far plane is mapped to Q_ONE.
static inline Q_MAT4 q_viewport(int32_t x, int32_t y, uint32_t width, uint32_t height)
{
    const int32_t half_w = width  >> 1;
    const int32_t half_h = height >> 1;

    const Q_TYPE xx = Q_FROM_INT(half_w);
    const Q_TYPE xw = Q_FROM_INT(x + half_w);
    const Q_TYPE yy = Q_FROM_INT(-half_h);
    const Q_TYPE yw = Q_FROM_INT(y + half_h);

    return (Q_MAT4){{
            xx, Q_ZERO, Q_ZERO,     xw,
        Q_ZERO,     yy, Q_ZERO,     yw,
        Q_ZERO, Q_ZERO, Q_HALF, Q_HALF,
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

#endif // QGLM_Q_VIEWPORT_TEMPLATE_H

