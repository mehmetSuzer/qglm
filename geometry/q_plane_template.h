
#ifndef __Q_PLANE_TEMPLATE_H__
#define __Q_PLANE_TEMPLATE_H__

typedef struct
{
    Q_VEC3 normal; // must be a unit vector
    Q_TYPE offset; // the signed distance of the origin
} plane_t;

static inline Q_TYPE plane_signed_distance(plane_t plane, Q_VEC3 point)
{
    return q_add(q_vec3_dot(plane.normal, point), plane.offset);
}

static inline bool plane_intersects_ray(plane_t plane, ray_t ray, Q_TYPE near, Q_TYPE far, Q_TYPE* dist_out)
{
    const Q_TYPE dot_dir_normal = q_vec3_dot(ray.direction, plane.normal);
    if (q_epsilon_equal(dot_dir_normal, Q_ZERO, Q_EPSILON))
       return false;

    const Q_TYPE dot_source_normal = q_vec3_dot(ray.source, plane.normal);
    const Q_TYPE distance = q_negate(q_div(q_add(plane.offset, dot_source_normal), dot_dir_normal));

    if (near < distance && distance < far)
    {
        *dist_out = distance;
        return true;
    }

    return false;
}

#endif // __Q_PLANE_TEMPLATE_H__

