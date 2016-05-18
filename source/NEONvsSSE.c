#ifndef NO_INTRINSICS

#ifdef _WIN32
	#define NATIVE_PATH_WIN
	//define something for Windows (32-bit and 64-bit, this part is common)
	#ifdef _M_ARM
		#include <arm_neon.h>
	#else
		#include <NEONvsSSE.h>
	#endif

	#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
	// This code is for Win32 desktop apps
	#define NATIVE_PATH_WIN_DESKTOP
	#else
	// This code is for WinRT Windows Store apps
	#define NATIVE_PATH_WIN_APP
	#endif

	#ifdef _WIN64
	  //define something for Windows (64-bit only)
	#endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
        #define NATIVE_PATH_IOS
         // iOS Simulator
        #include <NEONvsSSE.h>
    #elif TARGET_OS_IPHONE
        #define NATIVE_PATH_IOS
        #include <stdio.h>
        #include <arm_neon.h>
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
    #   error "Unknown Apple platform"
    #endif
#elif defined(__ANDROID__)
	#define NATIVE_PATH_ANDROID
	#include <stdio.h>
	#ifdef __USE_NEON__
	#include <arm_neon.h>
	#else
	#include <NEONvsSSE.h>
	#endif
#elif __linux__
	#define NATIVE_PATH_LINUX
	#include <stdio.h>
	#include <NEONvsSSE.h>
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

int npCanUseSIMD()
{
	return 1;
}

int8x16_t np_vaddq_s8(int8x16_t a, int8x16_t b)
{
	return vaddq_s8(a, b);
}

int16x8_t np_vaddq_s16(int16x8_t a, int16x8_t b)
{
	return vaddq_s16(a, b);
}

int32x4_t np_vaddq_s32(int32x4_t a, int32x4_t b)
{
	return vaddq_s32(a, b);
}

int64x2_t np_vaddq_s64(int64x2_t a, int64x2_t b)
{
	return vaddq_s64(a, b);
}

float32x4_t np_vaddq_f32(float32x4_t a, float32x4_t b)
{
	return vaddq_f32(a, b);
}

uint8x16_t np_vaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vaddq_u8(a, b);
}

uint16x8_t np_vaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vaddq_u16(a, b);
}

uint32x4_t np_vaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vaddq_u32(a, b);
}

uint64x2_t np_vaddq_u64(uint64x2_t a, uint64x2_t b)
{
	return vaddq_u64(a, b);
}

int8x16_t np_vhaddq_s8(int8x16_t a, int8x16_t b)
{
	return vhaddq_s8(a, b);
}

int16x8_t np_vhaddq_s16(int16x8_t a, int16x8_t b)
{
	return vhaddq_s16(a, b);
}

int32x4_t np_vhaddq_s32(int32x4_t a, int32x4_t b)
{
	return vhaddq_s32(a, b);
}

uint8x16_t np_vhaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vhaddq_u8(a, b);
}

uint16x8_t np_vhaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vhaddq_u16(a, b);
}

uint32x4_t np_vhaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vhaddq_u32(a, b);
}

int8x16_t np_vrhaddq_s8(int8x16_t a, int8x16_t b)
{
	return vrhaddq_s8(a, b);
}

int16x8_t np_vrhaddq_s16(int16x8_t a, int16x8_t b)
{
	return vrhaddq_s16(a, b);
}

int32x4_t np_vrhaddq_s32(int32x4_t a, int32x4_t b)
{
	return vrhaddq_s32(a, b);
}

uint8x16_t np_vrhaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vrhaddq_u8(a, b);
}

uint16x8_t np_vrhaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vrhaddq_u16(a, b);
}

uint32x4_t np_vrhaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vrhaddq_u32(a, b);
}

int8x16_t np_vqaddq_s8(int8x16_t a, int8x16_t b)
{
	return vqaddq_s8(a, b);
}

int16x8_t np_vqaddq_s16(int16x8_t a, int16x8_t b)
{
	return vqaddq_s16(a, b);
}

int32x4_t np_vqaddq_s32(int32x4_t a, int32x4_t b)
{
	return vqaddq_s32(a, b);
}

int64x2_t np_vqaddq_s64(int64x2_t a, int64x2_t b)
{
	return vqaddq_s64(a, b);
}

uint8x16_t np_vqaddq_u8(uint8x16_t a, uint8x16_t b)
{
	return vqaddq_u8(a, b);
}

uint16x8_t np_vqaddq_u16(uint16x8_t a, uint16x8_t b)
{
	return vqaddq_u16(a, b);
}

uint32x4_t np_vqaddq_u32(uint32x4_t a, uint32x4_t b)
{
	return vqaddq_u32(a, b);
}

uint64x2_t np_vqaddq_u64(uint64x2_t a, uint64x2_t b)
{
	return vqaddq_u64(a, b);
}

int8x16_t np_vmulq_s8(int8x16_t a, int8x16_t b)
{
	return vmulq_s8(a, b);
}

int16x8_t np_vmulq_s16(int16x8_t a, int16x8_t b)
{
	return vmulq_s16(a, b);
}

int32x4_t np_vmulq_s32(int32x4_t a, int32x4_t b)
{
	return vmulq_s32(a, b);
}

float32x4_t np_vmulq_f32(float32x4_t a, float32x4_t b)
{
	return vmulq_f32(a, b);
}

uint8x16_t np_vmulq_u8(uint8x16_t a, uint8x16_t b)
{
	return vmulq_u8(a, b);
}

uint16x8_t np_vmulq_u16(uint16x8_t a, uint16x8_t b)
{
	return vmulq_u16(a, b);
}

uint32x4_t np_vmulq_u32(uint32x4_t a, uint32x4_t b)
{
	return vmulq_u32(a, b);
}

poly8x16_t np_vmulq_p8(poly8x16_t a, poly8x16_t b)
{
	return vmulq_p8(a, b);
}

int8x16_t np_vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
{
	return vmlaq_s8(a, b, c);
}

int16x8_t np_vmlaq_s16(int16x8_t a, int16x8_t b, int16x8_t c)
{
	return vmlaq_s16(a, b, c);
}

int32x4_t np_vmlaq_s32(int32x4_t a, int32x4_t b, int32x4_t c)
{
	return vmlaq_s32(a, b, c);
}

float32x4_t np_vmlaq_f32(float32x4_t a, float32x4_t b, float32x4_t c)
{
	return vmlaq_f32(a, b, c);
}

uint8x16_t np_vmlaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vmlaq_u8(a, b, c);
}

uint16x8_t np_vmlaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vmlaq_u16(a, b, c);
}

uint32x4_t np_vmlaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vmlaq_u32(a, b, c);
}

int8x16_t np_vmlsq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
{
	return vmlsq_s8(a, b, c);
}

int16x8_t np_vmlsq_s16(int16x8_t a, int16x8_t b, int16x8_t c)
{
	return vmlsq_s16(a, b, c);
}

int32x4_t np_vmlsq_s32(int32x4_t a, int32x4_t b, int32x4_t c)
{
	return vmlsq_s32(a, b, c);
}

float32x4_t np_vmlsq_f32(float32x4_t a, float32x4_t b, float32x4_t c)
{
	return vmlsq_f32(a, b, c);
}

uint8x16_t np_vmlsq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vmlsq_u8(a, b, c);
}

uint16x8_t np_vmlsq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vmlsq_u16(a, b, c);
}

uint32x4_t np_vmlsq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vmlsq_u32(a, b, c);
}

int16x8_t np_vqdmulhq_s16(int16x8_t a, int16x8_t b)
{
	return vqdmulhq_s16(a, b);
}

int32x4_t np_vqdmulhq_s32(int32x4_t a, int32x4_t b)
{
	return vqdmulhq_s32(a, b);
}

int16x8_t np_vqrdmulhq_s16(int16x8_t a, int16x8_t b)
{
	return vqrdmulhq_s16(a, b);
}

int32x4_t np_vqrdmulhq_s32(int32x4_t a, int32x4_t b)
{
	return vqrdmulhq_s32(a, b);
}

int8x16_t np_vsubq_s8(int8x16_t a, int8x16_t b)
{
	return vsubq_s8(a, b);
}

int16x8_t np_vsubq_s16(int16x8_t a, int16x8_t b)
{
	return vsubq_s16(a, b);
}

int32x4_t np_vsubq_s32(int32x4_t a, int32x4_t b)
{
	return vsubq_s32(a, b);
}

int64x2_t np_vsubq_s64(int64x2_t a, int64x2_t b)
{
	return vsubq_s64(a, b);
}

float32x4_t np_vsubq_f32(float32x4_t a, float32x4_t b)
{
	return vsubq_f32(a, b);
}

uint8x16_t np_vsubq_u8(uint8x16_t a, uint8x16_t b)
{
	return vsubq_u8(a, b);
}

uint16x8_t np_vsubq_u16(uint16x8_t a, uint16x8_t b)
{
	return vsubq_u16(a, b);
}

uint32x4_t np_vsubq_u32(uint32x4_t a, uint32x4_t b)
{
	return vsubq_u32(a, b);
}

uint64x2_t np_vsubq_u64(uint64x2_t a, uint64x2_t b)
{
	return vsubq_u64(a, b);
}

int8x16_t np_vqsubq_s8(int8x16_t a, int8x16_t b)
{
	return vqsubq_s8(a, b);
}

int16x8_t np_vqsubq_s16(int16x8_t a, int16x8_t b)
{
	return vqsubq_s16(a, b);
}

int32x4_t np_vqsubq_s32(int32x4_t a, int32x4_t b)
{
	return vqsubq_s32(a, b);
}

int64x2_t np_vqsubq_s64(int64x2_t a, int64x2_t b)
{
	return vqsubq_s64(a, b);
}

uint8x16_t np_vqsubq_u8(uint8x16_t a, uint8x16_t b)
{
	return vqsubq_u8(a, b);
}

uint16x8_t np_vqsubq_u16(uint16x8_t a, uint16x8_t b)
{
	return vqsubq_u16(a, b);
}

uint32x4_t np_vqsubq_u32(uint32x4_t a, uint32x4_t b)
{
	return vqsubq_u32(a, b);
}

uint64x2_t np_vqsubq_u64(uint64x2_t a, uint64x2_t b)
{
	return vqsubq_u64(a, b);
}

int8x16_t np_vhsubq_s8(int8x16_t a, int8x16_t b)
{
	return vhsubq_s8(a, b);
}

int16x8_t np_vhsubq_s16(int16x8_t a, int16x8_t b)
{
	return vhsubq_s16(a, b);
}

int32x4_t np_vhsubq_s32(int32x4_t a, int32x4_t b)
{
	return vhsubq_s32(a, b);
}

uint8x16_t np_vhsubq_u8(uint8x16_t a, uint8x16_t b)
{
	return vhsubq_u8(a, b);
}

uint16x8_t np_vhsubq_u16(uint16x8_t a, uint16x8_t b)
{
	return vhsubq_u16(a, b);
}

uint32x4_t np_vhsubq_u32(uint32x4_t a, uint32x4_t b)
{
	return vhsubq_u32(a, b);
}

uint8x16_t np_vceqq_s8(int8x16_t a, int8x16_t b)
{
	return vceqq_s8(a, b);
}

uint16x8_t np_vceqq_s16(int16x8_t a, int16x8_t b)
{
	return vceqq_s16(a, b);
}

uint32x4_t np_vceqq_s32(int32x4_t a, int32x4_t b)
{
	return vceqq_s32(a, b);
}

uint32x4_t np_vceqq_f32(float32x4_t a, float32x4_t b)
{
	return vceqq_f32(a, b);
}

uint8x16_t np_vceqq_u8(uint8x16_t a, uint8x16_t b)
{
	return vceqq_u8(a, b);
}

uint16x8_t np_vceqq_u16(uint16x8_t a, uint16x8_t b)
{
	return vceqq_u16(a, b);
}

uint32x4_t np_vceqq_u32(uint32x4_t a, uint32x4_t b)
{
	return vceqq_u32(a, b);
}

uint8x16_t np_vceqq_p8(poly8x16_t a, poly8x16_t b)
{
	return vceqq_p8(a, b);
}

uint8x16_t np_vcgeq_s8(int8x16_t a, int8x16_t b)
{
	return vcgeq_s8(a, b);
}

uint16x8_t np_vcgeq_s16(int16x8_t a, int16x8_t b)
{
	return vcgeq_s16(a, b);
}

uint32x4_t np_vcgeq_s32(int32x4_t a, int32x4_t b)
{
	return vcgeq_s32(a, b);
}

uint32x4_t np_vcgeq_f32(float32x4_t a, float32x4_t b)
{
	return vcgeq_f32(a, b);
}

uint8x16_t np_vcgeq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcgeq_u8(a, b);
}

uint16x8_t np_vcgeq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcgeq_u16(a, b);
}

uint32x4_t np_vcgeq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcgeq_u32(a, b);
}

uint8x16_t np_vcleq_s8(int8x16_t a, int8x16_t b)
{
	return vcleq_s8(a, b);
}

uint16x8_t np_vcleq_s16(int16x8_t a, int16x8_t b)
{
	return vcleq_s16(a, b);
}

uint32x4_t np_vcleq_s32(int32x4_t a, int32x4_t b)
{
	return vcleq_s32(a, b);
}

uint32x4_t np_vcleq_f32(float32x4_t a, float32x4_t b)
{
	return vcleq_f32(a, b);
}

uint8x16_t np_vcleq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcleq_u8(a, b);
}

uint16x8_t np_vcleq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcleq_u16(a, b);
}

uint32x4_t np_vcleq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcleq_u32(a, b);
}

uint8x16_t np_vcgtq_s8(int8x16_t a, int8x16_t b)
{
	return vcgtq_s8(a, b);
}

uint16x8_t np_vcgtq_s16(int16x8_t a, int16x8_t b)
{
	return vcgtq_s16(a, b);
}

uint32x4_t np_vcgtq_s32(int32x4_t a, int32x4_t b)
{
	return vcgtq_s32(a, b);
}

uint32x4_t np_vcgtq_f32(float32x4_t a, float32x4_t b)
{
	return vcgtq_f32(a, b);
}

uint8x16_t np_vcgtq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcgtq_u8(a, b);
}

uint16x8_t np_vcgtq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcgtq_u16(a, b);
}

uint32x4_t np_vcgtq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcgtq_u32(a, b);
}

uint8x16_t np_vcltq_s8(int8x16_t a, int8x16_t b)
{
	return vcltq_s8(a, b);
}

uint16x8_t np_vcltq_s16(int16x8_t a, int16x8_t b)
{
	return vcltq_s16(a, b);
}

uint32x4_t np_vcltq_s32(int32x4_t a, int32x4_t b)
{
	return vcltq_s32(a, b);
}

uint32x4_t np_vcltq_f32(float32x4_t a, float32x4_t b)
{
	return vcltq_f32(a, b);
}

uint8x16_t np_vcltq_u8(uint8x16_t a, uint8x16_t b)
{
	return vcltq_u8(a, b);
}

uint16x8_t np_vcltq_u16(uint16x8_t a, uint16x8_t b)
{
	return vcltq_u16(a, b);
}

uint32x4_t np_vcltq_u32(uint32x4_t a, uint32x4_t b)
{
	return vcltq_u32(a, b);
}

uint8x16_t np_vtstq_s8(int8x16_t a, int8x16_t b)
{
	return vtstq_s8(a, b);
}

uint16x8_t np_vtstq_s16(int16x8_t a, int16x8_t b)
{
	return vtstq_s16(a, b);
}

uint32x4_t np_vtstq_s32(int32x4_t a, int32x4_t b)
{
	return vtstq_s32(a, b);
}

uint8x16_t np_vtstq_u8(uint8x16_t a, uint8x16_t b)
{
	return vtstq_u8(a, b);
}

uint16x8_t np_vtstq_u16(uint16x8_t a, uint16x8_t b)
{
	return vtstq_u16(a, b);
}

uint32x4_t np_vtstq_u32(uint32x4_t a, uint32x4_t b)
{
	return vtstq_u32(a, b);
}

uint8x16_t np_vtstq_p8(poly8x16_t a, poly8x16_t b)
{
	return vtstq_p8(a, b);
}

int8x16_t np_vabdq_s8(int8x16_t a, int8x16_t b)
{
	return vabdq_s8(a, b);
}

int16x8_t np_vabdq_s16(int16x8_t a, int16x8_t b)
{
	return vabdq_s16(a, b);
}

int32x4_t np_vabdq_s32(int32x4_t a, int32x4_t b)
{
	return vabdq_s32(a, b);
}

uint8x16_t np_vabdq_u8(uint8x16_t a, uint8x16_t b)
{
	return vabdq_u8(a, b);
}

uint16x8_t np_vabdq_u16(uint16x8_t a, uint16x8_t b)
{
	return vabdq_u16(a, b);
}

uint32x4_t np_vabdq_u32(uint32x4_t a, uint32x4_t b)
{
	return vabdq_u32(a, b);
}

float32x4_t np_vabdq_f32(float32x4_t a, float32x4_t b)
{
	return vabdq_f32(a, b);
}

int8x16_t np_vabaq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
{
	return vabaq_s8(a, b, c);
}

int16x8_t np_vabaq_s16(int16x8_t a, int16x8_t b, int16x8_t c)
{
	return vabaq_s16(a, b, c);
}

int32x4_t np_vabaq_s32(int32x4_t a, int32x4_t b, int32x4_t c)
{
	return vabaq_s32(a, b, c);
}

uint8x16_t np_vabaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vabaq_u8(a, b, c);
}

uint16x8_t np_vabaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vabaq_u16(a, b, c);
}

uint32x4_t np_vabaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vabaq_u32(a, b, c);
}

int8x16_t np_vmaxq_s8(int8x16_t a, int8x16_t b)
{
	return vmaxq_s8(a, b);
}

int16x8_t np_vmaxq_s16(int16x8_t a, int16x8_t b)
{
	return vmaxq_s16(a, b);
}

