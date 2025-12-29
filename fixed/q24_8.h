
#ifndef QGLM_Q24_8_H
#define QGLM_Q24_8_H

#include <stdint.h>
#include <stdbool.h>

typedef int32_t q24_8_t;

#define Q_TYPE int32_t
#define Q_WIDE int64_t

#define Q_INT_BITS  24
#define Q_FRAC_BITS  8

#define Q_INT_MASK  0xFFFFFF00
#define Q_FRAC_MASK 0x000000FF

#define Q_MIN            ((Q_TYPE)INT32_MIN)               // -8388608.0
#define Q_MAX            ((Q_TYPE)INT32_MAX)               // +8388608.0 - 2^(-8)

#define Q_ZERO           ((Q_TYPE)0)                       //  0.00

#define Q_QUARTER        ((Q_TYPE)+(1 << (Q_FRAC_BITS-2))) // +0.25
#define Q_HALF           ((Q_TYPE)+(1 << (Q_FRAC_BITS-1))) // +0.50
#define Q_THREEQUARTER   ((Q_TYPE)+(3 << (Q_FRAC_BITS-2))) // +0.75
#define Q_ONE            ((Q_TYPE)+(1 << Q_FRAC_BITS))     // +1.00
#define Q_THREEHALF      ((Q_TYPE)+(3 << (Q_FRAC_BITS-1))) // +1.50
#define Q_TWO            ((Q_TYPE)+(2 << Q_FRAC_BITS))     // +2.00
#define Q_THREE          ((Q_TYPE)+(3 << Q_FRAC_BITS))     // +3.00

#define Q_M_QUARTER      ((Q_TYPE)-(1 << (Q_FRAC_BITS-2))) // -0.25
#define Q_M_HALF         ((Q_TYPE)-(1 << (Q_FRAC_BITS-1))) // -0.50
#define Q_M_THREEQUARTER ((Q_TYPE)-(3 << (Q_FRAC_BITS-2))) // -0.75
#define Q_M_ONE          ((Q_TYPE)-(1 << Q_FRAC_BITS))     // -1.00
#define Q_M_THREEHALF    ((Q_TYPE)-(3 << (Q_FRAC_BITS-1))) // -1.50
#define Q_M_TWO          ((Q_TYPE)-(2 << Q_FRAC_BITS))     // -2.00
#define Q_M_THREE        ((Q_TYPE)-(3 << Q_FRAC_BITS))     // -3.00

#define Q_PI             ((Q_TYPE)804)                     // pi
#define Q_2PI            ((Q_TYPE)1608)                    // pi * 2.0
#define Q_HALFPI         ((Q_TYPE)402)                     // pi / 2.0
#define Q_THIRDPI        ((Q_TYPE)268)                     // pi / 3.0
#define Q_FOURTHPI       ((Q_TYPE)201)                     // pi / 4.0
#define Q_1_PI           ((Q_TYPE)81)                      // 1.0 / pi
#define Q_2_PI           ((Q_TYPE)163)                     // 2.0 / pi
#define Q_3_PI           ((Q_TYPE)244)                     // 3.0 / pi
#define Q_4_PI           ((Q_TYPE)326)                     // 4.0 / pi
#define Q_SQRTPI         ((Q_TYPE)454)                     // sqrt(pi)
#define Q_1_SQRTPI       ((Q_TYPE)144)                     // 1.0 / sqrt(pi)
#define Q_2_SQRTPI       ((Q_TYPE)289)                     // 2.0 / sqrt(pi)
#define Q_3_SQRTPI       ((Q_TYPE)433)                     // 3.0 / sqrt(pi)

#define Q_E              ((Q_TYPE)696)                     // e
#define Q_LOG2E          ((Q_TYPE)369)                     // log2(e)
#define Q_LOG10E         ((Q_TYPE)111)                     // log10(e)
#define Q_LN2            ((Q_TYPE)177)                     // ln(2.0)
#define Q_LN10           ((Q_TYPE)589)                     // ln(10.0)

#define Q_SQRT2          ((Q_TYPE)362)                     // sqrt(2.0)
#define Q_SQRT3          ((Q_TYPE)443)                     // sqrt(3.0)
#define Q_1_SQRT2        ((Q_TYPE)181)                     // 1.0 / sqrt(2.0)
#define Q_1_SQRT3        ((Q_TYPE)148)                     // 1.0 / sqrt(3.0)
#define Q_HALFSQRT3      ((Q_TYPE)222)                     // 0.5 * sqrt(3.0)
#define Q_1_2SQRT3       ((Q_TYPE)74)                      // 0.5 / sqrt(3.0)

#define Q_TO_RADIAN      ((Q_TYPE)4)                       // pi / 180.0
#define Q_TO_DEGREE      ((Q_TYPE)14668)                   // 180.0 / pi

#define Q_EPSILON        ((Q_TYPE)32)                      // epsilon

#include "q_conversion_template.h"
#include "q_comparison_template.h"
#include "q_arithmetic_template.h"
#include "q_fast_math_template.h"
#include "q_util_template.h"
#include "q_root_template.h"
#include "q_log_template.h"
#include "q_exp_template.h"
#include "q_tri_template.h"
#include "q_inv_tri_template.h"
#include "q_epsilon_template.h"

#endif // QGLM_Q24_8_H

