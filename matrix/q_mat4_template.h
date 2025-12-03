
#ifndef __Q_MAT4_TEMPLATE_H__
#define __Q_MAT4_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz, xw;
        Q_TYPE yx, yy, yz, yw;
        Q_TYPE zx, zy, zz, zw;
        Q_TYPE wx, wy, wz, ww;
    };
    Q_TYPE raw[4][4];
    Q_VEC4 rows[4];
} Q_MAT4;


#define Q_MAT4_ZERO ((Q_MAT4){{         \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
}})

#define Q_MAT4_IDENTITY ((Q_MAT4){{     \
         Q_ONE, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO,  Q_ONE, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO,  Q_ONE, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE, \
}})

// TODO: Implement functions

#endif // __Q_MAT4_TEMPLATE_H__

