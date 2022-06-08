#include <string>
using namespace std;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int length = s.length();
        for (int i = 0; i < (int)(length / 2); i++)
            if (s[i] != s[length - 1 - i])
                return 2;
        return 1;
    }
};