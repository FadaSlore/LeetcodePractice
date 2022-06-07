#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = 0;
        for (int pile : piles)
            high = max(high, pile);
        int temp = high;
        while (low < high)
        {
            int speed = ((high - low) >> 1) + low;
            long time = 0;
            for (int pile : piles)
                time += int((pile + speed - 1) / speed);
            if (time <= h)
                temp = high = speed;
            else
                low = speed + 1;
        }
        return temp;
    }
};