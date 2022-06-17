#include <vector>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int size = arr.size(), count = 0, index = -1;
        while (count < size)
        {
            index++;
            if (arr[index] != 0)
                count += 1;
            else
                count += 2;
        }
        int right = size - 1;
        if (count == (size + 1))
        {
            arr[right--] = 0;
            index--;
        }
        while (right >= 0)
        {
            arr[right--] = arr[index];
            if (arr[index] == 0)
                arr[right--] = arr[index];
            index--;
        }
    }
};