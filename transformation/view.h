
#ifndef __VIEW_H__
#define __VIEW_H__

#include "../vector/q16_16_vec3.h"
#include "../matrix/q16_16_mat4.h"

static inline q16_16_mat4 view(q16_16_vec3 eye, q16_16_vec3 forward, q16_16_vec3 up)
{
    const q16_16_vec3 right = q16_16_vec3_cross(forward, up);

    const q16_16 dotr = q16_16_vec3_dot(right,   eye);
    const q16_16 dotu = q16_16_vec3_dot(up,      eye);
    const q16_16 dotf = q16_16_vec3_dot(forward, eye);

    return (q16_16_mat4){{
           right.x,     right.y,     right.z,      -dotr,
              up.x,        up.y,        up.z,      -dotu,
        -forward.x,  -forward.y,  -forward.z,       dotf,
       Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ONE,
    }};
}

#endif // __VIEW_H__

