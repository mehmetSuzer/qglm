
#ifndef __Q16_16_MAT4_H__
#define __Q16_16_MAT4_H__

#include "../vector/q16_16_vec4.h"

typedef union
{
    struct
    {
        q16_16 xx, xy, xz, xw;
        q16_16 yx, yy, yz, yw;
        q16_16 zx, zy, zz, zw;
        q16_16 wx, wy, wz, ww;
    };
    q16_16 raw[4][4];
    q16_16_vec4 rows[4];
} q16_16_mat4;


#define Q16_16_MAT4_ZERO ((q16_16_mat4){{                   \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO  \
}})

#define Q16_16_MAT4_IDENTITY ((q16_16_mat4){{               \
         Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO, \
        Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO, Q16_16_ZERO, \
        Q16_16_ZERO, Q16_16_ZERO,  Q16_16_ONE, Q16_16_ZERO, \
        Q16_16_ZERO, Q16_16_ZERO, Q16_16_ZERO,  Q16_16_ONE  \
}})

// TODO: Implement functions

#endif // __Q16_16_MAT4_H__

