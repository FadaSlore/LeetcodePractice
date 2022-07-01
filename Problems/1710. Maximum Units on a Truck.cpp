#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] > b[1]; });

        int result = 0;
        for (vector<int> box : boxTypes)
        {
            if (box[0] < truckSize)
            {
                result += box[0] * box[1];
                truckSize -= box[0];
            }
            else
            {
                result += truckSize * box[1];
                return result;
            }
        }
        return result;
    }
};