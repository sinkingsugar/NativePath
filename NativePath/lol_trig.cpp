//
// Lol Engine
//
// Copyright: (c) 2010-2011 Sam Hocevar <sam@hocevar.net>
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the Do What The Fuck You Want To
//   Public License, Version 2, as published by Sam Hocevar. See
//   http://www.wtfpl.net/ for more details.
//

//#include <lol/engine-internal.h>

#include <cmath>

static const double D_PI = 3.1415926535897932384626433f;

#if defined HAVE_FASTMATH_H
#   include <fastmath.h>
#endif

// Optimisation helpers
#if defined __GNUC__
#   define __likely(x)   __builtin_expect(!!(x), 1)
#   define __unlikely(x) __builtin_expect(!!(x), 0)
#   define INLINEATTR __attribute__((always_inline))
#   if defined __x86_64__
#      define FP_USE(x) __asm__("" : "+x" (x))
#   elif defined __i386__ /* FIXME: this isn't good */
#      define FP_USE(x) __asm__("" : "+m" (x))
#   else
#      define FP_USE(x) (void)(x)
#   endif
#else
#   define __likely(x)   x
#   define __unlikely(x) x
#   define INLINEATTR
#   define FP_USE(x) (void)(x)
#endif

namespace lol
{
    
    static const double PI_2   = 1.57079632679489661923132;
    static const double PI_4   = 0.785398163397448309615661;
    static const double INV_PI = 0.318309886183790671537768;
    static const double ROOT3  = 1.73205080756887729352745;
    
    static const double ZERO    = 0.0;
    static const double ONE     = 1.0;
    static const double NEG_ONE = -1.0;
    static const double HALF    = 0.5;
    static const double QUARTER = 0.25;
    static const double TWO     = 2.0;
#if defined __GNUC__
    static const double VERY_SMALL_NUMBER = 0x1.0p-128;
#else
    static const double VERY_SMALL_NUMBER = 3e-39;
#endif
    static const double TWO_EXP_52 = 4503599627370496.0;
    static const double TWO_EXP_54 = 18014398509481984.0;
    
    /** sin Taylor series coefficients. */
    static const double SC[] =
    {
        -1.6449340668482264364724e-0, // π^2/3!
        +8.1174242528335364363700e-1, // π^4/5!
        -1.9075182412208421369647e-1, // π^6/7!
        +2.6147847817654800504653e-2, // π^8/9!
        -2.3460810354558236375089e-3, // π^10/11!
        +1.4842879303107100368487e-4, // π^12/13!
        -6.9758736616563804745344e-6, // π^14/15!
        +2.5312174041370276513517e-7, // π^16/17!
    };
    
    /* Note: the last value should be -1.3878952462213772114468e-7 (ie.
     * π^18/18!) but we tweak it in order to get the better average precision
     * required for tan() computations when close to π/2+kπ values. */
    static const double CC[] =
    {
        -4.9348022005446793094172e-0, // π^2/2!
        +4.0587121264167682181850e-0, // π^4/4!
        -1.3352627688545894958753e-0, // π^6/6!
        +2.3533063035889320454188e-1, // π^8/8!
        -2.5806891390014060012598e-2, // π^10/10!
        +1.9295743094039230479033e-3, // π^12/12!
        -1.0463810492484570711802e-4, // π^14/14!
        +4.3030695870329470072978e-6, // π^16/16!
        -1.3777e-7,
    };
    
    /* These coefficients use Sloane’s http://oeis.org/A002430 and
     * http://oeis.org/A036279 sequences for the Taylor series of tan().
     * Note: the last value should be 2.12485922978838540352881e5 (ie.
     * 443861162*π^18/1856156927625), but we tweak it in order to get
     * sub 1e-11 average precision in a larger range. */
    static const double TC[] =
    {
        3.28986813369645287294483e0, // π^2/3
        1.29878788045336582981920e1, // 2*π^4/15
        5.18844961612069061254404e1, // 17*π^6/315
        2.07509320280908496804928e2, // 62*π^8/2835
        8.30024701695986756361561e2, // 1382*π^10/155925
        3.32009324029001216460018e3, // 21844*π^12/6081075
        1.32803704909665483598490e4, // 929569*π^14/638512875
        5.31214808666037709352112e4, // 6404582*π^16/10854718875
        2.373e5,
    };
    
