#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    int number;

public:
    int totalNQueens(int n)
    {
        number = 0;
        vector<int> queens(n, -1);
        solve(queens, n, 0, 0, 0, 0);
        return number;
    }

    void solve(vector<int> &queens, int n, int rowNow, int columns, int diagonals_forward, int diagonals_backword)
    {
        if (rowNow == n)
            number++;
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
                solve(queens, n, rowNow + 1, columns | pos, (diagonals_forward | pos) >> 1, (diagonals_backword | pos) << 1);
                queens[rowNow] = -1;
            }
        }
    }
};