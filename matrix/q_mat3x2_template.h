
#ifndef __Q_MAT3X2_TEMPLATE_H__
#define __Q_MAT3X2_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy;
        Q_TYPE yx, yy;
        Q_TYPE zx, zy;
    };
    Q_TYPE raw[3][2];
    Q_VEC2 rows[3];
} Q_MAT3X2;


#define Q_MAT3X2_ZERO ((Q_MAT3X2){{ \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
}})

// TODO: Implement functions

#endif // __Q_MAT3X2_TEMPLATE_H__

