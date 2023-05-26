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

local factors = prime_factors(600851475143)
print(factors[#factors])

