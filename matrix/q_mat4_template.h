
#ifndef __Q_MAT4_TEMPLATE_H__
#define __Q_MAT4_TEMPLATE_H__

typedef union
{
    struct
    {
        Q_TYPE xx, xy, xz, xw;
        Q_TYPE yx, yy, yz, yw;
        Q_TYPE zx, zy, zz, zw;
        Q_TYPE wx, wy, wz, ww;
    };
    Q_TYPE raw[4][4];
    Q_VEC4 rows[4];
} Q_MAT4;


#define Q_MAT4_ZERO ((Q_MAT4){{         \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO, Q_ZERO, \
}})

#define Q_MAT4_IDENTITY ((Q_MAT4){{     \
         Q_ONE, Q_ZERO, Q_ZERO, Q_ZERO, \
        Q_ZERO,  Q_ONE, Q_ZERO, Q_ZERO, \
        Q_ZERO, Q_ZERO,  Q_ONE, Q_ZERO, \
        Q_ZERO, Q_ZERO, Q_ZERO,  Q_ONE, \
}})

static inline Q_MAT4 q_mat4_diagonal(Q_VEC4 v) 
{
    return (Q_MAT4){{
           v.x, Q_ZERO, Q_ZERO, Q_ZERO,
        Q_ZERO,    v.y, Q_ZERO, Q_ZERO,
        Q_ZERO, Q_ZERO,    v.z, Q_ZERO,
        Q_ZERO, Q_ZERO, Q_ZERO,    v.w,
    }};
}

static inline Q_MAT4 q_mat4_negate(Q_MAT4 m) 
{
    return (Q_MAT4){{
        q_negate(m.xx), q_negate(m.xy), q_negate(m.xz), q_negate(m.xw),
        q_negate(m.yx), q_negate(m.yy), q_negate(m.yz), q_negate(m.yw),
        q_negate(m.zx), q_negate(m.zy), q_negate(m.zz), q_negate(m.zw),
        q_negate(m.wx), q_negate(m.wy), q_negate(m.wz), q_negate(m.ww),
    }};
}

static inline Q_MAT4 q_mat4_from_rows(Q_VEC4 row0, Q_VEC4 row1, Q_VEC4 row2, Q_VEC4 row3) 
{
    return (Q_MAT4){{
        row0.x, row0.y, row0.z, row0.w,
        row1.x, row1.y, row1.z, row1.w,
        row2.x, row2.y, row2.z, row2.w,
        row3.x, row3.y, row3.z, row3.w,
    }};
}

static inline Q_MAT4 q_mat4_from_cols(Q_VEC4 col0, Q_VEC4 col1, Q_VEC4 col2, Q_VEC4 col3) 
{
    return (Q_MAT4){{
        col0.x, col1.x, col2.x, col3.x,
        col0.y, col1.y, col2.y, col3.y,
        col0.z, col1.z, col2.z, col3.z,
        col0.w, col1.w, col2.w, col3.w,
    }};
}

static inline Q_MAT4 q_mat4_add(Q_MAT4 m1, Q_MAT4 m2) 
{
    return (Q_MAT4){{
        q_add(m1.xx, m2.xx), q_add(m1.xy, m2.xy), q_add(m1.xz, m2.xz), q_add(m1.xw, m2.xw),
        q_add(m1.yx, m2.yx), q_add(m1.yy, m2.yy), q_add(m1.yz, m2.yz), q_add(m1.yw, m2.yw),
        q_add(m1.zx, m2.zx), q_add(m1.zy, m2.zy), q_add(m1.zz, m2.zz), q_add(m1.zw, m2.zw),
        q_add(m1.wx, m2.wx), q_add(m1.wy, m2.wy), q_add(m1.wz, m2.wz), q_add(m1.ww, m2.ww),
    }};
}

static inline Q_MAT4 q_mat4_sub(Q_MAT4 m1, Q_MAT4 m2) 
{
    return (Q_MAT4){{
        q_sub(m1.xx, m2.xx), q_sub(m1.xy, m2.xy), q_sub(m1.xz, m2.xz), q_sub(m1.xw, m2.xw),
        q_sub(m1.yx, m2.yx), q_sub(m1.yy, m2.yy), q_sub(m1.yz, m2.yz), q_sub(m1.yw, m2.yw),
        q_sub(m1.zx, m2.zx), q_sub(m1.zy, m2.zy), q_sub(m1.zz, m2.zz), q_sub(m1.zw, m2.zw),
        q_sub(m1.wx, m2.wx), q_sub(m1.wy, m2.wy), q_sub(m1.wz, m2.wz), q_sub(m1.ww, m2.ww),
    }};
}

