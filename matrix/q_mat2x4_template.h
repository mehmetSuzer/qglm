
#ifndef __Q_MAT2X4_TEMPLATE_H__
#define __Q_MAT2X4_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz, xw;
        Q_TYPE yx, yy, yz, yw;
    };
    Q_TYPE raw[2][4];
    Q_VEC4 rows[2];
} Q_MAT2X4;


#define Q_MAT2X4_ZERO ((Q_MAT2X4){{     \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO  Q_ZERO, \
}})

// TODO: Implement functions

#endif // __Q_MAT2X4_TEMPLATE_H__

