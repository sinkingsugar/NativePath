//
//  NativeMath.h
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/16/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#ifndef nativemath_h
#define nativemath_h

//Totally header free and macro free math.h wrapper

//Returns the arc cosine of x in radians.
extern double npAcos(double x);
//Returns the arc sine of x in radians.
extern double npAsin(double x);
//Returns the arc tangent of x in radians.
extern double npAtan(double x);
//Returns the arc tangent in radians of y/x based on the signs of both values to determine the correct quadrant.
extern double npAtan2(doubly y, double x);
//Returns the cosine of a radian angle x.
extern double npCos(double x);
//Returns the hyperbolic cosine of x.
extern double npCosh(double x);
//Returns the sine of a radian angle x.
extern double npSin(double x);
//Returns the hyperbolic sine of x.
extern double npSinh(double x);
//Returns the hyperbolic tangent of x.
extern double npTanh(double x);
//Returns the value of e raised to the xth power.
extern double npExp(double x);
//The returned value is the mantissa and the integer pointed to by exponent is the exponent. The resultant value is x = mantissa * 2 ^ exponent.
extern double npFrexp(double x, int *exponent);
//Returns x multiplied by 2 raised to the power of exponent.
extern double npLdexp(double x, int exponent);
//Returns the natural logarithm (base-e logarithm) of x.
extern double npLog(double x);
//Returns the common logarithm (base-10 logarithm) of x.
extern double npLog10(double x);
//The returned value is the fraction component (part after the decimal), and sets integer to the integer component.
extern double npModf(double x, double *integer);
//Returns x raised to the power of y.
extern double npPow(double x, double y);
//Returns the square root of x.
extern double npSqrt(double x);
//Returns the smallest integer value greater than or equal to x.
extern double npCeil(double x);
//Returns the absolute value of x.
extern double npFabs(double x);
//Returns the largest integer value less than or equal to x.
extern double npFloor(double x);
//Returns the remainder of x divided by y.
extern double npFmod(double x, double y);

//ShaderFastMathLib

//
// Using 0 Newton Raphson iterations
// Relative error : ~3.4% over full
// Precise format : ~small float
// 2 ALU
//
extern float npFastRcpSqrtNR0(float inX);

//
// Using 1 Newton Raphson iterations
// Relative error : ~0.2% over full
// Precise format : ~half float
// 6 ALU
//
extern float npFastRcpSqrtNR1(float inX);

//
// Using 2 Newton Raphson iterations
// Relative error : ~4.6e-004%  over full
// Precise format : ~full float
// 9 ALU
//
extern float npFastRcpSqrtNR2(float inX);

//
// Using 0 Newton Raphson iterations
// Relative error : < 0.7% over full
// Precise format : ~small float
// 1 ALU
//
extern float npFastSqrtNR0(float inX);

//
// Use inverse Rcp Sqrt
// Using 1 Newton Raphson iterations
// Relative error : ~0.2% over full
// Precise format : ~half float
// 6 ALU
//
extern float npFastSqrtNR1(float inX);

//
// Use inverse Rcp Sqrt
// Using 2 Newton Raphson iterations
// Relative error : ~4.6e-004%  over full
// Precise format : ~full float
// 9 ALU
//
extern float npFastSqrtNR2(float inX);

//
// Using 0 Newton Raphson iterations
// Relative error : < 0.4% over full
// Precise format : ~small float
// 1 ALU
//
extern float npFastRcpNR0(float inX);

//
// Using 1 Newton Raphson iterations
// Relative error : < 0.02% over full
// Precise format : ~half float
// 3 ALU
//
extern float npFastRcpNR1(float inX);

//
// Using 2 Newton Raphson iterations
// Relative error : < 5.0e-005%  over full
// Precise format : ~full float
// 5 ALU
//
extern float npFastRcpNR2(float inX);

// 4th order polynomial approximation
// 4 VGRP, 16 ALU Full Rate
// 7 * 10^-5 radians precision
// Reference : Handbook of Mathematical Functions (chapter : Elementary Transcendental Functions), M. Abramowitz and I.A. Stegun, Ed.
extern float npAcosFast4(float inX);

// 4th order polynomial approximation
// 4 VGRP, 16 ALU Full Rate
// 7 * 10^-5 radians precision
extern float npAsinFast4(float inX);

// 4th order hyperbolical approximation
// 4 VGRP, 12 ALU Full Rate
// 7 * 10^-5 radians precision
// Reference : Efficient approximations for the arctangent function, Rajan, S. Sichun Wang Inkol, R. Joyal, A., May 2006
extern float npAtanFast4(float inX);

#endif /* nativemath_h */
