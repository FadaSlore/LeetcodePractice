#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                result[i][j] = matrix[j][i];
        return result;
    }
};