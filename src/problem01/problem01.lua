local sum = 0
local i = 1
while i < 1000 do
    do if i % 3 == 0 or i % 5 == 0 then do sum = sum + i end end end
    i = i + 1
end

print(sum)
