
#ifndef __Q_MAT_MUL_TEMPLATE_H__
#define __Q_MAT_MUL_TEMPLATE_H__

#include "q_mat2_template.h"
#include "q_mat2x3_template.h"
#include "q_mat2x4_template.h"
#include "q_mat3x2_template.h"
#include "q_mat3_template.h"
#include "q_mat3x4_template.h"
#include "q_mat4x2_template.h"
#include "q_mat4x3_template.h"
#include "q_mat4_template.h"

// -------------------------------- Q_MAT2 -------------------------------- //

static inline Q_MAT2 q_mat2_mul_mat2(Q_MAT2 m1, Q_MAT2 m2) 
{
    return (Q_MAT2){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), 
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),

        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), 
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
    }};
}

static inline Q_MAT2X3 q_mat2_mul_mat2x3(Q_MAT2 m1, Q_MAT2X3 m2)
{
    return (Q_MAT2X3){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)),
    }};
}

static inline Q_MAT2X4 q_mat2_mul_mat2x4(Q_MAT2 m1, Q_MAT2X4 m2)
{
    return (Q_MAT2X4){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)),
        q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)),
        q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)),
    }};
}

// -------------------------------- Q_MAT2X3 -------------------------------- //

static inline Q_MAT2 q_mat2x3_mul_mat3x2(Q_MAT2X3 m1, Q_MAT3X2 m2)
{
    return (Q_MAT2){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
    }};
}

static inline Q_MAT2X3 q_mat2x3_mul_mat3(Q_MAT2X3 m1, Q_MAT3 m2) 
{
    return (Q_MAT2X3){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)),
    }};
}

static inline Q_MAT2X4 q_mat2x3_mul_mat3x4(Q_MAT2X3 m1, Q_MAT3X4 m2)
{
    return (Q_MAT2X4){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)),
        q_add(q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)), q_mul(m1.xz, m2.zw)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)),
        q_add(q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)), q_mul(m1.yz, m2.zw)),
    }};
}

// -------------------------------- Q_MAT2X4 -------------------------------- //

static inline Q_MAT2 q_mat2x4_mul_mat4x2(Q_MAT2X4 m1, Q_MAT4X2 m2)
{
    return (Q_MAT2){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
    }};
}

static inline Q_MAT2X3 q_mat2x4_mul_mat4x3(Q_MAT2X4 m1, Q_MAT4X3 m2)
{
    return (Q_MAT2X3){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)), q_mul(m1.xw, m2.wz)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)), q_mul(m1.yw, m2.wz)),
    }};
}

static inline Q_MAT2X4 q_mat2x4_mul_mat4(Q_MAT2X4 m1, Q_MAT4 m2) 
{
    return (Q_MAT2X4){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)), q_mul(m1.xw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)), q_mul(m1.xz, m2.zw)), q_mul(m1.xw, m2.ww)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)), q_mul(m1.yw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)), q_mul(m1.yz, m2.zw)), q_mul(m1.yw, m2.ww)),
    }};
}

// -------------------------------- Q_MAT3X2 -------------------------------- //

static inline Q_MAT3X2 q_mat3x2_mul_mat2(Q_MAT3X2 m1, Q_MAT2 m2)
{
    return (Q_MAT3X2){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        
        q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)),
        q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)),
    }};
}

static inline Q_MAT3 q_mat3x2_mul_mat2x3(Q_MAT3X2 m1, Q_MAT2X3 m2)
{
    return (Q_MAT3){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)),
        
        q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)),
        q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)),
        q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)),
    }};
}

static inline Q_MAT3X4 q_mat3x2_mul_mat2x4(Q_MAT3X2 m1, Q_MAT2X4 m2)
{
    return (Q_MAT3X4){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)),
        q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)),
        q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)),
        
        q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)),
        q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)),
        q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)),
        q_add(q_mul(m1.zx, m2.xw), q_mul(m1.zy, m2.yw)),
    }};
}

// -------------------------------- Q_MAT3 -------------------------------- //

static inline Q_MAT3X2 q_mat3_mul_mat3x2(Q_MAT3 m1, Q_MAT3X2 m2)
{
    return (Q_MAT3X2){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        
        q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)),
        q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)),
    }};
}

static inline Q_MAT3 q_mat3_mul_mat3(Q_MAT3 m1, Q_MAT3 m2) 
{
    return (Q_MAT3){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)),
        
        q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)),
        q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)),
        q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)),
    }};
}

static inline Q_MAT3X4 q_mat3_mul_mat3x4(Q_MAT3 m1, Q_MAT3X4 m2)
{
    return (Q_MAT3X4){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)),
        q_add(q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)), q_mul(m1.xz, m2.zw)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)),
        q_add(q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)), q_mul(m1.yz, m2.zw)),
        
        q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)),
        q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)),
        q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)),
        q_add(q_add(q_mul(m1.zx, m2.xw), q_mul(m1.zy, m2.yw)), q_mul(m1.zz, m2.zw)),
    }};
}

