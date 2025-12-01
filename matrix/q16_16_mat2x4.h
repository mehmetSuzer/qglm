
#ifndef __Q16_16_MAT2X4_H__
#define __Q16_16_MAT2X4_H__

#include "../vector/q16_16_vec2.h"
#include "../vector/q16_16_vec4.h"

typedef union
{
    struct
    {
        q16_16 xx, xy, xz, xw;
        q16_16 yx, yy, yz, yw;
    };
    q16_16 raw[2][4];
    q16_16_vec4 rows[2];
} q16_16_mat2x4;


#define Q16_16_MAT2X4_ZERO ((q16_16_mat2x4){{               \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO  Q16_16_ZERO, \
}})

// TODO: Implement functions

#endif // __Q16_16_MAT2X4_H__

