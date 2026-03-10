
#ifndef QGLM_Q8_24_H
#define QGLM_Q8_24_H

#include <stdint.h>
#include <stdbool.h>

typedef int32_t q8_24_t;

#define Q_TYPE int32_t
#define Q_WIDE int64_t

#define Q_INT_BITS   8
#define Q_FRAC_BITS 24

#define Q_INT_MASK  ((uint32_t)0xFF000000u)
#define Q_FRAC_MASK ((uint32_t)0x00FFFFFFu)

#define Q_MIN            ((Q_TYPE)INT32_MIN)               // -128.0
#define Q_MAX            ((Q_TYPE)INT32_MAX)               // +128.0 - 2^(-24)

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

#define Q_PI             ((Q_TYPE)52707179)                // pi
#define Q_TWOPI          ((Q_TYPE)105414357)               // pi * 2.0
#define Q_HALFPI         ((Q_TYPE)26353589)                // pi / 2.0
#define Q_THIRDPI        ((Q_TYPE)17569060)                // pi / 3.0
#define Q_QUARTERPI      ((Q_TYPE)13176795)                // pi / 4.0
#define Q_1_PI           ((Q_TYPE)5340354)                 // 1.0 / pi
#define Q_2_PI           ((Q_TYPE)10680707)                // 2.0 / pi
#define Q_3_PI           ((Q_TYPE)16021061)                // 3.0 / pi
#define Q_4_PI           ((Q_TYPE)21361415)                // 4.0 / pi
#define Q_SQRTPI         ((Q_TYPE)29736841)                // sqrt(pi)
#define Q_1_SQRTPI       ((Q_TYPE)9465531)                 // 1.0 / sqrt(pi)
#define Q_2_SQRTPI       ((Q_TYPE)18931061)                // 2.0 / sqrt(pi)
#define Q_3_SQRTPI       ((Q_TYPE)28396592)                // 3.0 / sqrt(pi)

#define Q_E              ((Q_TYPE)45605201)                // e
#define Q_LOG2_E         ((Q_TYPE)24204406)                // log2(e)
#define Q_LOG2_10        ((Q_TYPE)55732705)                // log2(10)
#define Q_LN2            ((Q_TYPE)11629080)                // ln(2.0)
#define Q_LN10           ((Q_TYPE)38630967)                // ln(10.0)
#define Q_LOG10_2        ((Q_TYPE)5050445)                 // log10(2)
#define Q_LOG10_E        ((Q_TYPE)7286252)                 // log10(e)

#define Q_SQRT2          ((Q_TYPE)23726566)                // sqrt(2.0)
#define Q_SQRT3          ((Q_TYPE)29058991)                // sqrt(3.0)
#define Q_1_SQRT2        ((Q_TYPE)11863283)                // 1.0 / sqrt(2.0)
#define Q_1_SQRT3        ((Q_TYPE)9686330)                 // 1.0 / sqrt(3.0)
#define Q_HALFSQRT3      ((Q_TYPE)14529495)                // 0.5 * sqrt(3.0)
#define Q_1_2SQRT3       ((Q_TYPE)4843165)                 // 0.5 / sqrt(3.0)

#define Q_TO_RADIAN      ((Q_TYPE)292818)                  // pi / 180.0
#define Q_TO_DEGREE      ((Q_TYPE)961263669)               // 180.0 / pi

#define Q_EPSILON        ((Q_TYPE)+32)                     // +epsilon
#define Q_M_EPSILON      ((Q_TYPE)-32)                     // -epsilon

#include "core/q_conversion_template.h"
#include "core/q_comparison_template.h"
#include "core/q_arithmetic_template.h"
#include "core/q_fast_math_template.h"
#include "core/q_util_template.h"
#include "core/q_root_template.h"
#include "core/q_log_template.h"
#include "core/q_exp_template.h"
#include "core/q_tri_template.h"
#include "core/q_inv_tri_template.h"
#include "core/q_epsilon_template.h"

#define Q_VEC2 q8_24_vec2_t
#define Q_VEC3 q8_24_vec3_t
#define Q_VEC4 q8_24_vec4_t

#include "vector/q_vec2_template.h"
#include "vector/q_vec3_template.h"
#include "vector/q_vec4_template.h"

#define Q_QUAT q8_24_quat_t

#include "quat/q_quat_template.h"

#define Q_MAT2      q8_24_mat2_t
#define Q_MAT2X3    q8_24_mat2x3_t
#define Q_MAT2X4    q8_24_mat2x4_t
#define Q_MAT3X2    q8_24_mat3x2_t
#define Q_MAT3      q8_24_mat3_t
#define Q_MAT3X4    q8_24_mat3x4_t
#define Q_MAT4X2    q8_24_mat4x2_t
#define Q_MAT4X3    q8_24_mat4x3_t
#define Q_MAT4      q8_24_mat4_t

#include "matrix/q_mat2_template.h"
#include "matrix/q_mat2x3_template.h"
#include "matrix/q_mat2x4_template.h"
#include "matrix/q_mat3x2_template.h"
#include "matrix/q_mat3_template.h"
#include "matrix/q_mat3x4_template.h"
#include "matrix/q_mat4x2_template.h"
#include "matrix/q_mat4x3_template.h"
#include "matrix/q_mat4_template.h"
#include "matrix/q_mat_tr_template.h"
#include "matrix/q_mat_mul_template.h"
#include "matrix/q_mat_cast_template.h"

#include "transformation/q_view_template.h"
#include "transformation/q_projection_template.h"
#include "transformation/q_viewport_template.h"
#include "transformation/q_homogeneous_template.h"
#include "transformation/q_transform_2d_template.h"
#include "transformation/q_transform_3d_template.h"

#define Q_RAY           q8_24_ray_t
#define Q_AABB          q8_24_aabb_t
#define Q_PLANE         q8_24_plane_t
#define Q_SPHERE        q8_24_sphere_t
#define Q_TRIANGLE      q8_24_triangle_t
#define Q_COLLISION     q8_24_collision_t

#include "geometry/q_ray_template.h"
#include "geometry/q_aabb_template.h"
#include "geometry/q_plane_template.h"
#include "geometry/q_sphere_template.h"
#include "geometry/q_triangle_template.h"
#include "geometry/q_intersection_template.h"
#include "geometry/q_collision_template.h"

#endif // QGLM_Q8_24_H

