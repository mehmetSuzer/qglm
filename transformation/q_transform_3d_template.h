
#ifndef QGLM_Q_TRANSFORM_3D_TEMPLATE_H
#define QGLM_Q_TRANSFORM_3D_TEMPLATE_H

static inline Q_MAT4 q_translate_mat4(Q_VEC3 v)
{
    return (Q_MAT4){{
         Q_ONE, Q_ZERO, Q_ZERO,   v.x,
        Q_ZERO,  Q_ONE, Q_ZERO,   v.y,
        Q_ZERO, Q_ZERO,  Q_ONE,   v.z,
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ONE,
    }};
}

// M <- M * T
static inline void q_translate_3d(Q_MAT4* m, Q_VEC3 v)
{
    const Q_TYPE dx = q_add(q_add(q_mul(m->xx, v.x), q_mul(m->xy, v.y)), q_mul(m->xz, v.z));
    const Q_TYPE dy = q_add(q_add(q_mul(m->yx, v.x), q_mul(m->yy, v.y)), q_mul(m->yz, v.z));
    const Q_TYPE dz = q_add(q_add(q_mul(m->zx, v.x), q_mul(m->zy, v.y)), q_mul(m->zz, v.z));
    const Q_TYPE dw = q_add(q_add(q_mul(m->wx, v.x), q_mul(m->wy, v.y)), q_mul(m->wz, v.z));

    m->xw = q_add(m->xw, dx);
    m->yw = q_add(m->yw, dy);
    m->zw = q_add(m->zw, dz);
    m->ww = q_add(m->ww, dw);
}

// REQUIREMENT: angle must be in radians.
// REQUIREMENT: axis must be a unit vector.
static inline Q_MAT4 q_rotate_mat4(Q_TYPE angle, Q_VEC3 axis)
{
    const Q_TYPE s = q_sin(angle);
    const Q_TYPE c = q_cos(angle);
    const Q_TYPE t = q_sub(Q_ONE, c);

    const Q_TYPE xs = q_mul(axis.x, s);
    const Q_TYPE ys = q_mul(axis.y, s);
    const Q_TYPE zs = q_mul(axis.z, s);

    const Q_TYPE xxt = q_mul(q_mul(axis.x, axis.x), t);
    const Q_TYPE xyt = q_mul(q_mul(axis.x, axis.y), t);
    const Q_TYPE xzt = q_mul(q_mul(axis.x, axis.z), t);
    const Q_TYPE yyt = q_mul(q_mul(axis.y, axis.y), t);
    const Q_TYPE yzt = q_mul(q_mul(axis.y, axis.z), t);
    const Q_TYPE zzt = q_mul(q_mul(axis.z, axis.z), t);

    return (Q_MAT4){{
        q_add(xxt,  c), q_sub(xyt, zs), q_add(xzt, ys), Q_ZERO,
        q_add(xyt, zs), q_add(yyt,  c), q_sub(yzt, xs), Q_ZERO,
        q_sub(xzt, ys), q_add(yzt, xs), q_add(zzt,  c), Q_ZERO,
                Q_ZERO,         Q_ZERO,         Q_ZERO,  Q_ONE,
    }};
}

