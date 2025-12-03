
#ifndef __Q_MAT2X3_TEMPLATE_H__
#define __Q_MAT2X3_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz;
        Q_TYPE yx, yy, yz;
    };
    Q_TYPE raw[2][3];
    Q_VEC3 rows[2];
} Q_MAT2X3;


#define Q_MAT2X3_ZERO ((Q_MAT2X3){{ \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
}})

// TODO: Implement functions

#endif // __Q_MAT2X3_TEMPLATE_H__

