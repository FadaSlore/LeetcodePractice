#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> address;
        for (auto email : emails)
        {
            string local;
            for (char c : email)
            {
                if (c == '+' || c == '@')
                    break;
                if (c != '.')
                    local += c;
            }
            address.emplace(local + email.substr(email.find('@')));
        }
        return address.size();
    }
};