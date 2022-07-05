#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numberSet;
        for (int number : nums)
            numberSet.insert(number);

        int result = 0;
        for (int number : nums)
        {
            if (!numberSet.count(number - 1))
            {
                int currentNumber = number, currentLength = 1;
                while (numberSet.count(currentNumber + 1))
                {
                    currentNumber += 1;
                    currentLength += 1;
                }
                result = max(result, currentLength);
            }
        }
        return result;
    }
};