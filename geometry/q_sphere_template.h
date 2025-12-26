
#ifndef QGLM_Q_SPHERE_TEMPLATE_H
#define QGLM_Q_SPHERE_TEMPLATE_H

typedef struct
{
    Q_VEC3 centre;
    Q_TYPE radius; // REQUIREMENT: radius must be positive.
} Q_SPHERE;

static inline Q_VEC3 q_sphere_normal_at(Q_SPHERE sphere, Q_VEC3 point_on_sphere)
{
    const Q_TYPE inv_radius = q_div(Q_ONE, sphere.radius);
    const Q_VEC3 centre_to_point = q_vec3_sub(point_on_sphere, sphere.centre);
    const Q_VEC3 normal = q_vec3_scale(centre_to_point, inv_radius);
    return normal;
}

static inline Q_VEC3 q_sphere_normal_towards(Q_SPHERE sphere, Q_VEC3 point)
{
    const Q_VEC3 centre_to_point = q_vec3_sub(point, sphere.centre);
    const Q_VEC3 normal = q_vec3_normalise(centre_to_point);
    return normal;
}

static inline bool q_sphere_intersects_ray(Q_SPHERE sphere, Q_RAY ray, Q_TYPE near, Q_TYPE far, Q_TYPE* dist_out)
{
    const Q_VEC3 centre_to_source = q_vec3_sub(ray.source, sphere.centre);
    const Q_TYPE dist2 = q_vec3_length2(centre_to_source);
    const Q_TYPE dot = q_vec3_dot(centre_to_source, ray.direction);
    
    const Q_TYPE dot2 = q_mul(dot, dot);
    const Q_TYPE radius2 = q_mul(sphere.radius, sphere.radius);
    const Q_TYPE quarter_discriminant = q_add(q_sub(dot2, dist2), radius2);

    if (q_lt(quarter_discriminant, Q_EPSILON))
        return false;

    const Q_TYPE half_sqrt_discriminant = q_sqrt(quarter_discriminant);
    const Q_TYPE low_distance = q_negate(q_add(dot, half_sqrt_discriminant));

    if (near < low_distance && low_distance < far)
    {
        *dist_out = low_distance;
        return true;
    }

    return false;
}

#endif // QGLM_Q_SPHERE_TEMPLATE_H

