local a, b, c, sum = 0, 1, 1, 0
while c < 4000000 do
    c = a + b
    a = b
    b = c
    if c % 2 == 0 then sum = sum + c end
end

print(sum)