// -------------------------------- Q_MAT3X4 -------------------------------- //

static inline Q_MAT3X2 q_mat3x4_mul_mat4x2(Q_MAT3X4 m1, Q_MAT4X2 m2)
{
    return (Q_MAT3X2){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        
        q_add(q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)), q_mul(m1.zw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)), q_mul(m1.zw, m2.wy)),
    }};
}

static inline Q_MAT3 q_mat3x4_mul_mat4x3(Q_MAT3X4 m1, Q_MAT4X3 m2) 
{
    return (Q_MAT3){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)), q_mul(m1.xw, m2.wz)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)), q_mul(m1.yw, m2.wz)),
        
        q_add(q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)), q_mul(m1.zw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)), q_mul(m1.zw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)), q_mul(m1.zw, m2.wz)),
    }};
}

static inline Q_MAT3X4 q_mat3x4_mul_mat4(Q_MAT3X4 m1, Q_MAT4 m2) 
{
    return (Q_MAT3X4){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)), q_mul(m1.xw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)), q_mul(m1.xz, m2.zw)), q_mul(m1.xw, m2.ww)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)), q_mul(m1.yw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)), q_mul(m1.yz, m2.zw)), q_mul(m1.yw, m2.ww)),
        
        q_add(q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)), q_mul(m1.zw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)), q_mul(m1.zw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)), q_mul(m1.zw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xw), q_mul(m1.zy, m2.yw)), q_mul(m1.zz, m2.zw)), q_mul(m1.zw, m2.ww)),
    }};
}

// -------------------------------- Q_MAT4X2 -------------------------------- //

static inline Q_MAT4X2 q_mat4x2_mul_mat2(Q_MAT4X2 m1, Q_MAT2 m2)
{
    return (Q_MAT4X2){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        
        q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)),
        q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)),
        
        q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)),
        q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)),
    }};
}

static inline Q_MAT4X3 q_mat4x2_mul_mat2x3(Q_MAT4X2 m1, Q_MAT2X3 m2)
{
    return (Q_MAT4X3){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)),
        
        q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)),
        q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)),
        q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)),
        
        q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)),
        q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)),
        q_add(q_mul(m1.wx, m2.xz), q_mul(m1.wy, m2.yz)),
    }};
}

static inline Q_MAT4 q_mat4x2_mul_mat2x4(Q_MAT4X2 m1, Q_MAT2X4 m2)
{
    return (Q_MAT4){{
        q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)),
        q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)),
        q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)),
        q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)),
        
        q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)),
        q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)),
        q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)),
        q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)),
        
        q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)),
        q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)),
        q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)),
        q_add(q_mul(m1.zx, m2.xw), q_mul(m1.zy, m2.yw)),
        
        q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)),
        q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)),
        q_add(q_mul(m1.wx, m2.xz), q_mul(m1.wy, m2.yz)),
        q_add(q_mul(m1.wx, m2.xw), q_mul(m1.wy, m2.yw)),
    }};

}

// -------------------------------- Q_MAT4X3 -------------------------------- //

static inline Q_MAT4X2 q_mat4x3_mul_mat3x2(Q_MAT4X3 m1, Q_MAT3X2 m2)
{
    return (Q_MAT4X2){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        
        q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)),
        q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)),
        
        q_add(q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)), q_mul(m1.wz, m2.zx)),
        q_add(q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)), q_mul(m1.wz, m2.zy)),
    }};
}

static inline Q_MAT4X3 q_mat4x3_mul_mat3(Q_MAT4X3 m1, Q_MAT3 m2)
{
    return (Q_MAT4X3){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)),
        
        q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)),
        q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)),
        q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)),
        
        q_add(q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)), q_mul(m1.wz, m2.zx)),
        q_add(q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)), q_mul(m1.wz, m2.zy)),
        q_add(q_add(q_mul(m1.wx, m2.xz), q_mul(m1.wy, m2.yz)), q_mul(m1.wz, m2.zz)),
    }};
}

static inline Q_MAT4 q_mat4x3_mul_mat3x4(Q_MAT4X3 m1, Q_MAT3X4 m2)
{
    return (Q_MAT4){{
        q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)),
        q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)),
        q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)),
        q_add(q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)), q_mul(m1.xz, m2.zw)),
        
        q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)),
        q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)),
        q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)),
        q_add(q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)), q_mul(m1.yz, m2.zw)),
        
        q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)),
        q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)),
        q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)),
        q_add(q_add(q_mul(m1.zx, m2.xw), q_mul(m1.zy, m2.yw)), q_mul(m1.zz, m2.zw)),
        
        q_add(q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)), q_mul(m1.wz, m2.zx)),
        q_add(q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)), q_mul(m1.wz, m2.zy)),
        q_add(q_add(q_mul(m1.wx, m2.xz), q_mul(m1.wy, m2.yz)), q_mul(m1.wz, m2.zz)),
        q_add(q_add(q_mul(m1.wx, m2.xw), q_mul(m1.wy, m2.yw)), q_mul(m1.wz, m2.zw)),
    }};
}

