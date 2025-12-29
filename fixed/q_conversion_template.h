
#ifndef QGLM_Q_CONVERSION_TEMPLATE_H
#define QGLM_Q_CONVERSION_TEMPLATE_H

#ifdef QGLM_SAFE_MATH
    #define Q_FROM_INT(x)       (((x) < (INT32_MIN >> Q_FRAC_BITS)) ? Q_MIN : \
                                 ((x) > (INT32_MAX >> Q_FRAC_BITS)) ? Q_MAX : \
                                 (Q_TYPE)((x) * (1 << Q_FRAC_BITS)))

    #define Q_FROM_FLOAT(x)     (((x) < (float)INT32_MIN / (float)(1 << Q_FRAC_BITS)) ? Q_MIN : \
                                 ((x) > (float)INT32_MAX / (float)(1 << Q_FRAC_BITS)) ? Q_MAX : \
                                 (Q_TYPE)((x) * (float)(1 << Q_FRAC_BITS)))

    #define Q_FROM_DOUBLE(x)    (((x) < (double)INT32_MIN / (double)(1 << Q_FRAC_BITS)) ? Q_MIN : \
                                 ((x) > (double)INT32_MAX / (double)(1 << Q_FRAC_BITS)) ? Q_MAX : \
                                 (Q_TYPE)((x) * (double)(1 << Q_FRAC_BITS)))
#else
    #define Q_FROM_INT(x)       ((Q_TYPE)((x) * (1 << Q_FRAC_BITS)))
    #define Q_FROM_FLOAT(x)     ((Q_TYPE)((x) * (float)(1 << Q_FRAC_BITS)))
    #define Q_FROM_DOUBLE(x)    ((Q_TYPE)((x) * (double)(1 << Q_FRAC_BITS)))
#endif

#define Q_TO_INT(q)         ((int32_t)((q) >> Q_FRAC_BITS))
#define Q_TO_FLOAT(q)       ((float)(q) / (float)(1 << Q_FRAC_BITS))
#define Q_TO_DOUBLE(q)      ((double)(q) / (double)(1 << Q_FRAC_BITS))

#endif // QGLM_Q_CONVERSION_TEMPLATE_H

