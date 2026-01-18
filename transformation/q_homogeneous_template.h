
#ifndef QGLM_Q_HOMOGENEOUS_TEMPLATE_H
#define QGLM_Q_HOMOGENEOUS_TEMPLATE_H

static inline Q_VEC4 q_homogeneous_vector(Q_VEC3 v)
{
    return (Q_VEC4){{
        v.x,
        v.y,
        v.z,
        Q_ZERO,
    }};
}

static inline Q_VEC4 q_homogeneous_point(Q_VEC3 v)
{
    return (Q_VEC4){{
        v.x,
        v.y,
        v.z,
        Q_ONE,
    }};
}

static inline Q_VEC3 q_homogeneous_vector_to_vec3(Q_VEC4 v)
{
    return (Q_VEC3){{
        v.x,
        v.y,
        v.z,
    }};
}

static inline Q_VEC3 q_homogeneous_point_to_vec3(Q_VEC4 v)
{
    const Q_TYPE inv_w = q_div(Q_ONE, v.w);
    return (Q_VEC3){{
        q_mul(v.x, inv_w),
        q_mul(v.y, inv_w),
        q_mul(v.z, inv_w),
    }};
}

static inline Q_VEC4 q_homogeneous_point_normalise(Q_VEC4 v)
{
    const Q_TYPE inv_w = q_div(Q_ONE, v.w);
    return (Q_VEC4){{
        q_mul(v.x, inv_w),
        q_mul(v.y, inv_w),
        q_mul(v.z, inv_w),
        Q_ONE,
    }};
}

#endif // QGLM_Q_HOMOGENEOUS_TEMPLATE_H

