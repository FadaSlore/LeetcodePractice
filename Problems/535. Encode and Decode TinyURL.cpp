#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    unordered_map<int, string> dataBase;
    int id;

public:
    Solution()
    {
        dataBase.clear();
        id = 1;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        dataBase[id] = longUrl;
        return string("http://tinyurl.com/") + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int numberIndex = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(numberIndex, int(shortUrl.size() - numberIndex)));
        return dataBase[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));