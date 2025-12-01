
#ifndef __Q16_16_MAT3_H__
#define __Q16_16_MAT3_H__

#include "../vector/q16_16_vec3.h"

typedef union
{
    struct
    {
        q16_16 xx, xy, xz;
        q16_16 yx, yy, yz;
        q16_16 zx, zy, zz;
    };
    q16_16 raw[3][3];
    q16_16_vec3 rows[3];
} q16_16_mat3;


#define Q16_16_MAT3_ZERO ((q16_16_mat3){{       \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,  \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,  \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO   \
}})

#define Q16_16_MAT3_IDENTITY ((q16_16_mat3){{   \
         Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO,  \
        Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO,  \
        Q16_16_ZERO, Q16_16_ZERO,  Q16_16_ONE   \
}})

// TODO: Implement functions

#endif // __Q16_16_MAT3_H__

