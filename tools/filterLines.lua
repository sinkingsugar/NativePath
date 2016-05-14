function file_exists(file)
  local f = io.open(file, "rb")
  if f then f:close() end
  return f ~= nil
end

function lines_from(file)
  if not file_exists(file) then return {} end
  lines = {}
  for line in io.lines(file) do 
    lines[#lines + 1] = line
  end
  return lines
end

local file = 'NEONvsSSE_gen.lua'
local lines = lines_from(file)

io.output(file.."2")

local filters = { "int8x8", "int16x4", "int32x2", "int64x1", "float32x2", "poly8x8", "poly16x4" }

for k,v in pairs(lines) do
    local ignore = false
    for i,f in ipairs(filters) do
        if string.match(v, f) then
            print("ignoring"..v)
            ignore = true
        end
    end
    if ignore ~= true then
        io.write(v)
        io.write("\n")
    end
end