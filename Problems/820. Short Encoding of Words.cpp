#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static bool compare(const string a, const string b)
    {
        int aLength = a.length(), bLength = b.length();
        for (int i = 0; i < min(aLength, bLength); i++)
        {
            if (a[aLength - 1 - i] != b[bLength - 1 - i])
                return a[aLength - 1 - i] < b[bLength - 1 - i];
        }
        return aLength < bLength;
    }

public:
    bool endWith(string a, string b)
    {
        int aLength = a.length(), bLength = b.length();
        if (aLength < bLength)
            return false;
        for (int i = 0; i < bLength; i++)
            if (a[aLength - bLength + i] != b[i])
                return false;
        return true;
    }
    int minimumLengthEncoding(vector<string> &words)
    {
        sort(words.begin(), words.end(), compare);
        int result = 0;
        for (int i = 1; i < words.size(); i++)
            if (!endWith(words[i], words[i - 1]))
                result += words[i - 1].length() + 1;
        result += words[words.size() - 1].length() + 1;
        return result;
    }
};