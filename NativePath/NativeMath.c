//
//  NativeMath.c
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/16/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#include <math.h>
#include "ShaderFastMathLib.h"
#include "lol_trig.h"

//Returns the arc cosine of x in radians.
double npAcos(double x)
{
    return acos(x);
}

//Returns the arc sine of x in radians.
double npAsin(double x)
{
    return asin(x);
}

//Returns the arc tangent of x in radians.
double npAtan(double x)
{
    return atan(x);
}

//Returns the arc tangent in radians of y/x based on the signs of both values to determine the correct quadrant.
double npAtan2(double y, double x)
{
    return atan2(y, x);
}

//Returns the cosine of a radian angle x.
double npCos(double x)
{
    return cos(x);
}

//Returns the hyperbolic cosine of x.
double npCosh(double x)
{
    return cosh(x);
}

//Returns the sine of a radian angle x.
double npSin(double x)
{
    return sin(x);
}

//Returns the hyperbolic sine of x.
double npSinh(double x)
{
    return sinh(x);
}

//Returns the hyperbolic tangent of x.
double npTanh(double x)
{
    return tanh(x);
}

//Returns the value of e raised to the xth power.
double npExp(double x)
{
    return exp(x);
}

//The returned value is the mantissa and the integer pointed to by exponent is the exponent. The resultant value is x = mantissa * 2 ^ exponent.
double npFrexp(double x, int *exponent)
{
    return frexp(x, exponent);
}

//Returns x multiplied by 2 raised to the power of exponent.
double npLdexp(double x, int exponent)
{
    return ldexp(x, exponent);
}

//Returns the natural logarithm (base-e logarithm) of x.
double npLog(double x)
{
    return log(x);
}

//Returns the common logarithm (base-10 logarithm) of x.
double npLog10(double x)
{
    return log10(x);
}

//The returned value is the fraction component (part after the decimal), and sets integer to the integer component.
double npModf(double x, double *integer)
{
    return modf(x, integer);
}

//Returns x raised to the power of y.
double npPow(double x, double y)
{
    return pow(x, y);
}

//Returns the square root of x.
double npSqrt(double x)
{
    return sqrt(x);
}

//Returns the smallest integer value greater than or equal to x.
double npCeil(double x)
{
    return ceil(x);
}

//Returns the absolute value of x.
double npFabs(double x)
{
    return fabs(x);
}

//Returns the largest integer value less than or equal to x.
double npFloor(double x)
{
    return floor(x);
}

//Returns the remainder of x divided by y.
double npFmod(double x, double y)
{
    return fmod(x, y);
}

double npFmax(double x, double y)
{
	return fmax(x, y);
}

double npFmin(double x, double y)
{
	return fmin(x, y);
}

//ShaderFastMathLib

//
// Using 0 Newton Raphson iterations
// Relative error : ~3.4% over full
// Precise format : ~small float
// 2 ALU
//
float npFastRcpSqrtNR0(float inX)
{
    return fastRcpSqrtNR0(inX);
}

//
// Using 1 Newton Raphson iterations
// Relative error : ~0.2% over full
// Precise format : ~half float
// 6 ALU
//
float npFastRcpSqrtNR1(float inX)
{
    return fastRcpSqrtNR1(inX);
}

//
// Using 2 Newton Raphson iterations
// Relative error : ~4.6e-004%  over full
// Precise format : ~full float
// 9 ALU
//
float npFastRcpSqrtNR2(float inX)
{
    return fastRcpSqrtNR2(inX);
}

//
// Using 0 Newton Raphson iterations
// Relative error : < 0.7% over full
// Precise format : ~small float
// 1 ALU
//
float npFastSqrtNR0(float inX)
{
    return fastSqrtNR0(inX);
}

//
// Use inverse Rcp Sqrt
// Using 1 Newton Raphson iterations
// Relative error : ~0.2% over full
// Precise format : ~half float
// 6 ALU
//
float npFastSqrtNR1(float inX)
{
    return fastSqrtNR1(inX);
}

//
// Use inverse Rcp Sqrt
// Using 2 Newton Raphson iterations
// Relative error : ~4.6e-004%  over full
// Precise format : ~full float
// 9 ALU
//
float npFastSqrtNR2(float inX)
{
    return fastSqrtNR2(inX);
}

//
// Using 0 Newton Raphson iterations
// Relative error : < 0.4% over full
// Precise format : ~small float
// 1 ALU
//
float npFastRcpNR0(float inX)
{
    return fastRcpNR0(inX);
}

//
// Using 1 Newton Raphson iterations
// Relative error : < 0.02% over full
// Precise format : ~half float
// 3 ALU
//
float npFastRcpNR1(float inX)
{
    return fastRcpNR1(inX);
}

//
// Using 2 Newton Raphson iterations
// Relative error : < 5.0e-005%  over full
// Precise format : ~full float
// 5 ALU
//
float npFastRcpNR2(float inX)
{
    return fastRcpNR2(inX);
}

// 4th order polynomial approximation
// 4 VGRP, 16 ALU Full Rate
// 7 * 10^-5 radians precision
// Reference : Handbook of Mathematical Functions (chapter : Elementary Transcendental Functions), M. Abramowitz and I.A. Stegun, Ed.
float npAcosFast4(float inX)
{
    return acosFast4(inX);
}

// 4th order polynomial approximation
// 4 VGRP, 16 ALU Full Rate
// 7 * 10^-5 radians precision
float npAsinFast4(float inX)
{
    return asinFast4(inX);
}

// 4th order hyperbolical approximation
// 4 VGRP, 12 ALU Full Rate
// 7 * 10^-5 radians precision
// Reference : Efficient approximations for the arctangent function, Rajan, S. Sichun Wang Inkol, R. Joyal, A., May 2006
float npAtanFast4(float inX)
{
    return atanFast4(inX);
}

double npLolFabs(double x)
{
    return _lol_fabs(x);
}

double npLolSin(double x)
{
    return _lol_sin(x);
}

double npLolCos(double x)
{
    return _lol_cos(x);
}

void npLolSincos(double x, double *sinx, double *cosx)
{
    _lol_sincos(x, sinx, cosx);
}

void npLolSincosf(float x, float *sinx, float *cosx)
{
    _lol_sincosf(x, sinx, cosx);
}

double npLolTan(double x)
{
    return _lol_tan(x);
}

