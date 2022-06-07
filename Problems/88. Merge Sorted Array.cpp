#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int index1 = m - 1, index2 = n - 1, tail = m + n - 1, current;
        while (index1 >= 0 || index2 >= 0)
        {
            if (index1 == -1)
                current = nums2[index2--];
            else if (index2 == -1)
                current = nums1[index1--];
            else if (nums1[index1] > nums2[index2])
                current = nums1[index1--];
            else
                current = nums2[index2--];
            nums1[tail--] = current;
        }
    }
};