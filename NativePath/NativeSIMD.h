/*
Copyright (c) 2016 Giovanni Petrantoni

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
//  NativeSIMD.h
//  NativePath
//
//  Created by Giovanni Petrantoni on 05/14/16.
//  Copyright © 2016 Giovanni Petrantoni. All rights reserved.
//

#ifndef NativeSIMD_h
#define NativeSIMD_h

#include <NativePath.h>

typedef float float32_t;
typedef int8_t poly8_t;
typedef int16_t poly16_t;

typedef __attribute__((__vector_size__(16))) int8_t int8x16_t;
typedef __attribute__((__vector_size__(16))) int16_t int16x8_t;
typedef __attribute__((__vector_size__(16))) int32_t int32x4_t;
typedef __attribute__((__vector_size__(16))) int64_t int64x2_t;
typedef __attribute__((__vector_size__(16))) uint8_t uint8x16_t;
typedef __attribute__((__vector_size__(16))) uint16_t uint16x8_t;
typedef __attribute__((__vector_size__(16))) uint32_t uint32x4_t;
typedef __attribute__((__vector_size__(16))) uint64_t uint64x2_t;
typedef __attribute__((__vector_size__(16))) float32_t float32x4_t;
typedef __attribute__((__vector_size__(16))) poly8_t poly8x16_t;
typedef __attribute__((__vector_size__(16))) poly16_t poly16x8_t;

typedef struct int8x16x2_t {
  int8x16_t val[2];
} int8x16x2_t;

typedef struct int16x8x2_t {
  int16x8_t val[2];
} int16x8x2_t;

typedef struct int32x4x2_t {
  int32x4_t val[2];
} int32x4x2_t;

typedef struct int64x2x2_t {
  int64x2_t val[2];
} int64x2x2_t;

typedef struct uint8x16x2_t {
  uint8x16_t val[2];
} uint8x16x2_t;

typedef struct uint16x8x2_t {
  uint16x8_t val[2];
} uint16x8x2_t;

typedef struct uint32x4x2_t {
  uint32x4_t val[2];
} uint32x4x2_t;

typedef struct uint64x2x2_t {
  uint64x2_t val[2];
} uint64x2x2_t;

typedef struct float32x4x2_t {
  float32x4_t val[2];
} float32x4x2_t;

typedef struct poly8x16x2_t {
  poly8x16_t val[2];
} poly8x16x2_t;

typedef struct poly16x8x2_t {
  poly16x8_t val[2];
} poly16x8x2_t;

typedef struct int8x16x3_t {
  int8x16_t val[3];
} int8x16x3_t;

typedef struct int16x8x3_t {
  int16x8_t val[3];
} int16x8x3_t;

typedef struct int32x4x3_t {
  int32x4_t val[3];
} int32x4x3_t;

typedef struct int64x2x3_t {
  int64x2_t val[3];
} int64x2x3_t;

typedef struct uint8x16x3_t {
  uint8x16_t val[3];
} uint8x16x3_t;

typedef struct uint16x8x3_t {
  uint16x8_t val[3];
} uint16x8x3_t;

typedef struct uint32x4x3_t {
  uint32x4_t val[3];
} uint32x4x3_t;

typedef struct uint64x2x3_t {
  uint64x2_t val[3];
} uint64x2x3_t;

typedef struct float32x4x3_t {
  float32x4_t val[3];
} float32x4x3_t;

typedef struct poly8x16x3_t {
  poly8x16_t val[3];
} poly8x16x3_t;

typedef struct poly16x8x3_t {
  poly16x8_t val[3];
} poly16x8x3_t;

typedef struct int8x16x4_t {
  int8x16_t val[4];
} int8x16x4_t;

typedef struct int16x8x4_t {
  int16x8_t val[4];
} int16x8x4_t;

typedef struct int32x4x4_t {
  int32x4_t val[4];
} int32x4x4_t;

typedef struct int64x2x4_t {
  int64x2_t val[4];
} int64x2x4_t;

typedef struct uint8x16x4_t {
  uint8x16_t val[4];
} uint8x16x4_t;

typedef struct uint16x8x4_t {
  uint16x8_t val[4];
} uint16x8x4_t;

typedef struct uint32x4x4_t {
  uint32x4_t val[4];
} uint32x4x4_t;

typedef struct uint64x2x4_t {
  uint64x2_t val[4];
} uint64x2x4_t;

typedef struct float32x4x4_t {
  float32x4_t val[4];
} float32x4x4_t;

typedef struct poly8x16x4_t {
  poly8x16_t val[4];
} poly8x16x4_t;

typedef struct poly16x8x4_t {
  poly16x8_t val[4];
} poly16x8x4_t;

extern int npCanUseSIMD();

extern int8x16_t np_vaddq_s8(int8x16_t a, int8x16_t b);
#define vaddq_s8 np_vaddq_s8
extern int16x8_t np_vaddq_s16(int16x8_t a, int16x8_t b);
#define vaddq_s16 np_vaddq_s16
extern int32x4_t np_vaddq_s32(int32x4_t a, int32x4_t b);
#define vaddq_s32 np_vaddq_s32
extern int64x2_t np_vaddq_s64(int64x2_t a, int64x2_t b);
#define vaddq_s64 np_vaddq_s64
extern float32x4_t np_vaddq_f32(float32x4_t a, float32x4_t b);
#define vaddq_f32 np_vaddq_f32
extern uint8x16_t np_vaddq_u8(uint8x16_t a, uint8x16_t b);
#define vaddq_u8 np_vaddq_u8
extern uint16x8_t np_vaddq_u16(uint16x8_t a, uint16x8_t b);
#define vaddq_u16 np_vaddq_u16
extern uint32x4_t np_vaddq_u32(uint32x4_t a, uint32x4_t b);
#define vaddq_u32 np_vaddq_u32
extern uint64x2_t np_vaddq_u64(uint64x2_t a, uint64x2_t b);
#define vaddq_u64 np_vaddq_u64
extern int8x16_t np_vhaddq_s8(int8x16_t a, int8x16_t b);
#define vhaddq_s8 np_vhaddq_s8
extern int16x8_t np_vhaddq_s16(int16x8_t a, int16x8_t b);
#define vhaddq_s16 np_vhaddq_s16
extern int32x4_t np_vhaddq_s32(int32x4_t a, int32x4_t b);
#define vhaddq_s32 np_vhaddq_s32
extern uint8x16_t np_vhaddq_u8(uint8x16_t a, uint8x16_t b);
#define vhaddq_u8 np_vhaddq_u8
extern uint16x8_t np_vhaddq_u16(uint16x8_t a, uint16x8_t b);
#define vhaddq_u16 np_vhaddq_u16
extern uint32x4_t np_vhaddq_u32(uint32x4_t a, uint32x4_t b);
#define vhaddq_u32 np_vhaddq_u32
extern int8x16_t np_vrhaddq_s8(int8x16_t a, int8x16_t b);
#define vrhaddq_s8 np_vrhaddq_s8
extern int16x8_t np_vrhaddq_s16(int16x8_t a, int16x8_t b);
#define vrhaddq_s16 np_vrhaddq_s16
extern int32x4_t np_vrhaddq_s32(int32x4_t a, int32x4_t b);
#define vrhaddq_s32 np_vrhaddq_s32
extern uint8x16_t np_vrhaddq_u8(uint8x16_t a, uint8x16_t b);
#define vrhaddq_u8 np_vrhaddq_u8
extern uint16x8_t np_vrhaddq_u16(uint16x8_t a, uint16x8_t b);
#define vrhaddq_u16 np_vrhaddq_u16
extern uint32x4_t np_vrhaddq_u32(uint32x4_t a, uint32x4_t b);
#define vrhaddq_u32 np_vrhaddq_u32
extern int8x16_t np_vqaddq_s8(int8x16_t a, int8x16_t b);
#define vqaddq_s8 np_vqaddq_s8
extern int16x8_t np_vqaddq_s16(int16x8_t a, int16x8_t b);
#define vqaddq_s16 np_vqaddq_s16
extern int32x4_t np_vqaddq_s32(int32x4_t a, int32x4_t b);
#define vqaddq_s32 np_vqaddq_s32
extern int64x2_t np_vqaddq_s64(int64x2_t a, int64x2_t b);
#define vqaddq_s64 np_vqaddq_s64
extern uint8x16_t np_vqaddq_u8(uint8x16_t a, uint8x16_t b);
#define vqaddq_u8 np_vqaddq_u8
extern uint16x8_t np_vqaddq_u16(uint16x8_t a, uint16x8_t b);
#define vqaddq_u16 np_vqaddq_u16
extern uint32x4_t np_vqaddq_u32(uint32x4_t a, uint32x4_t b);
#define vqaddq_u32 np_vqaddq_u32
extern uint64x2_t np_vqaddq_u64(uint64x2_t a, uint64x2_t b);
#define vqaddq_u64 np_vqaddq_u64
extern int8x16_t np_vmulq_s8(int8x16_t a, int8x16_t b);
#define vmulq_s8 np_vmulq_s8
extern int16x8_t np_vmulq_s16(int16x8_t a, int16x8_t b);
#define vmulq_s16 np_vmulq_s16
extern int32x4_t np_vmulq_s32(int32x4_t a, int32x4_t b);
#define vmulq_s32 np_vmulq_s32
extern float32x4_t np_vmulq_f32(float32x4_t a, float32x4_t b);
#define vmulq_f32 np_vmulq_f32
extern uint8x16_t np_vmulq_u8(uint8x16_t a, uint8x16_t b);
#define vmulq_u8 np_vmulq_u8
extern uint16x8_t np_vmulq_u16(uint16x8_t a, uint16x8_t b);
#define vmulq_u16 np_vmulq_u16
extern uint32x4_t np_vmulq_u32(uint32x4_t a, uint32x4_t b);
#define vmulq_u32 np_vmulq_u32
extern poly8x16_t np_vmulq_p8(poly8x16_t a, poly8x16_t b);
#define vmulq_p8 np_vmulq_p8
extern int8x16_t np_vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c);
#define vmlaq_s8 np_vmlaq_s8
extern int16x8_t np_vmlaq_s16(int16x8_t a, int16x8_t b, int16x8_t c);
#define vmlaq_s16 np_vmlaq_s16
extern int32x4_t np_vmlaq_s32(int32x4_t a, int32x4_t b, int32x4_t c);
#define vmlaq_s32 np_vmlaq_s32
extern float32x4_t np_vmlaq_f32(float32x4_t a, float32x4_t b, float32x4_t c);
#define vmlaq_f32 np_vmlaq_f32
extern uint8x16_t np_vmlaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c);
#define vmlaq_u8 np_vmlaq_u8
extern uint16x8_t np_vmlaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c);
#define vmlaq_u16 np_vmlaq_u16
extern uint32x4_t np_vmlaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c);
#define vmlaq_u32 np_vmlaq_u32
extern int8x16_t np_vmlsq_s8(int8x16_t a, int8x16_t b, int8x16_t c);
#define vmlsq_s8 np_vmlsq_s8
extern int16x8_t np_vmlsq_s16(int16x8_t a, int16x8_t b, int16x8_t c);
#define vmlsq_s16 np_vmlsq_s16
extern int32x4_t np_vmlsq_s32(int32x4_t a, int32x4_t b, int32x4_t c);
#define vmlsq_s32 np_vmlsq_s32
extern float32x4_t np_vmlsq_f32(float32x4_t a, float32x4_t b, float32x4_t c);
#define vmlsq_f32 np_vmlsq_f32
extern uint8x16_t np_vmlsq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c);
#define vmlsq_u8 np_vmlsq_u8
extern uint16x8_t np_vmlsq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c);
#define vmlsq_u16 np_vmlsq_u16
extern uint32x4_t np_vmlsq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c);
#define vmlsq_u32 np_vmlsq_u32
extern int16x8_t np_vqdmulhq_s16(int16x8_t a, int16x8_t b);
#define vqdmulhq_s16 np_vqdmulhq_s16
extern int32x4_t np_vqdmulhq_s32(int32x4_t a, int32x4_t b);
#define vqdmulhq_s32 np_vqdmulhq_s32
extern int16x8_t np_vqrdmulhq_s16(int16x8_t a, int16x8_t b);
#define vqrdmulhq_s16 np_vqrdmulhq_s16
extern int32x4_t np_vqrdmulhq_s32(int32x4_t a, int32x4_t b);
#define vqrdmulhq_s32 np_vqrdmulhq_s32
extern int8x16_t np_vsubq_s8(int8x16_t a, int8x16_t b);
#define vsubq_s8 np_vsubq_s8
extern int16x8_t np_vsubq_s16(int16x8_t a, int16x8_t b);
#define vsubq_s16 np_vsubq_s16
extern int32x4_t np_vsubq_s32(int32x4_t a, int32x4_t b);
#define vsubq_s32 np_vsubq_s32
extern int64x2_t np_vsubq_s64(int64x2_t a, int64x2_t b);
#define vsubq_s64 np_vsubq_s64
extern float32x4_t np_vsubq_f32(float32x4_t a, float32x4_t b);
#define vsubq_f32 np_vsubq_f32
extern uint8x16_t np_vsubq_u8(uint8x16_t a, uint8x16_t b);
#define vsubq_u8 np_vsubq_u8
extern uint16x8_t np_vsubq_u16(uint16x8_t a, uint16x8_t b);
#define vsubq_u16 np_vsubq_u16
extern uint32x4_t np_vsubq_u32(uint32x4_t a, uint32x4_t b);
#define vsubq_u32 np_vsubq_u32
extern uint64x2_t np_vsubq_u64(uint64x2_t a, uint64x2_t b);
#define vsubq_u64 np_vsubq_u64
extern int8x16_t np_vqsubq_s8(int8x16_t a, int8x16_t b);
#define vqsubq_s8 np_vqsubq_s8
extern int16x8_t np_vqsubq_s16(int16x8_t a, int16x8_t b);
#define vqsubq_s16 np_vqsubq_s16
extern int32x4_t np_vqsubq_s32(int32x4_t a, int32x4_t b);
#define vqsubq_s32 np_vqsubq_s32
extern int64x2_t np_vqsubq_s64(int64x2_t a, int64x2_t b);
#define vqsubq_s64 np_vqsubq_s64
extern uint8x16_t np_vqsubq_u8(uint8x16_t a, uint8x16_t b);
#define vqsubq_u8 np_vqsubq_u8
extern uint16x8_t np_vqsubq_u16(uint16x8_t a, uint16x8_t b);
#define vqsubq_u16 np_vqsubq_u16
extern uint32x4_t np_vqsubq_u32(uint32x4_t a, uint32x4_t b);
#define vqsubq_u32 np_vqsubq_u32
extern uint64x2_t np_vqsubq_u64(uint64x2_t a, uint64x2_t b);
#define vqsubq_u64 np_vqsubq_u64
extern int8x16_t np_vhsubq_s8(int8x16_t a, int8x16_t b);
#define vhsubq_s8 np_vhsubq_s8
extern int16x8_t np_vhsubq_s16(int16x8_t a, int16x8_t b);
#define vhsubq_s16 np_vhsubq_s16
extern int32x4_t np_vhsubq_s32(int32x4_t a, int32x4_t b);
#define vhsubq_s32 np_vhsubq_s32
extern uint8x16_t np_vhsubq_u8(uint8x16_t a, uint8x16_t b);
#define vhsubq_u8 np_vhsubq_u8
extern uint16x8_t np_vhsubq_u16(uint16x8_t a, uint16x8_t b);
#define vhsubq_u16 np_vhsubq_u16
extern uint32x4_t np_vhsubq_u32(uint32x4_t a, uint32x4_t b);
#define vhsubq_u32 np_vhsubq_u32
extern uint8x16_t np_vceqq_s8(int8x16_t a, int8x16_t b);
#define vceqq_s8 np_vceqq_s8
extern uint16x8_t np_vceqq_s16(int16x8_t a, int16x8_t b);
#define vceqq_s16 np_vceqq_s16
extern uint32x4_t np_vceqq_s32(int32x4_t a, int32x4_t b);
#define vceqq_s32 np_vceqq_s32
extern uint32x4_t np_vceqq_f32(float32x4_t a, float32x4_t b);
#define vceqq_f32 np_vceqq_f32
extern uint8x16_t np_vceqq_u8(uint8x16_t a, uint8x16_t b);
#define vceqq_u8 np_vceqq_u8
extern uint16x8_t np_vceqq_u16(uint16x8_t a, uint16x8_t b);
#define vceqq_u16 np_vceqq_u16
extern uint32x4_t np_vceqq_u32(uint32x4_t a, uint32x4_t b);
#define vceqq_u32 np_vceqq_u32
extern uint8x16_t np_vceqq_p8(poly8x16_t a, poly8x16_t b);
#define vceqq_p8 np_vceqq_p8
extern uint8x16_t np_vcgeq_s8(int8x16_t a, int8x16_t b);
#define vcgeq_s8 np_vcgeq_s8
extern uint16x8_t np_vcgeq_s16(int16x8_t a, int16x8_t b);
#define vcgeq_s16 np_vcgeq_s16
extern uint32x4_t np_vcgeq_s32(int32x4_t a, int32x4_t b);
#define vcgeq_s32 np_vcgeq_s32
extern uint32x4_t np_vcgeq_f32(float32x4_t a, float32x4_t b);
#define vcgeq_f32 np_vcgeq_f32
extern uint8x16_t np_vcgeq_u8(uint8x16_t a, uint8x16_t b);
#define vcgeq_u8 np_vcgeq_u8
extern uint16x8_t np_vcgeq_u16(uint16x8_t a, uint16x8_t b);
#define vcgeq_u16 np_vcgeq_u16
extern uint32x4_t np_vcgeq_u32(uint32x4_t a, uint32x4_t b);
#define vcgeq_u32 np_vcgeq_u32
extern uint8x16_t np_vcleq_s8(int8x16_t a, int8x16_t b);
#define vcleq_s8 np_vcleq_s8
extern uint16x8_t np_vcleq_s16(int16x8_t a, int16x8_t b);
#define vcleq_s16 np_vcleq_s16
extern uint32x4_t np_vcleq_s32(int32x4_t a, int32x4_t b);
#define vcleq_s32 np_vcleq_s32
extern uint32x4_t np_vcleq_f32(float32x4_t a, float32x4_t b);
#define vcleq_f32 np_vcleq_f32
extern uint8x16_t np_vcleq_u8(uint8x16_t a, uint8x16_t b);
#define vcleq_u8 np_vcleq_u8
extern uint16x8_t np_vcleq_u16(uint16x8_t a, uint16x8_t b);
#define vcleq_u16 np_vcleq_u16
extern uint32x4_t np_vcleq_u32(uint32x4_t a, uint32x4_t b);
#define vcleq_u32 np_vcleq_u32
extern uint8x16_t np_vcgtq_s8(int8x16_t a, int8x16_t b);
#define vcgtq_s8 np_vcgtq_s8
extern uint16x8_t np_vcgtq_s16(int16x8_t a, int16x8_t b);
#define vcgtq_s16 np_vcgtq_s16
extern uint32x4_t np_vcgtq_s32(int32x4_t a, int32x4_t b);
#define vcgtq_s32 np_vcgtq_s32
extern uint32x4_t np_vcgtq_f32(float32x4_t a, float32x4_t b);
#define vcgtq_f32 np_vcgtq_f32
extern uint8x16_t np_vcgtq_u8(uint8x16_t a, uint8x16_t b);
#define vcgtq_u8 np_vcgtq_u8
extern uint16x8_t np_vcgtq_u16(uint16x8_t a, uint16x8_t b);
#define vcgtq_u16 np_vcgtq_u16
extern uint32x4_t np_vcgtq_u32(uint32x4_t a, uint32x4_t b);
#define vcgtq_u32 np_vcgtq_u32
extern uint8x16_t np_vcltq_s8(int8x16_t a, int8x16_t b);
#define vcltq_s8 np_vcltq_s8
extern uint16x8_t np_vcltq_s16(int16x8_t a, int16x8_t b);
#define vcltq_s16 np_vcltq_s16
extern uint32x4_t np_vcltq_s32(int32x4_t a, int32x4_t b);
#define vcltq_s32 np_vcltq_s32
extern uint32x4_t np_vcltq_f32(float32x4_t a, float32x4_t b);
#define vcltq_f32 np_vcltq_f32
extern uint8x16_t np_vcltq_u8(uint8x16_t a, uint8x16_t b);
#define vcltq_u8 np_vcltq_u8
extern uint16x8_t np_vcltq_u16(uint16x8_t a, uint16x8_t b);
#define vcltq_u16 np_vcltq_u16
extern uint32x4_t np_vcltq_u32(uint32x4_t a, uint32x4_t b);
#define vcltq_u32 np_vcltq_u32
extern uint8x16_t np_vtstq_s8(int8x16_t a, int8x16_t b);
#define vtstq_s8 np_vtstq_s8
extern uint16x8_t np_vtstq_s16(int16x8_t a, int16x8_t b);
#define vtstq_s16 np_vtstq_s16
extern uint32x4_t np_vtstq_s32(int32x4_t a, int32x4_t b);
#define vtstq_s32 np_vtstq_s32
extern uint8x16_t np_vtstq_u8(uint8x16_t a, uint8x16_t b);
#define vtstq_u8 np_vtstq_u8
extern uint16x8_t np_vtstq_u16(uint16x8_t a, uint16x8_t b);
#define vtstq_u16 np_vtstq_u16
extern uint32x4_t np_vtstq_u32(uint32x4_t a, uint32x4_t b);
#define vtstq_u32 np_vtstq_u32
extern uint8x16_t np_vtstq_p8(poly8x16_t a, poly8x16_t b);
#define vtstq_p8 np_vtstq_p8
extern int8x16_t np_vabdq_s8(int8x16_t a, int8x16_t b);
#define vabdq_s8 np_vabdq_s8
extern int16x8_t np_vabdq_s16(int16x8_t a, int16x8_t b);
#define vabdq_s16 np_vabdq_s16
extern int32x4_t np_vabdq_s32(int32x4_t a, int32x4_t b);
#define vabdq_s32 np_vabdq_s32
extern uint8x16_t np_vabdq_u8(uint8x16_t a, uint8x16_t b);
#define vabdq_u8 np_vabdq_u8
extern uint16x8_t np_vabdq_u16(uint16x8_t a, uint16x8_t b);
#define vabdq_u16 np_vabdq_u16
extern uint32x4_t np_vabdq_u32(uint32x4_t a, uint32x4_t b);
#define vabdq_u32 np_vabdq_u32
extern float32x4_t np_vabdq_f32(float32x4_t a, float32x4_t b);
#define vabdq_f32 np_vabdq_f32
extern int8x16_t np_vabaq_s8(int8x16_t a, int8x16_t b, int8x16_t c);
#define vabaq_s8 np_vabaq_s8
extern int16x8_t np_vabaq_s16(int16x8_t a, int16x8_t b, int16x8_t c);
#define vabaq_s16 np_vabaq_s16
extern int32x4_t np_vabaq_s32(int32x4_t a, int32x4_t b, int32x4_t c);
#define vabaq_s32 np_vabaq_s32
extern uint8x16_t np_vabaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c);
#define vabaq_u8 np_vabaq_u8
extern uint16x8_t np_vabaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c);
#define vabaq_u16 np_vabaq_u16
extern uint32x4_t np_vabaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c);
#define vabaq_u32 np_vabaq_u32
extern int8x16_t np_vmaxq_s8(int8x16_t a, int8x16_t b);
#define vmaxq_s8 np_vmaxq_s8
extern int16x8_t np_vmaxq_s16(int16x8_t a, int16x8_t b);
#define vmaxq_s16 np_vmaxq_s16
extern int32x4_t np_vmaxq_s32(int32x4_t a, int32x4_t b);
#define vmaxq_s32 np_vmaxq_s32
extern uint8x16_t np_vmaxq_u8(uint8x16_t a, uint8x16_t b);
#define vmaxq_u8 np_vmaxq_u8
extern uint16x8_t np_vmaxq_u16(uint16x8_t a, uint16x8_t b);
#define vmaxq_u16 np_vmaxq_u16
extern uint32x4_t np_vmaxq_u32(uint32x4_t a, uint32x4_t b);
#define vmaxq_u32 np_vmaxq_u32
extern float32x4_t np_vmaxq_f32(float32x4_t a, float32x4_t b);
#define vmaxq_f32 np_vmaxq_f32
extern int8x16_t np_vminq_s8(int8x16_t a, int8x16_t b);
#define vminq_s8 np_vminq_s8
extern int16x8_t np_vminq_s16(int16x8_t a, int16x8_t b);
#define vminq_s16 np_vminq_s16
extern int32x4_t np_vminq_s32(int32x4_t a, int32x4_t b);
#define vminq_s32 np_vminq_s32
extern uint8x16_t np_vminq_u8(uint8x16_t a, uint8x16_t b);
#define vminq_u8 np_vminq_u8
extern uint16x8_t np_vminq_u16(uint16x8_t a, uint16x8_t b);
#define vminq_u16 np_vminq_u16
extern uint32x4_t np_vminq_u32(uint32x4_t a, uint32x4_t b);
#define vminq_u32 np_vminq_u32
extern float32x4_t np_vminq_f32(float32x4_t a, float32x4_t b);
#define vminq_f32 np_vminq_f32
extern int16x8_t np_vpaddlq_s8(int8x16_t a);
#define vpaddlq_s8 np_vpaddlq_s8
extern int32x4_t np_vpaddlq_s16(int16x8_t a);
#define vpaddlq_s16 np_vpaddlq_s16
extern int64x2_t np_vpaddlq_s32(int32x4_t a);
#define vpaddlq_s32 np_vpaddlq_s32
extern uint16x8_t np_vpaddlq_u8(uint8x16_t a);
#define vpaddlq_u8 np_vpaddlq_u8
extern uint32x4_t np_vpaddlq_u16(uint16x8_t a);
#define vpaddlq_u16 np_vpaddlq_u16
extern uint64x2_t np_vpaddlq_u32(uint32x4_t a);
#define vpaddlq_u32 np_vpaddlq_u32
extern int16x8_t np_vpadalq_s8(int16x8_t a, int8x16_t b);
#define vpadalq_s8 np_vpadalq_s8
extern int32x4_t np_vpadalq_s16(int32x4_t a, int16x8_t b);
#define vpadalq_s16 np_vpadalq_s16
extern int64x2_t np_vpadalq_s32(int64x2_t a, int32x4_t b);
#define vpadalq_s32 np_vpadalq_s32
extern uint16x8_t np_vpadalq_u8(uint16x8_t a, uint8x16_t b);
#define vpadalq_u8 np_vpadalq_u8
extern uint32x4_t np_vpadalq_u16(uint32x4_t a, uint16x8_t b);
#define vpadalq_u16 np_vpadalq_u16
extern uint64x2_t np_vpadalq_u32(uint64x2_t a, uint32x4_t b);
#define vpadalq_u32 np_vpadalq_u32
extern float32x4_t np_vrecpsq_f32(float32x4_t a, float32x4_t b);
#define vrecpsq_f32 np_vrecpsq_f32
extern float32x4_t np_vrsqrtsq_f32(float32x4_t a, float32x4_t b);
#define vrsqrtsq_f32 np_vrsqrtsq_f32
extern int8x16_t np_vshlq_s8(int8x16_t a, int8x16_t b);
#define vshlq_s8 np_vshlq_s8
extern int16x8_t np_vshlq_s16(int16x8_t a, int16x8_t b);
#define vshlq_s16 np_vshlq_s16
extern int32x4_t np_vshlq_s32(int32x4_t a, int32x4_t b);
#define vshlq_s32 np_vshlq_s32
extern int64x2_t np_vshlq_s64(int64x2_t a, int64x2_t b);
#define vshlq_s64 np_vshlq_s64
extern uint8x16_t np_vshlq_u8(uint8x16_t a, int8x16_t b);
#define vshlq_u8 np_vshlq_u8
extern uint16x8_t np_vshlq_u16(uint16x8_t a, int16x8_t b);
#define vshlq_u16 np_vshlq_u16
extern uint32x4_t np_vshlq_u32(uint32x4_t a, int32x4_t b);
#define vshlq_u32 np_vshlq_u32
extern uint64x2_t np_vshlq_u64(uint64x2_t a, int64x2_t b);
#define vshlq_u64 np_vshlq_u64
extern int8x16_t np_vqshlq_s8(int8x16_t a, int8x16_t b);
#define vqshlq_s8 np_vqshlq_s8
extern int16x8_t np_vqshlq_s16(int16x8_t a, int16x8_t b);
#define vqshlq_s16 np_vqshlq_s16
extern int32x4_t np_vqshlq_s32(int32x4_t a, int32x4_t b);
#define vqshlq_s32 np_vqshlq_s32
extern int64x2_t np_vqshlq_s64(int64x2_t a, int64x2_t b);
#define vqshlq_s64 np_vqshlq_s64
extern uint8x16_t np_vqshlq_u8(uint8x16_t a, int8x16_t b);
#define vqshlq_u8 np_vqshlq_u8
extern uint16x8_t np_vqshlq_u16(uint16x8_t a, int16x8_t b);
#define vqshlq_u16 np_vqshlq_u16
extern uint32x4_t np_vqshlq_u32(uint32x4_t a, int32x4_t b);
#define vqshlq_u32 np_vqshlq_u32
extern uint64x2_t np_vqshlq_u64(uint64x2_t a, int64x2_t b);
#define vqshlq_u64 np_vqshlq_u64
extern int8x16_t np_vrshlq_s8(int8x16_t a, int8x16_t b);
#define vrshlq_s8 np_vrshlq_s8
extern int16x8_t np_vrshlq_s16(int16x8_t a, int16x8_t b);
#define vrshlq_s16 np_vrshlq_s16
extern int32x4_t np_vrshlq_s32(int32x4_t a, int32x4_t b);
#define vrshlq_s32 np_vrshlq_s32
extern int64x2_t np_vrshlq_s64(int64x2_t a, int64x2_t b);
#define vrshlq_s64 np_vrshlq_s64
extern uint8x16_t np_vrshlq_u8(uint8x16_t a, int8x16_t b);
#define vrshlq_u8 np_vrshlq_u8
extern uint16x8_t np_vrshlq_u16(uint16x8_t a, int16x8_t b);
#define vrshlq_u16 np_vrshlq_u16
extern uint32x4_t np_vrshlq_u32(uint32x4_t a, int32x4_t b);
#define vrshlq_u32 np_vrshlq_u32
extern uint64x2_t np_vrshlq_u64(uint64x2_t a, int64x2_t b);
#define vrshlq_u64 np_vrshlq_u64
extern int8x16_t np_vqrshlq_s8(int8x16_t a, int8x16_t b);
#define vqrshlq_s8 np_vqrshlq_s8
extern int16x8_t np_vqrshlq_s16(int16x8_t a, int16x8_t b);
#define vqrshlq_s16 np_vqrshlq_s16
extern int32x4_t np_vqrshlq_s32(int32x4_t a, int32x4_t b);
#define vqrshlq_s32 np_vqrshlq_s32
extern int64x2_t np_vqrshlq_s64(int64x2_t a, int64x2_t b);
#define vqrshlq_s64 np_vqrshlq_s64
extern uint8x16_t np_vqrshlq_u8(uint8x16_t a, int8x16_t b);
#define vqrshlq_u8 np_vqrshlq_u8
extern uint16x8_t np_vqrshlq_u16(uint16x8_t a, int16x8_t b);
#define vqrshlq_u16 np_vqrshlq_u16
extern uint32x4_t np_vqrshlq_u32(uint32x4_t a, int32x4_t b);
#define vqrshlq_u32 np_vqrshlq_u32
extern uint64x2_t np_vqrshlq_u64(uint64x2_t a, int64x2_t b);
#define vqrshlq_u64 np_vqrshlq_u64
extern uint8x16_t np_vld1q_u8(uint8_t const * ptr);
#define vld1q_u8 np_vld1q_u8
extern uint16x8_t np_vld1q_u16(uint16_t const * ptr);
#define vld1q_u16 np_vld1q_u16
extern uint32x4_t np_vld1q_u32(uint32_t const * ptr);
#define vld1q_u32 np_vld1q_u32
extern uint64x2_t np_vld1q_u64(uint64_t const * ptr);
#define vld1q_u64 np_vld1q_u64
extern int8x16_t np_vld1q_s8(int8_t const * ptr);
#define vld1q_s8 np_vld1q_s8
extern int16x8_t np_vld1q_s16(int16_t const * ptr);
#define vld1q_s16 np_vld1q_s16
extern int32x4_t np_vld1q_s32(int32_t const * ptr);
#define vld1q_s32 np_vld1q_s32
extern int64x2_t np_vld1q_s64(int64_t const * ptr);
#define vld1q_s64 np_vld1q_s64
extern float32x4_t np_vld1q_f32(float32_t const * ptr);
#define vld1q_f32 np_vld1q_f32
extern poly8x16_t np_vld1q_p8(poly8_t const * ptr);
#define vld1q_p8 np_vld1q_p8
extern poly16x8_t np_vld1q_p16(poly16_t const * ptr);
#define vld1q_p16 np_vld1q_p16
extern uint8x16_t np_vld1q_dup_u8(uint8_t const * ptr);
#define vld1q_dup_u8 np_vld1q_dup_u8
extern uint16x8_t np_vld1q_dup_u16(uint16_t const * ptr);
#define vld1q_dup_u16 np_vld1q_dup_u16
extern uint32x4_t np_vld1q_dup_u32(uint32_t const * ptr);
#define vld1q_dup_u32 np_vld1q_dup_u32
extern int8x16_t np_vld1q_dup_s8(int8_t const * ptr);
#define vld1q_dup_s8 np_vld1q_dup_s8
extern int16x8_t np_vld1q_dup_s16(int16_t const * ptr);
#define vld1q_dup_s16 np_vld1q_dup_s16
extern int32x4_t np_vld1q_dup_s32(int32_t const * ptr);
#define vld1q_dup_s32 np_vld1q_dup_s32
extern float32x4_t np_vld1q_dup_f32(float32_t const * ptr);
#define vld1q_dup_f32 np_vld1q_dup_f32
extern poly8x16_t np_vld1q_dup_p8(poly8_t const * ptr);
#define vld1q_dup_p8 np_vld1q_dup_p8
extern poly16x8_t np_vld1q_dup_p16(poly16_t const * ptr);
#define vld1q_dup_p16 np_vld1q_dup_p16
extern uint8x16x2_t np_vld2q_u8(uint8_t const * ptr);
#define vld2q_u8 np_vld2q_u8
extern uint16x8x2_t np_vld2q_u16(uint16_t const * ptr);
#define vld2q_u16 np_vld2q_u16
extern uint32x4x2_t np_vld2q_u32(uint32_t const * ptr);
#define vld2q_u32 np_vld2q_u32
extern int8x16x2_t np_vld2q_s8(int8_t const * ptr);
#define vld2q_s8 np_vld2q_s8
extern int16x8x2_t np_vld2q_s16(int16_t const * ptr);
#define vld2q_s16 np_vld2q_s16
extern int32x4x2_t np_vld2q_s32(int32_t const * ptr);
#define vld2q_s32 np_vld2q_s32
extern float32x4x2_t np_vld2q_f32(float32_t const * ptr);
#define vld2q_f32 np_vld2q_f32
extern poly8x16x2_t np_vld2q_p8(poly8_t const * ptr);
#define vld2q_p8 np_vld2q_p8
extern poly16x8x2_t np_vld2q_p16(poly16_t const * ptr);
#define vld2q_p16 np_vld2q_p16
extern uint8x16x3_t np_vld3q_u8(uint8_t const * ptr);
#define vld3q_u8 np_vld3q_u8
extern uint16x8x3_t np_vld3q_u16(uint16_t const * ptr);
#define vld3q_u16 np_vld3q_u16
extern uint32x4x3_t np_vld3q_u32(uint32_t const * ptr);
#define vld3q_u32 np_vld3q_u32
extern int8x16x3_t np_vld3q_s8(int8_t const * ptr);
#define vld3q_s8 np_vld3q_s8
extern int16x8x3_t np_vld3q_s16(int16_t const * ptr);
#define vld3q_s16 np_vld3q_s16
extern int32x4x3_t np_vld3q_s32(int32_t const * ptr);
#define vld3q_s32 np_vld3q_s32
extern float32x4x3_t np_vld3q_f32(float32_t const * ptr);
#define vld3q_f32 np_vld3q_f32
extern poly8x16x3_t np_vld3q_p8(poly8_t const * ptr);
#define vld3q_p8 np_vld3q_p8
extern poly16x8x3_t np_vld3q_p16(poly16_t const * ptr);
#define vld3q_p16 np_vld3q_p16
extern uint8x16x4_t np_vld4q_u8(uint8_t const * ptr);
#define vld4q_u8 np_vld4q_u8
extern uint16x8x4_t np_vld4q_u16(uint16_t const * ptr);
#define vld4q_u16 np_vld4q_u16
extern uint32x4x4_t np_vld4q_u32(uint32_t const * ptr);
#define vld4q_u32 np_vld4q_u32
extern int8x16x4_t np_vld4q_s8(int8_t const * ptr);
#define vld4q_s8 np_vld4q_s8
extern int16x8x4_t np_vld4q_s16(int16_t const * ptr);
#define vld4q_s16 np_vld4q_s16
extern int32x4x4_t np_vld4q_s32(int32_t const * ptr);
#define vld4q_s32 np_vld4q_s32
extern float32x4x4_t np_vld4q_f32(float32_t const * ptr);
#define vld4q_f32 np_vld4q_f32
extern poly8x16x4_t np_vld4q_p8(poly8_t const * ptr);
#define vld4q_p8 np_vld4q_p8
extern poly16x8x4_t np_vld4q_p16(poly16_t const * ptr);
#define vld4q_p16 np_vld4q_p16
extern uint8x16_t np_vdupq_n_u8(uint8_t value);
#define vdupq_n_u8 np_vdupq_n_u8
extern uint16x8_t np_vdupq_n_u16(uint16_t value);
#define vdupq_n_u16 np_vdupq_n_u16
extern uint32x4_t np_vdupq_n_u32(uint32_t value);
#define vdupq_n_u32 np_vdupq_n_u32
extern int8x16_t np_vdupq_n_s8(int8_t value);
#define vdupq_n_s8 np_vdupq_n_s8
extern int16x8_t np_vdupq_n_s16(int16_t value);
#define vdupq_n_s16 np_vdupq_n_s16
extern int32x4_t np_vdupq_n_s32(int32_t value);
#define vdupq_n_s32 np_vdupq_n_s32
extern poly8x16_t np_vdupq_n_p8(poly8_t value);
#define vdupq_n_p8 np_vdupq_n_p8
extern poly16x8_t np_vdupq_n_p16(poly16_t value);
#define vdupq_n_p16 np_vdupq_n_p16
extern float32x4_t np_vdupq_n_f32(float32_t value);
#define vdupq_n_f32 np_vdupq_n_f32
extern int64x2_t np_vdupq_n_s64(int64_t value);
#define vdupq_n_s64 np_vdupq_n_s64
extern uint64x2_t np_vdupq_n_u64(uint64_t value);
#define vdupq_n_u64 np_vdupq_n_u64
extern uint8x16_t np_vmovq_n_u8(uint8_t value);
#define vmovq_n_u8 np_vmovq_n_u8
extern uint16x8_t np_vmovq_n_u16(uint16_t value);
#define vmovq_n_u16 np_vmovq_n_u16
extern uint32x4_t np_vmovq_n_u32(uint32_t value);
#define vmovq_n_u32 np_vmovq_n_u32
extern int8x16_t np_vmovq_n_s8(int8_t value);
#define vmovq_n_s8 np_vmovq_n_s8
extern int16x8_t np_vmovq_n_s16(int16_t value);
#define vmovq_n_s16 np_vmovq_n_s16
extern int32x4_t np_vmovq_n_s32(int32_t value);
#define vmovq_n_s32 np_vmovq_n_s32
extern poly8x16_t np_vmovq_n_p8(poly8_t value);
#define vmovq_n_p8 np_vmovq_n_p8
extern poly16x8_t np_vmovq_n_p16(poly16_t value);
#define vmovq_n_p16 np_vmovq_n_p16
extern float32x4_t np_vmovq_n_f32(float32_t value);
#define vmovq_n_f32 np_vmovq_n_f32
extern int64x2_t np_vmovq_n_s64(int64_t value);
#define vmovq_n_s64 np_vmovq_n_s64
extern uint64x2_t np_vmovq_n_u64(uint64_t value);
#define vmovq_n_u64 np_vmovq_n_u64
extern int32x4_t np_vcvtq_s32_f32(float32x4_t a);
#define vcvtq_s32_f32 np_vcvtq_s32_f32
extern uint32x4_t np_vcvtq_u32_f32(float32x4_t a);
#define vcvtq_u32_f32 np_vcvtq_u32_f32
extern float32x4_t np_vcvtq_f32_s32(int32x4_t a);
#define vcvtq_f32_s32 np_vcvtq_f32_s32
extern float32x4_t np_vcvtq_f32_u32(uint32x4_t a);
#define vcvtq_f32_u32 np_vcvtq_f32_u32
extern int16x8_t np_vmulq_n_s16(int16x8_t a, int16_t b);
#define vmulq_n_s16 np_vmulq_n_s16
extern int32x4_t np_vmulq_n_s32(int32x4_t a, int32_t b);
#define vmulq_n_s32 np_vmulq_n_s32
extern float32x4_t np_vmulq_n_f32(float32x4_t a, float32_t b);
#define vmulq_n_f32 np_vmulq_n_f32
extern uint16x8_t np_vmulq_n_u16(uint16x8_t a, uint16_t b);
#define vmulq_n_u16 np_vmulq_n_u16
extern uint32x4_t np_vmulq_n_u32(uint32x4_t a, uint32_t b);
#define vmulq_n_u32 np_vmulq_n_u32
extern int16x8_t np_vqdmulhq_n_s16(int16x8_t vec1, int16_t val2);
#define vqdmulhq_n_s16 np_vqdmulhq_n_s16
extern int32x4_t np_vqdmulhq_n_s32(int32x4_t vec1, int32_t val2);
#define vqdmulhq_n_s32 np_vqdmulhq_n_s32
extern int16x8_t np_vqrdmulhq_n_s16(int16x8_t vec1, int16_t val2);
#define vqrdmulhq_n_s16 np_vqrdmulhq_n_s16
extern int32x4_t np_vqrdmulhq_n_s32(int32x4_t vec1, int32_t val2);
#define vqrdmulhq_n_s32 np_vqrdmulhq_n_s32
extern int16x8_t np_vmlaq_n_s16(int16x8_t a, int16x8_t b, int16_t c);
#define vmlaq_n_s16 np_vmlaq_n_s16
extern int32x4_t np_vmlaq_n_s32(int32x4_t a, int32x4_t b, int32_t c);
#define vmlaq_n_s32 np_vmlaq_n_s32
extern uint16x8_t np_vmlaq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c);
#define vmlaq_n_u16 np_vmlaq_n_u16
extern uint32x4_t np_vmlaq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c);
#define vmlaq_n_u32 np_vmlaq_n_u32
extern float32x4_t np_vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c);
#define vmlaq_n_f32 np_vmlaq_n_f32
extern int16x8_t np_vmlsq_n_s16(int16x8_t a, int16x8_t b, int16_t c);
#define vmlsq_n_s16 np_vmlsq_n_s16
extern int32x4_t np_vmlsq_n_s32(int32x4_t a, int32x4_t b, int32_t c);
#define vmlsq_n_s32 np_vmlsq_n_s32
extern uint16x8_t np_vmlsq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c);
#define vmlsq_n_u16 np_vmlsq_n_u16
extern uint32x4_t np_vmlsq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c);
#define vmlsq_n_u32 np_vmlsq_n_u32
extern float32x4_t np_vmlsq_n_f32(float32x4_t a, float32x4_t b, float32_t c);
#define vmlsq_n_f32 np_vmlsq_n_f32
extern int8x16_t np_vrev64q_s8(int8x16_t vec);
#define vrev64q_s8 np_vrev64q_s8
extern int16x8_t np_vrev64q_s16(int16x8_t vec);
#define vrev64q_s16 np_vrev64q_s16
extern int32x4_t np_vrev64q_s32(int32x4_t vec);
#define vrev64q_s32 np_vrev64q_s32
extern uint8x16_t np_vrev64q_u8(uint8x16_t vec);
#define vrev64q_u8 np_vrev64q_u8
extern uint16x8_t np_vrev64q_u16(uint16x8_t vec);
#define vrev64q_u16 np_vrev64q_u16
extern uint32x4_t np_vrev64q_u32(uint32x4_t vec);
#define vrev64q_u32 np_vrev64q_u32
extern poly8x16_t np_vrev64q_p8(poly8x16_t vec);
#define vrev64q_p8 np_vrev64q_p8
extern poly16x8_t np_vrev64q_p16(poly16x8_t vec);
#define vrev64q_p16 np_vrev64q_p16
extern float32x4_t np_vrev64q_f32(float32x4_t vec);
#define vrev64q_f32 np_vrev64q_f32
extern int8x16_t np_vrev32q_s8(int8x16_t vec);
#define vrev32q_s8 np_vrev32q_s8
extern int16x8_t np_vrev32q_s16(int16x8_t vec);
#define vrev32q_s16 np_vrev32q_s16
extern uint8x16_t np_vrev32q_u8(uint8x16_t vec);
#define vrev32q_u8 np_vrev32q_u8
extern uint16x8_t np_vrev32q_u16(uint16x8_t vec);
#define vrev32q_u16 np_vrev32q_u16
extern poly8x16_t np_vrev32q_p8(poly8x16_t vec);
#define vrev32q_p8 np_vrev32q_p8
extern poly16x8_t np_vrev32q_p16(poly16x8_t vec);
#define vrev32q_p16 np_vrev32q_p16
extern int8x16_t np_vrev16q_s8(int8x16_t vec);
#define vrev16q_s8 np_vrev16q_s8
extern uint8x16_t np_vrev16q_u8(uint8x16_t vec);
#define vrev16q_u8 np_vrev16q_u8
extern poly8x16_t np_vrev16q_p8(poly8x16_t vec);
#define vrev16q_p8 np_vrev16q_p8
extern int8x16_t np_vabsq_s8(int8x16_t a);
#define vabsq_s8 np_vabsq_s8
extern int16x8_t np_vabsq_s16(int16x8_t a);
#define vabsq_s16 np_vabsq_s16
extern int32x4_t np_vabsq_s32(int32x4_t a);
#define vabsq_s32 np_vabsq_s32
extern float32x4_t np_vabsq_f32(float32x4_t a);
#define vabsq_f32 np_vabsq_f32
extern int8x16_t np_vqabsq_s8(int8x16_t a);
#define vqabsq_s8 np_vqabsq_s8
extern int16x8_t np_vqabsq_s16(int16x8_t a);
#define vqabsq_s16 np_vqabsq_s16
extern int32x4_t np_vqabsq_s32(int32x4_t a);
#define vqabsq_s32 np_vqabsq_s32
extern int8x16_t np_vnegq_s8(int8x16_t a);
#define vnegq_s8 np_vnegq_s8
extern int16x8_t np_vnegq_s16(int16x8_t a);
#define vnegq_s16 np_vnegq_s16
extern int32x4_t np_vnegq_s32(int32x4_t a);
#define vnegq_s32 np_vnegq_s32
extern float32x4_t np_vnegq_f32(float32x4_t a);
#define vnegq_f32 np_vnegq_f32
extern int8x16_t np_vqnegq_s8(int8x16_t a);
#define vqnegq_s8 np_vqnegq_s8
extern int16x8_t np_vqnegq_s16(int16x8_t a);
#define vqnegq_s16 np_vqnegq_s16
extern int32x4_t np_vqnegq_s32(int32x4_t a);
#define vqnegq_s32 np_vqnegq_s32
extern int8x16_t np_vclsq_s8(int8x16_t a);
#define vclsq_s8 np_vclsq_s8
extern int16x8_t np_vclsq_s16(int16x8_t a);
#define vclsq_s16 np_vclsq_s16
extern int32x4_t np_vclsq_s32(int32x4_t a);
#define vclsq_s32 np_vclsq_s32
extern int8x16_t np_vclzq_s8(int8x16_t a);
#define vclzq_s8 np_vclzq_s8
extern int16x8_t np_vclzq_s16(int16x8_t a);
#define vclzq_s16 np_vclzq_s16
extern int32x4_t np_vclzq_s32(int32x4_t a);
#define vclzq_s32 np_vclzq_s32
extern uint8x16_t np_vclzq_u8(uint8x16_t a);
#define vclzq_u8 np_vclzq_u8
extern uint16x8_t np_vclzq_u16(uint16x8_t a);
#define vclzq_u16 np_vclzq_u16
extern uint32x4_t np_vclzq_u32(uint32x4_t a);
#define vclzq_u32 np_vclzq_u32
extern uint8x16_t np_vcntq_u8(uint8x16_t a);
#define vcntq_u8 np_vcntq_u8
extern int8x16_t np_vcntq_s8(int8x16_t a);
#define vcntq_s8 np_vcntq_s8
extern poly8x16_t np_vcntq_p8(poly8x16_t a);
#define vcntq_p8 np_vcntq_p8
extern float32x4_t np_vrecpeq_f32(float32x4_t a);
#define vrecpeq_f32 np_vrecpeq_f32
extern uint32x4_t np_vrecpeq_u32(uint32x4_t a);
#define vrecpeq_u32 np_vrecpeq_u32
extern float32x4_t np_vrsqrteq_f32(float32x4_t a);
#define vrsqrteq_f32 np_vrsqrteq_f32
extern uint32x4_t np_vrsqrteq_u32(uint32x4_t a);
#define vrsqrteq_u32 np_vrsqrteq_u32
extern int8x16_t np_vmvnq_s8(int8x16_t a);
#define vmvnq_s8 np_vmvnq_s8
extern int16x8_t np_vmvnq_s16(int16x8_t a);
#define vmvnq_s16 np_vmvnq_s16
extern int32x4_t np_vmvnq_s32(int32x4_t a);
#define vmvnq_s32 np_vmvnq_s32
extern uint8x16_t np_vmvnq_u8(uint8x16_t a);
#define vmvnq_u8 np_vmvnq_u8
extern uint16x8_t np_vmvnq_u16(uint16x8_t a);
#define vmvnq_u16 np_vmvnq_u16
extern uint32x4_t np_vmvnq_u32(uint32x4_t a);
#define vmvnq_u32 np_vmvnq_u32
extern poly8x16_t np_vmvnq_p8(poly8x16_t a);
#define vmvnq_p8 np_vmvnq_p8
extern int8x16_t np_vandq_s8(int8x16_t a, int8x16_t b);
#define vandq_s8 np_vandq_s8
extern int16x8_t np_vandq_s16(int16x8_t a, int16x8_t b);
#define vandq_s16 np_vandq_s16
extern int32x4_t np_vandq_s32(int32x4_t a, int32x4_t b);
#define vandq_s32 np_vandq_s32
extern int64x2_t np_vandq_s64(int64x2_t a, int64x2_t b);
#define vandq_s64 np_vandq_s64
extern uint8x16_t np_vandq_u8(uint8x16_t a, uint8x16_t b);
#define vandq_u8 np_vandq_u8
extern uint16x8_t np_vandq_u16(uint16x8_t a, uint16x8_t b);
#define vandq_u16 np_vandq_u16
extern uint32x4_t np_vandq_u32(uint32x4_t a, uint32x4_t b);
#define vandq_u32 np_vandq_u32
extern uint64x2_t np_vandq_u64(uint64x2_t a, uint64x2_t b);
#define vandq_u64 np_vandq_u64
extern int8x16_t np_vorrq_s8(int8x16_t a, int8x16_t b);
#define vorrq_s8 np_vorrq_s8
extern int16x8_t np_vorrq_s16(int16x8_t a, int16x8_t b);
#define vorrq_s16 np_vorrq_s16
extern int32x4_t np_vorrq_s32(int32x4_t a, int32x4_t b);
#define vorrq_s32 np_vorrq_s32
extern int64x2_t np_vorrq_s64(int64x2_t a, int64x2_t b);
#define vorrq_s64 np_vorrq_s64
extern uint8x16_t np_vorrq_u8(uint8x16_t a, uint8x16_t b);
#define vorrq_u8 np_vorrq_u8
extern uint16x8_t np_vorrq_u16(uint16x8_t a, uint16x8_t b);
#define vorrq_u16 np_vorrq_u16
extern uint32x4_t np_vorrq_u32(uint32x4_t a, uint32x4_t b);
#define vorrq_u32 np_vorrq_u32
extern uint64x2_t np_vorrq_u64(uint64x2_t a, uint64x2_t b);
#define vorrq_u64 np_vorrq_u64
extern int8x16_t np_veorq_s8(int8x16_t a, int8x16_t b);
#define veorq_s8 np_veorq_s8
extern int16x8_t np_veorq_s16(int16x8_t a, int16x8_t b);
#define veorq_s16 np_veorq_s16
extern int32x4_t np_veorq_s32(int32x4_t a, int32x4_t b);
#define veorq_s32 np_veorq_s32
extern int64x2_t np_veorq_s64(int64x2_t a, int64x2_t b);
#define veorq_s64 np_veorq_s64
extern uint8x16_t np_veorq_u8(uint8x16_t a, uint8x16_t b);
#define veorq_u8 np_veorq_u8
extern uint16x8_t np_veorq_u16(uint16x8_t a, uint16x8_t b);
#define veorq_u16 np_veorq_u16
extern uint32x4_t np_veorq_u32(uint32x4_t a, uint32x4_t b);
#define veorq_u32 np_veorq_u32
extern uint64x2_t np_veorq_u64(uint64x2_t a, uint64x2_t b);
#define veorq_u64 np_veorq_u64
extern int8x16_t np_vbicq_s8(int8x16_t a, int8x16_t b);
#define vbicq_s8 np_vbicq_s8
extern int16x8_t np_vbicq_s16(int16x8_t a, int16x8_t b);
#define vbicq_s16 np_vbicq_s16
extern int32x4_t np_vbicq_s32(int32x4_t a, int32x4_t b);
#define vbicq_s32 np_vbicq_s32
extern int64x2_t np_vbicq_s64(int64x2_t a, int64x2_t b);
#define vbicq_s64 np_vbicq_s64
extern uint8x16_t np_vbicq_u8(uint8x16_t a, uint8x16_t b);
#define vbicq_u8 np_vbicq_u8
extern uint16x8_t np_vbicq_u16(uint16x8_t a, uint16x8_t b);
#define vbicq_u16 np_vbicq_u16
extern uint32x4_t np_vbicq_u32(uint32x4_t a, uint32x4_t b);
#define vbicq_u32 np_vbicq_u32
extern uint64x2_t np_vbicq_u64(uint64x2_t a, uint64x2_t b);
#define vbicq_u64 np_vbicq_u64
extern int8x16_t np_vornq_s8(int8x16_t a, int8x16_t b);
#define vornq_s8 np_vornq_s8
extern int16x8_t np_vornq_s16(int16x8_t a, int16x8_t b);
#define vornq_s16 np_vornq_s16
extern int32x4_t np_vornq_s32(int32x4_t a, int32x4_t b);
#define vornq_s32 np_vornq_s32
extern int64x2_t np_vornq_s64(int64x2_t a, int64x2_t b);
#define vornq_s64 np_vornq_s64
extern uint8x16_t np_vornq_u8(uint8x16_t a, uint8x16_t b);
#define vornq_u8 np_vornq_u8
extern uint16x8_t np_vornq_u16(uint16x8_t a, uint16x8_t b);
#define vornq_u16 np_vornq_u16
extern uint32x4_t np_vornq_u32(uint32x4_t a, uint32x4_t b);
#define vornq_u32 np_vornq_u32
extern uint64x2_t np_vornq_u64(uint64x2_t a, uint64x2_t b);
#define vornq_u64 np_vornq_u64
extern int8x16_t np_vbslq_s8(uint8x16_t a, int8x16_t b, int8x16_t c);
#define vbslq_s8 np_vbslq_s8
extern int16x8_t np_vbslq_s16(uint16x8_t a, int16x8_t b, int16x8_t c);
#define vbslq_s16 np_vbslq_s16
extern int32x4_t np_vbslq_s32(uint32x4_t a, int32x4_t b, int32x4_t c);
#define vbslq_s32 np_vbslq_s32
extern int64x2_t np_vbslq_s64(uint64x2_t a, int64x2_t b, int64x2_t c);
#define vbslq_s64 np_vbslq_s64
extern uint8x16_t np_vbslq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c);
#define vbslq_u8 np_vbslq_u8
extern uint16x8_t np_vbslq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c);
#define vbslq_u16 np_vbslq_u16
extern uint32x4_t np_vbslq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c);
#define vbslq_u32 np_vbslq_u32
extern uint64x2_t np_vbslq_u64(uint64x2_t a, uint64x2_t b, uint64x2_t c);
#define vbslq_u64 np_vbslq_u64
extern float32x4_t np_vbslq_f32(uint32x4_t a, float32x4_t b, float32x4_t c);
#define vbslq_f32 np_vbslq_f32
extern poly8x16_t np_vbslq_p8(uint8x16_t a, poly8x16_t b, poly8x16_t c);
#define vbslq_p8 np_vbslq_p8
extern poly16x8_t np_vbslq_p16(uint16x8_t a, poly16x8_t b, poly16x8_t c);
#define vbslq_p16 np_vbslq_p16
extern int8x16x2_t np_vtrnq_s8(int8x16_t a, int8x16_t b);
#define vtrnq_s8 np_vtrnq_s8
extern int16x8x2_t np_vtrnq_s16(int16x8_t a, int16x8_t b);
#define vtrnq_s16 np_vtrnq_s16
extern int32x4x2_t np_vtrnq_s32(int32x4_t a, int32x4_t b);
#define vtrnq_s32 np_vtrnq_s32
extern uint8x16x2_t np_vtrnq_u8(uint8x16_t a, uint8x16_t b);
#define vtrnq_u8 np_vtrnq_u8
extern uint16x8x2_t np_vtrnq_u16(uint16x8_t a, uint16x8_t b);
#define vtrnq_u16 np_vtrnq_u16
extern uint32x4x2_t np_vtrnq_u32(uint32x4_t a, uint32x4_t b);
#define vtrnq_u32 np_vtrnq_u32
extern float32x4x2_t np_vtrnq_f32(float32x4_t a, float32x4_t b);
#define vtrnq_f32 np_vtrnq_f32
extern poly8x16x2_t np_vtrnq_p8(poly8x16_t a, poly8x16_t b);
#define vtrnq_p8 np_vtrnq_p8
extern poly16x8x2_t np_vtrnq_p16(poly16x8_t a, poly16x8_t b);
#define vtrnq_p16 np_vtrnq_p16
extern int8x16x2_t np_vzipq_s8(int8x16_t a, int8x16_t b);
#define vzipq_s8 np_vzipq_s8
extern int16x8x2_t np_vzipq_s16(int16x8_t a, int16x8_t b);
#define vzipq_s16 np_vzipq_s16
extern int32x4x2_t np_vzipq_s32(int32x4_t a, int32x4_t b);
#define vzipq_s32 np_vzipq_s32
extern uint8x16x2_t np_vzipq_u8(uint8x16_t a, uint8x16_t b);
#define vzipq_u8 np_vzipq_u8
extern uint16x8x2_t np_vzipq_u16(uint16x8_t a, uint16x8_t b);
#define vzipq_u16 np_vzipq_u16
extern uint32x4x2_t np_vzipq_u32(uint32x4_t a, uint32x4_t b);
#define vzipq_u32 np_vzipq_u32
extern float32x4x2_t np_vzipq_f32(float32x4_t a, float32x4_t b);
#define vzipq_f32 np_vzipq_f32
extern poly8x16x2_t np_vzipq_p8(poly8x16_t a, poly8x16_t b);
#define vzipq_p8 np_vzipq_p8
extern poly16x8x2_t np_vzipq_p16(poly16x8_t a, poly16x8_t b);
#define vzipq_p16 np_vzipq_p16
extern int8x16x2_t np_vuzpq_s8(int8x16_t a, int8x16_t b);
#define vuzpq_s8 np_vuzpq_s8
extern int16x8x2_t np_vuzpq_s16(int16x8_t a, int16x8_t b);
#define vuzpq_s16 np_vuzpq_s16
extern int32x4x2_t np_vuzpq_s32(int32x4_t a, int32x4_t b);
#define vuzpq_s32 np_vuzpq_s32
extern uint8x16x2_t np_vuzpq_u8(uint8x16_t a, uint8x16_t b);
#define vuzpq_u8 np_vuzpq_u8
extern uint16x8x2_t np_vuzpq_u16(uint16x8_t a, uint16x8_t b);
#define vuzpq_u16 np_vuzpq_u16
extern uint32x4x2_t np_vuzpq_u32(uint32x4_t a, uint32x4_t b);
#define vuzpq_u32 np_vuzpq_u32
extern float32x4x2_t np_vuzpq_f32(float32x4_t a, float32x4_t b);
#define vuzpq_f32 np_vuzpq_f32
extern poly8x16x2_t np_vuzpq_p8(poly8x16_t a, poly8x16_t b);
#define vuzpq_p8 np_vuzpq_p8
extern poly16x8x2_t np_vuzpq_p16(poly16x8_t a, poly16x8_t b);
#define vuzpq_p16 np_vuzpq_p16

#endif