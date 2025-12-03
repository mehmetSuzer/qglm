
#ifndef __Q_VEC4_TEMPLATE_H__
#define __Q_VEC4_TEMPLATE_H__

typedef union 
{
    struct 
    {
        Q_TYPE x;
        Q_TYPE y;
        Q_TYPE z;
        Q_TYPE w;
    };
    struct 
    {
        Q_TYPE r;
        Q_TYPE g;
        Q_TYPE b;
        Q_TYPE a;
    };
    Q_TYPE raw[4];
} Q_VEC4;

#define Q_VEC4_ZERO     ((Q_VEC4){{Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO}})
#define Q_VEC4_ONE      ((Q_VEC4){{ Q_ONE,  Q_ONE,  Q_ONE,  Q_ONE}})

#define Q_VEC4_RIGHT    ((Q_VEC4){{ Q_ONE, Q_ZERO, Q_ZERO, Q_ZERO}})
#define Q_VEC4_LEFT     ((Q_VEC4){{-Q_ONE, Q_ZERO, Q_ZERO, Q_ZERO}})
#define Q_VEC4_UP       ((Q_VEC4){{Q_ZERO,  Q_ONE, Q_ZERO, Q_ZERO}})
#define Q_VEC4_DOWN     ((Q_VEC4){{Q_ZERO, -Q_ONE, Q_ZERO, Q_ZERO}})
#define Q_VEC4_BACKWARD ((Q_VEC4){{Q_ZERO, Q_ZERO,  Q_ONE, Q_ZERO}})
#define Q_VEC4_FORWARD  ((Q_VEC4){{Q_ZERO, Q_ZERO, -Q_ONE, Q_ZERO}})

static inline Q_VEC4 q_vec4_negate(Q_VEC4 v) 
{
    return (Q_VEC4){{
        -v.x,
        -v.y,
        -v.z,
        -v.w,
    }};
}

static inline Q_VEC4 q_vec4_add(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_add(v1.x, v2.x), 
        q_add(v1.y, v2.y),
        q_add(v1.z, v2.z),
        q_add(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_sub(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_sub(v1.x, v2.x), 
        q_sub(v1.y, v2.y),
        q_sub(v1.z, v2.z),
        q_sub(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_mul(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_mul(v1.x, v2.x), 
        q_mul(v1.y, v2.y),
        q_mul(v1.z, v2.z),
        q_mul(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_div(Q_VEC4 v1, Q_VEC4 v2) 
{
    return (Q_VEC4){{
        q_div(v1.x, v2.x), 
        q_div(v1.y, v2.y),
        q_div(v1.z, v2.z),
        q_div(v1.w, v2.w),
    }};
}

static inline Q_VEC4 q_vec4_scale(Q_VEC4 v, Q_TYPE q) 
{
    return (Q_VEC4){{
        q_mul(v.x, q), 
        q_mul(v.y, q),
        q_mul(v.z, q),
        q_mul(v.w, q),
    }};
}

static inline Q_TYPE q_vec4_dot(Q_VEC4 v1, Q_VEC4 v2)
{
    const Q_TYPE x2 = q_mul(v1.x, v2.x);
    const Q_TYPE y2 = q_mul(v1.y, v2.y);
    const Q_TYPE z2 = q_mul(v1.z, v2.z);
    const Q_TYPE w2 = q_mul(v1.w, v2.w);
    const Q_TYPE dot = q_add(q_add(q_add(x2, y2), z2), w2);

    return dot;
}

static inline Q_TYPE q_vec4_mag2(Q_VEC4 v)
{
    return q_vec4_dot(v, v);
}

static inline Q_TYPE q_vec4_mag(Q_VEC4 v) 
{
    const Q_TYPE mag2 = q_vec4_mag2(v);
    const Q_TYPE mag = q_sqrt(mag2);

    return mag;
}

static inline Q_VEC4 q_vec4_interp(Q_VEC4 v1, Q_VEC4 v2, Q_TYPE alpha) 
{
    return (Q_VEC4){{
        q_interp(v1.x, v2.x, alpha),
        q_interp(v1.y, v2.y, alpha),
        q_interp(v1.z, v2.z, alpha),
        q_interp(v1.w, v2.w, alpha),
    }};
}

static inline Q_VEC4 q_vec4_normalise(Q_VEC4 v) 
{
    const Q_TYPE inv_mag = q_div(Q_ONE, q_vec4_mag(v));
    const Q_VEC4 normalised = q_vec4_scale(v, inv_mag);

    return normalised;
}

#endif // __Q_VEC4_TEMPLATE_H__

