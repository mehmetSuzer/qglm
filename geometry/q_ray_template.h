
#ifndef QGLM_Q_RAY_TEMPLATE_H
#define QGLM_Q_RAY_TEMPLATE_H

typedef struct
{
    Q_VEC3 source;
    Q_VEC3 direction; // REQUIREMENT: direction must be a unit vector.
} Q_RAY;

static inline Q_VEC3 q_ray_at(Q_RAY ray, Q_TYPE distance)
{
    const Q_VEC3 forward = q_vec3_scale(ray.direction, distance);
    const Q_VEC3 position = q_vec3_add(ray.source, forward);
    return position;
}

#endif // QGLM_Q_RAY_TEMPLATE_H

