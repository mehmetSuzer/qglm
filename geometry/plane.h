
#ifndef __PLANE_H__
#define __PLANE_H__

#include "../vector/q16_16_vec3.h"

typedef struct
{
    q16_16_vec3 normal; // must be a unit vector
    q16_16 offset; // the signed distance of the origin
} plane_t;

static inline q16_16 plane_signed_distance(plane_t plane, q16_16_vec3 point)
{
    return q16_16_add(q16_16_vec3_dot(plane.normal, point), plane.offset);
}

static inline bool plane_intersects_ray(plane_t plane, ray_t ray, q16_16 near, q16_16 far, q16_16* dist_out)
{
    const q16_16 dot_dir_normal = q16_16_vec3_dot(ray.direction, plane.normal);
    if (q16_16_epsilon_equal(dot_dir_normal, Q16_16_ZERO, Q16_16_EPSILON))
       return false;

    const q16_16 dot_source_normal = q16_16_vec3_dot(ray.source, plane.normal);
    const q16_16 distance =  q16_16_negate(q16_16_div(
        q16_16_add(plane.offset, dot_source_normal), dot_dir_normal));

    if (near < distance && distance < far)
    {
        *dist_out = distance;
        return true;
    }

    return false;
}

#endif // __PLANE_H__

