
#ifndef __Q_MAT_CAST_TEMPLATE_H__
#define __Q_MAT_CAST_TEMPLATE_H__

static inline Q_MAT3 q_cast_mat2_to_mat3(Q_MAT2 m)
{
    return (Q_MAT3){{
          m.xx,   m.xy, Q_ZERO,
          m.yx,   m.yy, Q_ZERO,
        Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

static inline Q_MAT2 q_cast_mat3_to_mat2(Q_MAT3 m)
{
    return (Q_MAT2){{
        m.xx, m.xy,
        m.yx, m.yy,
    }};
}

static inline Q_MAT4 q_cast_mat3_to_mat4(Q_MAT3 m)
{
    return (Q_MAT4){{
          m.xx,   m.xy,   m.xz, Q_ZERO,
          m.yx,   m.yy,   m.yz, Q_ZERO,
          m.zx,   m.zy,   m.zz, Q_ZERO,
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

static inline Q_MAT3 q_cast_mat4_to_mat3(Q_MAT4 m)
{
    return (Q_MAT3){{
        m.xx, m.xy, m.xz,
        m.yx, m.yy, m.yz,
        m.zx, m.zy, m.zz,
    }};
}

static inline Q_MAT3 q_cast_quat_to_mat3(Q_QUAT q)
{
    const Q_TYPE xx = q_mul_pow_2(q_mul(q.v.x, q.v.x), 1);
    const Q_TYPE yy = q_mul_pow_2(q_mul(q.v.y, q.v.y), 1);
    const Q_TYPE zz = q_mul_pow_2(q_mul(q.v.z, q.v.z), 1); 
    const Q_TYPE xy = q_mul_pow_2(q_mul(q.v.x, q.v.y), 1);
    const Q_TYPE xz = q_mul_pow_2(q_mul(q.v.x, q.v.z), 1);
    const Q_TYPE yz = q_mul_pow_2(q_mul(q.v.y, q.v.z), 1);
    const Q_TYPE wx = q_mul_pow_2(q_mul(q.w,   q.v.x), 1);
    const Q_TYPE wy = q_mul_pow_2(q_mul(q.w,   q.v.y), 1);
    const Q_TYPE wz = q_mul_pow_2(q_mul(q.w,   q.v.z), 1);

    return (Q_MAT3){{
        q_sub(Q_ONE, q_add(yy, zz)),              q_sub(xy, wz) ,              q_add(xz, wy) ,
                     q_add(xy, wz) , q_sub(Q_ONE, q_add(xx, zz)),              q_sub(yz, wx) ,
                     q_sub(xz, wy) ,              q_add(yz, wx) , q_sub(Q_ONE, q_add(xx, yy)),
    }};
}

static inline Q_MAT4 q_cast_quat_to_mat4(Q_QUAT q)
{
    return q_cast_mat3_to_mat4(q_cast_quat_to_mat3(q));
}

#endif // __Q_MAT_CAST_TEMPLATE_H__

