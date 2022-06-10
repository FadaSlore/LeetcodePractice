#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int size = (1 << 8);
        int frequency[size] = { 0 }, length = s.length(), result = 0, j = 0;
        for (int i = 0;i < length;i++)
        {
            while (j < length && frequency[s[j]] == 0)
                frequency[s[j++]]++;
            frequency[s[i]]--;
            result = max(result, j - i);
        }
        return result;
    }
};