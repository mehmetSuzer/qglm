
#ifndef __Q16_16_MAT3X2_H__
#define __Q16_16_MAT3X2_H__

#include "../vector/q16_16_vec2.h"
#include "../vector/q16_16_vec3.h"

typedef union
{
    struct
    {
        q16_16 xx, xy;
        q16_16 yx, yy;
        q16_16 zx, zy;
    };
    q16_16 raw[3][2];
    q16_16_vec2 rows[3];
} q16_16_mat3x2;


#define Q16_16_MAT3X2_ZERO ((q16_16_mat3x2){{   \
        Q16_16_ZERO, Q16_16_ZERO,               \
        Q16_16_ZERO, Q16_16_ZERO,               \
        Q16_16_ZERO, Q16_16_ZERO                \
}})

// TODO: Implement functions

#endif // __Q16_16_MAT3X2_H__

