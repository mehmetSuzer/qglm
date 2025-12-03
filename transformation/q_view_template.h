
#ifndef __Q_VIEW_TEMPLATE_H__
#define __Q_VIEW_TEMPLATE_H__

static inline Q_MAT4 view(Q_VEC3 eye, Q_VEC3 forward, Q_VEC3 up)
{
    const Q_VEC3 right = q_vec3_cross(forward, up);

    const Q_TYPE dotr = q_vec3_dot(eye, right);
    const Q_TYPE dotu = q_vec3_dot(eye, up);
    const Q_TYPE dotf = q_vec3_dot(eye, forward);

    return (Q_MAT4){{
           right.x,    right.y,    right.z,     -dotr,
              up.x,       up.y,       up.z,     -dotu,
        -forward.x, -forward.y, -forward.z,      dotf,
            Q_ZERO,     Q_ZERO,     Q_ZERO,     Q_ONE,
    }};
}

#endif // __Q_VIEW_TEMPLATE_H__

