
#ifndef QGLM_Q16_16_H
#define QGLM_Q16_16_H

#include <stdint.h>
#include <stdbool.h>

typedef int32_t q16_16_t;

#define Q_TYPE int32_t
#define Q_WIDE int64_t

#define Q_INT_BITS  16
#define Q_FRAC_BITS 16

#define Q_INT_MASK  0xFFFF0000
#define Q_FRAC_MASK 0x0000FFFF

#define Q_MIN        ((Q_TYPE)INT32_MIN)               // -32768.0
#define Q_MAX        ((Q_TYPE)INT32_MAX)               // +32768.0 - 2^(-16)
#define Q_ZERO       ((Q_TYPE)0)                       //  0.0
#define Q_HALF       ((Q_TYPE)(1 << (Q_FRAC_BITS-1)))  // +0.5
#define Q_ONE        ((Q_TYPE)(1 << Q_FRAC_BITS))      // +1.0
#define Q_TWO        ((Q_TYPE)(2 << Q_FRAC_BITS))      // +2.0
#define Q_M_HALF     ((Q_TYPE)-(1 << (Q_FRAC_BITS-1))) // -0.5
#define Q_M_ONE      ((Q_TYPE)-(1 << Q_FRAC_BITS))     // -1.0
#define Q_M_TWO      ((Q_TYPE)-(2 << Q_FRAC_BITS))     // -2.0
#define Q_PI         ((Q_TYPE)205887)                  // pi
#define Q_2PI        ((Q_TYPE)411775)                  // pi * 2.0
#define Q_HALFPI     ((Q_TYPE)102944)                  // pi / 2.0
#define Q_THIRDPI    ((Q_TYPE)68629)                   // pi / 3.0
#define Q_FOURTHPI   ((Q_TYPE)51472)                   // pi / 4.0
#define Q_1_PI       ((Q_TYPE)20861)                   // 1.0 / pi
#define Q_2_PI       ((Q_TYPE)41722)                   // 2.0 / pi
#define Q_3_PI       ((Q_TYPE)62582)                   // 3.0 / pi
#define Q_4_PI       ((Q_TYPE)83443)                   // 4.0 / pi
#define Q_SQRTPI     ((Q_TYPE)116160)                  // sqrt(pi)
#define Q_1_SQRTPI   ((Q_TYPE)36975)                   // 1.0 / sqrt(pi)
#define Q_2_SQRTPI   ((Q_TYPE)73949)                   // 2.0 / sqrt(pi)
#define Q_3_SQRTPI   ((Q_TYPE)110924)                  // 3.0 / sqrt(pi)
#define Q_E          ((Q_TYPE)178145)                  // e
#define Q_LOG2E      ((Q_TYPE)94548)                   // log2(e)
#define Q_LOG10E     ((Q_TYPE)28462)                   // log10(e)
#define Q_LN2        ((Q_TYPE)45426)                   // ln(2.0)
#define Q_LN10       ((Q_TYPE)150902)                  // ln(10.0)
#define Q_SQRT2      ((Q_TYPE)92682)                   // sqrt(2.0)
#define Q_SQRT3      ((Q_TYPE)113512)                  // sqrt(3.0)
#define Q_1_SQRT2    ((Q_TYPE)46341)                   // 1.0 / sqrt(2.0)
#define Q_1_SQRT3    ((Q_TYPE)37837)                   // 1.0 / sqrt(3.0)
#define Q_HALFSQRT3  ((Q_TYPE)56756)                   // 0.5 * sqrt(3.0)
#define Q_1_2SQRT3   ((Q_TYPE)18919)                   // 0.5 / sqrt(3.0)
#define Q_TO_RADIAN  ((Q_TYPE)1144)                    // pi / 180.0
#define Q_TO_DEGREE  ((Q_TYPE)3754936)                 // 180.0 / pi
#define Q_EPSILON    ((Q_TYPE)1572)                    // epsilon

#include "q_template.h"

#endif // QGLM_Q16_16_H

