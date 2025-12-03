
#ifndef __Q_VEC3_TEMPLATE_H__
#define __Q_VEC3_TEMPLATE_H__

typedef union 
{
    struct 
    {
        Q_TYPE x;
        Q_TYPE y;
        Q_TYPE z;
    };
    struct 
    {
        Q_TYPE r;
        Q_TYPE g;
        Q_TYPE b;
    };
    struct 
    {
        Q_TYPE u;
        Q_TYPE v;
        Q_TYPE w;
    };
    Q_TYPE raw[3];
} Q_VEC3;

#define Q_VEC3_ZERO     ((Q_VEC3){{Q_ZERO, Q_ZERO, Q_ZERO}})
#define Q_VEC3_ONE      ((Q_VEC3){{ Q_ONE,  Q_ONE,  Q_ONE}})

#define Q_VEC3_RIGHT    ((Q_VEC3){{ Q_ONE, Q_ZERO, Q_ZERO}})
#define Q_VEC3_LEFT     ((Q_VEC3){{-Q_ONE, Q_ZERO, Q_ZERO}})
#define Q_VEC3_UP       ((Q_VEC3){{Q_ZERO,  Q_ONE, Q_ZERO}})
#define Q_VEC3_DOWN     ((Q_VEC3){{Q_ZERO, -Q_ONE, Q_ZERO}})
#define Q_VEC3_BACKWARD ((Q_VEC3){{Q_ZERO, Q_ZERO,  Q_ONE}})
#define Q_VEC3_FORWARD  ((Q_VEC3){{Q_ZERO, Q_ZERO, -Q_ONE}})

static inline Q_VEC3 q_vec3_negate(Q_VEC3 v) 
{
    return (Q_VEC3){{
        -v.x,
        -v.y,
        -v.z,
    }};
}

static inline Q_VEC3 q_vec3_add(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_add(v1.x, v2.x), 
        q_add(v1.y, v2.y),
        q_add(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_sub(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_sub(v1.x, v2.x), 
        q_sub(v1.y, v2.y),
        q_sub(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_mul(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_mul(v1.x, v2.x), 
        q_mul(v1.y, v2.y),
        q_mul(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_div(Q_VEC3 v1, Q_VEC3 v2) 
{
    return (Q_VEC3){{
        q_div(v1.x, v2.x), 
        q_div(v1.y, v2.y),
        q_div(v1.z, v2.z),
    }};
}

static inline Q_VEC3 q_vec3_scale(Q_VEC3 v, Q_TYPE q) 
{
    return (Q_VEC3){{
        q_mul(v.x, q), 
        q_mul(v.y, q),
        q_mul(v.z, q),
    }};
}

static inline Q_TYPE q_vec3_dot(Q_VEC3 v1, Q_VEC3 v2)
{
    const Q_TYPE x2 = q_mul(v1.x, v2.x);
    const Q_TYPE y2 = q_mul(v1.y, v2.y);
    const Q_TYPE z2 = q_mul(v1.z, v2.z);
    const Q_TYPE dot = q_add(q_add(x2, y2), z2);

    return dot;
}

static inline Q_TYPE q_vec3_mag2(Q_VEC3 v)
{
    return q_vec3_dot(v, v);
}

static inline Q_TYPE q_vec3_mag(Q_VEC3 v) 
{
    const Q_TYPE mag2 = q_vec3_mag2(v);
    const Q_TYPE mag = q_sqrt(mag2);

    return mag;
}

static inline Q_VEC3 q_vec3_interp(Q_VEC3 v1, Q_VEC3 v2, Q_TYPE alpha) 
{
    return (Q_VEC3){{
        q_interp(v1.x, v2.x, alpha),
        q_interp(v1.y, v2.y, alpha),
        q_interp(v1.z, v2.z, alpha),
    }};
}

static inline Q_VEC3 q_vec3_normalise(Q_VEC3 v) 
{
    const Q_TYPE inv_mag = q_div(Q_ONE, q_vec3_mag(v));
    const Q_VEC3 normalised = q_vec3_scale(v, inv_mag);

    return normalised;
}

static inline Q_VEC3 q_vec3_cross(Q_VEC3 v1, Q_VEC3 v2)
{
    const Q_TYPE x = q_sub(q_mul(v1.y, v2.z), q_mul(v1.z, v2.y));
    const Q_TYPE y = q_sub(q_mul(v1.z, v2.x), q_mul(v1.x, v2.z));
    const Q_TYPE z = q_sub(q_mul(v1.x, v2.y), q_mul(v1.y, v2.x));

    return (Q_VEC3){{x, y, z}};
}

// u is a unit vector.
// n is a unit normal.
static inline Q_VEC3 q_vec3_reflect(Q_VEC3 u, Q_VEC3 n)
{
    const Q_TYPE scale = q_mul(Q_TWO, q_vec3_dot(n, u));
    const Q_VEC3 scaled_n = q_vec3_scale(n, scale);
    const Q_VEC3 reflect = q_vec3_sub(u, scaled_n);
    
    return reflect;
}

// u1 and u2 are unit vectors.
static inline Q_VEC3 q_vec3_bisector(Q_VEC3 u1, Q_VEC3 u2)
{
    const Q_VEC3 sum = q_vec3_add(u1, u2);
    const Q_VEC3 bisector = q_vec3_normalise(sum);

    return bisector;
}

#endif // __Q_VEC3_TEMPLATE_H__

