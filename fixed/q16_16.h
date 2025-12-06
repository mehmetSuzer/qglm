
#ifndef __Q16_16_H__
#define __Q16_16_H__

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
#define Q_HALFPI     ((Q_TYPE)102943)                  // pi / 2.0
#define Q_THIRDPI    ((Q_TYPE)68629)                   // pi / 3.0
#define Q_FOURTHPI   ((Q_TYPE)51471)                   // pi / 4.0
#define Q_1_PI       ((Q_TYPE)20860)                   // 1.0 / pi
#define Q_2_PI       ((Q_TYPE)41721)                   // 2.0 / pi
#define Q_3_PI       ((Q_TYPE)62582)                   // 3.0 / pi
#define Q_4_PI       ((Q_TYPE)83443)                   // 4.0 / pi
#define Q_SQRTPI     ((Q_TYPE)116159)                  // sqrt(pi)
#define Q_1_SQRTPI   ((Q_TYPE)36974)                   // 1.0 / sqrt(pi)
#define Q_2_SQRTPI   ((Q_TYPE)73949)                   // 2.0 / sqrt(pi)
#define Q_3_SQRTPI   ((Q_TYPE)110924)                  // 3.0 / sqrt(pi)
#define Q_E          ((Q_TYPE)178145)                  // e
#define Q_LOG2E      ((Q_TYPE)94548)                   // log2(e)
#define Q_LOG10E     ((Q_TYPE)28461)                   // log10(e)
#define Q_LN2        ((Q_TYPE)45426)                   // ln(2.0)
#define Q_LN10       ((Q_TYPE)150902)                  // ln(10.0)
#define Q_SQRT2      ((Q_TYPE)92681)                   // sqrt(2.0)
#define Q_SQRT3      ((Q_TYPE)113511)                  // sqrt(3.0)
#define Q_1_SQRT2    ((Q_TYPE)46340)                   // 1.0 / sqrt(2.0)
#define Q_1_SQRT3    ((Q_TYPE)37837)                   // 1.0 / sqrt(3.0)
#define Q_HALFSQRT3  ((Q_TYPE)56755)                   // 0.5 * sqrt(3.0)
#define Q_1_2SQRT3   ((Q_TYPE)18918)                   // 0.5 / sqrt(3.0)

#include "q_template.h"

#endif // __Q16_16_H__

