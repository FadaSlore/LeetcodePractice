#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int result;
        priority_queue<int> bricksUsed;
        for (result = 0; result < heights.size() - 1; result++)
        {
            int diff = heights[result + 1] - heights[result];
            if (diff > 0)
            {
                bricksUsed.push(diff);
                bricks -= diff;
                if (bricks < 0 && bricksUsed.size() && ladders)
                {
                    bricks += bricksUsed.top();
                    bricksUsed.pop();
                    ladders--;
                }
                if (bricks < 0)
                    break;
            }
        }
        return result;
    }
};