    static inline double lol_fabs(double x) INLINEATTR;
#if defined __GNUC__
    static inline double lol_round(double x) INLINEATTR;
    static inline double lol_trunc(double x) INLINEATTR;
#endif
    
    static inline double lol_fabs(double x)
    {
#if defined __GNUC__
        return __builtin_fabs(x);
#else
        using std::fabs;
        return fabs(x);
#endif
    }
    
#if defined __GNUC__
    static inline double lol_round(double x)
    {
        return __builtin_round(x);
    }
    
    static inline double lol_trunc(double x)
    {
        return __builtin_trunc(x);
    }
#endif
    
    double lol_sin(double x)
    {
        double absx = lol_fabs(x * INV_PI);
        
        /* If branches are cheap, skip the cycle count when |x| < π/4,
         * and only do the Taylor series up to the required precision. */
#if LOL_FEATURE_CHEAP_BRANCHES
        if (absx < QUARTER)
        {
            /* Computing x^4 is one multiplication too many we do, but it helps
             * interleave the Taylor series operations a lot better. */
            double x2 = absx * absx;
            double x4 = x2 * x2;
            double sub1 = (SC[3] * x4 + SC[1]) * x4 + ONE;
            double sub2 = (SC[4] * x4 + SC[2]) * x4 + SC[0];
            double taylor = sub2 * x2 + sub1;
            return x * taylor;
        }
#endif
        
        /* Wrap |x| to the range [-1, 1] and keep track of the number of
         * cycles required. If odd, we'll need to change the sign of the
         * result. */
        double num_cycles = absx + TWO_EXP_52;
        FP_USE(num_cycles); num_cycles -= TWO_EXP_52;
        
        double is_even = TWO * num_cycles - ONE;
        FP_USE(is_even); is_even += TWO_EXP_54;
        FP_USE(is_even); is_even -= TWO_EXP_54;
        FP_USE(is_even);
        is_even -= TWO * num_cycles - ONE;
        double sign = is_even;
        
        absx -= num_cycles;
        
        /* If branches are very cheap, we have the option to do the Taylor
         * series at a much lower degree by splitting. */
#if LOL_FEATURE_VERY_CHEAP_BRANCHES
        if (lol_fabs(absx) > QUARTER)
        {
            sign = (x * absx >= 0.0) ? sign : -sign;
            
            double x1 = HALF - lol_fabs(absx);
            double x2 = x1 * x1;
            double x4 = x2 * x2;
            double sub1 = ((CC[5] * x4 + CC[3]) * x4 + CC[1]) * x4 + ONE;
            double sub2 = (CC[4] * x4 + CC[2]) * x4 + CC[0];
            double taylor = sub2 * x2 + sub1;
            
            return taylor * sign;
        }
#endif
        
        sign *= (x >= 0.0) ? D_PI : -D_PI;
        
        /* Compute a Tailor series for sin() and combine sign information. */
        double x2 = absx * absx;
        double x4 = x2 * x2;
#if LOL_FEATURE_VERY_CHEAP_BRANCHES
        double sub1 = (SC[3] * x4 + SC[1]) * x4 + ONE;
        double sub2 = (SC[4] * x4 + SC[2]) * x4 + SC[0];
#else
        double sub1 = (((SC[7] * x4 + SC[5]) * x4 + SC[3]) * x4 + SC[1]) * x4 + ONE;
        double sub2 = ((SC[6] * x4 + SC[4]) * x4 + SC[2]) * x4 + SC[0];
#endif
        double taylor = sub2 * x2 + sub1;
        
        return absx * taylor * sign;
    }
    
