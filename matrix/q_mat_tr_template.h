
#ifndef __Q_MAT_TR_TEMPLATE_H__
#define __Q_MAT_TR_TEMPLATE_H__

#include "q_mat2_template.h"
#include "q_mat2x3_template.h"
#include "q_mat2x4_template.h"
#include "q_mat3x2_template.h"
#include "q_mat3_template.h"
#include "q_mat3x4_template.h"
#include "q_mat4x2_template.h"
#include "q_mat4x3_template.h"
#include "q_mat4_template.h"

static inline Q_MAT2 q_mat2_tr(Q_MAT2 m) 
{
    return (Q_MAT2){{
        m.xx, m.yx, 
        m.xy, m.yy,
    }};
}

static inline Q_MAT3X2 q_mat2x3_tr(Q_MAT2X3 m) 
{
    return (Q_MAT3X2){{
        m.xx, m.yx,
        m.xy, m.yy,
        m.xz, m.yz,
    }};
}

static inline Q_MAT4X2 q_mat2x4_tr(Q_MAT2X4 m)
{
    return (Q_MAT4X2){{
        m.xx, m.yx,
        m.xy, m.yy,
        m.xz, m.yz,
        m.xw, m.yw,
    }};
}

static inline Q_MAT2X3 q_mat3x2_tr(Q_MAT3X2 m)
{
    return (Q_MAT2X3){{
        m.xx, m.yx, m.zx,
        m.xy, m.yy, m.zy,
    }};
}

static inline Q_MAT3 q_mat3_tr(Q_MAT3 m) 
{
    return (Q_MAT3){{
        m.xx, m.yx, m.zx,
        m.xy, m.yy, m.zy,
        m.xz, m.yz, m.zz,
    }};
}

static inline Q_MAT4X3 q_mat3x4_tr(Q_MAT3X4 m)
{
    return (Q_MAT4X3){{
        m.xx, m.yx, m.zx,
        m.xy, m.yy, m.zy,
        m.xz, m.yz, m.zz,
        m.xw, m.yw, m.zw,
    }};
}

static inline Q_MAT2X4 q_mat4x2_tr(Q_MAT4X2 m)
{
    return (Q_MAT2X4){{
        m.xx, m.yx, m.zx, m.wx,
        m.xy, m.yy, m.zy, m.wy,
    }};
}

static inline Q_MAT3X4 q_mat4x3_tr(Q_MAT4X3 m)
{
    return (Q_MAT3X4){{
        m.xx, m.yx, m.zx, m.wx,
        m.xy, m.yy, m.zy, m.wy,
        m.xz, m.yz, m.zz, m.wz,
    }};
}

static inline Q_MAT4 q_mat4_tr(Q_MAT4 m) 
{
    return (Q_MAT4){{
        m.xx, m.yx, m.zx, m.wx,
        m.xy, m.yy, m.zy, m.wy,
        m.xz, m.yz, m.zz, m.wz,
        m.xw, m.yw, m.zw, m.ww,
    }};
}

#endif // __Q_MAT_TR_TEMPLATE_H__

