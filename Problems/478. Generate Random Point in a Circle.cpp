#include <random>
using namespace std;

class Solution
{
private:
    mt19937 generate{random_device{}()};
    uniform_real_distribution<double> distance;
    double xCenter, yCenter, radius;

public:
    Solution(double radius, double x_center, double y_center) : distance(-radius, radius), xCenter(x_center), yCenter(y_center), radius(radius) {}

    vector<double> randPoint()
    {
        while (true)
        {
            double x = distance(generate), y = distance(generate);
            if (x * x + y * y <= radius * radius)
                return {xCenter + x, yCenter + y};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */