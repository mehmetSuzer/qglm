
#ifndef __Q_VIEWPORT_TEMPLATE_H__
#define __Q_VIEWPORT_TEMPLATE_H__

// The origin of the window is the top left corner of the window.
// The near plan is mapped to Q_ZERO, while the far plane is mapped to Q_ONE.
static inline Q_MAT4 viewport(int32_t x, int32_t y, uint32_t width, uint32_t height)
{
    const int32_t hw = (width  - 1) / 2;
    const int32_t hh = (height - 1) / 2;

    const Q_TYPE xx = Q_FROM_INT(hw);
    const Q_TYPE xw = Q_FROM_INT(x + hw);
    const Q_TYPE yy = Q_FROM_INT(-hh);
    const Q_TYPE yw = Q_FROM_INT(y + hh);

    return (Q_MAT4){{
            xx, Q_ZERO, Q_ZERO,     xw,
        Q_ZERO,     yy, Q_ZERO,     yw,
        Q_ZERO, Q_ZERO, Q_HALF, Q_HALF,
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

#endif // __Q_VIEWPORT_TEMPLATE_H__

