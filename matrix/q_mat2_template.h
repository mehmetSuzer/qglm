
#ifndef __Q_MAT2_TEMPLATE_H__
#define __Q_MAT2_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy;
        Q_TYPE yx, yy;
    };
    Q_TYPE raw[2][2];
    Q_VEC2 rows[2];
} Q_MAT2;


#define Q_MAT2_ZERO ((Q_MAT2){{     \
        Q_ZERO, Q_ZERO,             \
        Q_ZERO, Q_ZERO,             \
}})

#define Q_MAT2_IDENTITY ((Q_MAT2){{ \
         Q_ONE, Q_ZERO,             \
        Q_ZERO,  Q_ONE,             \
}})

// TODO: Implement functions

#endif // __Q_MAT2_TEMPLATE_H__

