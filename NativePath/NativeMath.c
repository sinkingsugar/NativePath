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
//  NativeMath.c
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/16/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#include <math.h>
#include "ShaderFastMathLib.h"
#include "lol_trig.h"

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

