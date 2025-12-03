
#ifndef __Q_MAT4X3_TEMPLATE_H__
#define __Q_MAT4X3_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz;
        Q_TYPE yx, yy, yz;
        Q_TYPE zx, zy, zz;
        Q_TYPE wx, wy, wz;
    };
    Q_TYPE raw[4][3];
    Q_VEC3 rows[4];
} Q_MAT4X3;


#define Q_MAT4X3_ZERO ((Q_MAT4X3){{ \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
        Q_ZERO, Q_ZERO, Q_ZERO,     \
}})

// TODO: Implement functions

#endif // __Q_MAT4X3_TEMPLATE_H__

