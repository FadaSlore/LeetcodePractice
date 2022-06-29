#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int size = people.size();
        vector<vector<int>> result(size);

        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0] || ((a[0] == b[0]) && (a[1] > b[1])); });
        for (vector<int> person : people)
        {
            int count = person[1] + 1;
            for (int i = 0; i < size; i++)
            {
                if (result[i].empty())
                {
                    count--;
                    if (!count)
                    {
                        result[i] = person;
                        break;
                    }
                }
            }
        }
        return result;
    }
};