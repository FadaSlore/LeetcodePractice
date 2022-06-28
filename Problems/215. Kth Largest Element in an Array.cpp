#include <vector>
using namespace std;

class Solution
{
public:
    int partion(int left, int right, vector<int> &nums)
    {
        int temp = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] >= temp)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= temp)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = temp;
        return left;
    }
    int quickSort(int left, int right, vector<int> &nums, int k)
    {
        int mid = partion(left, right, nums);
        if (mid == nums.size() - k)
            return nums[mid];
        else if (mid < (nums.size() - k))
            return quickSort(mid + 1, right, nums, k);
        else
            return quickSort(left, mid - 1, nums, k);
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSort(0, nums.size() - 1, nums, k);
    }
};