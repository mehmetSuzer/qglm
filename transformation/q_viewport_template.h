
#ifndef __Q_VIEWPORT_TEMPLATE_H__
#define __Q_VIEWPORT_TEMPLATE_H__

static inline Q_MAT4 viewport(int32_t x, int32_t y, uint32_t width, uint32_t height)
{
    const int32_t hw = (width  - 1) / 2;
    const int32_t hh = (height - 1) / 2;

    return (Q_MAT4){{
        Q_FROM_INT(hw),          Q_ZERO, Q_ZERO, Q_FROM_INT(x + hw),
                Q_ZERO, Q_FROM_INT(-hh), Q_ZERO, Q_FROM_INT(y + hh),
                Q_ZERO,          Q_ZERO, Q_HALF,             Q_HALF,
                Q_ZERO,          Q_ZERO, Q_ZERO,              Q_ONE,
    }};
}

#endif // __Q_VIEWPORT_TEMPLATE_H__

