io.input("Builtins.def")
io.output("output.txt")

local define = "#if !__has_builtin(__builtin_x)\n#error \"x clang built-in not available\"\n#else\n#define x __builtin_x\n#endif"

while true do
	local line = io.read()
	if line == nil then break end
	
	for w in string.gmatch(line, "BUILTIN%(__builtin_(.+)%s*,%s*\".+\"%s*,%s*\".+\"%)") do
		w = string.gsub(w, " ", "");
		local func = string.gsub(define, "x", w)
		io.write(func)
		io.write("\n")
	end	
end	