#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int index = (int)((size + 1) / 2);
        for (int i = 0, j = index - 1, k = size - 1; i < size; i += 2, j--, k--)
        {
            nums[i] = temp[j];
            if ((i + 1) < size)
                nums[i + 1] = temp[k];
        }
    }
};