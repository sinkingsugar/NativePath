io.input("Builtins.def")
io.output("output.txt")

getmetatable('').__index = function(str,i)
  if type(i) == 'number' then
    return string.sub(str,i,i)
  else
    return string[i]
  end
end

local define = [[#if !__has_builtin(__builtin_$1)
	#error \"$1 clang built-in not available\"
	// $3
	extern $2$1(...);
#else
	#define $1 __builtin_$1
#endif
]]

local define2 = [[#if !__has_builtin($1)
	#error \"$1 clang built-in not available\"
	// $3
	extern $2$1(...);
#endif
]]

function generateReturnType(args)
	local len = string.len(args)
	
	local result = "void*"
	local valid = false
	
	local prefix = ""
	local suffix = ""
	local type = ""
	
	for i=0, len, 1 do
		local char = args[i]
		
		if char == "*" then
			suffix = "* "
		elseif char == "&" then
			suffix = "& "
		end
		
		if valid then break end
		
		if char == "v" then
			type = "void"
			valid = true
		elseif char == "b" then
			type = "int"
			valid = true
		elseif char == "c" then
			type = "char"
			valid = true
		elseif char == "s" then
			type = "short"
			valid = true
		elseif char == "i" then
			type = "int"
			valid = true
		elseif char == "h" then
			type = "float"
			valid = true
		elseif char == "f" then
			type = "float"
			valid = true
		elseif char == "d" then
			type = "double"
			valid = true
		elseif char == "z" then
			type = "size_t"
			valid = true
		elseif char == "F" then
		elseif char == "G" then
		elseif char == "H" then
		elseif char == "M" then
		elseif char == "a" then
		elseif char == "A" then
		elseif char == "V" then
		elseif char == "E" then
		elseif char == "X" then
		elseif char == "Y" then
		elseif char == "P" then
		elseif char == "J" then
		elseif char == "SJ" then
		elseif char == "K" then
		elseif char == "p" then
		elseif char == "." then
		elseif char == "L" then
			prefix = prefix.."long "
		elseif char == "W" then
		elseif char == "S" then
			prefix = "signed "
		elseif char == "U" then
			prefix = "unsigned "
		elseif char == "I" then
		elseif char == "C" then
		elseif char == "D" then
		end
	end
	
	if valid then
		result = prefix..type.." "..suffix
	end
		
	return result
end

function parseLine(line, pattern, define)
	local name, args = string.match(line, pattern)
	if name ~= nil and args ~=nil then
		name = string.gsub(name, " ", "");
		local func = string.gsub(define, "$1", name)
		func = string.gsub(func, "$3", args)
		local retType, pointer = string.match(args, "(%w)(%*?)")
		func = string.gsub(func, "$2", generateReturnType(args))
		io.write(func)
		io.write("\n")
	end
end

while true do
	local line = io.read()
	if line == nil then break end
	
	parseLine(line, "BUILTIN%(__builtin_(.+)%s*,%s*\"(.+)\"%s*,%s*\".+\"%)", define)
	parseLine(line, "BUILTIN%((__sync_.+)%s*,%s*\"(.+)\"%s*,%s*\".+\"%)", define2)
end	