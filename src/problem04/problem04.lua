local function is_palindrome(n)
    local digits = {}
    while n ~= 0 do
        table.insert(digits, n - math.floor(n / 10) * 10)
        n = math.floor(n / 10)
    end

    for i = 1, math.floor(#digits / 2) do
        if digits[i] ~= digits[#digits + 1 - i] then return false end
    end
    return true
end

local max = 0
for i = 100, 999 do
    for j = 100, 999 do
        local k = i * j
        if is_palindrome(k) and k > max then max = k end
    end
end

print(max)
