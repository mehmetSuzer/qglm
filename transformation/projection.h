
#ifndef __PROJECTION_H__
#define __PROJECTION_H__

#include "../matrix/q16_16_mat4.h"

static inline q16_16_mat4 orthographic(q16_16 width, q16_16 height, q16_16 near, q16_16 far)
{
    const q16_16 far_plus_near = q16_16_add(far, near);
    const q16_16 inv_far_minus_near = q16_16_div(Q16_16_ONE, q16_16_sub(far, near));

    const q16_16 xx = q16_16_div(Q16_16_TWO, width);
    const q16_16 yy = q16_16_div(Q16_16_TWO, height);
    const q16_16 zz = q16_16_negate(q16_16_mul(Q16_16_TWO, inv_far_minus_near));
    const q16_16 zw = q16_16_negate(q16_16_mul(far_plus_near, inv_far_minus_near));
    const q16_16 ww = Q16_16_ONE;

    return (q16_16_mat4){{
                 xx, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,
        Q16_16_ZERO,          yy, Q16_16_ZERO, Q16_16_ZERO,
        Q16_16_ZERO, Q16_16_ZERO,          zz,          zw,
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,          ww,
    }};
}

static inline q16_16_mat4 perspective(q16_16 fovw, q16_16 aspect_ratio, q16_16 near, q16_16 far)
{
    const q16_16 half_fovw = q16_16_shift_right(fovw, 1);
    const q16_16 inv_tan_half_fovw = q16_16_div(Q16_16_ONE, q16_16_tan(half_fovw));
    const q16_16 inv_far_minus_near = q16_16_div(Q16_16_ONE, q16_16_sub(far, near));

    const q16_16 xx = inv_tan_half_fovw;
    const q16_16 yy = q16_16_mul(inv_tan_half_fovw, aspect_ratio);
    const q16_16 zz = q16_16_negate(q16_16_mul(q16_16_add(far, near), inv_far_minus_near));
    const q16_16 zw = q16_16_negate(q16_16_mul(q16_16_mul(q16_16_mul(Q16_16_TWO, far), near), inv_far_minus_near));
    const q16_16 wz = q16_16_negate(Q16_16_ONE);

    return (q16_16_mat4){{
                 xx, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,
        Q16_16_ZERO,          yy, Q16_16_ZERO, Q16_16_ZERO,
        Q16_16_ZERO, Q16_16_ZERO,          zz,          zw,
        Q16_16_ZERO, Q16_16_ZERO,          wz, Q16_16_ZERO,
    }};
}

#endif // __PROJECTION_H__

