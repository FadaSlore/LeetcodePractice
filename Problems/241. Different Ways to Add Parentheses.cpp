#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    const int ADDITION = -1, SUBTRACTION = -2, MULTIPLICATION = -3;
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> operation;
        int temp = 0;
        for (char c : expression)
        {
            if (isdigit(c))
                temp = temp * 10 + (c - '0');
            else
            {
                operation.push_back(temp);
                temp = 0;
                if (c == '+')
                    operation.push_back(ADDITION);
                else if (c == '-')
                    operation.push_back(SUBTRACTION);
                else
                    operation.push_back(MULTIPLICATION);
            }
        }
        operation.push_back(temp);

        int size = operation.size();

        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size));
        for (int i = 0; i < operation.size(); i += 2)
            dp[i][i] = {operation[i]};

        for (int i = 2; i < size; i++)
        {
            for (int j = 0; j + i < size; j += 2)
            {
                int leftIndex = j, rightIndex = j + i;
                for (int k = j + 1; k < rightIndex; k += 2)
                {
                    auto &left = dp[leftIndex][k - 1], right = dp[k + 1][rightIndex];
                    for (auto &number1 : left)
                    {
                        for (auto &number2 : right)
                        {
                            if (operation[k] == ADDITION)
                                dp[leftIndex][rightIndex].push_back(number1 + number2);
                            else if (operation[k] == SUBTRACTION)
                                dp[leftIndex][rightIndex].push_back(number1 - number2);
                            else if (operation[k] == MULTIPLICATION)
                                dp[leftIndex][rightIndex].push_back(number1 * number2);
                        }
                    }
                }
            }
        }

        return dp[0][size - 1];
    }
};