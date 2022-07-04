#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int result = 1, temp = 1, decreaseLength = 1, increaseLength = 1;
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] >= ratings[i - 1])
            {
                decreaseLength = 1;
                temp = (ratings[i] == ratings[i - 1]) ? 1 : temp + 1;
                result += temp;
                increaseLength = temp;
            }
            else
            {
                if (decreaseLength == increaseLength)
                    decreaseLength++;
                result += decreaseLength;
                decreaseLength++;
                temp = 1;
            }
        }
        return result;
    }
};