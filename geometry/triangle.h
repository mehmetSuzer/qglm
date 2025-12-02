
#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "../geometry/ray.h"

typedef struct
{
    q16_16_vec3 v0;
    q16_16_vec3 v1;
    q16_16_vec3 v2;
} triangle_t; // vertices must not lie on a straight line

static inline q16_16_vec3 triangle_normal(triangle_t triangle)
{
    const q16_16_vec3 edge01 = q16_16_vec3_sub(triangle.v1, triangle.v0);
    const q16_16_vec3 edge02 = q16_16_vec3_sub(triangle.v2, triangle.v0);
    const q16_16_vec3 cross = q16_16_vec3_cross(edge01, edge02);
    const q16_16_vec3 normal = q16_16_vec3_normalise(cross);

    return normal;
}

static inline bool triangle_intersects_ray(triangle_t triangle, ray_t ray, q16_16 near, q16_16 far, q16_16* dist_out)
{
    // Moller-Trumbore Intersection Algorithm
    const q16_16_vec3 edge01 = q16_16_vec3_sub(triangle.v1, triangle.v0);
    const q16_16_vec3 edge02 = q16_16_vec3_sub(triangle.v2, triangle.v0);
    const q16_16_vec3 ray_cross_edge02 = q16_16_vec3_cross(ray.direction, edge02);
    const q16_16 det = q16_16_vec3_dot(edge01, ray_cross_edge02);

    if (q16_16_epsilon_equal(det, Q16_16_ZERO, Q16_16_EPSILON))
        return false;

    const q16_16 inv_det = q16_16_div(Q16_16_ONE, det);
    const q16_16_vec3 v0_to_source = q16_16_vec3_sub(ray.source, triangle.v0);
    const q16_16 bary1 = q16_16_mul(inv_det, q16_16_vec3_dot(v0_to_source, ray_cross_edge02));

    if (bary1 < q16_16_negate(Q16_16_EPSILON) || bary1 > q16_16_add(Q16_16_ONE, Q16_16_EPSILON))
        return false;

    const q16_16_vec3 v0_to_source_cross_edge01 = q16_16_vec3_cross(v0_to_source, edge01);
    const q16_16 bary2 = q16_16_mul(inv_det, q16_16_vec3_dot(ray.direction, v0_to_source_cross_edge01));
    const q16_16 bary0 = q16_16_sub(Q16_16_ONE, q16_16_add(bary1, bary2));

    if (bary2 < q16_16_negate(Q16_16_EPSILON) || bary0 < q16_16_negate(Q16_16_EPSILON))
        return false;

    const q16_16 distance = q16_16_mul(inv_det, q16_16_vec3_dot(edge02, v0_to_source_cross_edge01));
    
    if (near < distance && distance < far) 
    {
        *dist_out = distance;
        return true;
    }

    return false;
}

#endif // __TRIANGLE_H__