// M <- M * R
// REQUIREMENT: angle must be in radians.
// REQUIREMENT: axis must be a unit vector.
static inline void q_rotate_3d_angle_axis(Q_MAT4* m, Q_TYPE angle, Q_VEC3 axis)
{
    const Q_TYPE s = q_sin(angle);
    const Q_TYPE c = q_cos(angle);
    const Q_TYPE t = q_sub(Q_ONE, c);

    const Q_TYPE xs = q_mul(axis.x, s);
    const Q_TYPE ys = q_mul(axis.y, s);
    const Q_TYPE zs = q_mul(axis.z, s);

    const Q_TYPE xxt = q_mul(q_mul(axis.x, axis.x), t);
    const Q_TYPE xyt = q_mul(q_mul(axis.x, axis.y), t);
    const Q_TYPE xzt = q_mul(q_mul(axis.x, axis.z), t);
    const Q_TYPE yyt = q_mul(q_mul(axis.y, axis.y), t);
    const Q_TYPE yzt = q_mul(q_mul(axis.y, axis.z), t);
    const Q_TYPE zzt = q_mul(q_mul(axis.z, axis.z), t);

    const Q_TYPE rxx = q_add(xxt,  c);
    const Q_TYPE rxy = q_sub(xyt, zs);
    const Q_TYPE rxz = q_add(xzt, ys);
    const Q_TYPE ryx = q_add(xyt, zs);
    const Q_TYPE ryy = q_add(yyt,  c);
    const Q_TYPE ryz = q_sub(yzt, xs);
    const Q_TYPE rzx = q_sub(xzt, ys);
    const Q_TYPE rzy = q_add(yzt, xs);
    const Q_TYPE rzz = q_add(zzt,  c);
 
    const Q_TYPE xx = q_add(q_add(q_mul(m->xx, rxx), q_mul(m->xy, ryx)), q_mul(m->xz, rzx));
    const Q_TYPE xy = q_add(q_add(q_mul(m->xx, rxy), q_mul(m->xy, ryy)), q_mul(m->xz, rzy));
    const Q_TYPE xz = q_add(q_add(q_mul(m->xx, rxz), q_mul(m->xy, ryz)), q_mul(m->xz, rzz));

    const Q_TYPE yx = q_add(q_add(q_mul(m->yx, rxx), q_mul(m->yy, ryx)), q_mul(m->yz, rzx));
    const Q_TYPE yy = q_add(q_add(q_mul(m->yx, rxy), q_mul(m->yy, ryy)), q_mul(m->yz, rzy));
    const Q_TYPE yz = q_add(q_add(q_mul(m->yx, rxz), q_mul(m->yy, ryz)), q_mul(m->yz, rzz));

    const Q_TYPE zx = q_add(q_add(q_mul(m->zx, rxx), q_mul(m->zy, ryx)), q_mul(m->zz, rzx));
    const Q_TYPE zy = q_add(q_add(q_mul(m->zx, rxy), q_mul(m->zy, ryy)), q_mul(m->zz, rzy));
    const Q_TYPE zz = q_add(q_add(q_mul(m->zx, rxz), q_mul(m->zy, ryz)), q_mul(m->zz, rzz));

    const Q_TYPE wx = q_add(q_add(q_mul(m->wx, rxx), q_mul(m->wy, ryx)), q_mul(m->wz, rzx));
    const Q_TYPE wy = q_add(q_add(q_mul(m->wx, rxy), q_mul(m->wy, ryy)), q_mul(m->wz, rzy));
    const Q_TYPE wz = q_add(q_add(q_mul(m->wx, rxz), q_mul(m->wy, ryz)), q_mul(m->wz, rzz));

    m->xx = xx;
    m->xy = xy;
    m->xz = xz;

    m->yx = yx;
    m->yy = yy;
    m->yz = yz;

    m->zx = zx;
    m->zy = zy;
    m->zz = zz;

    m->wx = wx;
    m->wy = wy;
    m->wz = wz;
}

