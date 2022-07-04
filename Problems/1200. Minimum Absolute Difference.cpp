#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int minimum = arr[1] - arr[0] + 1, temp;
        for (int i = 1; i < arr.size(); i++)
        {
            temp = arr[i] - arr[i - 1];
            if (temp <= minimum)
            {
                if (temp < minimum)
                    result.clear();
                minimum = temp;
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};