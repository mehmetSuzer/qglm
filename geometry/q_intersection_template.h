
#ifndef QGLM_Q_INTERSECTION_TEMPLATE_H
#define QGLM_Q_INTERSECTION_TEMPLATE_H

static inline bool q_sphere_intersects_sphere(Q_SPHERE sphere1, Q_SPHERE sphere2)
{
    const Q_VEC3 diff = q_vec3_sub(sphere2.centre, sphere1.centre);
    const Q_TYPE dist2 = q_vec3_dot(diff, diff);
    const Q_TYPE radii_sum = q_add(sphere1.radius, sphere2.radius);
    const Q_TYPE radii_sum2 = q_mul(radii_sum, radii_sum);

    return (q_le(dist2, radii_sum2));
}

static inline bool q_sphere_intersects_aabb(Q_SPHERE sphere, Q_AABB aabb)
{
    const Q_VEC3 closest = {{
        q_clamp(sphere.centre.x, aabb.min.x, aabb.max.x),
        q_clamp(sphere.centre.y, aabb.min.y, aabb.max.y),
        q_clamp(sphere.centre.z, aabb.min.z, aabb.max.z),
    }};

    const Q_VEC3 diff = q_vec3_sub(sphere.centre, closest);
    const Q_TYPE dist2 = q_vec3_dot(diff, diff);
    const Q_TYPE radius2 = q_mul(sphere.radius, sphere.radius);

    return (q_le(dist2, radius2));
}

static inline bool q_aabb_intersects_aabb(Q_AABB aabb1, Q_AABB aabb2)
{
    const Q_VEC3 min = {{
        q_greater(aabb1.min.x, aabb2.min.x),
        q_greater(aabb1.min.y, aabb2.min.y),
        q_greater(aabb1.min.z, aabb2.min.z),
    }};
    const Q_VEC3 max = {{
        q_smaller(aabb1.max.x, aabb2.max.x),
        q_smaller(aabb1.max.y, aabb2.max.y),
        q_smaller(aabb1.max.z, aabb2.max.z),
    }};

    return (q_le(min.x, max.x) && q_le(min.y, max.y) && q_le(min.z, max.z));
}

#endif // QGLM_Q_INTERSECTION_TEMPLATE_H