// M <- M * R
// REQUIREMENT: q must be a unit quaternion.
static inline void q_rotate_3d_quat(Q_MAT4* m, Q_QUAT q)
{
    const Q_TYPE qxx = q_mul_pow_2(q_mul(q.v.x, q.v.x), 1);
    const Q_TYPE qxy = q_mul_pow_2(q_mul(q.v.x, q.v.y), 1);
    const Q_TYPE qxz = q_mul_pow_2(q_mul(q.v.x, q.v.z), 1);
    const Q_TYPE qyy = q_mul_pow_2(q_mul(q.v.y, q.v.y), 1);
    const Q_TYPE qyz = q_mul_pow_2(q_mul(q.v.y, q.v.z), 1);
    const Q_TYPE qzz = q_mul_pow_2(q_mul(q.v.z, q.v.z), 1);
    const Q_TYPE qwx = q_mul_pow_2(q_mul(q.w,   q.v.x), 1);
    const Q_TYPE qwy = q_mul_pow_2(q_mul(q.w,   q.v.y), 1);
    const Q_TYPE qwz = q_mul_pow_2(q_mul(q.w,   q.v.z), 1);

    const Q_TYPE rxx = q_sub(Q_ONE, q_add(qyy, qzz));
    const Q_TYPE rxy = q_sub(qxy, qwz);
    const Q_TYPE rxz = q_add(qxz, qwy);
    
    const Q_TYPE ryx = q_add(qxy, qwz);
    const Q_TYPE ryy = q_sub(Q_ONE, q_add(qxx, qzz));
    const Q_TYPE ryz = q_sub(qyz, qwx);

    const Q_TYPE rzx = q_sub(qxz, qwy);
    const Q_TYPE rzy = q_add(qyz, qwx);
    const Q_TYPE rzz = q_sub(Q_ONE, q_add(qxx, qyy));
  
    const Q_TYPE xx = q_add(q_add(q_mul(m->xx, rxx), q_mul(m->xy, ryx)), q_mul(m->xz, rzx));
    const Q_TYPE xy = q_add(q_add(q_mul(m->xx, rxy), q_mul(m->xy, ryy)), q_mul(m->xz, rzy));
    const Q_TYPE xz = q_add(q_add(q_mul(m->xx, rxz), q_mul(m->xy, ryz)), q_mul(m->xz, rzz));

    const Q_TYPE yx = q_add(q_add(q_mul(m->yx, rxx), q_mul(m->yy, ryx)), q_mul(m->yz, rzx));
    const Q_TYPE yy = q_add(q_add(q_mul(m->yx, rxy), q_mul(m->yy, ryy)), q_mul(m->yz, rzy));
    const Q_TYPE yz = q_add(q_add(q_mul(m->yx, rxz), q_mul(m->yy, ryz)), q_mul(m->yz, rzz));

    const Q_TYPE zx = q_add(q_add(q_mul(m->zx, rxx), q_mul(m->zy, ryx)), q_mul(m->zz, rzx));
    const Q_TYPE zy = q_add(q_add(q_mul(m->zx, rxy), q_mul(m->zy, ryy)), q_mul(m->zz, rzy));
    const Q_TYPE zz = q_add(q_add(q_mul(m->zx, rxz), q_mul(m->zy, ryz)), q_mul(m->zz, rzz));

    const Q_TYPE wx = q_add(q_add(q_mul(m->wx, rxx), q_mul(m->wy, ryx)), q_mul(m->wz, rzx));
    const Q_TYPE wy = q_add(q_add(q_mul(m->wx, rxy), q_mul(m->wy, ryy)), q_mul(m->wz, rzy));
    const Q_TYPE wz = q_add(q_add(q_mul(m->wx, rxz), q_mul(m->wy, ryz)), q_mul(m->wz, rzz));

    m->xx = xx;
    m->xy = xy;
    m->xz = xz;

    m->yx = yx;
    m->yy = yy;
    m->yz = yz;

    m->zx = zx;
    m->zy = zy;
    m->zz = zz;

    m->wx = wx;
    m->wy = wy;
    m->wz = wz;
}

static inline Q_MAT4 q_scale_mat4(Q_VEC3 v)
{
    return (Q_MAT4){{
           v.x, Q_ZERO, Q_ZERO, Q_ZERO,
        Q_ZERO,    v.y, Q_ZERO, Q_ZERO,
        Q_ZERO, Q_ZERO,    v.z, Q_ZERO,
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE,
    }};
}

// M <- M * S
static inline void q_scale_3d(Q_MAT4* m, Q_VEC3 v)
{
    m->xx = q_mul(m->xx, v.x);
    m->xy = q_mul(m->xy, v.y);
    m->xz = q_mul(m->xz, v.z);
    m->yx = q_mul(m->yx, v.x);
    m->yy = q_mul(m->yy, v.y);
    m->yz = q_mul(m->yz, v.z);
    m->zx = q_mul(m->zx, v.x);
    m->zy = q_mul(m->zy, v.y);
    m->zz = q_mul(m->zz, v.z);
    m->wx = q_mul(m->wx, v.x);
    m->wy = q_mul(m->wy, v.y);
    m->wz = q_mul(m->wz, v.z);
}

#endif // QGLM_Q_TRANSFORM_3D_TEMPLATE_H

