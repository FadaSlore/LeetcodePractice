#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

class Solution
{
private:
    unordered_map<int, int> blackToWhite;
    int bound;

public:
    Solution(int n, vector<int> &blacklist)
    {
        bound = n - blacklist.size();
        unordered_set<int> blacks;
        for (int black : blacklist)
            if (black >= bound)
                blacks.emplace(black);

        // bijection map
        int white = bound;
        for (int black : blacklist)
            if (black < bound)
            {
                while (blacks.count(white))
                    white++;
                blackToWhite[black] = white++;
            }
    }

    int pick()
    {
        int temp = rand() % bound;
        return blackToWhite.count(temp) ? blackToWhite[temp] : temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */