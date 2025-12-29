
#ifndef QGLM_Q_COLLISION_TEMPLATE_H
#define QGLM_Q_COLLISION_TEMPLATE_H

typedef struct
{
    Q_VEC3 point;  // the contact point on the surface of the first object
    Q_VEC3 normal; // the unit vector from the surface of the first object towards the second one
    Q_TYPE depth;  // the total penetration
} Q_COLLISION;

static inline bool q_sphere_collides_sphere(Q_SPHERE sphere1, Q_SPHERE sphere2, Q_COLLISION* collision)
{
    const Q_VEC3 centre1_to_centre2 = q_vec3_sub(sphere2.centre, sphere1.centre);
    const Q_TYPE dist2 = q_vec3_dot(centre1_to_centre2, centre1_to_centre2);
    const Q_TYPE radii_sum = q_add(sphere1.radius, sphere2.radius);
    const Q_TYPE radii_sum2 = q_mul(radii_sum, radii_sum);

    if (dist2 > radii_sum2)
        return false;

    const Q_TYPE dist = q_sqrt(dist2);
    const Q_TYPE depth = q_sub(radii_sum, dist);
    const Q_VEC3 normal = q_vec3_scale(centre1_to_centre2, q_div(Q_ONE, dist));
    const Q_VEC3 point = q_vec3_add(sphere1.centre, q_vec3_scale(normal, sphere1.radius));

    collision->point = point;
    collision->normal = normal;
    collision->depth = depth;

    return true;
}

/*

TODO: implement

static inline bool q_sphere_collides_aabb(Q_SPHERE sphere, Q_AABB aabb, Q_COLLISION* collision)
{
    return false;
}

static inline bool q_aabb_collides_aabb(Q_AABB aabb1, Q_AABB aabb2, Q_COLLISION* collision)
{
    return false;
}
*/

#endif // QGLM_Q_COLLISION_TEMPLATE_H

