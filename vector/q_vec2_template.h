
#ifndef __Q_VEC2_TEMPLATE_H__
#define __Q_VEC2_TEMPLATE_H__

typedef union 
{
    struct 
    {
        Q_TYPE x;
        Q_TYPE y;
    };
    struct 
    {
        Q_TYPE r;
        Q_TYPE i;
    };
    struct 
    {
        Q_TYPE u;
        Q_TYPE v;
    };
    struct 
    {
        Q_TYPE s;
        Q_TYPE t;
    };
    Q_TYPE raw[2];
} Q_VEC2;

#define Q_VEC2_ZERO    ((Q_VEC2){{Q_ZERO, Q_ZERO}})
#define Q_VEC2_ONE     ((Q_VEC2){{ Q_ONE,  Q_ONE}})

#define Q_VEC2_RIGHT   ((Q_VEC2){{ Q_ONE, Q_ZERO}})
#define Q_VEC2_LEFT    ((Q_VEC2){{-Q_ONE, Q_ZERO}})
#define Q_VEC2_UP      ((Q_VEC2){{Q_ZERO,  Q_ONE}})
#define Q_VEC2_DOWN    ((Q_VEC2){{Q_ZERO, -Q_ONE}})

static inline Q_VEC2 q_vec2_negate(Q_VEC2 v) 
{
    return (Q_VEC2){{
        -v.x,
        -v.y,
    }};
}

static inline Q_VEC2 q_vec2_add(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_add(v1.x, v2.x), 
        q_add(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_sub(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_sub(v1.x, v2.x), 
        q_sub(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_mul(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_mul(v1.x, v2.x), 
        q_mul(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_div(Q_VEC2 v1, Q_VEC2 v2) 
{
    return (Q_VEC2){{
        q_div(v1.x, v2.x), 
        q_div(v1.y, v2.y),
    }};
}

static inline Q_VEC2 q_vec2_scale(Q_VEC2 v, Q_TYPE q) 
{
    return (Q_VEC2){{
        q_mul(v.x, q), 
        q_mul(v.y, q),
    }};
}

static inline Q_TYPE q_vec2_dot(Q_VEC2 v1, Q_VEC2 v2)
{
    const Q_TYPE x2 = q_mul(v1.x, v2.x);
    const Q_TYPE y2 = q_mul(v1.y, v2.y);
    const Q_TYPE dot = q_add(x2, y2);

    return dot;
}

static inline Q_TYPE q_vec2_mag2(Q_VEC2 v)
{
    return q_vec2_dot(v, v);
}

static inline Q_TYPE q_vec2_mag(Q_VEC2 v) 
{
    const Q_TYPE mag2 = q_vec2_mag2(v);
    const Q_TYPE mag = q_sqrt(mag2);

    return mag;
}

static inline Q_VEC2 q_vec2_interp(Q_VEC2 v1, Q_VEC2 v2, Q_TYPE alpha) 
{
    return (Q_VEC2){{
        q_interp(v1.x, v2.x, alpha),
        q_interp(v1.y, v2.y, alpha),
    }};
}

static inline Q_VEC2 q_vec2_normalise(Q_VEC2 v) 
{
    const Q_TYPE inv_mag = q_div(Q_ONE, q_vec2_mag(v));
    const Q_VEC2 normalised = q_vec2_scale(v, inv_mag);

    return normalised;
}

#endif // __Q_VEC2_TEMPLATE_H__