    double lol_cos(double x)
    {
        double absx = lol_fabs(x * INV_PI);
        
#if LOL_FEATURE_CHEAP_BRANCHES
        if (absx < QUARTER)
        {
            double x2 = absx * absx;
            double x4 = x2 * x2;
            double sub1 = (CC[5] * x4 + CC[3]) * x4 + CC[1];
            double sub2 = (CC[4] * x4 + CC[2]) * x4 + CC[0];
            double taylor = (sub1 * x2 + sub2) * x2 + ONE;
            return taylor;
        }
#endif
        
        double num_cycles = absx + TWO_EXP_52;
        FP_USE(num_cycles); num_cycles -= TWO_EXP_52;
        
        double is_even = TWO * num_cycles - ONE;
        FP_USE(is_even); is_even += TWO_EXP_54;
        FP_USE(is_even); is_even -= TWO_EXP_54;
        FP_USE(is_even);
        is_even -= TWO * num_cycles - ONE;
        double sign = is_even;
        
        absx -= num_cycles;
        
#if LOL_FEATURE_VERY_CHEAP_BRANCHES
        if (lol_fabs(absx) > QUARTER)
        {
            double x1 = HALF - lol_fabs(absx);
            double x2 = x1 * x1;
            double x4 = x2 * x2;
            double sub1 = (SC[3] * x4 + SC[1]) * x4 + ONE;
            double sub2 = (SC[4] * x4 + SC[2]) * x4 + SC[0];
            double taylor = sub2 * x2 + sub1;
            
            return x1 * taylor * sign * D_PI;
        }
#endif
        
        double x2 = absx * absx;
        double x4 = x2 * x2;
#if LOL_FEATURE_VERY_CHEAP_BRANCHES
        double sub1 = ((CC[5] * x4 + CC[3]) * x4 + CC[1]) * x4 + ONE;
        double sub2 = (CC[4] * x4 + CC[2]) * x4 + CC[0];
#else
        double sub1 = (((CC[7] * x4 + CC[5]) * x4 + CC[3]) * x4 + CC[1]) * x4 + ONE;
        double sub2 = ((CC[6] * x4 + CC[4]) * x4 + CC[2]) * x4 + CC[0];
#endif
        double taylor = sub2 * x2 + sub1;
        
        return taylor * sign;
    }
    
    void lol_sincos(double x, double *sinx, double *cosx)
    {
        double absx = lol_fabs(x * INV_PI);
        
#if LOL_FEATURE_CHEAP_BRANCHES
        if (absx < QUARTER)
        {
            double x2 = absx * absx;
            double x4 = x2 * x2;
            
            /* Computing the Taylor series to the 11th order is enough to get
             * x * 1e-11 precision, but we push it to the 13th order so that
             * tan() has a better precision. */
            double subs1 = ((SC[5] * x4 + SC[3]) * x4 + SC[1]) * x4 + ONE;
            double subs2 = (SC[4] * x4 + SC[2]) * x4 + SC[0];
            double taylors = subs2 * x2 + subs1;
            *sinx = x * taylors;
            
            double subc1 = (CC[5] * x4 + CC[3]) * x4 + CC[1];
            double subc2 = (CC[4] * x4 + CC[2]) * x4 + CC[0];
            double taylorc = (subc1 * x2 + subc2) * x2 + ONE;
            *cosx = taylorc;
            
            return;
        }
#endif
        
        double num_cycles = absx + TWO_EXP_52;
        FP_USE(num_cycles); num_cycles -= TWO_EXP_52;
        
        double is_even = TWO * num_cycles - ONE;
        FP_USE(is_even); is_even += TWO_EXP_54;
        FP_USE(is_even); is_even -= TWO_EXP_54;
        FP_USE(is_even);
        is_even -= TWO * num_cycles - ONE;
        double sin_sign = is_even;
        double cos_sign = is_even;
        
        absx -= num_cycles;
        
#if LOL_FEATURE_VERY_CHEAP_BRANCHES
        if (lol_fabs(absx) > QUARTER)
        {
            cos_sign = sin_sign;
            sin_sign = (x * absx >= 0.0) ? sin_sign : -sin_sign;
            
            double x1 = HALF - lol_fabs(absx);
            double x2 = x1 * x1;
            double x4 = x2 * x2;
            
            double subs1 = ((CC[5] * x4 + CC[3]) * x4 + CC[1]) * x4 + ONE;
            double subs2 = (CC[4] * x4 + CC[2]) * x4 + CC[0];
            double taylors = subs2 * x2 + subs1;
            *sinx = taylors * sin_sign;
            
            double subc1 = ((SC[5] * x4 + SC[3]) * x4 + SC[1]) * x4 + ONE;
            double subc2 = (SC[4] * x4 + SC[2]) * x4 + SC[0];
            double taylorc = subc2 * x2 + subc1;
            *cosx = x1 * taylorc * cos_sign * D_PI;
            
            return;
        }
#endif
        
        sin_sign *= (x >= 0.0) ? D_PI : -D_PI;
        
        double x2 = absx * absx;
        double x4 = x2 * x2;
#if LOL_FEATURE_VERY_CHEAP_BRANCHES
        double subs1 = ((SC[5] * x4 + SC[3]) * x4 + SC[1]) * x4 + ONE;
        double subs2 = (SC[4] * x4 + SC[2]) * x4 + SC[0];
        double subc1 = ((CC[5] * x4 + CC[3]) * x4 + CC[1]) * x4 + ONE;
        double subc2 = (CC[4] * x4 + CC[2]) * x4 + CC[0];
#else
        double subs1 = (((SC[7] * x4 + SC[5]) * x4 + SC[3]) * x4 + SC[1]) * x4 + ONE;
        double subs2 = ((SC[6] * x4 + SC[4]) * x4 + SC[2]) * x4 + SC[0];
        /* Push Taylor series to the 19th order to enhance tan() accuracy. */
        double subc1 = (((CC[7] * x4 + CC[5]) * x4 + CC[3]) * x4 + CC[1]) * x4 + ONE;
        double subc2 = (((CC[8] * x4 + CC[6]) * x4 + CC[4]) * x4 + CC[2]) * x4 + CC[0];
#endif
        double taylors = subs2 * x2 + subs1;
        *sinx = absx * taylors * sin_sign;
        
        double taylorc = subc2 * x2 + subc1;
        *cosx = taylorc * cos_sign;
    }
    
