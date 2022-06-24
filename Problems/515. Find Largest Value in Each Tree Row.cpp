#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void dfs(vector<int> &result, TreeNode *root, int height)
    {
        if (root == nullptr)
            return;

        if (result.size() <= height)
            result.push_back(root->val);
        else
            result[height] = max(result[height], root->val);

        dfs(result, root->right, height + 1);
        dfs(result, root->left, height + 1);
    }
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;
        dfs(result, root, 0);
        return result;
    }
};