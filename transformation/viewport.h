
#ifndef __VIEWPORT_H__
#define __VIEWPORT_H__

#include "../matrix/q16_16_mat4.h"

static inline q16_16_mat4 viewport(int32_t x, int32_t y, uint32_t width, uint32_t height)
{
    const int32_t hw = (width  - 1) / 2;
    const int32_t hh = (height - 1) / 2;

    return (q16_16_mat4){{
        Q16_16_FROM_INT(hw),          Q16_16_ZERO, Q16_16_ZERO, Q16_16_FROM_INT(x + hw),
                Q16_16_ZERO, Q16_16_FROM_INT(-hh), Q16_16_ZERO, Q16_16_FROM_INT(y + hh),
                Q16_16_ZERO,          Q16_16_ZERO, Q16_16_HALF,             Q16_16_HALF,
                Q16_16_ZERO,          Q16_16_ZERO, Q16_16_ZERO,              Q16_16_ONE,
    }};
}

#endif // __VIEWPORT_H__

