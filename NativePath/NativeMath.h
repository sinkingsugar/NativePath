/*
Copyright (c) 2015 Giovanni Petrantoni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

//
//  NativeMath.h
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/16/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#ifndef nativemath_h
#define nativemath_h

//type safeguard, if type sizes are not what we expect it the compiler will throw error
static union
{
	char int_incorrect[sizeof(int) == 4 ? 1 : -1];
	char float_incorrect[sizeof(float) == 4 ? 1 : -1];
	char double_incorrect[sizeof(double) == 8 ? 1 : -1];
} __types_safeguard;

//Totally header free and macro free math.h wrapper

//Returns the arc cosine of x in radians.
extern double npAcos(double x);
//Returns the arc sine of x in radians.
extern double npAsin(double x);
//Returns the arc tangent of x in radians.
extern double npAtan(double x);
//Returns the arc tangent in radians of y/x based on the signs of both values to determine the correct quadrant.
extern double npAtan2(double y, double x);
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

extern double npFmax(double x, double y);
extern double npFmin(double x, double y);

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

//LoL engine fast math

extern double npLolFabs(double x);
extern double npLolSin(double x);
extern double npLolCos(double x);
extern void npLolSincos(double x, double *sinx, double *cosx);
extern void npLolSincosf(float x, float *sinx, float *cosx);
extern double npLolTan(double x);

//Vectors

/*
 The following operators are supported on vectors:
 
 unary +, -
 ++, --
 +, -, *, /, %
 &, |, ^, ~
 >>, <<
 !, &&, ||
 ==, !=, >, <, >=, <=
 =
 
 // identity operation - return 4-element vector v1.
 __builtin_shufflevector(v1, v1, 0, 1, 2, 3)
 
 // "Splat" element 0 of v1 into a 4-element result.
 __builtin_shufflevector(v1, v1, 0, 0, 0, 0)
 
 // Reverse 4-element vector v1.
 __builtin_shufflevector(v1, v1, 3, 2, 1, 0)
 
 // Concatenate every other element of 4-element vectors v1 and v2.
 __builtin_shufflevector(v1, v2, 0, 2, 4, 6)
 
 // Concatenate every other element of 8-element vectors v1 and v2.
 __builtin_shufflevector(v1, v2, 0, 2, 4, 6, 8, 10, 12, 14)
 
 // Shuffle v1 with some elements being undefined
 __builtin_shufflevector(v1, v1, 3, -1, 1, -1)
 
 C-style casts can be used to convert one vector type to another without modifying the underlying bits. __builtin_convertvector can be used to convert from one type to another provided both types have the same number of elements, truncating when converting from floating-point to integer.
 */

//http://clang.llvm.org/docs/LanguageExtensions.html#vectors-and-extended-vectors
//https://developer.chrome.com/native-client/reference/pnacl-c-cpp-language-support

#define VECTOR_BYTES 16
#define VECTOR_ALIGN 4

typedef float npFloat4 __attribute__((vector_size(VECTOR_BYTES), aligned(VECTOR_ALIGN)));
typedef int npInt4 __attribute__((vector_size(VECTOR_BYTES), aligned(VECTOR_ALIGN)));
typedef unsigned int npUInt4 __attribute__((vector_size(VECTOR_BYTES), aligned(VECTOR_ALIGN)));

#endif /* nativemath_h */
