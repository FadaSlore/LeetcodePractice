#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int size = cardPoints.size(), temp = 0;
        for (int i = 0; i < (size - k); i++)
            temp += cardPoints[i];

        int sum = temp, sumLeft = temp;
        for (int i = (size - k); i < size; i++)
        {
            sum += cardPoints[i];
            temp += cardPoints[i] - cardPoints[i - (size - k)];
            sumLeft = min(sumLeft, temp);
        }
        return (sum - sumLeft);
    }
};