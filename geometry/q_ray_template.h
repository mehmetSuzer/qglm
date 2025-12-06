
#ifndef __Q_RAY_TEMPLATE_H__
#define __Q_RAY_TEMPLATE_H__

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

#endif // __Q_RAY_TEMPLATE_H__