static inline Q_MAT4 q_mat4_scale(Q_MAT4 m, Q_TYPE scale) 
{
    return (Q_MAT4){{
        q_mul(m.xx, scale), q_mul(m.xy, scale), q_mul(m.xz, scale), q_mul(m.xw, scale),
        q_mul(m.yx, scale), q_mul(m.yy, scale), q_mul(m.yz, scale), q_mul(m.yw, scale),
        q_mul(m.zx, scale), q_mul(m.zy, scale), q_mul(m.zz, scale), q_mul(m.zw, scale),
        q_mul(m.wx, scale), q_mul(m.wy, scale), q_mul(m.wz, scale), q_mul(m.ww, scale),
    }};
}

static inline Q_VEC4 q_mat4_mul_vec4(Q_MAT4 m, Q_VEC4 v) 
{
    return (Q_VEC4){{
        q_add(q_add(q_add(q_mul(m.xx, v.x), q_mul(m.xy, v.y)), q_mul(m.xz, v.z)), q_mul(m.xw, v.w)),
        q_add(q_add(q_add(q_mul(m.yx, v.x), q_mul(m.yy, v.y)), q_mul(m.yz, v.z)), q_mul(m.yw, v.w)),
        q_add(q_add(q_add(q_mul(m.zx, v.x), q_mul(m.zy, v.y)), q_mul(m.zz, v.z)), q_mul(m.zw, v.w)),
        q_add(q_add(q_add(q_mul(m.wx, v.x), q_mul(m.wy, v.y)), q_mul(m.wz, v.z)), q_mul(m.ww, v.w)),
    }};
}

static inline Q_TYPE q_mat4_det(Q_MAT4 m) 
{
    const Q_TYPE factor0 = q_sub(q_mul(m.zz, m.ww), q_mul(m.wz, m.zw));
	const Q_TYPE factor1 = q_sub(q_mul(m.zy, m.ww), q_mul(m.wy, m.zw));
	const Q_TYPE factor2 = q_sub(q_mul(m.zy, m.wz), q_mul(m.wy, m.zz));
	const Q_TYPE factor3 = q_sub(q_mul(m.zx, m.ww), q_mul(m.wx, m.zw));
	const Q_TYPE factor4 = q_sub(q_mul(m.zx, m.wz), q_mul(m.wx, m.zz));
	const Q_TYPE factor5 = q_sub(q_mul(m.zx, m.wy), q_mul(m.wx, m.zy));

	const Q_TYPE coef0 = q_add(q_sub(q_mul(m.yy, factor0), q_mul(m.yz, factor1)), q_mul(m.yw, factor2));
	const Q_TYPE coef1 = q_add(q_sub(q_mul(m.yx, factor0), q_mul(m.yz, factor3)), q_mul(m.yw, factor4));
	const Q_TYPE coef2 = q_add(q_sub(q_mul(m.yx, factor1), q_mul(m.yy, factor3)), q_mul(m.yw, factor5));
	const Q_TYPE coef3 = q_add(q_sub(q_mul(m.yx, factor2), q_mul(m.yy, factor4)), q_mul(m.yz, factor5));

    const Q_TYPE det = q_add(
        q_sub(q_mul(m.xx, coef0), q_mul(m.xy, coef1)), 
        q_sub(q_mul(m.xz, coef2), q_mul(m.xw, coef3))
    );

    return det;
}

