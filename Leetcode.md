# Leetcode

## [<font color=green>867. Transpose Matrix</font>](/Problems/867_Transpose_Matrix.cpp)
- 給定矩陣`matrix`，輸出轉置（transpose）矩陣
```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0;i<matrix[0].size();i++)
            for (int j = 0; j < matrix.size();j++)
                result[i][j] = matrix[j][i];
        return result;
    }
};
```