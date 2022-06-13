#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> numbers(101, 0);
        int max = 0;
        for (int i = 0; i < heights.size(); i++)
            numbers[heights[i]]++;
        for (int i = 1; i < 101; i++)
            numbers[i] += numbers[i - 1];

        int result = 0;
        for (int i = 0; i < heights.size(); i++)
            if (!(numbers[heights[i] - 1] <= i && i < numbers[heights[i]]))
                result++;
        return result;
    }
};