
#ifndef __Q_MAT4X2_TEMPLATE_H__
#define __Q_MAT4X2_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy;
        Q_TYPE yx, yy;
        Q_TYPE zx, zy;
        Q_TYPE wx, wy;
    };
    Q_TYPE raw[4][2];
    Q_VEC2 rows[4];
} Q_MAT4X2;

#define Q_MAT4X2_ZERO ((Q_MAT4X2){{ \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
}})

// TODO: Implement functions

#endif // __Q_MAT4X2_TEMPLATE_H__

