LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := NativePath
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../NativePath $(LOCAL_PATH)/../../source

LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O3 -DANDROID_NDK -Wall

LOCAL_SRC_FILES := \
   ../../source/NativeMath.c \
   ../../source/NativeMemory.c \
   ../../source/lol_trig.cpp \
   ../../source/NativeTime.cpp \
   ../../source/NativeDynamicLinking.c \
   ../../source/stdio.c \
   ../../source/stdlib.c

include $(BUILD_STATIC_LIBRARY)