#include <vector>
using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;
    int numPrimeArrangements(int n)
    {
        vector<bool> composite(n + 1, false);
        composite[1] = true;
        for (int i = 2; i * i <= n; i++)
            for (int j = 2; i * j <= n; j++)
                composite[i * j] = true;

        int count = 0;
        for (int i = 1; i <= n; i++)
            if (composite[i])
                count++;
        return (int)(factorial(count) * factorial(n - count) % mod);
    }
    long factorial(int n)
    {
        long result = 1;
        while (n)
        {
            result *= n--;
            result %= mod;
        }
        return result;
    }
};