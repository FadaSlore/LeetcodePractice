#include <string>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string temp = "[.]";
        for (int i = address.length() - 1; i >= 0; i--)
            if (address[i] == '.')
                address.replace(i, 1, temp);
        return address;
    }
};