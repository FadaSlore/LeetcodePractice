#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size(), low = 0, high = nums.back() - nums.front();
        while (low <= high)
        {
            int count = 0, mid = (int)((low + high) / 2);
            for (int i = 0, j = 0; j < size; j++)
            {
                while (nums[j] - nums[i] > mid)
                    i++;
                count += j - i;
            }
            if (count >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};