int32x4_t np_vmaxq_s32(int32x4_t a, int32x4_t b)
{
	return vmaxq_s32(a, b);
}

uint8x16_t np_vmaxq_u8(uint8x16_t a, uint8x16_t b)
{
	return vmaxq_u8(a, b);
}

uint16x8_t np_vmaxq_u16(uint16x8_t a, uint16x8_t b)
{
	return vmaxq_u16(a, b);
}

uint32x4_t np_vmaxq_u32(uint32x4_t a, uint32x4_t b)
{
	return vmaxq_u32(a, b);
}

float32x4_t np_vmaxq_f32(float32x4_t a, float32x4_t b)
{
	return vmaxq_f32(a, b);
}

int8x16_t np_vminq_s8(int8x16_t a, int8x16_t b)
{
	return vminq_s8(a, b);
}

int16x8_t np_vminq_s16(int16x8_t a, int16x8_t b)
{
	return vminq_s16(a, b);
}

int32x4_t np_vminq_s32(int32x4_t a, int32x4_t b)
{
	return vminq_s32(a, b);
}

uint8x16_t np_vminq_u8(uint8x16_t a, uint8x16_t b)
{
	return vminq_u8(a, b);
}

uint16x8_t np_vminq_u16(uint16x8_t a, uint16x8_t b)
{
	return vminq_u16(a, b);
}

uint32x4_t np_vminq_u32(uint32x4_t a, uint32x4_t b)
{
	return vminq_u32(a, b);
}

float32x4_t np_vminq_f32(float32x4_t a, float32x4_t b)
{
	return vminq_f32(a, b);
}

int16x8_t np_vpaddlq_s8(int8x16_t a)
{
	return vpaddlq_s8(a);
}

int32x4_t np_vpaddlq_s16(int16x8_t a)
{
	return vpaddlq_s16(a);
}

int64x2_t np_vpaddlq_s32(int32x4_t a)
{
	return vpaddlq_s32(a);
}

uint16x8_t np_vpaddlq_u8(uint8x16_t a)
{
	return vpaddlq_u8(a);
}

uint32x4_t np_vpaddlq_u16(uint16x8_t a)
{
	return vpaddlq_u16(a);
}

uint64x2_t np_vpaddlq_u32(uint32x4_t a)
{
	return vpaddlq_u32(a);
}

int16x8_t np_vpadalq_s8(int16x8_t a, int8x16_t b)
{
	return vpadalq_s8(a, b);
}

int32x4_t np_vpadalq_s16(int32x4_t a, int16x8_t b)
{
	return vpadalq_s16(a, b);
}

int64x2_t np_vpadalq_s32(int64x2_t a, int32x4_t b)
{
	return vpadalq_s32(a, b);
}

uint16x8_t np_vpadalq_u8(uint16x8_t a, uint8x16_t b)
{
	return vpadalq_u8(a, b);
}

uint32x4_t np_vpadalq_u16(uint32x4_t a, uint16x8_t b)
{
	return vpadalq_u16(a, b);
}

uint64x2_t np_vpadalq_u32(uint64x2_t a, uint32x4_t b)
{
	return vpadalq_u32(a, b);
}

float32x4_t np_vrecpsq_f32(float32x4_t a, float32x4_t b)
{
	return vrecpsq_f32(a, b);
}

float32x4_t np_vrsqrtsq_f32(float32x4_t a, float32x4_t b)
{
	return vrsqrtsq_f32(a, b);
}

int8x16_t np_vshlq_s8(int8x16_t a, int8x16_t b)
{
	return vshlq_s8(a, b);
}

int16x8_t np_vshlq_s16(int16x8_t a, int16x8_t b)
{
	return vshlq_s16(a, b);
}

int32x4_t np_vshlq_s32(int32x4_t a, int32x4_t b)
{
	return vshlq_s32(a, b);
}

int64x2_t np_vshlq_s64(int64x2_t a, int64x2_t b)
{
	return vshlq_s64(a, b);
}

uint8x16_t np_vshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vshlq_u8(a, b);
}

uint16x8_t np_vshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vshlq_u16(a, b);
}

uint32x4_t np_vshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vshlq_u32(a, b);
}

uint64x2_t np_vshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vshlq_u64(a, b);
}

int8x16_t np_vqshlq_s8(int8x16_t a, int8x16_t b)
{
	return vqshlq_s8(a, b);
}

int16x8_t np_vqshlq_s16(int16x8_t a, int16x8_t b)
{
	return vqshlq_s16(a, b);
}

int32x4_t np_vqshlq_s32(int32x4_t a, int32x4_t b)
{
	return vqshlq_s32(a, b);
}

int64x2_t np_vqshlq_s64(int64x2_t a, int64x2_t b)
{
	return vqshlq_s64(a, b);
}

uint8x16_t np_vqshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vqshlq_u8(a, b);
}

uint16x8_t np_vqshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vqshlq_u16(a, b);
}

uint32x4_t np_vqshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vqshlq_u32(a, b);
}

uint64x2_t np_vqshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vqshlq_u64(a, b);
}

int8x16_t np_vrshlq_s8(int8x16_t a, int8x16_t b)
{
	return vrshlq_s8(a, b);
}

int16x8_t np_vrshlq_s16(int16x8_t a, int16x8_t b)
{
	return vrshlq_s16(a, b);
}

int32x4_t np_vrshlq_s32(int32x4_t a, int32x4_t b)
{
	return vrshlq_s32(a, b);
}

int64x2_t np_vrshlq_s64(int64x2_t a, int64x2_t b)
{
	return vrshlq_s64(a, b);
}

uint8x16_t np_vrshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vrshlq_u8(a, b);
}

uint16x8_t np_vrshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vrshlq_u16(a, b);
}

uint32x4_t np_vrshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vrshlq_u32(a, b);
}

uint64x2_t np_vrshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vrshlq_u64(a, b);
}

int8x16_t np_vqrshlq_s8(int8x16_t a, int8x16_t b)
{
	return vqrshlq_s8(a, b);
}

int16x8_t np_vqrshlq_s16(int16x8_t a, int16x8_t b)
{
	return vqrshlq_s16(a, b);
}

int32x4_t np_vqrshlq_s32(int32x4_t a, int32x4_t b)
{
	return vqrshlq_s32(a, b);
}

int64x2_t np_vqrshlq_s64(int64x2_t a, int64x2_t b)
{
	return vqrshlq_s64(a, b);
}

uint8x16_t np_vqrshlq_u8(uint8x16_t a, int8x16_t b)
{
	return vqrshlq_u8(a, b);
}

uint16x8_t np_vqrshlq_u16(uint16x8_t a, int16x8_t b)
{
	return vqrshlq_u16(a, b);
}

uint32x4_t np_vqrshlq_u32(uint32x4_t a, int32x4_t b)
{
	return vqrshlq_u32(a, b);
}

uint64x2_t np_vqrshlq_u64(uint64x2_t a, int64x2_t b)
{
	return vqrshlq_u64(a, b);
}

int8x16_t np_vsraq_n_s8(int8x16_t a, int8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_s8(a, b, 1);
		case 2:
			return vsraq_n_s8(a, b, 2);
		case 3:
			return vsraq_n_s8(a, b, 3);
		case 4:
			return vsraq_n_s8(a, b, 4);
		case 5:
			return vsraq_n_s8(a, b, 5);
		case 6:
			return vsraq_n_s8(a, b, 6);
		case 7:
			return vsraq_n_s8(a, b, 7);
		case 8:
			return vsraq_n_s8(a, b, 8);
	}
	return vsraq_n_s8(a, b, 1);
}

int16x8_t np_vsraq_n_s16(int16x8_t a, int16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_s16(a, b, 1);
		case 2:
			return vsraq_n_s16(a, b, 2);
		case 3:
			return vsraq_n_s16(a, b, 3);
		case 4:
			return vsraq_n_s16(a, b, 4);
		case 5:
			return vsraq_n_s16(a, b, 5);
		case 6:
			return vsraq_n_s16(a, b, 6);
		case 7:
			return vsraq_n_s16(a, b, 7);
		case 8:
			return vsraq_n_s16(a, b, 8);
		case 9:
			return vsraq_n_s16(a, b, 9);
		case 10:
			return vsraq_n_s16(a, b, 10);
		case 11:
			return vsraq_n_s16(a, b, 11);
		case 12:
			return vsraq_n_s16(a, b, 12);
		case 13:
			return vsraq_n_s16(a, b, 13);
		case 14:
			return vsraq_n_s16(a, b, 14);
		case 15:
			return vsraq_n_s16(a, b, 15);
		case 16:
			return vsraq_n_s16(a, b, 16);
	}
	return vsraq_n_s16(a, b, 1);
}

int32x4_t np_vsraq_n_s32(int32x4_t a, int32x4_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_s32(a, b, 1);
		case 2:
			return vsraq_n_s32(a, b, 2);
		case 3:
			return vsraq_n_s32(a, b, 3);
		case 4:
			return vsraq_n_s32(a, b, 4);
		case 5:
			return vsraq_n_s32(a, b, 5);
		case 6:
			return vsraq_n_s32(a, b, 6);
		case 7:
			return vsraq_n_s32(a, b, 7);
		case 8:
			return vsraq_n_s32(a, b, 8);
		case 9:
			return vsraq_n_s32(a, b, 9);
		case 10:
			return vsraq_n_s32(a, b, 10);
		case 11:
			return vsraq_n_s32(a, b, 11);
		case 12:
			return vsraq_n_s32(a, b, 12);
		case 13:
			return vsraq_n_s32(a, b, 13);
		case 14:
			return vsraq_n_s32(a, b, 14);
		case 15:
			return vsraq_n_s32(a, b, 15);
		case 16:
			return vsraq_n_s32(a, b, 16);
		case 17:
			return vsraq_n_s32(a, b, 17);
		case 18:
			return vsraq_n_s32(a, b, 18);
		case 19:
			return vsraq_n_s32(a, b, 19);
		case 20:
			return vsraq_n_s32(a, b, 20);
		case 21:
			return vsraq_n_s32(a, b, 21);
		case 22:
			return vsraq_n_s32(a, b, 22);
		case 23:
			return vsraq_n_s32(a, b, 23);
		case 24:
			return vsraq_n_s32(a, b, 24);
		case 25:
			return vsraq_n_s32(a, b, 25);
		case 26:
			return vsraq_n_s32(a, b, 26);
		case 27:
			return vsraq_n_s32(a, b, 27);
		case 28:
			return vsraq_n_s32(a, b, 28);
		case 29:
			return vsraq_n_s32(a, b, 29);
		case 30:
			return vsraq_n_s32(a, b, 30);
		case 31:
			return vsraq_n_s32(a, b, 31);
		case 32:
			return vsraq_n_s32(a, b, 32);
	}
	return vsraq_n_s32(a, b, 1);
}

int64x2_t np_vsraq_n_s64(int64x2_t a, int64x2_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_s64(a, b, 1);
		case 2:
			return vsraq_n_s64(a, b, 2);
		case 3:
			return vsraq_n_s64(a, b, 3);
		case 4:
			return vsraq_n_s64(a, b, 4);
		case 5:
			return vsraq_n_s64(a, b, 5);
		case 6:
			return vsraq_n_s64(a, b, 6);
		case 7:
			return vsraq_n_s64(a, b, 7);
		case 8:
			return vsraq_n_s64(a, b, 8);
		case 9:
			return vsraq_n_s64(a, b, 9);
		case 10:
			return vsraq_n_s64(a, b, 10);
		case 11:
			return vsraq_n_s64(a, b, 11);
		case 12:
			return vsraq_n_s64(a, b, 12);
		case 13:
			return vsraq_n_s64(a, b, 13);
		case 14:
			return vsraq_n_s64(a, b, 14);
		case 15:
			return vsraq_n_s64(a, b, 15);
		case 16:
			return vsraq_n_s64(a, b, 16);
		case 17:
			return vsraq_n_s64(a, b, 17);
		case 18:
			return vsraq_n_s64(a, b, 18);
		case 19:
			return vsraq_n_s64(a, b, 19);
		case 20:
			return vsraq_n_s64(a, b, 20);
		case 21:
			return vsraq_n_s64(a, b, 21);
		case 22:
			return vsraq_n_s64(a, b, 22);
		case 23:
			return vsraq_n_s64(a, b, 23);
		case 24:
			return vsraq_n_s64(a, b, 24);
		case 25:
			return vsraq_n_s64(a, b, 25);
		case 26:
			return vsraq_n_s64(a, b, 26);
		case 27:
			return vsraq_n_s64(a, b, 27);
		case 28:
			return vsraq_n_s64(a, b, 28);
		case 29:
			return vsraq_n_s64(a, b, 29);
		case 30:
			return vsraq_n_s64(a, b, 30);
		case 31:
			return vsraq_n_s64(a, b, 31);
		case 32:
			return vsraq_n_s64(a, b, 32);
		case 33:
			return vsraq_n_s64(a, b, 33);
		case 34:
			return vsraq_n_s64(a, b, 34);
		case 35:
			return vsraq_n_s64(a, b, 35);
		case 36:
			return vsraq_n_s64(a, b, 36);
		case 37:
			return vsraq_n_s64(a, b, 37);
		case 38:
			return vsraq_n_s64(a, b, 38);
		case 39:
			return vsraq_n_s64(a, b, 39);
		case 40:
			return vsraq_n_s64(a, b, 40);
		case 41:
			return vsraq_n_s64(a, b, 41);
		case 42:
			return vsraq_n_s64(a, b, 42);
		case 43:
			return vsraq_n_s64(a, b, 43);
		case 44:
			return vsraq_n_s64(a, b, 44);
		case 45:
			return vsraq_n_s64(a, b, 45);
		case 46:
			return vsraq_n_s64(a, b, 46);
		case 47:
			return vsraq_n_s64(a, b, 47);
		case 48:
			return vsraq_n_s64(a, b, 48);
		case 49:
			return vsraq_n_s64(a, b, 49);
		case 50:
			return vsraq_n_s64(a, b, 50);
		case 51:
			return vsraq_n_s64(a, b, 51);
		case 52:
			return vsraq_n_s64(a, b, 52);
		case 53:
			return vsraq_n_s64(a, b, 53);
		case 54:
			return vsraq_n_s64(a, b, 54);
		case 55:
			return vsraq_n_s64(a, b, 55);
		case 56:
			return vsraq_n_s64(a, b, 56);
		case 57:
			return vsraq_n_s64(a, b, 57);
		case 58:
			return vsraq_n_s64(a, b, 58);
		case 59:
			return vsraq_n_s64(a, b, 59);
		case 60:
			return vsraq_n_s64(a, b, 60);
		case 61:
			return vsraq_n_s64(a, b, 61);
		case 62:
			return vsraq_n_s64(a, b, 62);
		case 63:
			return vsraq_n_s64(a, b, 63);
		case 64:
			return vsraq_n_s64(a, b, 64);
	}
	return vsraq_n_s64(a, b, 1);
}

uint8x16_t np_vsraq_n_u8(uint8x16_t a, uint8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_u8(a, b, 1);
		case 2:
			return vsraq_n_u8(a, b, 2);
		case 3:
			return vsraq_n_u8(a, b, 3);
		case 4:
			return vsraq_n_u8(a, b, 4);
		case 5:
			return vsraq_n_u8(a, b, 5);
		case 6:
			return vsraq_n_u8(a, b, 6);
		case 7:
			return vsraq_n_u8(a, b, 7);
		case 8:
			return vsraq_n_u8(a, b, 8);
	}
	return vsraq_n_u8(a, b, 1);
}

uint16x8_t np_vsraq_n_u16(uint16x8_t a, uint16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_u16(a, b, 1);
		case 2:
			return vsraq_n_u16(a, b, 2);
		case 3:
			return vsraq_n_u16(a, b, 3);
		case 4:
			return vsraq_n_u16(a, b, 4);
		case 5:
			return vsraq_n_u16(a, b, 5);
		case 6:
			return vsraq_n_u16(a, b, 6);
		case 7:
			return vsraq_n_u16(a, b, 7);
		case 8:
			return vsraq_n_u16(a, b, 8);
		case 9:
			return vsraq_n_u16(a, b, 9);
		case 10:
			return vsraq_n_u16(a, b, 10);
		case 11:
			return vsraq_n_u16(a, b, 11);
		case 12:
			return vsraq_n_u16(a, b, 12);
		case 13:
			return vsraq_n_u16(a, b, 13);
		case 14:
			return vsraq_n_u16(a, b, 14);
		case 15:
			return vsraq_n_u16(a, b, 15);
		case 16:
			return vsraq_n_u16(a, b, 16);
	}
	return vsraq_n_u16(a, b, 1);
}

uint32x4_t np_vsraq_n_u32(uint32x4_t a, uint32x4_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_u32(a, b, 1);
		case 2:
			return vsraq_n_u32(a, b, 2);
		case 3:
			return vsraq_n_u32(a, b, 3);
		case 4:
			return vsraq_n_u32(a, b, 4);
		case 5:
			return vsraq_n_u32(a, b, 5);
		case 6:
			return vsraq_n_u32(a, b, 6);
		case 7:
			return vsraq_n_u32(a, b, 7);
		case 8:
			return vsraq_n_u32(a, b, 8);
		case 9:
			return vsraq_n_u32(a, b, 9);
		case 10:
			return vsraq_n_u32(a, b, 10);
		case 11:
			return vsraq_n_u32(a, b, 11);
		case 12:
			return vsraq_n_u32(a, b, 12);
		case 13:
			return vsraq_n_u32(a, b, 13);
		case 14:
			return vsraq_n_u32(a, b, 14);
		case 15:
			return vsraq_n_u32(a, b, 15);
		case 16:
			return vsraq_n_u32(a, b, 16);
		case 17:
			return vsraq_n_u32(a, b, 17);
		case 18:
			return vsraq_n_u32(a, b, 18);
		case 19:
			return vsraq_n_u32(a, b, 19);
		case 20:
			return vsraq_n_u32(a, b, 20);
		case 21:
			return vsraq_n_u32(a, b, 21);
		case 22:
			return vsraq_n_u32(a, b, 22);
		case 23:
			return vsraq_n_u32(a, b, 23);
		case 24:
			return vsraq_n_u32(a, b, 24);
		case 25:
			return vsraq_n_u32(a, b, 25);
		case 26:
			return vsraq_n_u32(a, b, 26);
		case 27:
			return vsraq_n_u32(a, b, 27);
		case 28:
			return vsraq_n_u32(a, b, 28);
		case 29:
			return vsraq_n_u32(a, b, 29);
		case 30:
			return vsraq_n_u32(a, b, 30);
		case 31:
			return vsraq_n_u32(a, b, 31);
		case 32:
			return vsraq_n_u32(a, b, 32);
	}
	return vsraq_n_u32(a, b, 1);
}

