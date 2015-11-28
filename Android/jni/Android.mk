LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := NativePath
LOCAL_C_INCLUDES := \
   $(LOCAL_PATH)/../../NativePath


LOCAL_ARM_MODE := arm
LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O3 -DANDROID_NDK

LOCAL_SRC_FILES := \
   ../../NativePath/NativeMath.c \
   ../../NativePath/NativeMemory.c \
   ../../NativePath/lol_trig.cpp \
   ../../NativePath/NativeTime.cpp

include $(BUILD_STATIC_LIBRARY)