// REQUIREMENT: det(m) != 0
static inline Q_MAT4 q_mat4_inv(Q_MAT4 m) 
{
    const Q_TYPE factor00 = q_sub(q_mul(m.zz, m.ww), q_mul(m.wz, m.zw));
    const Q_TYPE factor01 = q_sub(q_mul(m.zy, m.ww), q_mul(m.wy, m.zw));
    const Q_TYPE factor02 = q_sub(q_mul(m.zy, m.wz), q_mul(m.wy, m.zz));
    const Q_TYPE factor03 = q_sub(q_mul(m.zx, m.ww), q_mul(m.wx, m.zw));
    const Q_TYPE factor04 = q_sub(q_mul(m.zx, m.wz), q_mul(m.wx, m.zz));
    const Q_TYPE factor05 = q_sub(q_mul(m.zx, m.wy), q_mul(m.wx, m.zy));
    const Q_TYPE factor06 = q_sub(q_mul(m.yz, m.ww), q_mul(m.wz, m.yw));
    const Q_TYPE factor07 = q_sub(q_mul(m.yy, m.ww), q_mul(m.wy, m.yw));
    const Q_TYPE factor08 = q_sub(q_mul(m.yy, m.wz), q_mul(m.wy, m.yz));
    const Q_TYPE factor09 = q_sub(q_mul(m.yx, m.ww), q_mul(m.wx, m.yw));
    const Q_TYPE factor10 = q_sub(q_mul(m.yx, m.wz), q_mul(m.wx, m.yz));
    const Q_TYPE factor11 = q_sub(q_mul(m.yx, m.wy), q_mul(m.wx, m.yy));
    const Q_TYPE factor12 = q_sub(q_mul(m.yz, m.zw), q_mul(m.zz, m.yw));
    const Q_TYPE factor13 = q_sub(q_mul(m.yy, m.zw), q_mul(m.zy, m.yw));
    const Q_TYPE factor14 = q_sub(q_mul(m.yy, m.zz), q_mul(m.zy, m.yz));
    const Q_TYPE factor15 = q_sub(q_mul(m.yx, m.zw), q_mul(m.zx, m.yw));
    const Q_TYPE factor16 = q_sub(q_mul(m.yx, m.zz), q_mul(m.zx, m.yz));
    const Q_TYPE factor17 = q_sub(q_mul(m.yx, m.zy), q_mul(m.zx, m.yy));

    const Q_MAT4 conjugate = {{
        q_add(q_sub(q_mul(m.yy, factor00), q_mul(m.yz, factor01)), q_mul(m.yw, factor02)),
        q_sub(q_sub(q_mul(m.xz, factor01), q_mul(m.xy, factor00)), q_mul(m.xw, factor02)),
        q_add(q_sub(q_mul(m.xy, factor06), q_mul(m.xz, factor07)), q_mul(m.xw, factor08)),
        q_sub(q_sub(q_mul(m.xz, factor13), q_mul(m.xy, factor12)), q_mul(m.xw, factor14)),
        
        q_sub(q_sub(q_mul(m.yz, factor03), q_mul(m.yx, factor00)), q_mul(m.yw, factor04)),
        q_add(q_sub(q_mul(m.xx, factor00), q_mul(m.xz, factor03)), q_mul(m.xw, factor04)),
        q_sub(q_sub(q_mul(m.xz, factor09), q_mul(m.xx, factor06)), q_mul(m.xw, factor10)),
        q_add(q_sub(q_mul(m.xx, factor12), q_mul(m.xz, factor15)), q_mul(m.xw, factor16)),
        
        q_add(q_sub(q_mul(m.yx, factor01), q_mul(m.yy, factor03)), q_mul(m.yw, factor05)),
        q_sub(q_sub(q_mul(m.xy, factor03), q_mul(m.xx, factor01)), q_mul(m.xw, factor05)),
        q_add(q_sub(q_mul(m.xx, factor07), q_mul(m.xy, factor09)), q_mul(m.xw, factor11)),
        q_sub(q_sub(q_mul(m.xy, factor15), q_mul(m.xx, factor13)), q_mul(m.xw, factor17)),
        
        q_sub(q_sub(q_mul(m.yy, factor04), q_mul(m.yx, factor02)), q_mul(m.yz, factor05)),
        q_add(q_sub(q_mul(m.xx, factor02), q_mul(m.xy, factor04)), q_mul(m.xz, factor05)),
        q_sub(q_sub(q_mul(m.xy, factor10), q_mul(m.xx, factor08)), q_mul(m.xz, factor11)),
        q_add(q_sub(q_mul(m.xx, factor14), q_mul(m.xy, factor16)), q_mul(m.xz, factor17)),
    }};

    const Q_TYPE det = q_add(
        q_add(q_mul(m.xx, conjugate.xx), q_mul(m.xy, conjugate.yx)), 
        q_add(q_mul(m.xz, conjugate.zx), q_mul(m.xw, conjugate.wx))
    );
    const Q_TYPE inv_det = q_div(Q_ONE, det);

    return q_mat4_scale(conjugate, inv_det);
}

// REQUIREMENT: det(m) != 0
static inline Q_VEC4 q_mat4_solve(Q_MAT4 m, Q_VEC4 v)
{
    // TODO: implement this function
    return q_mat4_mul_vec4(m, v);
}

#endif // __Q_MAT4_TEMPLATE_H__

