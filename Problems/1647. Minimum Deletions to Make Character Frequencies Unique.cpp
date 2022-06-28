#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> count(26, 0);
        for (char c : s)
            count[c - 'a']++;
        sort(count.begin(), count.end(), greater<int>());

        int result = 0, temp = count[0];
        for (int i = 1; i < 26 && (count[i] > 0); i++)
        {
            if (temp <= count[i])
            {
                temp = max(temp - 1, 0);
                result += count[i] - temp;
            }
            else
                temp = count[i];
        }
        return result;
    }
};