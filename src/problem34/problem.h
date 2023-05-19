#pragma once
#include <iostream>
#include "longint.h"
#include <vector>


class Solution
{
    public:
        lint sum_of_curious_number();
        bool is_curious(lint number);
        lint sum_of_digit_factorial(lint number);
        unsigned length();

        void answer();
    private:
        std::vector<unsigned> factorials{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

};
