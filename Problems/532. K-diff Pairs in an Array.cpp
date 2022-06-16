#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size(), right = 0, result = 0;
        for (int left = 0; left < size - 1; left++)
        {
            if (left == 0 || nums[left] != nums[left - 1])
            {
                while (right < size && ((nums[right] - nums[left]) < k))
                    right++;
                if (right == left)
                    right++;
                if (right < size && (nums[right] - nums[left]) == k)
                    result++;
            }
        }
        return result;
    }
};