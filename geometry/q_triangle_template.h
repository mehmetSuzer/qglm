
#ifndef __Q_TRIANGLE_TEMPLATE_H__
#define __Q_TRIANGLE_TEMPLATE_H__

typedef struct
{
    Q_VEC3 v0;
    Q_VEC3 v1;
    Q_VEC3 v2;
} triangle_t; // vertices must not lie on a straight line

static inline Q_VEC3 triangle_normal(triangle_t triangle)
{
    const Q_VEC3 edge01 = q_vec3_sub(triangle.v1, triangle.v0);
    const Q_VEC3 edge02 = q_vec3_sub(triangle.v2, triangle.v0);
    const Q_VEC3 cross = q_vec3_cross(edge01, edge02);
    const Q_VEC3 normal = q_vec3_normalise(cross);

    return normal;
}

static inline bool triangle_intersects_ray(triangle_t triangle, ray_t ray, Q_TYPE near, Q_TYPE far, Q_TYPE* dist_out)
{
    // Moller-Trumbore Intersection Algorithm
    const Q_VEC3 edge01 = q_vec3_sub(triangle.v1, triangle.v0);
    const Q_VEC3 edge02 = q_vec3_sub(triangle.v2, triangle.v0);
    const Q_VEC3 ray_cross_edge02 = q_vec3_cross(ray.direction, edge02);
    const Q_TYPE det = q_vec3_dot(edge01, ray_cross_edge02);

    if (q_epsilon_equal(det, Q_ZERO, Q_EPSILON))
        return false;

    const Q_TYPE inv_det = q_div(Q_ONE, det);
    const Q_VEC3 v0_to_source = q_vec3_sub(ray.source, triangle.v0);
    const Q_TYPE bary1 = q_mul(inv_det, q_vec3_dot(v0_to_source, ray_cross_edge02));

    if (bary1 < q_negate(Q_EPSILON) || bary1 > q_add(Q_ONE, Q_EPSILON))
        return false;

    const Q_VEC3 v0_to_source_cross_edge01 = q_vec3_cross(v0_to_source, edge01);
    const Q_TYPE bary2 = q_mul(inv_det, q_vec3_dot(ray.direction, v0_to_source_cross_edge01));
    const Q_TYPE bary0 = q_sub(Q_ONE, q_add(bary1, bary2));

    if (bary2 < q_negate(Q_EPSILON) || bary0 < q_negate(Q_EPSILON))
        return false;

    const Q_TYPE distance = q_mul(inv_det, q_vec3_dot(edge02, v0_to_source_cross_edge01));
    
    if (near < distance && distance < far) 
    {
        *dist_out = distance;
        return true;
    }

    return false;
}

#endif // __Q_TRIANGLE_TEMPLATE_H__