// -------------------------------- Q_MAT4 -------------------------------- //

static inline Q_MAT4X2 q_mat4_mul_mat4x2(Q_MAT4 m1, Q_MAT4X2 m2)
{
    return (Q_MAT4X2){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        
        q_add(q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)), q_mul(m1.zw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)), q_mul(m1.zw, m2.wy)),
        
        q_add(q_add(q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)), q_mul(m1.wz, m2.zx)), q_mul(m1.ww, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)), q_mul(m1.wz, m2.zy)), q_mul(m1.ww, m2.wy)),
    }};
}

static inline Q_MAT4X3 q_mat4_mul_mat4x3(Q_MAT4 m1, Q_MAT4X3 m2)
{
    return (Q_MAT4X3){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)), q_mul(m1.xw, m2.wz)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)), q_mul(m1.yw, m2.wz)),
        
        q_add(q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)), q_mul(m1.zw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)), q_mul(m1.zw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)), q_mul(m1.zw, m2.wz)),
        
        q_add(q_add(q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)), q_mul(m1.wz, m2.zx)), q_mul(m1.ww, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)), q_mul(m1.wz, m2.zy)), q_mul(m1.ww, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.wx, m2.xz), q_mul(m1.wy, m2.yz)), q_mul(m1.wz, m2.zz)), q_mul(m1.ww, m2.wz)),
    }};
}

static inline Q_MAT4 q_mat4_mul_mat4(Q_MAT4 m1, Q_MAT4 m2) 
{
    return (Q_MAT4){{
        q_add(q_add(q_add(q_mul(m1.xx, m2.xx), q_mul(m1.xy, m2.yx)), q_mul(m1.xz, m2.zx)), q_mul(m1.xw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xy), q_mul(m1.xy, m2.yy)), q_mul(m1.xz, m2.zy)), q_mul(m1.xw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xz), q_mul(m1.xy, m2.yz)), q_mul(m1.xz, m2.zz)), q_mul(m1.xw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.xx, m2.xw), q_mul(m1.xy, m2.yw)), q_mul(m1.xz, m2.zw)), q_mul(m1.xw, m2.ww)),
        
        q_add(q_add(q_add(q_mul(m1.yx, m2.xx), q_mul(m1.yy, m2.yx)), q_mul(m1.yz, m2.zx)), q_mul(m1.yw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xy), q_mul(m1.yy, m2.yy)), q_mul(m1.yz, m2.zy)), q_mul(m1.yw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xz), q_mul(m1.yy, m2.yz)), q_mul(m1.yz, m2.zz)), q_mul(m1.yw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.yx, m2.xw), q_mul(m1.yy, m2.yw)), q_mul(m1.yz, m2.zw)), q_mul(m1.yw, m2.ww)),
        
        q_add(q_add(q_add(q_mul(m1.zx, m2.xx), q_mul(m1.zy, m2.yx)), q_mul(m1.zz, m2.zx)), q_mul(m1.zw, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xy), q_mul(m1.zy, m2.yy)), q_mul(m1.zz, m2.zy)), q_mul(m1.zw, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xz), q_mul(m1.zy, m2.yz)), q_mul(m1.zz, m2.zz)), q_mul(m1.zw, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.zx, m2.xw), q_mul(m1.zy, m2.yw)), q_mul(m1.zz, m2.zw)), q_mul(m1.zw, m2.ww)),
        
        q_add(q_add(q_add(q_mul(m1.wx, m2.xx), q_mul(m1.wy, m2.yx)), q_mul(m1.wz, m2.zx)), q_mul(m1.ww, m2.wx)),
        q_add(q_add(q_add(q_mul(m1.wx, m2.xy), q_mul(m1.wy, m2.yy)), q_mul(m1.wz, m2.zy)), q_mul(m1.ww, m2.wy)),
        q_add(q_add(q_add(q_mul(m1.wx, m2.xz), q_mul(m1.wy, m2.yz)), q_mul(m1.wz, m2.zz)), q_mul(m1.ww, m2.wz)),
        q_add(q_add(q_add(q_mul(m1.wx, m2.xw), q_mul(m1.wy, m2.yw)), q_mul(m1.wz, m2.zw)), q_mul(m1.ww, m2.ww)),
    }};
}

#endif // __Q_MAT_MUL_TEMPLATE_H__

