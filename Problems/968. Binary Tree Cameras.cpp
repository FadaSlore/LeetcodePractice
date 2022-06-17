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
private:
    int answer = 0;

public:
    int minCameraCover(TreeNode *root)
    {
        if (dfs(root) == 2)
            answer += 1;
        return answer;
    }
    // 0: installed, 1: be monitored but not installed, 2: not be monitored (need to be installed)
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 1;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 2 || right == 2)
        {
            answer += 1;
            return 0;
        }
        else if (left == 0 || right == 0)
            return 1;
        else
            return 2;
    }
};