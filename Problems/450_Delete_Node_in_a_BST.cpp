
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *target = root, *parent;
        while (target != nullptr && target->val != key)
        {
            parent = target;
            if (target->val < key)
                target = target->right;
            else
                target = target->left;
        }
        if (target == nullptr)
            return root;
        if (parent == nullptr && target->left == nullptr && target->right == nullptr)
            return nullptr;
        if (target->left == nullptr && target->right == nullptr)
        {
            if (parent->left == target)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            return root;
        }

        TreeNode *change, *change_parent = target;
        if (target->right == nullptr)
        {
            change = target->left;
            while (change->right != nullptr)
            {
                change_parent = change;
                change = change->right;
            }
            if (change_parent == target)
                change_parent->left = change->left;
            else
                change_parent->right = change->left;
        }
        else
        {
            change = target->right;
            while (change->left != nullptr)
            {
                change_parent = change;
                change = change->left;
            }
            if (change_parent == target)
                change_parent->right = change->right;
            else
                change_parent->left = change->right;
        }
        target->val = change->val;
        return root;
    }
};