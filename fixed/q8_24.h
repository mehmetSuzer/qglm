
#ifndef QGLM_Q8_24_H
#define QGLM_Q8_24_H

#include <stdint.h>
#include <stdbool.h>

typedef int32_t q8_24_t;

#define Q_TYPE int32_t
#define Q_WIDE int64_t

#define Q_INT_BITS   8
#define Q_FRAC_BITS 24

#define Q_INT_MASK  0xFF000000
#define Q_FRAC_MASK 0x00FFFFFF

#define Q_MIN        ((Q_TYPE)INT32_MIN)               // -128.0
#define Q_MAX        ((Q_TYPE)INT32_MAX)               // +128.0 - 2^(-24)
#define Q_ZERO       ((Q_TYPE)0)                       //  0.0
#define Q_HALF       ((Q_TYPE)(+1 << (Q_FRAC_BITS-1))) // +0.5
#define Q_ONE        ((Q_TYPE)(+1 << Q_FRAC_BITS))     // +1.0
#define Q_TWO        ((Q_TYPE)(+2 << Q_FRAC_BITS))     // +2.0
#define Q_M_HALF     ((Q_TYPE)-(1 << (Q_FRAC_BITS-1))) // -0.5
#define Q_M_ONE      ((Q_TYPE)-(1 << Q_FRAC_BITS))     // -1.0
#define Q_M_TWO      ((Q_TYPE)-(2 << Q_FRAC_BITS))     // -2.0
#define Q_PI         ((Q_TYPE)52707178)                // pi
#define Q_2PI        ((Q_TYPE)105414357)               // pi * 2.0
#define Q_HALFPI     ((Q_TYPE)26353589)                // pi / 2.0
#define Q_THIRDPI    ((Q_TYPE)17569059)                // pi / 3.0
#define Q_FOURTHPI   ((Q_TYPE)13176794)                // pi / 4.0
#define Q_1_PI       ((Q_TYPE)5340353)                 // 1.0 / pi
#define Q_2_PI       ((Q_TYPE)10680707)                // 2.0 / pi
#define Q_3_PI       ((Q_TYPE)16021061)                // 3.0 / pi
#define Q_4_PI       ((Q_TYPE)21361414)                // 4.0 / pi
#define Q_SQRTPI     ((Q_TYPE)29736841)                // sqrt(pi)
#define Q_1_SQRTPI   ((Q_TYPE)9465530)                 // 1.0 / sqrt(pi)
#define Q_2_SQRTPI   ((Q_TYPE)18931061)                // 2.0 / sqrt(pi)
#define Q_3_SQRTPI   ((Q_TYPE)28396591)                // 3.0 / sqrt(pi)
#define Q_E          ((Q_TYPE)45605201)                // e
#define Q_LOG2E      ((Q_TYPE)24204406)                // log2(e)
#define Q_LOG10E     ((Q_TYPE)7286252)                 // log10(e)
#define Q_LN2        ((Q_TYPE)11629079)                // ln(2.0)
#define Q_LN10       ((Q_TYPE)38630967)                // ln(10.0)
#define Q_SQRT2      ((Q_TYPE)23726566)                // sqrt(2.0)
#define Q_SQRT3      ((Q_TYPE)29058990)                // sqrt(3.0)
#define Q_1_SQRT2    ((Q_TYPE)11863283)                // 1.0 / sqrt(2.0)
#define Q_1_SQRT3    ((Q_TYPE)9686330)                 // 1.0 / sqrt(3.0)
#define Q_HALFSQRT3  ((Q_TYPE)14529495)                // 0.5 * sqrt(3.0)
#define Q_1_2SQRT3   ((Q_TYPE)4843165)                 // 0.5 / sqrt(3.0)
#define Q_TO_RADIAN  ((Q_TYPE)292817)                  // pi / 180.0
#define Q_TO_DEGREE  ((Q_TYPE)961263668)               // 180.0 / pi

#include "q_template.h"

#endif // QGLM_Q8_24_H

