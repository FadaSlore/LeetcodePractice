#include <vector>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        if (target.size() == 1)
            return (target[0] == 1);
        int maximum, index, size = target.size();
        long long sum, otherSum;
        while (true)
        {
            maximum = 0, index = 0, sum = 0;
            for (int i = 0; i < size; i++)
            {
                sum += (long long)target[i];
                if (target[i] > maximum)
                {
                    maximum = target[i];
                    index = i;
                }
            }
            otherSum = sum - (long long)maximum;
            if (sum == (long long)size || otherSum == 1)
                return true;
            target[index] = (int)(maximum % otherSum);
            if (target[index] == 0 || ((maximum - otherSum) <= 0))
                return false;
        }
    }
};