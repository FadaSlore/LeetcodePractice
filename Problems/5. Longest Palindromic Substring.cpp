#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    pair<int, int> expand(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s)
    {
        int size = s.size();
        if (size < 2)
            return s;

        int start = 0, end = 0, left, right;
        for (int i = 0; i < size; i++)
        {
            pair<int, int> expandResult = expand(s, i, i);
            left = expandResult.first, right = expandResult.second;
            if ((right - left) > (end - start))
            {
                start = left;
                end = right;
            }
            expandResult = expand(s, i, i + 1);
            left = expandResult.first, right = expandResult.second;
            if ((right - left) > (end - start))
            {
                start = left;
                end = right;
            }
        }
        return s.substr(start, end - start + 1);
    }
};