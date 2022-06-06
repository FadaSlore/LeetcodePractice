#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree
{
private:
    map<int, int> bookMap;

public:
    MyCalendarThree()
    {
        bookMap.clear();
    }

    int book(int start, int end)
    {
        bookMap[start]++;
        bookMap[end]--;
        int temp = 0, result = 0;
        for (auto book : bookMap)
            result = max(result, temp += book.second);
        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */