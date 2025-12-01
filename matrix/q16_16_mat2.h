
#ifndef __Q16_16_MAT2_H__
#define __Q16_16_MAT2_H__

#include "../vector/q16_16_vec2.h"

typedef union
{
    struct
    {
        q16_16 xx, xy;
        q16_16 yx, yy;
    };
    q16_16 raw[2][2];
    q16_16_vec2 rows[2];
} q16_16_mat2;


#define Q16_16_MAT2_ZERO ((q16_16_mat2){{       \
        Q16_16_ZERO, Q16_16_ZERO,               \
        Q16_16_ZERO, Q16_16_ZERO                \
}})

#define Q16_16_MAT2_IDENTITY ((q16_16_mat2){{   \
         Q16_16_ONE, Q16_16_ZERO,               \
        Q16_16_ZERO,  Q16_16_ONE                \
}})

// TODO: Implement functions

#endif // __Q16_16_MAT2_H__