uint64x2_t np_vsraq_n_u64(uint64x2_t a, uint64x2_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsraq_n_u64(a, b, 1);
		case 2:
			return vsraq_n_u64(a, b, 2);
		case 3:
			return vsraq_n_u64(a, b, 3);
		case 4:
			return vsraq_n_u64(a, b, 4);
		case 5:
			return vsraq_n_u64(a, b, 5);
		case 6:
			return vsraq_n_u64(a, b, 6);
		case 7:
			return vsraq_n_u64(a, b, 7);
		case 8:
			return vsraq_n_u64(a, b, 8);
		case 9:
			return vsraq_n_u64(a, b, 9);
		case 10:
			return vsraq_n_u64(a, b, 10);
		case 11:
			return vsraq_n_u64(a, b, 11);
		case 12:
			return vsraq_n_u64(a, b, 12);
		case 13:
			return vsraq_n_u64(a, b, 13);
		case 14:
			return vsraq_n_u64(a, b, 14);
		case 15:
			return vsraq_n_u64(a, b, 15);
		case 16:
			return vsraq_n_u64(a, b, 16);
		case 17:
			return vsraq_n_u64(a, b, 17);
		case 18:
			return vsraq_n_u64(a, b, 18);
		case 19:
			return vsraq_n_u64(a, b, 19);
		case 20:
			return vsraq_n_u64(a, b, 20);
		case 21:
			return vsraq_n_u64(a, b, 21);
		case 22:
			return vsraq_n_u64(a, b, 22);
		case 23:
			return vsraq_n_u64(a, b, 23);
		case 24:
			return vsraq_n_u64(a, b, 24);
		case 25:
			return vsraq_n_u64(a, b, 25);
		case 26:
			return vsraq_n_u64(a, b, 26);
		case 27:
			return vsraq_n_u64(a, b, 27);
		case 28:
			return vsraq_n_u64(a, b, 28);
		case 29:
			return vsraq_n_u64(a, b, 29);
		case 30:
			return vsraq_n_u64(a, b, 30);
		case 31:
			return vsraq_n_u64(a, b, 31);
		case 32:
			return vsraq_n_u64(a, b, 32);
		case 33:
			return vsraq_n_u64(a, b, 33);
		case 34:
			return vsraq_n_u64(a, b, 34);
		case 35:
			return vsraq_n_u64(a, b, 35);
		case 36:
			return vsraq_n_u64(a, b, 36);
		case 37:
			return vsraq_n_u64(a, b, 37);
		case 38:
			return vsraq_n_u64(a, b, 38);
		case 39:
			return vsraq_n_u64(a, b, 39);
		case 40:
			return vsraq_n_u64(a, b, 40);
		case 41:
			return vsraq_n_u64(a, b, 41);
		case 42:
			return vsraq_n_u64(a, b, 42);
		case 43:
			return vsraq_n_u64(a, b, 43);
		case 44:
			return vsraq_n_u64(a, b, 44);
		case 45:
			return vsraq_n_u64(a, b, 45);
		case 46:
			return vsraq_n_u64(a, b, 46);
		case 47:
			return vsraq_n_u64(a, b, 47);
		case 48:
			return vsraq_n_u64(a, b, 48);
		case 49:
			return vsraq_n_u64(a, b, 49);
		case 50:
			return vsraq_n_u64(a, b, 50);
		case 51:
			return vsraq_n_u64(a, b, 51);
		case 52:
			return vsraq_n_u64(a, b, 52);
		case 53:
			return vsraq_n_u64(a, b, 53);
		case 54:
			return vsraq_n_u64(a, b, 54);
		case 55:
			return vsraq_n_u64(a, b, 55);
		case 56:
			return vsraq_n_u64(a, b, 56);
		case 57:
			return vsraq_n_u64(a, b, 57);
		case 58:
			return vsraq_n_u64(a, b, 58);
		case 59:
			return vsraq_n_u64(a, b, 59);
		case 60:
			return vsraq_n_u64(a, b, 60);
		case 61:
			return vsraq_n_u64(a, b, 61);
		case 62:
			return vsraq_n_u64(a, b, 62);
		case 63:
			return vsraq_n_u64(a, b, 63);
		case 64:
			return vsraq_n_u64(a, b, 64);
	}
	return vsraq_n_u64(a, b, 1);
}

int8x16_t np_vrsraq_n_s8(int8x16_t a, int8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_s8(a, b, 1);
		case 2:
			return vrsraq_n_s8(a, b, 2);
		case 3:
			return vrsraq_n_s8(a, b, 3);
		case 4:
			return vrsraq_n_s8(a, b, 4);
		case 5:
			return vrsraq_n_s8(a, b, 5);
		case 6:
			return vrsraq_n_s8(a, b, 6);
		case 7:
			return vrsraq_n_s8(a, b, 7);
		case 8:
			return vrsraq_n_s8(a, b, 8);
	}
	return vrsraq_n_s8(a, b, 1);
}

int16x8_t np_vrsraq_n_s16(int16x8_t a, int16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_s16(a, b, 1);
		case 2:
			return vrsraq_n_s16(a, b, 2);
		case 3:
			return vrsraq_n_s16(a, b, 3);
		case 4:
			return vrsraq_n_s16(a, b, 4);
		case 5:
			return vrsraq_n_s16(a, b, 5);
		case 6:
			return vrsraq_n_s16(a, b, 6);
		case 7:
			return vrsraq_n_s16(a, b, 7);
		case 8:
			return vrsraq_n_s16(a, b, 8);
		case 9:
			return vrsraq_n_s16(a, b, 9);
		case 10:
			return vrsraq_n_s16(a, b, 10);
		case 11:
			return vrsraq_n_s16(a, b, 11);
		case 12:
			return vrsraq_n_s16(a, b, 12);
		case 13:
			return vrsraq_n_s16(a, b, 13);
		case 14:
			return vrsraq_n_s16(a, b, 14);
		case 15:
			return vrsraq_n_s16(a, b, 15);
		case 16:
			return vrsraq_n_s16(a, b, 16);
	}
	return vrsraq_n_s16(a, b, 1);
}

int32x4_t np_vrsraq_n_s32(int32x4_t a, int32x4_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_s32(a, b, 1);
		case 2:
			return vrsraq_n_s32(a, b, 2);
		case 3:
			return vrsraq_n_s32(a, b, 3);
		case 4:
			return vrsraq_n_s32(a, b, 4);
		case 5:
			return vrsraq_n_s32(a, b, 5);
		case 6:
			return vrsraq_n_s32(a, b, 6);
		case 7:
			return vrsraq_n_s32(a, b, 7);
		case 8:
			return vrsraq_n_s32(a, b, 8);
		case 9:
			return vrsraq_n_s32(a, b, 9);
		case 10:
			return vrsraq_n_s32(a, b, 10);
		case 11:
			return vrsraq_n_s32(a, b, 11);
		case 12:
			return vrsraq_n_s32(a, b, 12);
		case 13:
			return vrsraq_n_s32(a, b, 13);
		case 14:
			return vrsraq_n_s32(a, b, 14);
		case 15:
			return vrsraq_n_s32(a, b, 15);
		case 16:
			return vrsraq_n_s32(a, b, 16);
		case 17:
			return vrsraq_n_s32(a, b, 17);
		case 18:
			return vrsraq_n_s32(a, b, 18);
		case 19:
			return vrsraq_n_s32(a, b, 19);
		case 20:
			return vrsraq_n_s32(a, b, 20);
		case 21:
			return vrsraq_n_s32(a, b, 21);
		case 22:
			return vrsraq_n_s32(a, b, 22);
		case 23:
			return vrsraq_n_s32(a, b, 23);
		case 24:
			return vrsraq_n_s32(a, b, 24);
		case 25:
			return vrsraq_n_s32(a, b, 25);
		case 26:
			return vrsraq_n_s32(a, b, 26);
		case 27:
			return vrsraq_n_s32(a, b, 27);
		case 28:
			return vrsraq_n_s32(a, b, 28);
		case 29:
			return vrsraq_n_s32(a, b, 29);
		case 30:
			return vrsraq_n_s32(a, b, 30);
		case 31:
			return vrsraq_n_s32(a, b, 31);
		case 32:
			return vrsraq_n_s32(a, b, 32);
	}
	return vrsraq_n_s32(a, b, 1);
}

int64x2_t np_vrsraq_n_s64(int64x2_t a, int64x2_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_s64(a, b, 1);
		case 2:
			return vrsraq_n_s64(a, b, 2);
		case 3:
			return vrsraq_n_s64(a, b, 3);
		case 4:
			return vrsraq_n_s64(a, b, 4);
		case 5:
			return vrsraq_n_s64(a, b, 5);
		case 6:
			return vrsraq_n_s64(a, b, 6);
		case 7:
			return vrsraq_n_s64(a, b, 7);
		case 8:
			return vrsraq_n_s64(a, b, 8);
		case 9:
			return vrsraq_n_s64(a, b, 9);
		case 10:
			return vrsraq_n_s64(a, b, 10);
		case 11:
			return vrsraq_n_s64(a, b, 11);
		case 12:
			return vrsraq_n_s64(a, b, 12);
		case 13:
			return vrsraq_n_s64(a, b, 13);
		case 14:
			return vrsraq_n_s64(a, b, 14);
		case 15:
			return vrsraq_n_s64(a, b, 15);
		case 16:
			return vrsraq_n_s64(a, b, 16);
		case 17:
			return vrsraq_n_s64(a, b, 17);
		case 18:
			return vrsraq_n_s64(a, b, 18);
		case 19:
			return vrsraq_n_s64(a, b, 19);
		case 20:
			return vrsraq_n_s64(a, b, 20);
		case 21:
			return vrsraq_n_s64(a, b, 21);
		case 22:
			return vrsraq_n_s64(a, b, 22);
		case 23:
			return vrsraq_n_s64(a, b, 23);
		case 24:
			return vrsraq_n_s64(a, b, 24);
		case 25:
			return vrsraq_n_s64(a, b, 25);
		case 26:
			return vrsraq_n_s64(a, b, 26);
		case 27:
			return vrsraq_n_s64(a, b, 27);
		case 28:
			return vrsraq_n_s64(a, b, 28);
		case 29:
			return vrsraq_n_s64(a, b, 29);
		case 30:
			return vrsraq_n_s64(a, b, 30);
		case 31:
			return vrsraq_n_s64(a, b, 31);
		case 32:
			return vrsraq_n_s64(a, b, 32);
		case 33:
			return vrsraq_n_s64(a, b, 33);
		case 34:
			return vrsraq_n_s64(a, b, 34);
		case 35:
			return vrsraq_n_s64(a, b, 35);
		case 36:
			return vrsraq_n_s64(a, b, 36);
		case 37:
			return vrsraq_n_s64(a, b, 37);
		case 38:
			return vrsraq_n_s64(a, b, 38);
		case 39:
			return vrsraq_n_s64(a, b, 39);
		case 40:
			return vrsraq_n_s64(a, b, 40);
		case 41:
			return vrsraq_n_s64(a, b, 41);
		case 42:
			return vrsraq_n_s64(a, b, 42);
		case 43:
			return vrsraq_n_s64(a, b, 43);
		case 44:
			return vrsraq_n_s64(a, b, 44);
		case 45:
			return vrsraq_n_s64(a, b, 45);
		case 46:
			return vrsraq_n_s64(a, b, 46);
		case 47:
			return vrsraq_n_s64(a, b, 47);
		case 48:
			return vrsraq_n_s64(a, b, 48);
		case 49:
			return vrsraq_n_s64(a, b, 49);
		case 50:
			return vrsraq_n_s64(a, b, 50);
		case 51:
			return vrsraq_n_s64(a, b, 51);
		case 52:
			return vrsraq_n_s64(a, b, 52);
		case 53:
			return vrsraq_n_s64(a, b, 53);
		case 54:
			return vrsraq_n_s64(a, b, 54);
		case 55:
			return vrsraq_n_s64(a, b, 55);
		case 56:
			return vrsraq_n_s64(a, b, 56);
		case 57:
			return vrsraq_n_s64(a, b, 57);
		case 58:
			return vrsraq_n_s64(a, b, 58);
		case 59:
			return vrsraq_n_s64(a, b, 59);
		case 60:
			return vrsraq_n_s64(a, b, 60);
		case 61:
			return vrsraq_n_s64(a, b, 61);
		case 62:
			return vrsraq_n_s64(a, b, 62);
		case 63:
			return vrsraq_n_s64(a, b, 63);
		case 64:
			return vrsraq_n_s64(a, b, 64);
	}
	return vrsraq_n_s64(a, b, 1);
}

uint8x16_t np_vrsraq_n_u8(uint8x16_t a, uint8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_u8(a, b, 1);
		case 2:
			return vrsraq_n_u8(a, b, 2);
		case 3:
			return vrsraq_n_u8(a, b, 3);
		case 4:
			return vrsraq_n_u8(a, b, 4);
		case 5:
			return vrsraq_n_u8(a, b, 5);
		case 6:
			return vrsraq_n_u8(a, b, 6);
		case 7:
			return vrsraq_n_u8(a, b, 7);
		case 8:
			return vrsraq_n_u8(a, b, 8);
	}
	return vrsraq_n_u8(a, b, 1);
}

uint16x8_t np_vrsraq_n_u16(uint16x8_t a, uint16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_u16(a, b, 1);
		case 2:
			return vrsraq_n_u16(a, b, 2);
		case 3:
			return vrsraq_n_u16(a, b, 3);
		case 4:
			return vrsraq_n_u16(a, b, 4);
		case 5:
			return vrsraq_n_u16(a, b, 5);
		case 6:
			return vrsraq_n_u16(a, b, 6);
		case 7:
			return vrsraq_n_u16(a, b, 7);
		case 8:
			return vrsraq_n_u16(a, b, 8);
		case 9:
			return vrsraq_n_u16(a, b, 9);
		case 10:
			return vrsraq_n_u16(a, b, 10);
		case 11:
			return vrsraq_n_u16(a, b, 11);
		case 12:
			return vrsraq_n_u16(a, b, 12);
		case 13:
			return vrsraq_n_u16(a, b, 13);
		case 14:
			return vrsraq_n_u16(a, b, 14);
		case 15:
			return vrsraq_n_u16(a, b, 15);
		case 16:
			return vrsraq_n_u16(a, b, 16);
	}
	return vrsraq_n_u16(a, b, 1);
}

uint32x4_t np_vrsraq_n_u32(uint32x4_t a, uint32x4_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_u32(a, b, 1);
		case 2:
			return vrsraq_n_u32(a, b, 2);
		case 3:
			return vrsraq_n_u32(a, b, 3);
		case 4:
			return vrsraq_n_u32(a, b, 4);
		case 5:
			return vrsraq_n_u32(a, b, 5);
		case 6:
			return vrsraq_n_u32(a, b, 6);
		case 7:
			return vrsraq_n_u32(a, b, 7);
		case 8:
			return vrsraq_n_u32(a, b, 8);
		case 9:
			return vrsraq_n_u32(a, b, 9);
		case 10:
			return vrsraq_n_u32(a, b, 10);
		case 11:
			return vrsraq_n_u32(a, b, 11);
		case 12:
			return vrsraq_n_u32(a, b, 12);
		case 13:
			return vrsraq_n_u32(a, b, 13);
		case 14:
			return vrsraq_n_u32(a, b, 14);
		case 15:
			return vrsraq_n_u32(a, b, 15);
		case 16:
			return vrsraq_n_u32(a, b, 16);
		case 17:
			return vrsraq_n_u32(a, b, 17);
		case 18:
			return vrsraq_n_u32(a, b, 18);
		case 19:
			return vrsraq_n_u32(a, b, 19);
		case 20:
			return vrsraq_n_u32(a, b, 20);
		case 21:
			return vrsraq_n_u32(a, b, 21);
		case 22:
			return vrsraq_n_u32(a, b, 22);
		case 23:
			return vrsraq_n_u32(a, b, 23);
		case 24:
			return vrsraq_n_u32(a, b, 24);
		case 25:
			return vrsraq_n_u32(a, b, 25);
		case 26:
			return vrsraq_n_u32(a, b, 26);
		case 27:
			return vrsraq_n_u32(a, b, 27);
		case 28:
			return vrsraq_n_u32(a, b, 28);
		case 29:
			return vrsraq_n_u32(a, b, 29);
		case 30:
			return vrsraq_n_u32(a, b, 30);
		case 31:
			return vrsraq_n_u32(a, b, 31);
		case 32:
			return vrsraq_n_u32(a, b, 32);
	}
	return vrsraq_n_u32(a, b, 1);
}

