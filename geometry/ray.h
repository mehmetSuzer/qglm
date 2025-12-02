
#ifndef __RAY_H__
#define __RAY_H__

#include "../vector/q16_16_vec3.h"

typedef struct
{
    q16_16_vec3 source;
    q16_16_vec3 direction; // must be a unit vector
} ray_t;

static inline q16_16_vec3 ray_at(ray_t ray, q16_16 distance)
{
    const q16_16_vec3 forward = q16_16_vec3_scale(ray.direction, distance);
    const q16_16_vec3 position = q16_16_vec3_add(ray.source, forward);

    return position;
}

#endif // __RAY_H__

