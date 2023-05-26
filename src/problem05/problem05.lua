local function is_prime(n)
    if n < 2 then return false end
    for i = 2, math.floor(math.sqrt(n)) do
        if n % i == 0 then return false end
    end
    return true
end

local function prime_factors(n)
    local factors = {}
    while n > 1 do
        for i = 2, n do
            if is_prime(i) and n % i == 0 then
                table.insert(factors, i)
                n = n / i
                break
            end
        end
    end
    return factors
end

local function lcm(a, b)
    local factors_a = prime_factors(a)
    local factors_b = prime_factors(b)
    for _, val_a in pairs(factors_a) do
        for index, val_b in ipairs(factors_b) do
            do
                if (val_a == val_b) then
                    table.remove(factors_b, index)
                    break
                end
            end
        end
    end
    local l = 1
    for _, val_a in pairs(factors_a) do l = l * val_a end
    for _, val_b in pairs(factors_b) do l = l * val_b end

    return l
end

local function lcm_of_range(cap)
    local ret = 1
    for i = 1, cap do
        ret = lcm(ret, i)
    end
    return ret
end

print(lcm_of_range(10))
print(lcm_of_range(20))