uint64x2_t np_vrsraq_n_u64(uint64x2_t a, uint64x2_t b, int c)
{
	switch(c)
	{
		case 1:
			return vrsraq_n_u64(a, b, 1);
		case 2:
			return vrsraq_n_u64(a, b, 2);
		case 3:
			return vrsraq_n_u64(a, b, 3);
		case 4:
			return vrsraq_n_u64(a, b, 4);
		case 5:
			return vrsraq_n_u64(a, b, 5);
		case 6:
			return vrsraq_n_u64(a, b, 6);
		case 7:
			return vrsraq_n_u64(a, b, 7);
		case 8:
			return vrsraq_n_u64(a, b, 8);
		case 9:
			return vrsraq_n_u64(a, b, 9);
		case 10:
			return vrsraq_n_u64(a, b, 10);
		case 11:
			return vrsraq_n_u64(a, b, 11);
		case 12:
			return vrsraq_n_u64(a, b, 12);
		case 13:
			return vrsraq_n_u64(a, b, 13);
		case 14:
			return vrsraq_n_u64(a, b, 14);
		case 15:
			return vrsraq_n_u64(a, b, 15);
		case 16:
			return vrsraq_n_u64(a, b, 16);
		case 17:
			return vrsraq_n_u64(a, b, 17);
		case 18:
			return vrsraq_n_u64(a, b, 18);
		case 19:
			return vrsraq_n_u64(a, b, 19);
		case 20:
			return vrsraq_n_u64(a, b, 20);
		case 21:
			return vrsraq_n_u64(a, b, 21);
		case 22:
			return vrsraq_n_u64(a, b, 22);
		case 23:
			return vrsraq_n_u64(a, b, 23);
		case 24:
			return vrsraq_n_u64(a, b, 24);
		case 25:
			return vrsraq_n_u64(a, b, 25);
		case 26:
			return vrsraq_n_u64(a, b, 26);
		case 27:
			return vrsraq_n_u64(a, b, 27);
		case 28:
			return vrsraq_n_u64(a, b, 28);
		case 29:
			return vrsraq_n_u64(a, b, 29);
		case 30:
			return vrsraq_n_u64(a, b, 30);
		case 31:
			return vrsraq_n_u64(a, b, 31);
		case 32:
			return vrsraq_n_u64(a, b, 32);
		case 33:
			return vrsraq_n_u64(a, b, 33);
		case 34:
			return vrsraq_n_u64(a, b, 34);
		case 35:
			return vrsraq_n_u64(a, b, 35);
		case 36:
			return vrsraq_n_u64(a, b, 36);
		case 37:
			return vrsraq_n_u64(a, b, 37);
		case 38:
			return vrsraq_n_u64(a, b, 38);
		case 39:
			return vrsraq_n_u64(a, b, 39);
		case 40:
			return vrsraq_n_u64(a, b, 40);
		case 41:
			return vrsraq_n_u64(a, b, 41);
		case 42:
			return vrsraq_n_u64(a, b, 42);
		case 43:
			return vrsraq_n_u64(a, b, 43);
		case 44:
			return vrsraq_n_u64(a, b, 44);
		case 45:
			return vrsraq_n_u64(a, b, 45);
		case 46:
			return vrsraq_n_u64(a, b, 46);
		case 47:
			return vrsraq_n_u64(a, b, 47);
		case 48:
			return vrsraq_n_u64(a, b, 48);
		case 49:
			return vrsraq_n_u64(a, b, 49);
		case 50:
			return vrsraq_n_u64(a, b, 50);
		case 51:
			return vrsraq_n_u64(a, b, 51);
		case 52:
			return vrsraq_n_u64(a, b, 52);
		case 53:
			return vrsraq_n_u64(a, b, 53);
		case 54:
			return vrsraq_n_u64(a, b, 54);
		case 55:
			return vrsraq_n_u64(a, b, 55);
		case 56:
			return vrsraq_n_u64(a, b, 56);
		case 57:
			return vrsraq_n_u64(a, b, 57);
		case 58:
			return vrsraq_n_u64(a, b, 58);
		case 59:
			return vrsraq_n_u64(a, b, 59);
		case 60:
			return vrsraq_n_u64(a, b, 60);
		case 61:
			return vrsraq_n_u64(a, b, 61);
		case 62:
			return vrsraq_n_u64(a, b, 62);
		case 63:
			return vrsraq_n_u64(a, b, 63);
		case 64:
			return vrsraq_n_u64(a, b, 64);
	}
	return vrsraq_n_u64(a, b, 1);
}

int8x16_t np_vsriq_n_s8(int8x16_t a, int8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_s8(a, b, 1);
		case 2:
			return vsriq_n_s8(a, b, 2);
		case 3:
			return vsriq_n_s8(a, b, 3);
		case 4:
			return vsriq_n_s8(a, b, 4);
		case 5:
			return vsriq_n_s8(a, b, 5);
		case 6:
			return vsriq_n_s8(a, b, 6);
		case 7:
			return vsriq_n_s8(a, b, 7);
		case 8:
			return vsriq_n_s8(a, b, 8);
	}
	return vsriq_n_s8(a, b, 1);
}

int16x8_t np_vsriq_n_s16(int16x8_t a, int16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_s16(a, b, 1);
		case 2:
			return vsriq_n_s16(a, b, 2);
		case 3:
			return vsriq_n_s16(a, b, 3);
		case 4:
			return vsriq_n_s16(a, b, 4);
		case 5:
			return vsriq_n_s16(a, b, 5);
		case 6:
			return vsriq_n_s16(a, b, 6);
		case 7:
			return vsriq_n_s16(a, b, 7);
		case 8:
			return vsriq_n_s16(a, b, 8);
		case 9:
			return vsriq_n_s16(a, b, 9);
		case 10:
			return vsriq_n_s16(a, b, 10);
		case 11:
			return vsriq_n_s16(a, b, 11);
		case 12:
			return vsriq_n_s16(a, b, 12);
		case 13:
			return vsriq_n_s16(a, b, 13);
		case 14:
			return vsriq_n_s16(a, b, 14);
		case 15:
			return vsriq_n_s16(a, b, 15);
		case 16:
			return vsriq_n_s16(a, b, 16);
	}
	return vsriq_n_s16(a, b, 1);
}

int32x4_t np_vsriq_n_s32(int32x4_t a, int32x4_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_s32(a, b, 1);
		case 2:
			return vsriq_n_s32(a, b, 2);
		case 3:
			return vsriq_n_s32(a, b, 3);
		case 4:
			return vsriq_n_s32(a, b, 4);
		case 5:
			return vsriq_n_s32(a, b, 5);
		case 6:
			return vsriq_n_s32(a, b, 6);
		case 7:
			return vsriq_n_s32(a, b, 7);
		case 8:
			return vsriq_n_s32(a, b, 8);
		case 9:
			return vsriq_n_s32(a, b, 9);
		case 10:
			return vsriq_n_s32(a, b, 10);
		case 11:
			return vsriq_n_s32(a, b, 11);
		case 12:
			return vsriq_n_s32(a, b, 12);
		case 13:
			return vsriq_n_s32(a, b, 13);
		case 14:
			return vsriq_n_s32(a, b, 14);
		case 15:
			return vsriq_n_s32(a, b, 15);
		case 16:
			return vsriq_n_s32(a, b, 16);
		case 17:
			return vsriq_n_s32(a, b, 17);
		case 18:
			return vsriq_n_s32(a, b, 18);
		case 19:
			return vsriq_n_s32(a, b, 19);
		case 20:
			return vsriq_n_s32(a, b, 20);
		case 21:
			return vsriq_n_s32(a, b, 21);
		case 22:
			return vsriq_n_s32(a, b, 22);
		case 23:
			return vsriq_n_s32(a, b, 23);
		case 24:
			return vsriq_n_s32(a, b, 24);
		case 25:
			return vsriq_n_s32(a, b, 25);
		case 26:
			return vsriq_n_s32(a, b, 26);
		case 27:
			return vsriq_n_s32(a, b, 27);
		case 28:
			return vsriq_n_s32(a, b, 28);
		case 29:
			return vsriq_n_s32(a, b, 29);
		case 30:
			return vsriq_n_s32(a, b, 30);
		case 31:
			return vsriq_n_s32(a, b, 31);
		case 32:
			return vsriq_n_s32(a, b, 32);
	}
	return vsriq_n_s32(a, b, 1);
}

int64x2_t np_vsriq_n_s64(int64x2_t a, int64x2_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_s64(a, b, 1);
		case 2:
			return vsriq_n_s64(a, b, 2);
		case 3:
			return vsriq_n_s64(a, b, 3);
		case 4:
			return vsriq_n_s64(a, b, 4);
		case 5:
			return vsriq_n_s64(a, b, 5);
		case 6:
			return vsriq_n_s64(a, b, 6);
		case 7:
			return vsriq_n_s64(a, b, 7);
		case 8:
			return vsriq_n_s64(a, b, 8);
		case 9:
			return vsriq_n_s64(a, b, 9);
		case 10:
			return vsriq_n_s64(a, b, 10);
		case 11:
			return vsriq_n_s64(a, b, 11);
		case 12:
			return vsriq_n_s64(a, b, 12);
		case 13:
			return vsriq_n_s64(a, b, 13);
		case 14:
			return vsriq_n_s64(a, b, 14);
		case 15:
			return vsriq_n_s64(a, b, 15);
		case 16:
			return vsriq_n_s64(a, b, 16);
		case 17:
			return vsriq_n_s64(a, b, 17);
		case 18:
			return vsriq_n_s64(a, b, 18);
		case 19:
			return vsriq_n_s64(a, b, 19);
		case 20:
			return vsriq_n_s64(a, b, 20);
		case 21:
			return vsriq_n_s64(a, b, 21);
		case 22:
			return vsriq_n_s64(a, b, 22);
		case 23:
			return vsriq_n_s64(a, b, 23);
		case 24:
			return vsriq_n_s64(a, b, 24);
		case 25:
			return vsriq_n_s64(a, b, 25);
		case 26:
			return vsriq_n_s64(a, b, 26);
		case 27:
			return vsriq_n_s64(a, b, 27);
		case 28:
			return vsriq_n_s64(a, b, 28);
		case 29:
			return vsriq_n_s64(a, b, 29);
		case 30:
			return vsriq_n_s64(a, b, 30);
		case 31:
			return vsriq_n_s64(a, b, 31);
		case 32:
			return vsriq_n_s64(a, b, 32);
		case 33:
			return vsriq_n_s64(a, b, 33);
		case 34:
			return vsriq_n_s64(a, b, 34);
		case 35:
			return vsriq_n_s64(a, b, 35);
		case 36:
			return vsriq_n_s64(a, b, 36);
		case 37:
			return vsriq_n_s64(a, b, 37);
		case 38:
			return vsriq_n_s64(a, b, 38);
		case 39:
			return vsriq_n_s64(a, b, 39);
		case 40:
			return vsriq_n_s64(a, b, 40);
		case 41:
			return vsriq_n_s64(a, b, 41);
		case 42:
			return vsriq_n_s64(a, b, 42);
		case 43:
			return vsriq_n_s64(a, b, 43);
		case 44:
			return vsriq_n_s64(a, b, 44);
		case 45:
			return vsriq_n_s64(a, b, 45);
		case 46:
			return vsriq_n_s64(a, b, 46);
		case 47:
			return vsriq_n_s64(a, b, 47);
		case 48:
			return vsriq_n_s64(a, b, 48);
		case 49:
			return vsriq_n_s64(a, b, 49);
		case 50:
			return vsriq_n_s64(a, b, 50);
		case 51:
			return vsriq_n_s64(a, b, 51);
		case 52:
			return vsriq_n_s64(a, b, 52);
		case 53:
			return vsriq_n_s64(a, b, 53);
		case 54:
			return vsriq_n_s64(a, b, 54);
		case 55:
			return vsriq_n_s64(a, b, 55);
		case 56:
			return vsriq_n_s64(a, b, 56);
		case 57:
			return vsriq_n_s64(a, b, 57);
		case 58:
			return vsriq_n_s64(a, b, 58);
		case 59:
			return vsriq_n_s64(a, b, 59);
		case 60:
			return vsriq_n_s64(a, b, 60);
		case 61:
			return vsriq_n_s64(a, b, 61);
		case 62:
			return vsriq_n_s64(a, b, 62);
		case 63:
			return vsriq_n_s64(a, b, 63);
		case 64:
			return vsriq_n_s64(a, b, 64);
	}
	return vsriq_n_s64(a, b, 1);
}

uint8x16_t np_vsriq_n_u8(uint8x16_t a, uint8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_u8(a, b, 1);
		case 2:
			return vsriq_n_u8(a, b, 2);
		case 3:
			return vsriq_n_u8(a, b, 3);
		case 4:
			return vsriq_n_u8(a, b, 4);
		case 5:
			return vsriq_n_u8(a, b, 5);
		case 6:
			return vsriq_n_u8(a, b, 6);
		case 7:
			return vsriq_n_u8(a, b, 7);
		case 8:
			return vsriq_n_u8(a, b, 8);
	}
	return vsriq_n_u8(a, b, 1);
}

uint16x8_t np_vsriq_n_u16(uint16x8_t a, uint16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_u16(a, b, 1);
		case 2:
			return vsriq_n_u16(a, b, 2);
		case 3:
			return vsriq_n_u16(a, b, 3);
		case 4:
			return vsriq_n_u16(a, b, 4);
		case 5:
			return vsriq_n_u16(a, b, 5);
		case 6:
			return vsriq_n_u16(a, b, 6);
		case 7:
			return vsriq_n_u16(a, b, 7);
		case 8:
			return vsriq_n_u16(a, b, 8);
		case 9:
			return vsriq_n_u16(a, b, 9);
		case 10:
			return vsriq_n_u16(a, b, 10);
		case 11:
			return vsriq_n_u16(a, b, 11);
		case 12:
			return vsriq_n_u16(a, b, 12);
		case 13:
			return vsriq_n_u16(a, b, 13);
		case 14:
			return vsriq_n_u16(a, b, 14);
		case 15:
			return vsriq_n_u16(a, b, 15);
		case 16:
			return vsriq_n_u16(a, b, 16);
	}
	return vsriq_n_u16(a, b, 1);
}

uint32x4_t np_vsriq_n_u32(uint32x4_t a, uint32x4_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_u32(a, b, 1);
		case 2:
			return vsriq_n_u32(a, b, 2);
		case 3:
			return vsriq_n_u32(a, b, 3);
		case 4:
			return vsriq_n_u32(a, b, 4);
		case 5:
			return vsriq_n_u32(a, b, 5);
		case 6:
			return vsriq_n_u32(a, b, 6);
		case 7:
			return vsriq_n_u32(a, b, 7);
		case 8:
			return vsriq_n_u32(a, b, 8);
		case 9:
			return vsriq_n_u32(a, b, 9);
		case 10:
			return vsriq_n_u32(a, b, 10);
		case 11:
			return vsriq_n_u32(a, b, 11);
		case 12:
			return vsriq_n_u32(a, b, 12);
		case 13:
			return vsriq_n_u32(a, b, 13);
		case 14:
			return vsriq_n_u32(a, b, 14);
		case 15:
			return vsriq_n_u32(a, b, 15);
		case 16:
			return vsriq_n_u32(a, b, 16);
		case 17:
			return vsriq_n_u32(a, b, 17);
		case 18:
			return vsriq_n_u32(a, b, 18);
		case 19:
			return vsriq_n_u32(a, b, 19);
		case 20:
			return vsriq_n_u32(a, b, 20);
		case 21:
			return vsriq_n_u32(a, b, 21);
		case 22:
			return vsriq_n_u32(a, b, 22);
		case 23:
			return vsriq_n_u32(a, b, 23);
		case 24:
			return vsriq_n_u32(a, b, 24);
		case 25:
			return vsriq_n_u32(a, b, 25);
		case 26:
			return vsriq_n_u32(a, b, 26);
		case 27:
			return vsriq_n_u32(a, b, 27);
		case 28:
			return vsriq_n_u32(a, b, 28);
		case 29:
			return vsriq_n_u32(a, b, 29);
		case 30:
			return vsriq_n_u32(a, b, 30);
		case 31:
			return vsriq_n_u32(a, b, 31);
		case 32:
			return vsriq_n_u32(a, b, 32);
	}
	return vsriq_n_u32(a, b, 1);
}

uint64x2_t np_vsriq_n_u64(uint64x2_t a, uint64x2_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_u64(a, b, 1);
		case 2:
			return vsriq_n_u64(a, b, 2);
		case 3:
			return vsriq_n_u64(a, b, 3);
		case 4:
			return vsriq_n_u64(a, b, 4);
		case 5:
			return vsriq_n_u64(a, b, 5);
		case 6:
			return vsriq_n_u64(a, b, 6);
		case 7:
			return vsriq_n_u64(a, b, 7);
		case 8:
			return vsriq_n_u64(a, b, 8);
		case 9:
			return vsriq_n_u64(a, b, 9);
		case 10:
			return vsriq_n_u64(a, b, 10);
		case 11:
			return vsriq_n_u64(a, b, 11);
		case 12:
			return vsriq_n_u64(a, b, 12);
		case 13:
			return vsriq_n_u64(a, b, 13);
		case 14:
			return vsriq_n_u64(a, b, 14);
		case 15:
			return vsriq_n_u64(a, b, 15);
		case 16:
			return vsriq_n_u64(a, b, 16);
		case 17:
			return vsriq_n_u64(a, b, 17);
		case 18:
			return vsriq_n_u64(a, b, 18);
		case 19:
			return vsriq_n_u64(a, b, 19);
		case 20:
			return vsriq_n_u64(a, b, 20);
		case 21:
			return vsriq_n_u64(a, b, 21);
		case 22:
			return vsriq_n_u64(a, b, 22);
		case 23:
			return vsriq_n_u64(a, b, 23);
		case 24:
			return vsriq_n_u64(a, b, 24);
		case 25:
			return vsriq_n_u64(a, b, 25);
		case 26:
			return vsriq_n_u64(a, b, 26);
		case 27:
			return vsriq_n_u64(a, b, 27);
		case 28:
			return vsriq_n_u64(a, b, 28);
		case 29:
			return vsriq_n_u64(a, b, 29);
		case 30:
			return vsriq_n_u64(a, b, 30);
		case 31:
			return vsriq_n_u64(a, b, 31);
		case 32:
			return vsriq_n_u64(a, b, 32);
		case 33:
			return vsriq_n_u64(a, b, 33);
		case 34:
			return vsriq_n_u64(a, b, 34);
		case 35:
			return vsriq_n_u64(a, b, 35);
		case 36:
			return vsriq_n_u64(a, b, 36);
		case 37:
			return vsriq_n_u64(a, b, 37);
		case 38:
			return vsriq_n_u64(a, b, 38);
		case 39:
			return vsriq_n_u64(a, b, 39);
		case 40:
			return vsriq_n_u64(a, b, 40);
		case 41:
			return vsriq_n_u64(a, b, 41);
		case 42:
			return vsriq_n_u64(a, b, 42);
		case 43:
			return vsriq_n_u64(a, b, 43);
		case 44:
			return vsriq_n_u64(a, b, 44);
		case 45:
			return vsriq_n_u64(a, b, 45);
		case 46:
			return vsriq_n_u64(a, b, 46);
		case 47:
			return vsriq_n_u64(a, b, 47);
		case 48:
			return vsriq_n_u64(a, b, 48);
		case 49:
			return vsriq_n_u64(a, b, 49);
		case 50:
			return vsriq_n_u64(a, b, 50);
		case 51:
			return vsriq_n_u64(a, b, 51);
		case 52:
			return vsriq_n_u64(a, b, 52);
		case 53:
			return vsriq_n_u64(a, b, 53);
		case 54:
			return vsriq_n_u64(a, b, 54);
		case 55:
			return vsriq_n_u64(a, b, 55);
		case 56:
			return vsriq_n_u64(a, b, 56);
		case 57:
			return vsriq_n_u64(a, b, 57);
		case 58:
			return vsriq_n_u64(a, b, 58);
		case 59:
			return vsriq_n_u64(a, b, 59);
		case 60:
			return vsriq_n_u64(a, b, 60);
		case 61:
			return vsriq_n_u64(a, b, 61);
		case 62:
			return vsriq_n_u64(a, b, 62);
		case 63:
			return vsriq_n_u64(a, b, 63);
		case 64:
			return vsriq_n_u64(a, b, 64);
	}
	return vsriq_n_u64(a, b, 1);
}

