call "%PROGRAMFILES(X86)%\Microsoft Visual Studio 14.0\vc\vcvarsall.bat" x86
set WindowsSdkDir=

REM Windows
mkdir build\Windows\x86
pushd build\Windows\x86
cmake ..\..\..\ -G "Visual Studio 14"
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows x64
mkdir build\Windows\x64
pushd build\Windows\x64
cmake ..\..\..\ -G "Visual Studio 14 Win64"
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Store
mkdir build\WindowsStore\x86
pushd build\WindowsStore\x86
cmake ..\..\..\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir build\WindowsStore\x64
pushd build\WindowsStore\x64
cmake ..\..\..\ -G "Visual Studio 14 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir build\WindowsStore\ARM
pushd build\WindowsStore\ARM
cmake ..\..\..\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Phone
mkdir build\WindowsPhone\x86
pushd build\WindowsPhone\x86
cmake ..\..\..\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsPhone -DCMAKE_SYSTEM_VERSION=8.1
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir build\WindowsPhone\ARM
pushd build\WindowsPhone\ARM
cmake ..\..\..\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsPhone -DCMAKE_SYSTEM_VERSION=8.1
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Universal
mkdir build\WindowsUniversal\x86
pushd build\WindowsUniversal\x86
cmake ..\..\..\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=10.0
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir build\WindowsUniversal\x64
pushd build\WindowsUniversal\x64
cmake ..\..\..\ -G "Visual Studio 14 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=10.0
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir build\WindowsUniversal\ARM
pushd build\WindowsUniversal\ARM
cmake ..\..\..\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=10.0
msbuild libNativePath.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd