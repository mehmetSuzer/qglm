
#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "../geometry/ray.h"

typedef struct
{
    q16_16_vec3 centre;
    q16_16 radius; // must be positive
} sphere_t;

static inline q16_16_vec3 sphere_normal_at(sphere_t sphere, q16_16_vec3 point_on_sphere)
{
    const q16_16 inv_radius = q16_16_div(Q16_16_ONE, sphere.radius);
    const q16_16_vec3 centre_to_point = q16_16_vec3_sub(point_on_sphere, sphere.centre);
    const q16_16_vec3 normal = q16_16_vec3_scale(centre_to_point, inv_radius);

    return normal;
}

static inline q16_16_vec3 sphere_normal_towards(sphere_t sphere, q16_16_vec3 point)
{
    const q16_16_vec3 centre_to_point = q16_16_vec3_sub(point, sphere.centre);
    const q16_16_vec3 normal = q16_16_vec3_normalise(centre_to_point);

    return normal;
}

static inline bool sphere_intersects_ray(sphere_t sphere, ray_t ray, q16_16 near, q16_16 far, q16_16* dist_out)
{
    const q16_16_vec3 centre_to_source = q16_16_vec3_sub(ray.source, sphere.centre);
    const q16_16 dist2 = q16_16_vec3_mag2(centre_to_source);
    const q16_16 dot = q16_16_vec3_dot(centre_to_source, ray.direction);
    
    const q16_16 dot2 = q16_16_mul(dot, dot);
    const q16_16 radius2 = q16_16_mul(sphere.radius, sphere.radius);
    const q16_16 quarter_discriminant = q16_16_add(q16_16_sub(dot2, dist2), radius2);

    if (quarter_discriminant < Q16_16_EPSILON)
        return false;

    const q16_16 half_sqrt_discriminant = q16_16_sqrt(quarter_discriminant);
    const q16_16 low_distance = q16_16_negate(q16_16_add(dot, half_sqrt_discriminant));

    if (near < low_distance && low_distance < far)
    {
        *dist_out = low_distance;
        return true;
    }

    return false;
}

#endif // __SHPERE_H__

