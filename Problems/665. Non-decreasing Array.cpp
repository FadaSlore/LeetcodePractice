#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool decreasedFlag = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (decreasedFlag)
                    return false;
                decreasedFlag = true;
                if ((i - 2) >= 0 && (i + 1) < nums.size() && (nums[i + 1] < nums[i - 1] && nums[i] < nums[i - 2]))
                    return false;
            }
        }
        return true;
    }
};