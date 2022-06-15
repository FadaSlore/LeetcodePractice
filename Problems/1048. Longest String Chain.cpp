#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string a, string b)
             { return a.length() < b.length(); });
        int size = words.size();
        vector<int> dp(size, 1);
        int result = 1;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if ((words[j].size() - words[i].size()) == 1)
                {
                    int a = 0, b = 0, diff = 0;
                    while (a < words[i].size() && b < words[j].size())
                    {
                        if (words[i][a] == words[j][b])
                            a++;
                        else
                            diff++;
                        b++;
                    }
                    if (a == words[i].size() || diff == 0)
                    {
                        dp[j] = max(dp[j], dp[i] + 1);
                        result = max(result, dp[j]);
                    }
                }
        return result;
    }
};