poly8x16_t np_vsriq_n_p8(poly8x16_t a, poly8x16_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_p8(a, b, 1);
		case 2:
			return vsriq_n_p8(a, b, 2);
		case 3:
			return vsriq_n_p8(a, b, 3);
		case 4:
			return vsriq_n_p8(a, b, 4);
		case 5:
			return vsriq_n_p8(a, b, 5);
		case 6:
			return vsriq_n_p8(a, b, 6);
		case 7:
			return vsriq_n_p8(a, b, 7);
		case 8:
			return vsriq_n_p8(a, b, 8);
	}
	return vsriq_n_p8(a, b, 1);
}

poly16x8_t np_vsriq_n_p16(poly16x8_t a, poly16x8_t b, int c)
{
	switch(c)
	{
		case 1:
			return vsriq_n_p16(a, b, 1);
		case 2:
			return vsriq_n_p16(a, b, 2);
		case 3:
			return vsriq_n_p16(a, b, 3);
		case 4:
			return vsriq_n_p16(a, b, 4);
		case 5:
			return vsriq_n_p16(a, b, 5);
		case 6:
			return vsriq_n_p16(a, b, 6);
		case 7:
			return vsriq_n_p16(a, b, 7);
		case 8:
			return vsriq_n_p16(a, b, 8);
		case 9:
			return vsriq_n_p16(a, b, 9);
		case 10:
			return vsriq_n_p16(a, b, 10);
		case 11:
			return vsriq_n_p16(a, b, 11);
		case 12:
			return vsriq_n_p16(a, b, 12);
		case 13:
			return vsriq_n_p16(a, b, 13);
		case 14:
			return vsriq_n_p16(a, b, 14);
		case 15:
			return vsriq_n_p16(a, b, 15);
		case 16:
			return vsriq_n_p16(a, b, 16);
	}
	return vsriq_n_p16(a, b, 1);
}

int8x16_t np_vsliq_n_s8(int8x16_t a, int8x16_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_s8(a, b, 0);
		case 1:
			return vsliq_n_s8(a, b, 1);
		case 2:
			return vsliq_n_s8(a, b, 2);
		case 3:
			return vsliq_n_s8(a, b, 3);
		case 4:
			return vsliq_n_s8(a, b, 4);
		case 5:
			return vsliq_n_s8(a, b, 5);
		case 6:
			return vsliq_n_s8(a, b, 6);
		case 7:
			return vsliq_n_s8(a, b, 7);
	}
	return vsliq_n_s8(a, b, 1);
}

int16x8_t np_vsliq_n_s16(int16x8_t a, int16x8_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_s16(a, b, 0);
		case 1:
			return vsliq_n_s16(a, b, 1);
		case 2:
			return vsliq_n_s16(a, b, 2);
		case 3:
			return vsliq_n_s16(a, b, 3);
		case 4:
			return vsliq_n_s16(a, b, 4);
		case 5:
			return vsliq_n_s16(a, b, 5);
		case 6:
			return vsliq_n_s16(a, b, 6);
		case 7:
			return vsliq_n_s16(a, b, 7);
		case 8:
			return vsliq_n_s16(a, b, 8);
		case 9:
			return vsliq_n_s16(a, b, 9);
		case 10:
			return vsliq_n_s16(a, b, 10);
		case 11:
			return vsliq_n_s16(a, b, 11);
		case 12:
			return vsliq_n_s16(a, b, 12);
		case 13:
			return vsliq_n_s16(a, b, 13);
		case 14:
			return vsliq_n_s16(a, b, 14);
		case 15:
			return vsliq_n_s16(a, b, 15);
	}
	return vsliq_n_s16(a, b, 1);
}

int32x4_t np_vsliq_n_s32(int32x4_t a, int32x4_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_s32(a, b, 0);
		case 1:
			return vsliq_n_s32(a, b, 1);
		case 2:
			return vsliq_n_s32(a, b, 2);
		case 3:
			return vsliq_n_s32(a, b, 3);
		case 4:
			return vsliq_n_s32(a, b, 4);
		case 5:
			return vsliq_n_s32(a, b, 5);
		case 6:
			return vsliq_n_s32(a, b, 6);
		case 7:
			return vsliq_n_s32(a, b, 7);
		case 8:
			return vsliq_n_s32(a, b, 8);
		case 9:
			return vsliq_n_s32(a, b, 9);
		case 10:
			return vsliq_n_s32(a, b, 10);
		case 11:
			return vsliq_n_s32(a, b, 11);
		case 12:
			return vsliq_n_s32(a, b, 12);
		case 13:
			return vsliq_n_s32(a, b, 13);
		case 14:
			return vsliq_n_s32(a, b, 14);
		case 15:
			return vsliq_n_s32(a, b, 15);
		case 16:
			return vsliq_n_s32(a, b, 16);
		case 17:
			return vsliq_n_s32(a, b, 17);
		case 18:
			return vsliq_n_s32(a, b, 18);
		case 19:
			return vsliq_n_s32(a, b, 19);
		case 20:
			return vsliq_n_s32(a, b, 20);
		case 21:
			return vsliq_n_s32(a, b, 21);
		case 22:
			return vsliq_n_s32(a, b, 22);
		case 23:
			return vsliq_n_s32(a, b, 23);
		case 24:
			return vsliq_n_s32(a, b, 24);
		case 25:
			return vsliq_n_s32(a, b, 25);
		case 26:
			return vsliq_n_s32(a, b, 26);
		case 27:
			return vsliq_n_s32(a, b, 27);
		case 28:
			return vsliq_n_s32(a, b, 28);
		case 29:
			return vsliq_n_s32(a, b, 29);
		case 30:
			return vsliq_n_s32(a, b, 30);
		case 31:
			return vsliq_n_s32(a, b, 31);
	}
	return vsliq_n_s32(a, b, 1);
}

int64x2_t np_vsliq_n_s64(int64x2_t a, int64x2_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_s64(a, b, 0);
		case 1:
			return vsliq_n_s64(a, b, 1);
		case 2:
			return vsliq_n_s64(a, b, 2);
		case 3:
			return vsliq_n_s64(a, b, 3);
		case 4:
			return vsliq_n_s64(a, b, 4);
		case 5:
			return vsliq_n_s64(a, b, 5);
		case 6:
			return vsliq_n_s64(a, b, 6);
		case 7:
			return vsliq_n_s64(a, b, 7);
		case 8:
			return vsliq_n_s64(a, b, 8);
		case 9:
			return vsliq_n_s64(a, b, 9);
		case 10:
			return vsliq_n_s64(a, b, 10);
		case 11:
			return vsliq_n_s64(a, b, 11);
		case 12:
			return vsliq_n_s64(a, b, 12);
		case 13:
			return vsliq_n_s64(a, b, 13);
		case 14:
			return vsliq_n_s64(a, b, 14);
		case 15:
			return vsliq_n_s64(a, b, 15);
		case 16:
			return vsliq_n_s64(a, b, 16);
		case 17:
			return vsliq_n_s64(a, b, 17);
		case 18:
			return vsliq_n_s64(a, b, 18);
		case 19:
			return vsliq_n_s64(a, b, 19);
		case 20:
			return vsliq_n_s64(a, b, 20);
		case 21:
			return vsliq_n_s64(a, b, 21);
		case 22:
			return vsliq_n_s64(a, b, 22);
		case 23:
			return vsliq_n_s64(a, b, 23);
		case 24:
			return vsliq_n_s64(a, b, 24);
		case 25:
			return vsliq_n_s64(a, b, 25);
		case 26:
			return vsliq_n_s64(a, b, 26);
		case 27:
			return vsliq_n_s64(a, b, 27);
		case 28:
			return vsliq_n_s64(a, b, 28);
		case 29:
			return vsliq_n_s64(a, b, 29);
		case 30:
			return vsliq_n_s64(a, b, 30);
		case 31:
			return vsliq_n_s64(a, b, 31);
		case 32:
			return vsliq_n_s64(a, b, 32);
		case 33:
			return vsliq_n_s64(a, b, 33);
		case 34:
			return vsliq_n_s64(a, b, 34);
		case 35:
			return vsliq_n_s64(a, b, 35);
		case 36:
			return vsliq_n_s64(a, b, 36);
		case 37:
			return vsliq_n_s64(a, b, 37);
		case 38:
			return vsliq_n_s64(a, b, 38);
		case 39:
			return vsliq_n_s64(a, b, 39);
		case 40:
			return vsliq_n_s64(a, b, 40);
		case 41:
			return vsliq_n_s64(a, b, 41);
		case 42:
			return vsliq_n_s64(a, b, 42);
		case 43:
			return vsliq_n_s64(a, b, 43);
		case 44:
			return vsliq_n_s64(a, b, 44);
		case 45:
			return vsliq_n_s64(a, b, 45);
		case 46:
			return vsliq_n_s64(a, b, 46);
		case 47:
			return vsliq_n_s64(a, b, 47);
		case 48:
			return vsliq_n_s64(a, b, 48);
		case 49:
			return vsliq_n_s64(a, b, 49);
		case 50:
			return vsliq_n_s64(a, b, 50);
		case 51:
			return vsliq_n_s64(a, b, 51);
		case 52:
			return vsliq_n_s64(a, b, 52);
		case 53:
			return vsliq_n_s64(a, b, 53);
		case 54:
			return vsliq_n_s64(a, b, 54);
		case 55:
			return vsliq_n_s64(a, b, 55);
		case 56:
			return vsliq_n_s64(a, b, 56);
		case 57:
			return vsliq_n_s64(a, b, 57);
		case 58:
			return vsliq_n_s64(a, b, 58);
		case 59:
			return vsliq_n_s64(a, b, 59);
		case 60:
			return vsliq_n_s64(a, b, 60);
		case 61:
			return vsliq_n_s64(a, b, 61);
		case 62:
			return vsliq_n_s64(a, b, 62);
		case 63:
			return vsliq_n_s64(a, b, 63);
	}
	return vsliq_n_s64(a, b, 1);
}

uint8x16_t np_vsliq_n_u8(uint8x16_t a, uint8x16_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_u8(a, b, 0);
		case 1:
			return vsliq_n_u8(a, b, 1);
		case 2:
			return vsliq_n_u8(a, b, 2);
		case 3:
			return vsliq_n_u8(a, b, 3);
		case 4:
			return vsliq_n_u8(a, b, 4);
		case 5:
			return vsliq_n_u8(a, b, 5);
		case 6:
			return vsliq_n_u8(a, b, 6);
		case 7:
			return vsliq_n_u8(a, b, 7);
	}
	return vsliq_n_u8(a, b, 1);
}

uint16x8_t np_vsliq_n_u16(uint16x8_t a, uint16x8_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_u16(a, b, 0);
		case 1:
			return vsliq_n_u16(a, b, 1);
		case 2:
			return vsliq_n_u16(a, b, 2);
		case 3:
			return vsliq_n_u16(a, b, 3);
		case 4:
			return vsliq_n_u16(a, b, 4);
		case 5:
			return vsliq_n_u16(a, b, 5);
		case 6:
			return vsliq_n_u16(a, b, 6);
		case 7:
			return vsliq_n_u16(a, b, 7);
		case 8:
			return vsliq_n_u16(a, b, 8);
		case 9:
			return vsliq_n_u16(a, b, 9);
		case 10:
			return vsliq_n_u16(a, b, 10);
		case 11:
			return vsliq_n_u16(a, b, 11);
		case 12:
			return vsliq_n_u16(a, b, 12);
		case 13:
			return vsliq_n_u16(a, b, 13);
		case 14:
			return vsliq_n_u16(a, b, 14);
		case 15:
			return vsliq_n_u16(a, b, 15);
	}
	return vsliq_n_u16(a, b, 1);
}

uint32x4_t np_vsliq_n_u32(uint32x4_t a, uint32x4_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_u32(a, b, 0);
		case 1:
			return vsliq_n_u32(a, b, 1);
		case 2:
			return vsliq_n_u32(a, b, 2);
		case 3:
			return vsliq_n_u32(a, b, 3);
		case 4:
			return vsliq_n_u32(a, b, 4);
		case 5:
			return vsliq_n_u32(a, b, 5);
		case 6:
			return vsliq_n_u32(a, b, 6);
		case 7:
			return vsliq_n_u32(a, b, 7);
		case 8:
			return vsliq_n_u32(a, b, 8);
		case 9:
			return vsliq_n_u32(a, b, 9);
		case 10:
			return vsliq_n_u32(a, b, 10);
		case 11:
			return vsliq_n_u32(a, b, 11);
		case 12:
			return vsliq_n_u32(a, b, 12);
		case 13:
			return vsliq_n_u32(a, b, 13);
		case 14:
			return vsliq_n_u32(a, b, 14);
		case 15:
			return vsliq_n_u32(a, b, 15);
		case 16:
			return vsliq_n_u32(a, b, 16);
		case 17:
			return vsliq_n_u32(a, b, 17);
		case 18:
			return vsliq_n_u32(a, b, 18);
		case 19:
			return vsliq_n_u32(a, b, 19);
		case 20:
			return vsliq_n_u32(a, b, 20);
		case 21:
			return vsliq_n_u32(a, b, 21);
		case 22:
			return vsliq_n_u32(a, b, 22);
		case 23:
			return vsliq_n_u32(a, b, 23);
		case 24:
			return vsliq_n_u32(a, b, 24);
		case 25:
			return vsliq_n_u32(a, b, 25);
		case 26:
			return vsliq_n_u32(a, b, 26);
		case 27:
			return vsliq_n_u32(a, b, 27);
		case 28:
			return vsliq_n_u32(a, b, 28);
		case 29:
			return vsliq_n_u32(a, b, 29);
		case 30:
			return vsliq_n_u32(a, b, 30);
		case 31:
			return vsliq_n_u32(a, b, 31);
	}
	return vsliq_n_u32(a, b, 1);
}

