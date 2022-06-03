#include <algorithm>

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        int result = 0;
        n <<= 1;
        for (int k = 1; k < sqrt(n); k++)
            if ((n % k == 0) && (((n / k) + 1 - k) & 1) == 0)
                result++;
        return result;
    }
};