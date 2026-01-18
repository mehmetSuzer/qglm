
#ifndef QGLM_Q_VIEW_TEMPLATE_H
#define QGLM_Q_VIEW_TEMPLATE_H

// REQUIREMENT: backward and up must be unit vectors that are perpendicular to each other.
static inline Q_MAT4 q_view(Q_VEC3 eye, Q_VEC3 backward, Q_VEC3 up)
{
    const Q_VEC3 right = q_vec3_cross(up, backward);

    const Q_TYPE dotr = q_vec3_dot(eye, right);
    const Q_TYPE dotu = q_vec3_dot(eye, up);
    const Q_TYPE dotb = q_vec3_dot(eye, backward);

    return (Q_MAT4){{
           right.x,    right.y,    right.z, q_negate(dotr),
              up.x,       up.y,       up.z, q_negate(dotu),
        backward.x, backward.y, backward.z, q_negate(dotb),
            Q_ZERO,     Q_ZERO,     Q_ZERO,          Q_ONE,
    }};
}

#endif // QGLM_Q_VIEW_TEMPLATE_H

