#include <vector>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;
        int a = 0, b = 1, result = 0;
        for (int i = 2; i <= n; i++)
        {
            result = a + b;
            b = a;
            a = result;
        }
        return result;
    }
};