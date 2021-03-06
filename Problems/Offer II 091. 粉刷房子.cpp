#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int size = costs.size();
        vector<vector<int>> dp(size, vector<int>(3, 0));
        dp[0][0] = costs[0][0], dp[0][1] = costs[0][1], dp[0][2] = costs[0][2];
        for (int i = 1; i < size; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = min(dp[i - 1][((j + 1) % 3)], dp[i - 1][((j + 2) % 3)]) + costs[i][j];
        return min(dp[size - 1][0], min(dp[size - 1][1], dp[size - 1][2]));
    }
};