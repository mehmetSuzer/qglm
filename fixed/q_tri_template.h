
#ifndef QGLM_Q_TRI_TEMPLATE_H
#define QGLM_Q_TRI_TEMPLATE_H

// Product for i in 0...31 (1.0 / sqrt(1.0 + pow(2.0, -2.0 * i)))
#define Q_CORDIC_K  Q_FROM_DOUBLE(0.60725293500888122277814318294986)

#define Q_CORDIC_ITER (Q_FRAC_BITS + 1)

static const Q_TYPE q_cordic_atan_table[] = {
    Q_FROM_DOUBLE(0.78539816339744827899949086713605), // atan(2^-00)
    Q_FROM_DOUBLE(0.46364760900080609351547877849953), // atan(2^-01)
    Q_FROM_DOUBLE(0.24497866312686414347332686247682), // atan(2^-02)
    Q_FROM_DOUBLE(0.12435499454676143815667899161781), // atan(2^-03)
    Q_FROM_DOUBLE(0.06241880999595735002305474381501), // atan(2^-04)
    Q_FROM_DOUBLE(0.03123983343026827744215445648024), // atan(2^-05)
    Q_FROM_DOUBLE(0.01562372862047683129416153491320), // atan(2^-06)
    Q_FROM_DOUBLE(0.00781234106010111114398730691732), // atan(2^-07)
    Q_FROM_DOUBLE(0.00390623013196697175739013907503), // atan(2^-08)
    Q_FROM_DOUBLE(0.00195312251647881875843415500071), // atan(2^-09)
    Q_FROM_DOUBLE(0.00097656218955931945943649274966), // atan(2^-10)
    Q_FROM_DOUBLE(0.00048828121119489828992621394121), // atan(2^-11)
    Q_FROM_DOUBLE(0.00024414062014936177124474481204), // atan(2^-12)
    Q_FROM_DOUBLE(0.00012207031189367020785306594544), // atan(2^-13)
    Q_FROM_DOUBLE(0.00006103515617420877259350145416), // atan(2^-14)
    Q_FROM_DOUBLE(0.00003051757811552609572715473452), // atan(2^-15)
    Q_FROM_DOUBLE(0.00001525878906131576154237786819), // atan(2^-16)
    Q_FROM_DOUBLE(0.00000762939453110196998103899671), // atan(2^-17)
    Q_FROM_DOUBLE(0.00000381469726560649614175075618), // atan(2^-18)
    Q_FROM_DOUBLE(0.00000190734863281018696477928532), // atan(2^-19)
    Q_FROM_DOUBLE(0.00000095367431640596084412763106), // atan(2^-20)
    Q_FROM_DOUBLE(0.00000047683715820308884228106408), // atan(2^-21)
    Q_FROM_DOUBLE(0.00000023841857910155797366768811), // atan(2^-22)
    Q_FROM_DOUBLE(0.00000011920928955078068089973856), // atan(2^-23)
    Q_FROM_DOUBLE(0.00000005960464477539055220810610), // atan(2^-24)
    Q_FROM_DOUBLE(0.00000002980232238769530257383265), // atan(2^-25)
    Q_FROM_DOUBLE(0.00000001490116119384765459563877), // atan(2^-26)
    Q_FROM_DOUBLE(0.00000000745058059692382812500000), // atan(2^-27)
    Q_FROM_DOUBLE(0.00000000372529029846191406250000), // atan(2^-28)
    Q_FROM_DOUBLE(0.00000000186264514923095703125000), // atan(2^-29)
    Q_FROM_DOUBLE(0.00000000093132257461547851562500), // atan(2^-30)
    Q_FROM_DOUBLE(0.00000000046566128730773925781250), // atan(2^-31)
};

static inline Q_TYPE q_to_radian(Q_TYPE degree)
{
    return q_mul(degree, Q_TO_RADIAN);
}

static inline Q_TYPE q_to_degree(Q_TYPE radian)
{
    return q_mul(radian, Q_TO_DEGREE);
}

// Wraps the angle to [-pi, pi)
static inline Q_TYPE q_wrap_pi(Q_TYPE theta)
{
    theta = q_add(theta, Q_PI);
    theta = q_mod(theta, Q_2PI);
    theta = q_sub(theta, Q_PI);
    return theta;
}

static inline void q_sincos(Q_TYPE theta, Q_TYPE* sin_out, Q_TYPE* cos_out)
{
    Q_TYPE x = Q_CORDIC_K;
    Q_TYPE y = Q_ZERO;
    Q_TYPE z = q_wrap_pi(theta);

    int sin_sign = 1;
    int cos_sign = 1;

    if (q_gt(z, Q_HALFPI))
    {
        z = q_sub(Q_PI, z);
        cos_sign = -1;
    }
    else if (q_lt(z, q_negate(Q_HALFPI)))
    {
        z = q_add(Q_PI, z);
        sin_sign = -1;
        cos_sign = -1;
    }

    for (uint32_t i = 0; i < Q_CORDIC_ITER; ++i)
    {
        const Q_TYPE dx = q_div_pow_2(y, i);
        const Q_TYPE dy = q_div_pow_2(x, i);

        if (q_ge(z, Q_ZERO))
        {
            x = q_sub(x, dx);
            y = q_add(y, dy);
            z = q_sub(z, q_cordic_atan_table[i]);
        }
        else
        {
            x = q_add(x, dx);
            y = q_sub(y, dy);
            z = q_add(z, q_cordic_atan_table[i]);
        }
    }

    *cos_out = (cos_sign > 0) ? x : q_negate(x);
    *sin_out = (sin_sign > 0) ? y : q_negate(y);
}

static inline Q_TYPE q_sin(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);
    return s;
}

static inline Q_TYPE q_cos(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);
    return c;
}

// tan(x) = sin(x) / cos(x)
static inline Q_TYPE q_tan(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);

#ifdef QGLM_SAFE_MATH
    if (q_eq(c, Q_ZERO))
        return q_lt(s, Q_ZERO) ? Q_MIN : Q_MAX;
#endif
    return q_div(s, c);
}

// cot(x) = cos(x) / sin(x)
static inline Q_TYPE q_cot(Q_TYPE theta)
{
    Q_TYPE s;
    Q_TYPE c;
    q_sincos(theta, &s, &c);

#ifdef QGLM_SAFE_MATH
    if (q_eq(s, Q_ZERO))
        return q_lt(c, Q_ZERO) ? Q_MIN : Q_MAX;
#endif
    return q_div(c, s);
}

#endif // QGLM_Q_TRI_TEMPLATE_H

