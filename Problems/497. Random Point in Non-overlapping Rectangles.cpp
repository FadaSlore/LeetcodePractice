#include <vector>
#include <random>
using namespace std;

class Solution
{
private:
    vector<int> sum;
    vector<vector<int>> rects;
    mt19937 generator{random_device{}()};

public:
    Solution(vector<vector<int>> &rects) : rects(rects)
    {
        this->sum.emplace_back(0);
        for (auto rect : rects)
            this->sum.emplace_back(sum.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
    }

    vector<int> pick()
    {
        uniform_int_distribution<int> distribution(0, sum.back() - 1);
        int temp = distribution(generator);
        int rectIndex = upper_bound(sum.begin(), sum.end(), temp) - sum.begin() - 1;
        temp -= sum[rectIndex];
        int column = rects[rectIndex][3] - rects[rectIndex][1] + 1;
        int aDistance = (int)(temp / column), bDistance = temp % column;
        return {rects[rectIndex][0] + aDistance, rects[rectIndex][1] + bDistance};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */