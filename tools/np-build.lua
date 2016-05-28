--eg: >c:\Users\giovanni.petrantoni\Desktop\luapower-all-master\luajit np-build.lua c:\Development\opus\celt_np -IC:\Development\opus\include -IC:\Development\opus\celt -DUSE_ALLOCA -DHAVE_LRINTF -DCUSTOM_MODES -DOPUS_BUILD -ncelt

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

local common_flags = "-Wall -Wno-macro-redefined -I.."..SLASH.."NativePath -I.."..SLASH.."NativePath"..SLASH.."standard"
local debug_flags = "-O0 -g"
local debug_ms_flags = "-Od -Zi"
local release_flags = "-O3"

local objs = {}

local cfiles = {}
local hfiles = {}

local debug = false
local platform = "windows"

local directory = ""
local outputName = "lib"

--Win dll for checking

function BuildWindows32DLL(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -m32 -DNP_WIN32 -fno-ms-extensions -nobuiltininc -nostdinc++ -target i686-pc-windows-msvc "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
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
	if debug then flags = debug_ms_flags else flags = release_flags end
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
	if debug then flags = debug_ms_flags else flags = release_flags end
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
	if debug then flags = debug_ms_flags else flags = release_flags end
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

--iOS

function BuildWindowsiOSArm7(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target armv7-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsiOSArm7()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_armv7.a "..objs_str
	os.execute(cmd)
end

function BuildWindowsiOSArm7s(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target armv7s-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsiOSArm7s()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_armv7s.a "..objs_str
	os.execute(cmd)
end

function BuildWindowsiOSArm64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target arm64-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsiOSArm64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_arm64.a "..objs_str
	os.execute(cmd)
end

function BuildWindowsiOSx86(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target i386-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsiOSx86()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_i386.a "..objs_str
	os.execute(cmd)
end

function BuildWindowsiOSx64(cfile)
	local flags = ""
	if debug then flags = debug_flags else flags = release_flags end
	local cmd = "clang -DNP_IOS -nobuiltininc -nostdinc++ -mios-version-min=6.0 -target x86_64-apple-ios "..common_flags.." "..flags.." -o "..cfile..".o ".." -c "..cfile;
	if os.execute(cmd) == 0 then table.insert(objs, cfile..".o") end
end

function LinkWindowsiOSx64()
	local objs_str = ""
	for i, o in ipairs(objs) do
		objs_str = objs_str..o.." "
	end
	local cmd = "llvm-ar rcs -format=bsd "..outputName.."_x86_64.a "..objs_str
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
	elseif v == "ios" then
		platform = "ios"
	elseif v == "linux" then
		platform = "linux"
	else
		directory = v
	end
end

for filename, attr in dirtree(directory) do
	if string.ends(filename, ".c") or string.ends(filename, ".cpp") and attr.mode == "file" then
		table.insert(cfiles, filename)
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
elseif platform == "ios" then
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsiOSArm7(f)
	end
	LinkWindowsiOSArm7()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsiOSArm7s(f)
	end
	LinkWindowsiOSArm7s()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsiOSArm64(f)
	end
	LinkWindowsiOSArm64()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsiOSx86(f)
	end
	LinkWindowsiOSx86()
	
	objs = {}

	for i,f in ipairs(cfiles) do
		BuildWindowsiOSx64(f)
	end
	LinkWindowsiOSx64()
	
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
end
