#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<int> queens(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int rowNow, int columns, int diagonals_forward, int diagonals_backword)
    {
        if (rowNow == n)
            solutions.push_back(build(queens, n));
        else
        {
            int positions = ((1 << n) - 1) & (~(columns | diagonals_forward | diagonals_backword));
            while (positions)
            {
                int pos = positions & (-positions);
                positions &= (positions - 1);
                int column = 0;
                for (int temp = pos; (temp & 1) == 0; temp >>= 1)
                    column++;
                queens[rowNow] = column;
                solve(solutions, queens, n, rowNow + 1, columns | pos, (diagonals_forward | pos) >> 1, (diagonals_backword | pos) << 1);
                queens[rowNow] = -1;
            }
        }
    }

    vector<string> build(vector<int> queens, int n)
    {
        vector<string> result;
        for (int i = 0; i < n; i++)
        {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            result.push_back(row);
        }
        return result;
    }
};