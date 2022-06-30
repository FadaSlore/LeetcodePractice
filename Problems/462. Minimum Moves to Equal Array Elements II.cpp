#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int result = 0, number = nums[(int)nums.size() / 2];
        for (int i = 0; i < nums.size(); i++)
            result += abs(number - nums[i]);
        return result;
    }
};