    void lol_sincos(float x, float *sinx, float *cosx)
    {
        double x2 = static_cast<double>(x);
        double s2, c2;
        lol_sincos(x2, &s2, &c2);
        *sinx = static_cast<float>(s2);
        *cosx = static_cast<float>(c2);
    }
    
    double lol_tan(double x)
    {
#if LOL_FEATURE_CHEAP_BRANCHES
        double absx = lol_fabs(x * INV_PI);
        
        /* This value was determined empirically to ensure an error of no
         * more than x * 1e-11 in this range. */
        if (absx < 0.163)
        {
            double x2 = absx * absx;
            double x4 = x2 * x2;
            double sub1 = (((TC[7] * x4 + TC[5]) * x4
                            + TC[3]) * x4 + TC[1]) * x4 + ONE;
            double sub2 = (((TC[8] * x4 + TC[6]) * x4
                            + TC[4]) * x4 + TC[2]) * x4 + TC[0];
            double taylor = sub2 * x2 + sub1;
            return x * taylor;
        }
#endif
        
        double sinx, cosx;
        lol_sincos(x, &sinx, &cosx);
        
        /* Ensure cosx isn't zero. FIXME: we lose the cosx sign here. */
        double absc = lol_fabs(cosx);
        
        if (__unlikely(absc < VERY_SMALL_NUMBER))
            cosx = VERY_SMALL_NUMBER;
        return sinx / cosx;
    }
    
} /* namespace lol */

#ifdef __cplusplus
extern "C"
{
    double _lol_fabs(double x)
    {
        return lol::lol_fabs(x);
    }
    
    double _lol_sin(double x)
    {
        return lol::lol_sin(x);
    }
    
    double _lol_cos(double x)
    {
        return lol::lol_cos(x);
    }
    
    void _lol_sincos(double x, double *sinx, double *cosx)
    {
        lol::lol_sincos(x, sinx, cosx);
    }
    
    void _lol_sincosf(float x, float *sinx, float *cosx)
    {
        lol::lol_sincos(x, sinx, cosx);
    }
    
    double _lol_tan(double x)
    {
        return lol::lol_tan(x);
    }
}
#endif

