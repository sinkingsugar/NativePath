@echo off

call "%PROGRAMFILES(X86)%\Microsoft Visual Studio 14.0\vc\vcvarsall.bat" x86
set WindowsSdkDir=

REM Windows
if not exist build\Windows\x86 mkdir build\Windows\x86
pushd build\Windows\x86
cmake ..\..\..\ -G "Visual Studio 14"
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows x64
if not exist build\Windows\x64 mkdir build\Windows\x64
pushd build\Windows\x64
cmake ..\..\..\ -G "Visual Studio 14 Win64"
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows UWP
if not exist build\UWP\x86 mkdir build\UWP\x86
pushd build\UWP\x86
cmake ..\..\..\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=10.0
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

if not exist build\UWP\x64 mkdir build\UWP\x64
pushd build\UWP\x64
cmake ..\..\..\ -G "Visual Studio 14 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=10.0
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

if not exist build\UWP\ARM mkdir build\UWP\ARM
pushd build\UWP\ARM
cmake ..\..\..\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=10.0
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

goto :exit

:error_popd
popd

:exit 
@echo on
