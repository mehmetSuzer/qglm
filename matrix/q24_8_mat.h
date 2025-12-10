
#ifndef __Q24_8_MAT_H__
#define __Q24_8_MAT_H__

#include "../vector/q24_8_vec.h"
#include "../quat/q24_8_quat.h"

#define Q_MAT2      q24_8_mat2_t
#define Q_MAT2X3    q24_8_mat2x3_t
#define Q_MAT2X4    q24_8_mat2x4_t
#define Q_MAT3X2    q24_8_mat3x2_t
#define Q_MAT3      q24_8_mat3_t
#define Q_MAT3X4    q24_8_mat3x4_t
#define Q_MAT4X2    q24_8_mat4x2_t
#define Q_MAT4X3    q24_8_mat4x3_t
#define Q_MAT4      q24_8_mat4_t

#include "q_mat2_template.h"
#include "q_mat2x3_template.h"
#include "q_mat2x4_template.h"
#include "q_mat3x2_template.h"
#include "q_mat3_template.h"
#include "q_mat3x4_template.h"
#include "q_mat4x2_template.h"
#include "q_mat4x3_template.h"
#include "q_mat4_template.h"

#include "q_mat_tr_template.h"
#include "q_mat_mul_template.h"
#include "q_mat_cast_template.h"

#endif // __Q24_8_MAT_H__

