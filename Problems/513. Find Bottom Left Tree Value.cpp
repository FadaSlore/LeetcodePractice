#include <queue>
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
    void dfs(TreeNode *root, int height, int *currentValue, int *currentHeight)
    {
        if (root == nullptr)
            return;
        height++;
        dfs(root->left, height, currentValue, currentHeight);
        dfs(root->right, height, currentValue, currentHeight);
        if (height > *currentHeight)
        {
            *currentHeight = height;
            *currentValue = root->val;
        }
    }
    int bfs(TreeNode *root)
    {
        int result = 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            if (node->right != nullptr)
                nodeQueue.push(node->right);
            if (node->left != nullptr)
                nodeQueue.push(node->left);
            result = node->val;
        }
        return result;
    }
    int findBottomLeftValue(TreeNode *root)
    {
        // int *value = new int(0), *height = new int(0);
        // dfs(root, 0, value, height);
        // return *value;
        return bfs(root);
    }
};