uint64x2_t np_vsliq_n_u64(uint64x2_t a, uint64x2_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_u64(a, b, 0);
		case 1:
			return vsliq_n_u64(a, b, 1);
		case 2:
			return vsliq_n_u64(a, b, 2);
		case 3:
			return vsliq_n_u64(a, b, 3);
		case 4:
			return vsliq_n_u64(a, b, 4);
		case 5:
			return vsliq_n_u64(a, b, 5);
		case 6:
			return vsliq_n_u64(a, b, 6);
		case 7:
			return vsliq_n_u64(a, b, 7);
		case 8:
			return vsliq_n_u64(a, b, 8);
		case 9:
			return vsliq_n_u64(a, b, 9);
		case 10:
			return vsliq_n_u64(a, b, 10);
		case 11:
			return vsliq_n_u64(a, b, 11);
		case 12:
			return vsliq_n_u64(a, b, 12);
		case 13:
			return vsliq_n_u64(a, b, 13);
		case 14:
			return vsliq_n_u64(a, b, 14);
		case 15:
			return vsliq_n_u64(a, b, 15);
		case 16:
			return vsliq_n_u64(a, b, 16);
		case 17:
			return vsliq_n_u64(a, b, 17);
		case 18:
			return vsliq_n_u64(a, b, 18);
		case 19:
			return vsliq_n_u64(a, b, 19);
		case 20:
			return vsliq_n_u64(a, b, 20);
		case 21:
			return vsliq_n_u64(a, b, 21);
		case 22:
			return vsliq_n_u64(a, b, 22);
		case 23:
			return vsliq_n_u64(a, b, 23);
		case 24:
			return vsliq_n_u64(a, b, 24);
		case 25:
			return vsliq_n_u64(a, b, 25);
		case 26:
			return vsliq_n_u64(a, b, 26);
		case 27:
			return vsliq_n_u64(a, b, 27);
		case 28:
			return vsliq_n_u64(a, b, 28);
		case 29:
			return vsliq_n_u64(a, b, 29);
		case 30:
			return vsliq_n_u64(a, b, 30);
		case 31:
			return vsliq_n_u64(a, b, 31);
		case 32:
			return vsliq_n_u64(a, b, 32);
		case 33:
			return vsliq_n_u64(a, b, 33);
		case 34:
			return vsliq_n_u64(a, b, 34);
		case 35:
			return vsliq_n_u64(a, b, 35);
		case 36:
			return vsliq_n_u64(a, b, 36);
		case 37:
			return vsliq_n_u64(a, b, 37);
		case 38:
			return vsliq_n_u64(a, b, 38);
		case 39:
			return vsliq_n_u64(a, b, 39);
		case 40:
			return vsliq_n_u64(a, b, 40);
		case 41:
			return vsliq_n_u64(a, b, 41);
		case 42:
			return vsliq_n_u64(a, b, 42);
		case 43:
			return vsliq_n_u64(a, b, 43);
		case 44:
			return vsliq_n_u64(a, b, 44);
		case 45:
			return vsliq_n_u64(a, b, 45);
		case 46:
			return vsliq_n_u64(a, b, 46);
		case 47:
			return vsliq_n_u64(a, b, 47);
		case 48:
			return vsliq_n_u64(a, b, 48);
		case 49:
			return vsliq_n_u64(a, b, 49);
		case 50:
			return vsliq_n_u64(a, b, 50);
		case 51:
			return vsliq_n_u64(a, b, 51);
		case 52:
			return vsliq_n_u64(a, b, 52);
		case 53:
			return vsliq_n_u64(a, b, 53);
		case 54:
			return vsliq_n_u64(a, b, 54);
		case 55:
			return vsliq_n_u64(a, b, 55);
		case 56:
			return vsliq_n_u64(a, b, 56);
		case 57:
			return vsliq_n_u64(a, b, 57);
		case 58:
			return vsliq_n_u64(a, b, 58);
		case 59:
			return vsliq_n_u64(a, b, 59);
		case 60:
			return vsliq_n_u64(a, b, 60);
		case 61:
			return vsliq_n_u64(a, b, 61);
		case 62:
			return vsliq_n_u64(a, b, 62);
		case 63:
			return vsliq_n_u64(a, b, 63);
	}
	return vsliq_n_u64(a, b, 1);
}

poly8x16_t np_vsliq_n_p8(poly8x16_t a, poly8x16_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_p8(a, b, 0);
		case 1:
			return vsliq_n_p8(a, b, 1);
		case 2:
			return vsliq_n_p8(a, b, 2);
		case 3:
			return vsliq_n_p8(a, b, 3);
		case 4:
			return vsliq_n_p8(a, b, 4);
		case 5:
			return vsliq_n_p8(a, b, 5);
		case 6:
			return vsliq_n_p8(a, b, 6);
		case 7:
			return vsliq_n_p8(a, b, 7);
	}
	return vsliq_n_p8(a, b, 1);
}

poly16x8_t np_vsliq_n_p16(poly16x8_t a, poly16x8_t b, int c)
{
	switch(c)
	{
		case 0:
			return vsliq_n_p16(a, b, 0);
		case 1:
			return vsliq_n_p16(a, b, 1);
		case 2:
			return vsliq_n_p16(a, b, 2);
		case 3:
			return vsliq_n_p16(a, b, 3);
		case 4:
			return vsliq_n_p16(a, b, 4);
		case 5:
			return vsliq_n_p16(a, b, 5);
		case 6:
			return vsliq_n_p16(a, b, 6);
		case 7:
			return vsliq_n_p16(a, b, 7);
		case 8:
			return vsliq_n_p16(a, b, 8);
		case 9:
			return vsliq_n_p16(a, b, 9);
		case 10:
			return vsliq_n_p16(a, b, 10);
		case 11:
			return vsliq_n_p16(a, b, 11);
		case 12:
			return vsliq_n_p16(a, b, 12);
		case 13:
			return vsliq_n_p16(a, b, 13);
		case 14:
			return vsliq_n_p16(a, b, 14);
		case 15:
			return vsliq_n_p16(a, b, 15);
	}
	return vsliq_n_p16(a, b, 1);
}

uint8x16_t np_vld1q_u8(uint8_t const * ptr)
{
	return vld1q_u8(ptr);
}

uint16x8_t np_vld1q_u16(uint16_t const * ptr)
{
	return vld1q_u16(ptr);
}

uint32x4_t np_vld1q_u32(uint32_t const * ptr)
{
	return vld1q_u32(ptr);
}

uint64x2_t np_vld1q_u64(uint64_t const * ptr)
{
	return vld1q_u64(ptr);
}

int8x16_t np_vld1q_s8(int8_t const * ptr)
{
	return vld1q_s8(ptr);
}

int16x8_t np_vld1q_s16(int16_t const * ptr)
{
	return vld1q_s16(ptr);
}

int32x4_t np_vld1q_s32(int32_t const * ptr)
{
	return vld1q_s32(ptr);
}

int64x2_t np_vld1q_s64(int64_t const * ptr)
{
	return vld1q_s64(ptr);
}

float32x4_t np_vld1q_f32(float32_t const * ptr)
{
	return vld1q_f32(ptr);
}

poly8x16_t np_vld1q_p8(poly8_t const * ptr)
{
	return vld1q_p8(ptr);
}

poly16x8_t np_vld1q_p16(poly16_t const * ptr)
{
	return vld1q_p16(ptr);
}

uint8x16_t np_vld1q_lane_u8(uint8_t const * ptr, uint8x16_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_u8(ptr, vec, 0);
		case 1:
			return vld1q_lane_u8(ptr, vec, 1);
		case 2:
			return vld1q_lane_u8(ptr, vec, 2);
		case 3:
			return vld1q_lane_u8(ptr, vec, 3);
		case 4:
			return vld1q_lane_u8(ptr, vec, 4);
		case 5:
			return vld1q_lane_u8(ptr, vec, 5);
		case 6:
			return vld1q_lane_u8(ptr, vec, 6);
		case 7:
			return vld1q_lane_u8(ptr, vec, 7);
		case 8:
			return vld1q_lane_u8(ptr, vec, 8);
		case 9:
			return vld1q_lane_u8(ptr, vec, 9);
		case 10:
			return vld1q_lane_u8(ptr, vec, 10);
		case 11:
			return vld1q_lane_u8(ptr, vec, 11);
		case 12:
			return vld1q_lane_u8(ptr, vec, 12);
		case 13:
			return vld1q_lane_u8(ptr, vec, 13);
		case 14:
			return vld1q_lane_u8(ptr, vec, 14);
		case 15:
			return vld1q_lane_u8(ptr, vec, 15);
	}
	return vld1q_lane_u8(ptr, vec, 1);
}

uint16x8_t np_vld1q_lane_u16(uint16_t const * ptr, uint16x8_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_u16(ptr, vec, 0);
		case 1:
			return vld1q_lane_u16(ptr, vec, 1);
		case 2:
			return vld1q_lane_u16(ptr, vec, 2);
		case 3:
			return vld1q_lane_u16(ptr, vec, 3);
		case 4:
			return vld1q_lane_u16(ptr, vec, 4);
		case 5:
			return vld1q_lane_u16(ptr, vec, 5);
		case 6:
			return vld1q_lane_u16(ptr, vec, 6);
		case 7:
			return vld1q_lane_u16(ptr, vec, 7);
	}
	return vld1q_lane_u16(ptr, vec, 1);
}

uint32x4_t np_vld1q_lane_u32(uint32_t const * ptr, uint32x4_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_u32(ptr, vec, 0);
		case 1:
			return vld1q_lane_u32(ptr, vec, 1);
		case 2:
			return vld1q_lane_u32(ptr, vec, 2);
		case 3:
			return vld1q_lane_u32(ptr, vec, 3);
	}
	return vld1q_lane_u32(ptr, vec, 1);
}

int8x16_t np_vld1q_lane_s8(int8_t const * ptr, int8x16_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_s8(ptr, vec, 0);
		case 1:
			return vld1q_lane_s8(ptr, vec, 1);
		case 2:
			return vld1q_lane_s8(ptr, vec, 2);
		case 3:
			return vld1q_lane_s8(ptr, vec, 3);
		case 4:
			return vld1q_lane_s8(ptr, vec, 4);
		case 5:
			return vld1q_lane_s8(ptr, vec, 5);
		case 6:
			return vld1q_lane_s8(ptr, vec, 6);
		case 7:
			return vld1q_lane_s8(ptr, vec, 7);
		case 8:
			return vld1q_lane_s8(ptr, vec, 8);
		case 9:
			return vld1q_lane_s8(ptr, vec, 9);
		case 10:
			return vld1q_lane_s8(ptr, vec, 10);
		case 11:
			return vld1q_lane_s8(ptr, vec, 11);
		case 12:
			return vld1q_lane_s8(ptr, vec, 12);
		case 13:
			return vld1q_lane_s8(ptr, vec, 13);
		case 14:
			return vld1q_lane_s8(ptr, vec, 14);
		case 15:
			return vld1q_lane_s8(ptr, vec, 15);
	}
	return vld1q_lane_s8(ptr, vec, 1);
}

int16x8_t np_vld1q_lane_s16(int16_t const * ptr, int16x8_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_s16(ptr, vec, 0);
		case 1:
			return vld1q_lane_s16(ptr, vec, 1);
		case 2:
			return vld1q_lane_s16(ptr, vec, 2);
		case 3:
			return vld1q_lane_s16(ptr, vec, 3);
		case 4:
			return vld1q_lane_s16(ptr, vec, 4);
		case 5:
			return vld1q_lane_s16(ptr, vec, 5);
		case 6:
			return vld1q_lane_s16(ptr, vec, 6);
		case 7:
			return vld1q_lane_s16(ptr, vec, 7);
	}
	return vld1q_lane_s16(ptr, vec, 1);
}

int32x4_t np_vld1q_lane_s32(int32_t const * ptr, int32x4_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_s32(ptr, vec, 0);
		case 1:
			return vld1q_lane_s32(ptr, vec, 1);
		case 2:
			return vld1q_lane_s32(ptr, vec, 2);
		case 3:
			return vld1q_lane_s32(ptr, vec, 3);
	}
	return vld1q_lane_s32(ptr, vec, 1);
}

float32x4_t np_vld1q_lane_f32(float32_t const * ptr, float32x4_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_f32(ptr, vec, 0);
		case 1:
			return vld1q_lane_f32(ptr, vec, 1);
		case 2:
			return vld1q_lane_f32(ptr, vec, 2);
		case 3:
			return vld1q_lane_f32(ptr, vec, 3);
	}
	return vld1q_lane_f32(ptr, vec, 1);
}

poly8x16_t np_vld1q_lane_p8(poly8_t const * ptr, poly8x16_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_p8(ptr, vec, 0);
		case 1:
			return vld1q_lane_p8(ptr, vec, 1);
		case 2:
			return vld1q_lane_p8(ptr, vec, 2);
		case 3:
			return vld1q_lane_p8(ptr, vec, 3);
		case 4:
			return vld1q_lane_p8(ptr, vec, 4);
		case 5:
			return vld1q_lane_p8(ptr, vec, 5);
		case 6:
			return vld1q_lane_p8(ptr, vec, 6);
		case 7:
			return vld1q_lane_p8(ptr, vec, 7);
		case 8:
			return vld1q_lane_p8(ptr, vec, 8);
		case 9:
			return vld1q_lane_p8(ptr, vec, 9);
		case 10:
			return vld1q_lane_p8(ptr, vec, 10);
		case 11:
			return vld1q_lane_p8(ptr, vec, 11);
		case 12:
			return vld1q_lane_p8(ptr, vec, 12);
		case 13:
			return vld1q_lane_p8(ptr, vec, 13);
		case 14:
			return vld1q_lane_p8(ptr, vec, 14);
		case 15:
			return vld1q_lane_p8(ptr, vec, 15);
	}
	return vld1q_lane_p8(ptr, vec, 1);
}

poly16x8_t np_vld1q_lane_p16(poly16_t const * ptr, poly16x8_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vld1q_lane_p16(ptr, vec, 0);
		case 1:
			return vld1q_lane_p16(ptr, vec, 1);
		case 2:
			return vld1q_lane_p16(ptr, vec, 2);
		case 3:
			return vld1q_lane_p16(ptr, vec, 3);
		case 4:
			return vld1q_lane_p16(ptr, vec, 4);
		case 5:
			return vld1q_lane_p16(ptr, vec, 5);
		case 6:
			return vld1q_lane_p16(ptr, vec, 6);
		case 7:
			return vld1q_lane_p16(ptr, vec, 7);
	}
	return vld1q_lane_p16(ptr, vec, 1);
}

uint8x16_t np_vld1q_dup_u8(uint8_t const * ptr)
{
	return vld1q_dup_u8(ptr);
}

uint16x8_t np_vld1q_dup_u16(uint16_t const * ptr)
{
	return vld1q_dup_u16(ptr);
}

uint32x4_t np_vld1q_dup_u32(uint32_t const * ptr)
{
	return vld1q_dup_u32(ptr);
}

int8x16_t np_vld1q_dup_s8(int8_t const * ptr)
{
	return vld1q_dup_s8(ptr);
}

int16x8_t np_vld1q_dup_s16(int16_t const * ptr)
{
	return vld1q_dup_s16(ptr);
}

int32x4_t np_vld1q_dup_s32(int32_t const * ptr)
{
	return vld1q_dup_s32(ptr);
}

float32x4_t np_vld1q_dup_f32(float32_t const * ptr)
{
	return vld1q_dup_f32(ptr);
}

poly8x16_t np_vld1q_dup_p8(poly8_t const * ptr)
{
	return vld1q_dup_p8(ptr);
}

poly16x8_t np_vld1q_dup_p16(poly16_t const * ptr)
{
	return vld1q_dup_p16(ptr);
}

void np_vst1q_u8(uint8_t * ptr, uint8x16_t val)
{
	vst1q_u8(ptr, val);
}

void np_vst1q_u16(uint16_t * ptr, uint16x8_t val)
{
	vst1q_u16(ptr, val);
}

void np_vst1q_u32(uint32_t * ptr, uint32x4_t val)
{
	vst1q_u32(ptr, val);
}

void np_vst1q_u64(uint64_t * ptr, uint64x2_t val)
{
	vst1q_u64(ptr, val);
}

void np_vst1q_s8(int8_t * ptr, int8x16_t val)
{
	vst1q_s8(ptr, val);
}

void np_vst1q_s16(int16_t * ptr, int16x8_t val)
{
	vst1q_s16(ptr, val);
}

void np_vst1q_s32(int32_t * ptr, int32x4_t val)
{
	vst1q_s32(ptr, val);
}

void np_vst1q_s64(int64_t * ptr, int64x2_t val)
{
	vst1q_s64(ptr, val);
}

void np_vst1q_f32(float32_t * ptr, float32x4_t val)
{
	vst1q_f32(ptr, val);
}

void np_vst1q_p8(poly8_t * ptr, poly8x16_t val)
{
	vst1q_p8(ptr, val);
}

void np_vst1q_p16(poly16_t * ptr, poly16x8_t val)
{
	vst1q_p16(ptr, val);
}

uint8x16x2_t np_vld2q_u8(uint8_t const * ptr)
{
	return vld2q_u8(ptr);
}

uint16x8x2_t np_vld2q_u16(uint16_t const * ptr)
{
	return vld2q_u16(ptr);
}

uint32x4x2_t np_vld2q_u32(uint32_t const * ptr)
{
	return vld2q_u32(ptr);
}

int8x16x2_t np_vld2q_s8(int8_t const * ptr)
{
	return vld2q_s8(ptr);
}

int16x8x2_t np_vld2q_s16(int16_t const * ptr)
{
	return vld2q_s16(ptr);
}

int32x4x2_t np_vld2q_s32(int32_t const * ptr)
{
	return vld2q_s32(ptr);
}

float32x4x2_t np_vld2q_f32(float32_t const * ptr)
{
	return vld2q_f32(ptr);
}

poly8x16x2_t np_vld2q_p8(poly8_t const * ptr)
{
	return vld2q_p8(ptr);
}

poly16x8x2_t np_vld2q_p16(poly16_t const * ptr)
{
	return vld2q_p16(ptr);
}

uint8x16x3_t np_vld3q_u8(uint8_t const * ptr)
{
	return vld3q_u8(ptr);
}

uint16x8x3_t np_vld3q_u16(uint16_t const * ptr)
{
	return vld3q_u16(ptr);
}

uint32x4x3_t np_vld3q_u32(uint32_t const * ptr)
{
	return vld3q_u32(ptr);
}

int8x16x3_t np_vld3q_s8(int8_t const * ptr)
{
	return vld3q_s8(ptr);
}

int16x8x3_t np_vld3q_s16(int16_t const * ptr)
{
	return vld3q_s16(ptr);
}

int32x4x3_t np_vld3q_s32(int32_t const * ptr)
{
	return vld3q_s32(ptr);
}

float32x4x3_t np_vld3q_f32(float32_t const * ptr)
{
	return vld3q_f32(ptr);
}

poly8x16x3_t np_vld3q_p8(poly8_t const * ptr)
{
	return vld3q_p8(ptr);
}

poly16x8x3_t np_vld3q_p16(poly16_t const * ptr)
{
	return vld3q_p16(ptr);
}

uint8x16x4_t np_vld4q_u8(uint8_t const * ptr)
{
	return vld4q_u8(ptr);
}

uint16x8x4_t np_vld4q_u16(uint16_t const * ptr)
{
	return vld4q_u16(ptr);
}

uint32x4x4_t np_vld4q_u32(uint32_t const * ptr)
{
	return vld4q_u32(ptr);
}

int8x16x4_t np_vld4q_s8(int8_t const * ptr)
{
	return vld4q_s8(ptr);
}

int16x8x4_t np_vld4q_s16(int16_t const * ptr)
{
	return vld4q_s16(ptr);
}

int32x4x4_t np_vld4q_s32(int32_t const * ptr)
{
	return vld4q_s32(ptr);
}

