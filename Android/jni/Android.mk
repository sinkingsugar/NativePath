LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := NativePath
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../NativePath $(LOCAL_PATH)/../../source

LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O3 -DANDROID_NDK -Wall -D__ANDROID__

ifeq ($(TARGET_ARCH_ABI),x86)
    LOCAL_CFLAGS    += -mssse3
    LOCAL_CPPFLAGS  += -mssse3
    LOCAL_CXXFLAGS  += -mssse3
endif

ifeq ($(TARGET_ARCH_ABI),x86_64)
    LOCAL_CFLAGS    += -mssse3
    LOCAL_CPPFLAGS  += -mssse3
    LOCAL_CXXFLAGS  += -mssse3
endif
 
ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
	LOCAL_ARM_MODE  := arm
    LOCAL_ARM_NEON  := true
    LOCAL_CFLAGS    += -mfpu=neon -D__USE_NEON__
    LOCAL_CPPFLAGS  += -mfpu=neon -D__USE_NEON__
    LOCAL_CXXFLAGS  += -mfpu=neon -D__USE_NEON__
endif

ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
    LOCAL_CFLAGS    += -D__USE_NEON__
    LOCAL_CPPFLAGS  += -D__USE_NEON__
    LOCAL_CXXFLAGS  += -D__USE_NEON__
endif

ifeq ($(TARGET_ARCH_ABI),armeabi)
    LOCAL_CFLAGS    += -DNO_INTRINSICS
    LOCAL_CPPFLAGS  += -DNO_INTRINSICS
    LOCAL_CXXFLAGS  += -DNO_INTRINSICS
endif

LOCAL_SRC_FILES := \
   ../../source/NativeMath.c \
   ../../source/NativeMemory.c \
   ../../source/lol_trig.cpp \
   ../../source/NativeTime.cpp \
   ../../source/NativeDynamicLinking.c \
   ../../source/stdio.c \
   ../../source/stdlib.c \
   ../../source/NEONvsSSE.c \
   ../../source/workarounds.c \
   ../../source/NativeThreading.cpp

include $(BUILD_STATIC_LIBRARY)