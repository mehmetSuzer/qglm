
#ifndef __Q_MAT3_TEMPLATE_H__
#define __Q_MAT3_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz;
        Q_TYPE yx, yy, yz;
        Q_TYPE zx, zy, zz;
    };
    Q_TYPE raw[3][3];
    Q_VEC3 rows[3];
} Q_MAT3;


#define Q_MAT3_ZERO ((Q_MAT3){{ \
        Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, \
}})

#define Q_MAT3_IDENTITY ((Q_MAT3){{ \
         Q_ONE, Q_ZERO, Q_ZERO,     \
        Q_ZERO,  Q_ONE, Q_ZERO,     \
        Q_ZERO, Q_ZERO,  Q_ONE,     \
}})

// TODO: Implement functions

#endif // __Q_MAT3_TEMPLATE_H__