float32x4x4_t np_vld4q_f32(float32_t const * ptr)
{
	return vld4q_f32(ptr);
}

poly8x16x4_t np_vld4q_p8(poly8_t const * ptr)
{
	return vld4q_p8(ptr);
}

poly16x8x4_t np_vld4q_p16(poly16_t const * ptr)
{
	return vld4q_p16(ptr);
}

uint8x16_t np_vsetq_lane_u8(uint8_t value, uint8x16_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_u8(value, vec, 0);
		case 1:
			return vsetq_lane_u8(value, vec, 1);
		case 2:
			return vsetq_lane_u8(value, vec, 2);
		case 3:
			return vsetq_lane_u8(value, vec, 3);
		case 4:
			return vsetq_lane_u8(value, vec, 4);
		case 5:
			return vsetq_lane_u8(value, vec, 5);
		case 6:
			return vsetq_lane_u8(value, vec, 6);
		case 7:
			return vsetq_lane_u8(value, vec, 7);
		case 8:
			return vsetq_lane_u8(value, vec, 8);
		case 9:
			return vsetq_lane_u8(value, vec, 9);
		case 10:
			return vsetq_lane_u8(value, vec, 10);
		case 11:
			return vsetq_lane_u8(value, vec, 11);
		case 12:
			return vsetq_lane_u8(value, vec, 12);
		case 13:
			return vsetq_lane_u8(value, vec, 13);
		case 14:
			return vsetq_lane_u8(value, vec, 14);
		case 15:
			return vsetq_lane_u8(value, vec, 15);
	}
	return vsetq_lane_u8(value, vec, 1);
}

uint16x8_t np_vsetq_lane_u16(uint16_t value, uint16x8_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_u16(value, vec, 0);
		case 1:
			return vsetq_lane_u16(value, vec, 1);
		case 2:
			return vsetq_lane_u16(value, vec, 2);
		case 3:
			return vsetq_lane_u16(value, vec, 3);
		case 4:
			return vsetq_lane_u16(value, vec, 4);
		case 5:
			return vsetq_lane_u16(value, vec, 5);
		case 6:
			return vsetq_lane_u16(value, vec, 6);
		case 7:
			return vsetq_lane_u16(value, vec, 7);
	}
	return vsetq_lane_u16(value, vec, 1);
}

uint32x4_t np_vsetq_lane_u32(uint32_t value, uint32x4_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_u32(value, vec, 0);
		case 1:
			return vsetq_lane_u32(value, vec, 1);
		case 2:
			return vsetq_lane_u32(value, vec, 2);
		case 3:
			return vsetq_lane_u32(value, vec, 3);
	}
	return vsetq_lane_u32(value, vec, 1);
}

int8x16_t np_vsetq_lane_s8(int8_t value, int8x16_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_s8(value, vec, 0);
		case 1:
			return vsetq_lane_s8(value, vec, 1);
		case 2:
			return vsetq_lane_s8(value, vec, 2);
		case 3:
			return vsetq_lane_s8(value, vec, 3);
		case 4:
			return vsetq_lane_s8(value, vec, 4);
		case 5:
			return vsetq_lane_s8(value, vec, 5);
		case 6:
			return vsetq_lane_s8(value, vec, 6);
		case 7:
			return vsetq_lane_s8(value, vec, 7);
		case 8:
			return vsetq_lane_s8(value, vec, 8);
		case 9:
			return vsetq_lane_s8(value, vec, 9);
		case 10:
			return vsetq_lane_s8(value, vec, 10);
		case 11:
			return vsetq_lane_s8(value, vec, 11);
		case 12:
			return vsetq_lane_s8(value, vec, 12);
		case 13:
			return vsetq_lane_s8(value, vec, 13);
		case 14:
			return vsetq_lane_s8(value, vec, 14);
		case 15:
			return vsetq_lane_s8(value, vec, 15);
	}
	return vsetq_lane_s8(value, vec, 1);
}

int16x8_t np_vsetq_lane_s16(int16_t value, int16x8_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_s16(value, vec, 0);
		case 1:
			return vsetq_lane_s16(value, vec, 1);
		case 2:
			return vsetq_lane_s16(value, vec, 2);
		case 3:
			return vsetq_lane_s16(value, vec, 3);
		case 4:
			return vsetq_lane_s16(value, vec, 4);
		case 5:
			return vsetq_lane_s16(value, vec, 5);
		case 6:
			return vsetq_lane_s16(value, vec, 6);
		case 7:
			return vsetq_lane_s16(value, vec, 7);
	}
	return vsetq_lane_s16(value, vec, 1);
}

int32x4_t np_vsetq_lane_s32(int32_t value, int32x4_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_s32(value, vec, 0);
		case 1:
			return vsetq_lane_s32(value, vec, 1);
		case 2:
			return vsetq_lane_s32(value, vec, 2);
		case 3:
			return vsetq_lane_s32(value, vec, 3);
	}
	return vsetq_lane_s32(value, vec, 1);
}

poly8x16_t np_vsetq_lane_p8(poly8_t value, poly8x16_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_p8(value, vec, 0);
		case 1:
			return vsetq_lane_p8(value, vec, 1);
		case 2:
			return vsetq_lane_p8(value, vec, 2);
		case 3:
			return vsetq_lane_p8(value, vec, 3);
		case 4:
			return vsetq_lane_p8(value, vec, 4);
		case 5:
			return vsetq_lane_p8(value, vec, 5);
		case 6:
			return vsetq_lane_p8(value, vec, 6);
		case 7:
			return vsetq_lane_p8(value, vec, 7);
		case 8:
			return vsetq_lane_p8(value, vec, 8);
		case 9:
			return vsetq_lane_p8(value, vec, 9);
		case 10:
			return vsetq_lane_p8(value, vec, 10);
		case 11:
			return vsetq_lane_p8(value, vec, 11);
		case 12:
			return vsetq_lane_p8(value, vec, 12);
		case 13:
			return vsetq_lane_p8(value, vec, 13);
		case 14:
			return vsetq_lane_p8(value, vec, 14);
		case 15:
			return vsetq_lane_p8(value, vec, 15);
	}
	return vsetq_lane_p8(value, vec, 1);
}

poly16x8_t np_vsetq_lane_p16(poly16_t value, poly16x8_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_p16(value, vec, 0);
		case 1:
			return vsetq_lane_p16(value, vec, 1);
		case 2:
			return vsetq_lane_p16(value, vec, 2);
		case 3:
			return vsetq_lane_p16(value, vec, 3);
		case 4:
			return vsetq_lane_p16(value, vec, 4);
		case 5:
			return vsetq_lane_p16(value, vec, 5);
		case 6:
			return vsetq_lane_p16(value, vec, 6);
		case 7:
			return vsetq_lane_p16(value, vec, 7);
	}
	return vsetq_lane_p16(value, vec, 1);
}

float32x4_t np_vsetq_lane_f32(float32_t value, float32x4_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_f32(value, vec, 0);
		case 1:
			return vsetq_lane_f32(value, vec, 1);
		case 2:
			return vsetq_lane_f32(value, vec, 2);
		case 3:
			return vsetq_lane_f32(value, vec, 3);
	}
	return vsetq_lane_f32(value, vec, 1);
}

int64x2_t np_vsetq_lane_s64(int64_t value, int64x2_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_s64(value, vec, 0);
		case 1:
			return vsetq_lane_s64(value, vec, 1);
	}
	return vsetq_lane_s64(value, vec, 1);
}

uint64x2_t np_vsetq_lane_u64(uint64_t value, uint64x2_t vec, int lane)
{
	switch(lane)
	{
		case 0:
			return vsetq_lane_u64(value, vec, 0);
		case 1:
			return vsetq_lane_u64(value, vec, 1);
	}
	return vsetq_lane_u64(value, vec, 1);
}

uint8x16_t np_vdupq_n_u8(uint8_t value)
{
	return vdupq_n_u8(value);
}

uint16x8_t np_vdupq_n_u16(uint16_t value)
{
	return vdupq_n_u16(value);
}

uint32x4_t np_vdupq_n_u32(uint32_t value)
{
	return vdupq_n_u32(value);
}

int8x16_t np_vdupq_n_s8(int8_t value)
{
	return vdupq_n_s8(value);
}

int16x8_t np_vdupq_n_s16(int16_t value)
{
	return vdupq_n_s16(value);
}

int32x4_t np_vdupq_n_s32(int32_t value)
{
	return vdupq_n_s32(value);
}

poly8x16_t np_vdupq_n_p8(poly8_t value)
{
	return vdupq_n_p8(value);
}

poly16x8_t np_vdupq_n_p16(poly16_t value)
{
	return vdupq_n_p16(value);
}

float32x4_t np_vdupq_n_f32(float32_t value)
{
	return vdupq_n_f32(value);
}

int64x2_t np_vdupq_n_s64(int64_t value)
{
	return vdupq_n_s64(value);
}

uint64x2_t np_vdupq_n_u64(uint64_t value)
{
	return vdupq_n_u64(value);
}

uint8x16_t np_vmovq_n_u8(uint8_t value)
{
	return vmovq_n_u8(value);
}

uint16x8_t np_vmovq_n_u16(uint16_t value)
{
	return vmovq_n_u16(value);
}

uint32x4_t np_vmovq_n_u32(uint32_t value)
{
	return vmovq_n_u32(value);
}

int8x16_t np_vmovq_n_s8(int8_t value)
{
	return vmovq_n_s8(value);
}

int16x8_t np_vmovq_n_s16(int16_t value)
{
	return vmovq_n_s16(value);
}

int32x4_t np_vmovq_n_s32(int32_t value)
{
	return vmovq_n_s32(value);
}

poly8x16_t np_vmovq_n_p8(poly8_t value)
{
	return vmovq_n_p8(value);
}

poly16x8_t np_vmovq_n_p16(poly16_t value)
{
	return vmovq_n_p16(value);
}

float32x4_t np_vmovq_n_f32(float32_t value)
{
	return vmovq_n_f32(value);
}

int64x2_t np_vmovq_n_s64(int64_t value)
{
	return vmovq_n_s64(value);
}

uint64x2_t np_vmovq_n_u64(uint64_t value)
{
	return vmovq_n_u64(value);
}

int32x4_t np_vcvtq_s32_f32(float32x4_t a)
{
	return vcvtq_s32_f32(a);
}

uint32x4_t np_vcvtq_u32_f32(float32x4_t a)
{
	return vcvtq_u32_f32(a);
}

float32x4_t np_vcvtq_f32_s32(int32x4_t a)
{
	return vcvtq_f32_s32(a);
}

float32x4_t np_vcvtq_f32_u32(uint32x4_t a)
{
	return vcvtq_f32_u32(a);
}

int16x8_t np_vmulq_n_s16(int16x8_t a, int16_t b)
{
	return vmulq_n_s16(a, b);
}

int32x4_t np_vmulq_n_s32(int32x4_t a, int32_t b)
{
	return vmulq_n_s32(a, b);
}

float32x4_t np_vmulq_n_f32(float32x4_t a, float32_t b)
{
	return vmulq_n_f32(a, b);
}

uint16x8_t np_vmulq_n_u16(uint16x8_t a, uint16_t b)
{
	return vmulq_n_u16(a, b);
}

uint32x4_t np_vmulq_n_u32(uint32x4_t a, uint32_t b)
{
	return vmulq_n_u32(a, b);
}

int16x8_t np_vqdmulhq_n_s16(int16x8_t vec1, int16_t val2)
{
	return vqdmulhq_n_s16(vec1, val2);
}

int32x4_t np_vqdmulhq_n_s32(int32x4_t vec1, int32_t val2)
{
	return vqdmulhq_n_s32(vec1, val2);
}

int16x8_t np_vqrdmulhq_n_s16(int16x8_t vec1, int16_t val2)
{
	return vqrdmulhq_n_s16(vec1, val2);
}

int32x4_t np_vqrdmulhq_n_s32(int32x4_t vec1, int32_t val2)
{
	return vqrdmulhq_n_s32(vec1, val2);
}

int16x8_t np_vmlaq_n_s16(int16x8_t a, int16x8_t b, int16_t c)
{
	return vmlaq_n_s16(a, b, c);
}

int32x4_t np_vmlaq_n_s32(int32x4_t a, int32x4_t b, int32_t c)
{
	return vmlaq_n_s32(a, b, c);
}

uint16x8_t np_vmlaq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c)
{
	return vmlaq_n_u16(a, b, c);
}

uint32x4_t np_vmlaq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c)
{
	return vmlaq_n_u32(a, b, c);
}

float32x4_t np_vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c)
{
	return vmlaq_n_f32(a, b, c);
}

int16x8_t np_vmlsq_n_s16(int16x8_t a, int16x8_t b, int16_t c)
{
	return vmlsq_n_s16(a, b, c);
}

int32x4_t np_vmlsq_n_s32(int32x4_t a, int32x4_t b, int32_t c)
{
	return vmlsq_n_s32(a, b, c);
}

uint16x8_t np_vmlsq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c)
{
	return vmlsq_n_u16(a, b, c);
}

uint32x4_t np_vmlsq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c)
{
	return vmlsq_n_u32(a, b, c);
}

float32x4_t np_vmlsq_n_f32(float32x4_t a, float32x4_t b, float32_t c)
{
	return vmlsq_n_f32(a, b, c);
}

int8x16_t np_vextq_s8(int8x16_t a, int8x16_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_s8(a, b, 0);
		case 1:
			return vextq_s8(a, b, 1);
		case 2:
			return vextq_s8(a, b, 2);
		case 3:
			return vextq_s8(a, b, 3);
		case 4:
			return vextq_s8(a, b, 4);
		case 5:
			return vextq_s8(a, b, 5);
		case 6:
			return vextq_s8(a, b, 6);
		case 7:
			return vextq_s8(a, b, 7);
		case 8:
			return vextq_s8(a, b, 8);
		case 9:
			return vextq_s8(a, b, 9);
		case 10:
			return vextq_s8(a, b, 10);
		case 11:
			return vextq_s8(a, b, 11);
		case 12:
			return vextq_s8(a, b, 12);
		case 13:
			return vextq_s8(a, b, 13);
		case 14:
			return vextq_s8(a, b, 14);
		case 15:
			return vextq_s8(a, b, 15);
	}
	return vextq_s8(a, b, 1);
}

uint8x16_t np_vextq_u8(uint8x16_t a, uint8x16_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_u8(a, b, 0);
		case 1:
			return vextq_u8(a, b, 1);
		case 2:
			return vextq_u8(a, b, 2);
		case 3:
			return vextq_u8(a, b, 3);
		case 4:
			return vextq_u8(a, b, 4);
		case 5:
			return vextq_u8(a, b, 5);
		case 6:
			return vextq_u8(a, b, 6);
		case 7:
			return vextq_u8(a, b, 7);
		case 8:
			return vextq_u8(a, b, 8);
		case 9:
			return vextq_u8(a, b, 9);
		case 10:
			return vextq_u8(a, b, 10);
		case 11:
			return vextq_u8(a, b, 11);
		case 12:
			return vextq_u8(a, b, 12);
		case 13:
			return vextq_u8(a, b, 13);
		case 14:
			return vextq_u8(a, b, 14);
		case 15:
			return vextq_u8(a, b, 15);
	}
	return vextq_u8(a, b, 1);
}

poly8x16_t np_vextq_p8(poly8x16_t a, poly8x16_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_p8(a, b, 0);
		case 1:
			return vextq_p8(a, b, 1);
		case 2:
			return vextq_p8(a, b, 2);
		case 3:
			return vextq_p8(a, b, 3);
		case 4:
			return vextq_p8(a, b, 4);
		case 5:
			return vextq_p8(a, b, 5);
		case 6:
			return vextq_p8(a, b, 6);
		case 7:
			return vextq_p8(a, b, 7);
		case 8:
			return vextq_p8(a, b, 8);
		case 9:
			return vextq_p8(a, b, 9);
		case 10:
			return vextq_p8(a, b, 10);
		case 11:
			return vextq_p8(a, b, 11);
		case 12:
			return vextq_p8(a, b, 12);
		case 13:
			return vextq_p8(a, b, 13);
		case 14:
			return vextq_p8(a, b, 14);
		case 15:
			return vextq_p8(a, b, 15);
	}
	return vextq_p8(a, b, 1);
}

int16x8_t np_vextq_s16(int16x8_t a, int16x8_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_s16(a, b, 0);
		case 1:
			return vextq_s16(a, b, 1);
		case 2:
			return vextq_s16(a, b, 2);
		case 3:
			return vextq_s16(a, b, 3);
		case 4:
			return vextq_s16(a, b, 4);
		case 5:
			return vextq_s16(a, b, 5);
		case 6:
			return vextq_s16(a, b, 6);
		case 7:
			return vextq_s16(a, b, 7);
	}
	return vextq_s16(a, b, 1);
}

uint16x8_t np_vextq_u16(uint16x8_t a, uint16x8_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_u16(a, b, 0);
		case 1:
			return vextq_u16(a, b, 1);
		case 2:
			return vextq_u16(a, b, 2);
		case 3:
			return vextq_u16(a, b, 3);
		case 4:
			return vextq_u16(a, b, 4);
		case 5:
			return vextq_u16(a, b, 5);
		case 6:
			return vextq_u16(a, b, 6);
		case 7:
			return vextq_u16(a, b, 7);
	}
	return vextq_u16(a, b, 1);
}

poly16x8_t np_vextq_p16(poly16x8_t a, poly16x8_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_p16(a, b, 0);
		case 1:
			return vextq_p16(a, b, 1);
		case 2:
			return vextq_p16(a, b, 2);
		case 3:
			return vextq_p16(a, b, 3);
		case 4:
			return vextq_p16(a, b, 4);
		case 5:
			return vextq_p16(a, b, 5);
		case 6:
			return vextq_p16(a, b, 6);
		case 7:
			return vextq_p16(a, b, 7);
	}
	return vextq_p16(a, b, 1);
}

