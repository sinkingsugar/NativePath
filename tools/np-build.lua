ffi = require 'ffi'

local SLASH = "/"
if ffi.os == "Windows" then SLASH = "\\" end

-- Code by David Kastrup
require "lfs"

function dirtree(dir)
  assert(dir and dir ~= "", "directory parameter is missing or empty")
  if string.sub(dir, -1) == SLASH then
    dir=string.sub(dir, 1, -2)
  end

  local function yieldtree(dir)
    for entry in lfs.dir(dir) do
      if entry ~= "." and entry ~= ".." then
        entry=dir..SLASH..entry
	local attr=lfs.attributes(entry)
	coroutine.yield(entry,attr)
	if attr.mode == "directory" then
	  yieldtree(entry)
	end
      end
    end
  end

  return coroutine.wrap(function() yieldtree(dir) end)
end

function string.ends(String,End)
   return End=='' or string.sub(String,-string.len(End))==End
end

function string.starts(String,Start)
   return string.sub(String,1,string.len(Start))==Start
end

local common_flags = "-Wno-macro-redefined -I.."..SLASH.."NativePath -I.."..SLASH.."NativePath"..SLASH.."standard"
local debug_flags = "-O0 -g"
local debug_ms_flags = "-Od"
local release_flags = "-O3"
local release_ms_flags = "-O2"

local objs = {}

local cfiles = {}
local hfiles = {}
local exclude_dirs = {}
local exclude_files = {}

local debug = false
local platform = "windows"

local directory = ""
local outputName = "lib"

local android_ndk_path = os.getenv("ANDROID_NDK_PATH");

--Win dll for checking

