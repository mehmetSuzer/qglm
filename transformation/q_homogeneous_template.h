
#ifndef __Q_HOMOGENEOUS_TEMPLATE_H__
#define __Q_HOMOGENEOUS_TEMPLATE_H__

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
    return (Q_VEC3){{
        q_div(v.x, v.w),
        q_div(v.y, v.w),
        q_div(v.z, v.w),
    }};
}

static inline Q_VEC4 q_homogeneous_point_normalise(Q_VEC4 v)
{
    return (Q_VEC4){{
        q_div(v.x, v.w),
        q_div(v.y, v.w),
        q_div(v.z, v.w),
        Q_ONE,
    }};
}

#endif // __Q_HOMOGENEOUS_TEMPLATE_H__