int32x4_t np_vextq_s32(int32x4_t a, int32x4_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_s32(a, b, 0);
		case 1:
			return vextq_s32(a, b, 1);
		case 2:
			return vextq_s32(a, b, 2);
		case 3:
			return vextq_s32(a, b, 3);
	}
	return vextq_s32(a, b, 1);
}

uint32x4_t np_vextq_u32(uint32x4_t a, uint32x4_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_u32(a, b, 0);
		case 1:
			return vextq_u32(a, b, 1);
		case 2:
			return vextq_u32(a, b, 2);
		case 3:
			return vextq_u32(a, b, 3);
	}
	return vextq_u32(a, b, 1);
}

int64x2_t np_vextq_s64(int64x2_t a, int64x2_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_s64(a, b, 0);
		case 1:
			return vextq_s64(a, b, 1);
	}
	return vextq_s64(a, b, 1);
}

uint64x2_t np_vextq_u64(uint64x2_t a, uint64x2_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_u64(a, b, 0);
		case 1:
			return vextq_u64(a, b, 1);
	}
	return vextq_u64(a, b, 1);
}

float32x4_t np_vextq_f32(float32x4_t a, float32x4_t b, int c)
{
	switch(c)
	{
		case 0:
			return vextq_f32(a, b, 0);
		case 1:
			return vextq_f32(a, b, 1);
		case 2:
			return vextq_f32(a, b, 2);
		case 3:
			return vextq_f32(a, b, 3);
	}
	return vextq_f32(a, b, 1);
}

int8x16_t np_vrev64q_s8(int8x16_t vec)
{
	return vrev64q_s8(vec);
}

int16x8_t np_vrev64q_s16(int16x8_t vec)
{
	return vrev64q_s16(vec);
}

int32x4_t np_vrev64q_s32(int32x4_t vec)
{
	return vrev64q_s32(vec);
}

uint8x16_t np_vrev64q_u8(uint8x16_t vec)
{
	return vrev64q_u8(vec);
}

uint16x8_t np_vrev64q_u16(uint16x8_t vec)
{
	return vrev64q_u16(vec);
}

uint32x4_t np_vrev64q_u32(uint32x4_t vec)
{
	return vrev64q_u32(vec);
}

poly8x16_t np_vrev64q_p8(poly8x16_t vec)
{
	return vrev64q_p8(vec);
}

poly16x8_t np_vrev64q_p16(poly16x8_t vec)
{
	return vrev64q_p16(vec);
}

float32x4_t np_vrev64q_f32(float32x4_t vec)
{
	return vrev64q_f32(vec);
}

int8x16_t np_vrev32q_s8(int8x16_t vec)
{
	return vrev32q_s8(vec);
}

int16x8_t np_vrev32q_s16(int16x8_t vec)
{
	return vrev32q_s16(vec);
}

uint8x16_t np_vrev32q_u8(uint8x16_t vec)
{
	return vrev32q_u8(vec);
}

uint16x8_t np_vrev32q_u16(uint16x8_t vec)
{
	return vrev32q_u16(vec);
}

poly8x16_t np_vrev32q_p8(poly8x16_t vec)
{
	return vrev32q_p8(vec);
}

poly16x8_t np_vrev32q_p16(poly16x8_t vec)
{
	return vrev32q_p16(vec);
}

int8x16_t np_vrev16q_s8(int8x16_t vec)
{
	return vrev16q_s8(vec);
}

uint8x16_t np_vrev16q_u8(uint8x16_t vec)
{
	return vrev16q_u8(vec);
}

poly8x16_t np_vrev16q_p8(poly8x16_t vec)
{
	return vrev16q_p8(vec);
}

int8x16_t np_vabsq_s8(int8x16_t a)
{
	return vabsq_s8(a);
}

int16x8_t np_vabsq_s16(int16x8_t a)
{
	return vabsq_s16(a);
}

int32x4_t np_vabsq_s32(int32x4_t a)
{
	return vabsq_s32(a);
}

float32x4_t np_vabsq_f32(float32x4_t a)
{
	return vabsq_f32(a);
}

int8x16_t np_vqabsq_s8(int8x16_t a)
{
	return vqabsq_s8(a);
}

int16x8_t np_vqabsq_s16(int16x8_t a)
{
	return vqabsq_s16(a);
}

int32x4_t np_vqabsq_s32(int32x4_t a)
{
	return vqabsq_s32(a);
}

int8x16_t np_vnegq_s8(int8x16_t a)
{
	return vnegq_s8(a);
}

int16x8_t np_vnegq_s16(int16x8_t a)
{
	return vnegq_s16(a);
}

int32x4_t np_vnegq_s32(int32x4_t a)
{
	return vnegq_s32(a);
}

float32x4_t np_vnegq_f32(float32x4_t a)
{
	return vnegq_f32(a);
}

int8x16_t np_vqnegq_s8(int8x16_t a)
{
	return vqnegq_s8(a);
}

int16x8_t np_vqnegq_s16(int16x8_t a)
{
	return vqnegq_s16(a);
}

int32x4_t np_vqnegq_s32(int32x4_t a)
{
	return vqnegq_s32(a);
}

int8x16_t np_vclsq_s8(int8x16_t a)
{
	return vclsq_s8(a);
}

int16x8_t np_vclsq_s16(int16x8_t a)
{
	return vclsq_s16(a);
}

int32x4_t np_vclsq_s32(int32x4_t a)
{
	return vclsq_s32(a);
}

int8x16_t np_vclzq_s8(int8x16_t a)
{
	return vclzq_s8(a);
}

int16x8_t np_vclzq_s16(int16x8_t a)
{
	return vclzq_s16(a);
}

int32x4_t np_vclzq_s32(int32x4_t a)
{
	return vclzq_s32(a);
}

uint8x16_t np_vclzq_u8(uint8x16_t a)
{
	return vclzq_u8(a);
}

uint16x8_t np_vclzq_u16(uint16x8_t a)
{
	return vclzq_u16(a);
}

uint32x4_t np_vclzq_u32(uint32x4_t a)
{
	return vclzq_u32(a);
}

uint8x16_t np_vcntq_u8(uint8x16_t a)
{
	return vcntq_u8(a);
}

int8x16_t np_vcntq_s8(int8x16_t a)
{
	return vcntq_s8(a);
}

poly8x16_t np_vcntq_p8(poly8x16_t a)
{
	return vcntq_p8(a);
}

float32x4_t np_vrecpeq_f32(float32x4_t a)
{
	return vrecpeq_f32(a);
}

uint32x4_t np_vrecpeq_u32(uint32x4_t a)
{
	return vrecpeq_u32(a);
}

float32x4_t np_vrsqrteq_f32(float32x4_t a)
{
	return vrsqrteq_f32(a);
}

uint32x4_t np_vrsqrteq_u32(uint32x4_t a)
{
	return vrsqrteq_u32(a);
}

int8x16_t np_vmvnq_s8(int8x16_t a)
{
	return vmvnq_s8(a);
}

int16x8_t np_vmvnq_s16(int16x8_t a)
{
	return vmvnq_s16(a);
}

int32x4_t np_vmvnq_s32(int32x4_t a)
{
	return vmvnq_s32(a);
}

uint8x16_t np_vmvnq_u8(uint8x16_t a)
{
	return vmvnq_u8(a);
}

uint16x8_t np_vmvnq_u16(uint16x8_t a)
{
	return vmvnq_u16(a);
}

uint32x4_t np_vmvnq_u32(uint32x4_t a)
{
	return vmvnq_u32(a);
}

poly8x16_t np_vmvnq_p8(poly8x16_t a)
{
	return vmvnq_p8(a);
}

int8x16_t np_vandq_s8(int8x16_t a, int8x16_t b)
{
	return vandq_s8(a, b);
}

int16x8_t np_vandq_s16(int16x8_t a, int16x8_t b)
{
	return vandq_s16(a, b);
}

int32x4_t np_vandq_s32(int32x4_t a, int32x4_t b)
{
	return vandq_s32(a, b);
}

int64x2_t np_vandq_s64(int64x2_t a, int64x2_t b)
{
	return vandq_s64(a, b);
}

uint8x16_t np_vandq_u8(uint8x16_t a, uint8x16_t b)
{
	return vandq_u8(a, b);
}

uint16x8_t np_vandq_u16(uint16x8_t a, uint16x8_t b)
{
	return vandq_u16(a, b);
}

uint32x4_t np_vandq_u32(uint32x4_t a, uint32x4_t b)
{
	return vandq_u32(a, b);
}

uint64x2_t np_vandq_u64(uint64x2_t a, uint64x2_t b)
{
	return vandq_u64(a, b);
}

int8x16_t np_vorrq_s8(int8x16_t a, int8x16_t b)
{
	return vorrq_s8(a, b);
}

int16x8_t np_vorrq_s16(int16x8_t a, int16x8_t b)
{
	return vorrq_s16(a, b);
}

int32x4_t np_vorrq_s32(int32x4_t a, int32x4_t b)
{
	return vorrq_s32(a, b);
}

int64x2_t np_vorrq_s64(int64x2_t a, int64x2_t b)
{
	return vorrq_s64(a, b);
}

uint8x16_t np_vorrq_u8(uint8x16_t a, uint8x16_t b)
{
	return vorrq_u8(a, b);
}

uint16x8_t np_vorrq_u16(uint16x8_t a, uint16x8_t b)
{
	return vorrq_u16(a, b);
}

uint32x4_t np_vorrq_u32(uint32x4_t a, uint32x4_t b)
{
	return vorrq_u32(a, b);
}

uint64x2_t np_vorrq_u64(uint64x2_t a, uint64x2_t b)
{
	return vorrq_u64(a, b);
}

int8x16_t np_veorq_s8(int8x16_t a, int8x16_t b)
{
	return veorq_s8(a, b);
}

int16x8_t np_veorq_s16(int16x8_t a, int16x8_t b)
{
	return veorq_s16(a, b);
}

int32x4_t np_veorq_s32(int32x4_t a, int32x4_t b)
{
	return veorq_s32(a, b);
}

int64x2_t np_veorq_s64(int64x2_t a, int64x2_t b)
{
	return veorq_s64(a, b);
}

uint8x16_t np_veorq_u8(uint8x16_t a, uint8x16_t b)
{
	return veorq_u8(a, b);
}

uint16x8_t np_veorq_u16(uint16x8_t a, uint16x8_t b)
{
	return veorq_u16(a, b);
}

uint32x4_t np_veorq_u32(uint32x4_t a, uint32x4_t b)
{
	return veorq_u32(a, b);
}

uint64x2_t np_veorq_u64(uint64x2_t a, uint64x2_t b)
{
	return veorq_u64(a, b);
}

int8x16_t np_vbicq_s8(int8x16_t a, int8x16_t b)
{
	return vbicq_s8(a, b);
}

int16x8_t np_vbicq_s16(int16x8_t a, int16x8_t b)
{
	return vbicq_s16(a, b);
}

int32x4_t np_vbicq_s32(int32x4_t a, int32x4_t b)
{
	return vbicq_s32(a, b);
}

int64x2_t np_vbicq_s64(int64x2_t a, int64x2_t b)
{
	return vbicq_s64(a, b);
}

uint8x16_t np_vbicq_u8(uint8x16_t a, uint8x16_t b)
{
	return vbicq_u8(a, b);
}

uint16x8_t np_vbicq_u16(uint16x8_t a, uint16x8_t b)
{
	return vbicq_u16(a, b);
}

uint32x4_t np_vbicq_u32(uint32x4_t a, uint32x4_t b)
{
	return vbicq_u32(a, b);
}

uint64x2_t np_vbicq_u64(uint64x2_t a, uint64x2_t b)
{
	return vbicq_u64(a, b);
}

int8x16_t np_vornq_s8(int8x16_t a, int8x16_t b)
{
	return vornq_s8(a, b);
}

int16x8_t np_vornq_s16(int16x8_t a, int16x8_t b)
{
	return vornq_s16(a, b);
}

int32x4_t np_vornq_s32(int32x4_t a, int32x4_t b)
{
	return vornq_s32(a, b);
}

int64x2_t np_vornq_s64(int64x2_t a, int64x2_t b)
{
	return vornq_s64(a, b);
}

uint8x16_t np_vornq_u8(uint8x16_t a, uint8x16_t b)
{
	return vornq_u8(a, b);
}

uint16x8_t np_vornq_u16(uint16x8_t a, uint16x8_t b)
{
	return vornq_u16(a, b);
}

uint32x4_t np_vornq_u32(uint32x4_t a, uint32x4_t b)
{
	return vornq_u32(a, b);
}

uint64x2_t np_vornq_u64(uint64x2_t a, uint64x2_t b)
{
	return vornq_u64(a, b);
}

int8x16_t np_vbslq_s8(uint8x16_t a, int8x16_t b, int8x16_t c)
{
	return vbslq_s8(a, b, c);
}

int16x8_t np_vbslq_s16(uint16x8_t a, int16x8_t b, int16x8_t c)
{
	return vbslq_s16(a, b, c);
}

int32x4_t np_vbslq_s32(uint32x4_t a, int32x4_t b, int32x4_t c)
{
	return vbslq_s32(a, b, c);
}

int64x2_t np_vbslq_s64(uint64x2_t a, int64x2_t b, int64x2_t c)
{
	return vbslq_s64(a, b, c);
}

uint8x16_t np_vbslq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c)
{
	return vbslq_u8(a, b, c);
}

uint16x8_t np_vbslq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c)
{
	return vbslq_u16(a, b, c);
}

uint32x4_t np_vbslq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c)
{
	return vbslq_u32(a, b, c);
}

uint64x2_t np_vbslq_u64(uint64x2_t a, uint64x2_t b, uint64x2_t c)
{
	return vbslq_u64(a, b, c);
}

float32x4_t np_vbslq_f32(uint32x4_t a, float32x4_t b, float32x4_t c)
{
	return vbslq_f32(a, b, c);
}

poly8x16_t np_vbslq_p8(uint8x16_t a, poly8x16_t b, poly8x16_t c)
{
	return vbslq_p8(a, b, c);
}

poly16x8_t np_vbslq_p16(uint16x8_t a, poly16x8_t b, poly16x8_t c)
{
	return vbslq_p16(a, b, c);
}

int8x16x2_t np_vtrnq_s8(int8x16_t a, int8x16_t b)
{
	return vtrnq_s8(a, b);
}

int16x8x2_t np_vtrnq_s16(int16x8_t a, int16x8_t b)
{
	return vtrnq_s16(a, b);
}

int32x4x2_t np_vtrnq_s32(int32x4_t a, int32x4_t b)
{
	return vtrnq_s32(a, b);
}

uint8x16x2_t np_vtrnq_u8(uint8x16_t a, uint8x16_t b)
{
	return vtrnq_u8(a, b);
}

uint16x8x2_t np_vtrnq_u16(uint16x8_t a, uint16x8_t b)
{
	return vtrnq_u16(a, b);
}

uint32x4x2_t np_vtrnq_u32(uint32x4_t a, uint32x4_t b)
{
	return vtrnq_u32(a, b);
}

float32x4x2_t np_vtrnq_f32(float32x4_t a, float32x4_t b)
{
	return vtrnq_f32(a, b);
}

poly8x16x2_t np_vtrnq_p8(poly8x16_t a, poly8x16_t b)
{
	return vtrnq_p8(a, b);
}

poly16x8x2_t np_vtrnq_p16(poly16x8_t a, poly16x8_t b)
{
	return vtrnq_p16(a, b);
}

int8x16x2_t np_vzipq_s8(int8x16_t a, int8x16_t b)
{
	return vzipq_s8(a, b);
}

int16x8x2_t np_vzipq_s16(int16x8_t a, int16x8_t b)
{
	return vzipq_s16(a, b);
}

int32x4x2_t np_vzipq_s32(int32x4_t a, int32x4_t b)
{
	return vzipq_s32(a, b);
}

uint8x16x2_t np_vzipq_u8(uint8x16_t a, uint8x16_t b)
{
	return vzipq_u8(a, b);
}

uint16x8x2_t np_vzipq_u16(uint16x8_t a, uint16x8_t b)
{
	return vzipq_u16(a, b);
}

uint32x4x2_t np_vzipq_u32(uint32x4_t a, uint32x4_t b)
{
	return vzipq_u32(a, b);
}

float32x4x2_t np_vzipq_f32(float32x4_t a, float32x4_t b)
{
	return vzipq_f32(a, b);
}

poly8x16x2_t np_vzipq_p8(poly8x16_t a, poly8x16_t b)
{
	return vzipq_p8(a, b);
}

poly16x8x2_t np_vzipq_p16(poly16x8_t a, poly16x8_t b)
{
	return vzipq_p16(a, b);
}

int8x16x2_t np_vuzpq_s8(int8x16_t a, int8x16_t b)
{
	return vuzpq_s8(a, b);
}

int16x8x2_t np_vuzpq_s16(int16x8_t a, int16x8_t b)
{
	return vuzpq_s16(a, b);
}

int32x4x2_t np_vuzpq_s32(int32x4_t a, int32x4_t b)
{
	return vuzpq_s32(a, b);
}

uint8x16x2_t np_vuzpq_u8(uint8x16_t a, uint8x16_t b)
{
	return vuzpq_u8(a, b);
}

uint16x8x2_t np_vuzpq_u16(uint16x8_t a, uint16x8_t b)
{
	return vuzpq_u16(a, b);
}

uint32x4x2_t np_vuzpq_u32(uint32x4_t a, uint32x4_t b)
{
	return vuzpq_u32(a, b);
}

float32x4x2_t np_vuzpq_f32(float32x4_t a, float32x4_t b)
{
	return vuzpq_f32(a, b);
}

poly8x16x2_t np_vuzpq_p8(poly8x16_t a, poly8x16_t b)
{
	return vuzpq_p8(a, b);
}

poly16x8x2_t np_vuzpq_p16(poly16x8_t a, poly16x8_t b)
{
	return vuzpq_p16(a, b);
}

#else

int npCanUseSIMD()
{
	return 0;
}

#endif
