
#ifndef QGLM_Q_AABB_TEMPLATE_H
#define QGLM_Q_AABB_TEMPLATE_H

typedef struct
{
    Q_VEC3 min;
    Q_VEC3 max;
} Q_AABB; // REQUIREMENT: max coordinates must be greater than min coordinates

static inline Q_AABB q_aabb_from_centre_size(Q_VEC3 centre, Q_VEC3 size)
{
    const Q_VEC3 half = q_vec3_downscale_pow_2(size, 1);
    return (Q_AABB){
        q_vec3_sub(centre, half),
        q_vec3_add(centre, half),
    };
}

static inline Q_VEC3 q_aabb_centre(Q_AABB aabb)
{
    const Q_VEC3 centre = q_vec3_downscale_pow_2(q_vec3_add(aabb.min, aabb.max), 1);
    return centre;
}

static inline Q_VEC3 q_aabb_size(Q_AABB aabb)
{
    return q_vec3_sub(aabb.max, aabb.min);
}

static inline Q_TYPE q_aabb_volume(Q_AABB aabb)
{
    const Q_VEC3 size = q_aabb_size(aabb);
    const Q_TYPE volume = q_mul(q_mul(size.x, size.y), size.z);
    return volume;
}

static inline bool q_aabb_contains_point(Q_AABB aabb, Q_VEC3 point)
{
    return (aabb.min.x < point.x && point.x < aabb.max.x &&
            aabb.min.y < point.y && point.y < aabb.max.y &&
            aabb.min.z < point.z && point.z < aabb.max.z);
}

static inline bool q_aabb_intersects_ray(Q_AABB aabb, Q_RAY ray, Q_TYPE near, Q_TYPE far, Q_TYPE* dist_out)
{
    Q_VEC3 low  = {{near, near, near}};
    Q_VEC3 high = {{far,  far,  far}};

    for (int32_t i = 0; i < 3; ++i)
    {
        if (q_epsilon_eq(ray.direction.raw[i], Q_ZERO, Q_EPSILON))
        {
            if (ray.source.raw[i] < aabb.min.raw[i] || ray.source.raw[i] > aabb.max.raw[i])
                return false;
        }
        else
        {
            low.raw[i]  = q_div(q_sub(aabb.min.raw[i], ray.source.raw[i]), ray.direction.raw[i]);
            high.raw[i] = q_div(q_sub(aabb.max.raw[i], ray.source.raw[i]), ray.direction.raw[i]);
        }
    }

    if (low.x > high.x)
        q_swap(&low.x, &high.x);
    if (low.y > high.y)
        q_swap(&low.y, &high.y);
    if (low.z > high.z)
        q_swap(&low.z, &high.z);

    const Q_TYPE low_dist  = q_greater(q_greater(low.x, low.y), low.z);
    const Q_TYPE high_dist = q_smaller(q_smaller(high.x, high.y), high.z);

    if (low_dist > high_dist)
        return false;

    *dist_out = low_dist;
    return true;
}

#endif // QGLM_Q_AABB_TEMPLATE_H

