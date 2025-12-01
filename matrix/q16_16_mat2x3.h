
#ifndef __Q16_16_MAT2X3_H__
#define __Q16_16_MAT2X3_H__

#include "../vector/q16_16_vec2.h"
#include "../vector/q16_16_vec3.h"

typedef union
{
    struct
    {
        q16_16 xx, xy, xz;
        q16_16 yx, yy, yz;
    };
    q16_16 raw[2][3];
    q16_16_vec3 rows[2];
} q16_16_mat2x3;


#define Q16_16_MAT2X3_ZERO ((q16_16_mat2x3){{   \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,  \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO   \
}})

// TODO: Implement functions

#endif // __Q16_16_MAT2X3_H__