function BuildWindows32DLL(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m32 -DNP_WIN32 -Wall -fno-ms-extensions -nobuiltininc -nostdinc++ -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	print(cmd)
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindows32DLL()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "clang -v -m32 -shared -o Windows\\x86\\"..outputName..".dll -Wl,\"-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.10586.0\\ucrt\\x86\",\"-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.10586.0\\um\\x86\",-nodefaultlib:libcmt,-dll,-libpath:..\\Libs\\Windows\\x86\\ -llibNativePath "..objs_str
	os.execute(cmd)
end

--Win

function BuildWindows32(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m32 -DNP_WIN32 -nobuiltininc -nostdinc++ -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindows32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x86 && lib /OUT:Windows\\x86\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

function BuildWindows64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m64 -DNP_WIN32 -nobuiltininc -nostdinc++ -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindows64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x64 && lib /OUT:Windows\\x64\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

--Win UWP

function BuildWindowsUWP32(cfile)
	local flags = ""
	if debug then flags = debug_ms_flags else flags = release_ms_flags end
	local cmd = "clang-cl -DNP_WIN32 -WX -EHsc -MD -DWIN_EXPORT -m32 "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsUWP32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x86 store && lib /OUT:WindowsUWP\\x86\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

function BuildWindowsUWP64(cfile)
	local flags = ""
	if debug then flags = debug_ms_flags else flags = release_ms_flags end
	local cmd = "clang-cl -DNP_WIN32 -WX -EHsc -MD -DWIN_EXPORT -m64 "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsUWP64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x64 store && lib /OUT:WindowsUWP\\x64\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

function BuildWindowsUWPARM(cfile)
	local flags = ""
	if debug then flags = debug_ms_flags else flags = release_ms_flags end
	local cmd = "clang-cl -DNP_WIN32 -WX -EHsc -MD -DWIN_EXPORT -m32 --target=thumbv7-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsUWPARM()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x86_arm store && lib /OUT:WindowsUWP\\ARM\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

--Win 8.1

function LinkWindows8132()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x86 8.1 store && lib /OUT:Windows8.1\\x86\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

function LinkWindows8164()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x64 8.1 store && lib /OUT:Windows8.1\\x64\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

function LinkWindows81ARM()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall\" x86_arm 8.1 store && lib /OUT:Windows8.1\\ARM\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

--Win Phone 8.1

function LinkWindowsWP32()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 11.0\\VC\\WPSDK\\WP80\\vcvarsphoneall\" x86 && lib /OUT:WindowsPhone\\x86\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

function LinkWindowsWPARM()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "\"C:\\Program Files (x86)\\Microsoft Visual Studio 11.0\\VC\\WPSDK\\WP80\\vcvarsphoneall\" x86_arm && lib /OUT:WindowsPhone\\ARM\\"..outputName..".lib "..objs_str
	os.execute(cmd)
end

--iOS

function BuildIOSArm7(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target armv7-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkIOSArm7()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_armv7.a "..objs_str
	os.execute(cmd)
end

function BuildIOSArm7s(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target armv7s-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkIOSArm7s()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_armv7s.a "..objs_str
	os.execute(cmd)
end

function BuildIOSArm64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target arm64-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkIOSArm64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_arm64.a "..objs_str
	os.execute(cmd)
end

function BuildIOSx86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target i386-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkIOSx86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_i386.a "..objs_str
	os.execute(cmd)
end

function BuildIOSx64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target x86_64-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkIOSx64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_x86_64.a "..objs_str
	os.execute(cmd)
end

--Android

function BuildAndroidArm(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -nobuiltininc -nostdinc++ -target arm-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkAndroidArm()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\armeabi\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

function BuildAndroidArm7(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -nobuiltininc -nostdinc++ -target armv7-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkAndroidArm7()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\armeabi-v7a\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

function BuildAndroidArm64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -nobuiltininc -nostdinc++ -target aarch64-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkAndroidArm64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\arm64-v8a\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

function BuildAndroidx86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -nobuiltininc -nostdinc++ -target i386-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkAndroidx86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\x86\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

function BuildAndroidx64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_ANDROID -nobuiltininc -nostdinc++ -target x86_64-none-android "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkAndroidx64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Android\\x86_64\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

--linux

function BuildLinuxX64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_LINUX -nobuiltininc -nostdinc++ -fPIC -target x86_64-linux-gnu "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkLinuxX64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Linux\\x64\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

function BuildLinuxX86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_LINUX -nobuiltininc -nostdinc++ -fPIC -target i386-linux-gnu "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkLinuxX86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=gnu Linux\\x86\\"..outputName..".a "..objs_str
	os.execute(cmd)
end

function table.contains(table, element)
  for _, value in pairs(table) do
    if string.starts(element, value) then
      return true
    end
  end
  return false
end

for i,v in ipairs(arg) do 
	if v == "debug" then
		debug = true
	elseif string.starts(v, "-I") then
		local includeDir = string.sub(v, 3)
		common_flags = common_flags.." -I"..includeDir
	elseif string.starts(v, "-D") then
		local includeDir = string.sub(v, 3)
		common_flags = common_flags.." -D"..includeDir
	elseif string.starts(v, "-n") then
		local n = string.sub(v, 3)
		outputName = n
	elseif string.starts(v, "-E") then
		local n = string.sub(v, 3)
		table.insert(exclude_dirs, n)
 	elseif string.starts(v, "-e") then
		local n = string.sub(v, 3)
		table.insert(exclude_files, n)
	elseif v == "ios" then
		platform = "ios"
	elseif v == "linux" then
		platform = "linux"
    elseif v == "android" then
		platform = "android"
	else
		directory = v
	end
end

for filename, attr in dirtree(directory) do
	if table.contains(exclude_dirs, filename) ~= true then
		if (string.ends(filename, ".c") or string.ends(filename, ".cpp")) and attr.mode == "file" and table.contains(exclude_files, filename) ~= true then
			table.insert(cfiles, filename)
		end
	else
		print("Excluding: "..filename)
	end
end

if platform == "windows" then 
	lfs.mkdir("Windows")
	lfs.chdir("Windows")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.chdir("..")

	for i,f in ipairs(cfiles) do
		BuildWindows32DLL(f)
	end
	LinkWindows32DLL()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindows32(f)
	end
	LinkWindows32()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindows64(f)
	end
	LinkWindows64()

	objs = {}

	lfs.mkdir("WindowsUWP")
	lfs.chdir("WindowsUWP")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.mkdir("ARM")
	lfs.chdir("..")

	for i,f in ipairs(cfiles) do
		BuildWindowsUWP32(f)
	end
	LinkWindowsUWP32()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsUWP64(f)
	end
	LinkWindowsUWP64()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsUWPARM(f)
	end
	LinkWindowsUWPARM()

	objs = {}

	lfs.mkdir("Windows8.1")
	lfs.chdir("Windows8.1")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.mkdir("ARM")
	lfs.chdir("..")

	for i,f in ipairs(cfiles) do
		BuildWindowsUWP32(f)
	end
	LinkWindows8132()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsUWP64(f)
	end
	LinkWindows8164()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsUWPARM(f)
	end
	LinkWindows81ARM()

	--

	objs = {}

	lfs.mkdir("WindowsPhone")
	lfs.chdir("WindowsPhone")
	lfs.mkdir("x86")
	lfs.mkdir("ARM")
	lfs.chdir("..")

	for i,f in ipairs(cfiles) do
		BuildWindowsUWP32(f)
	end
	LinkWindowsWP32()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsUWPARM(f)
	end
	LinkWindowsWPARM()
elseif platform == "ios" then
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildIOSArm7(f)
	end
	LinkIOSArm7()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildIOSArm7s(f)
	end
	LinkIOSArm7s()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildIOSArm64(f)
	end
	LinkIOSArm64()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildIOSx86(f)
	end
	LinkIOSx86()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildIOSx64(f)
	end
	LinkIOSx64()
	
	lfs.mkdir("iOS")
	
	os.execute("lipo "..outputName.."_armv7.a "..outputName.."_armv7s.a "..outputName.."_arm64.a "..outputName.."_i386.a "..outputName.."_x86_64.a -create -output iOS\\"..outputName..".a")
elseif platform == "linux" then
	lfs.mkdir("Linux")
	lfs.chdir("Linux")
	lfs.mkdir("x64")
	lfs.mkdir("x86")
	lfs.chdir("..")
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildLinuxX64(f)
	end
	LinkLinuxX64()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildLinuxX86(f)
	end
	LinkLinuxX86()
elseif platform == "android" then
	lfs.mkdir("Android")
	lfs.chdir("Android")
	lfs.mkdir("x86_64")
	lfs.mkdir("x86")
	lfs.mkdir("arm64-v8a")
	lfs.mkdir("armeabi")
	lfs.mkdir("armeabi-v7a")
	lfs.chdir("..")
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildAndroidArm(f)
	end
	LinkAndroidArm()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildAndroidArm7(f)
	end
	LinkAndroidArm7()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildAndroidArm64(f)
	end
	LinkAndroidArm64()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildAndroidx86(f)
	end
	LinkAndroidx86()

	objs = {}

	for i,f in ipairs(cfiles) do
		BuildAndroidx64(f)
	end
	LinkAndroidx64()
end
