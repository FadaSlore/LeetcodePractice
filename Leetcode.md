# Leetcode
<!--
<font color=green>Easy</font>
<font color=orange>Medium</font>
<font color=red>Hard</font>
-->

## [450. Delete Node in a BST](/Problems/450_Delete_Node_in_a_BST.cpp)
- 給定一個二元樹根節點`root`與一數`key`，若`key`存在於此二元數內，則刪除並重組二元樹，回傳新的根節點
- 技巧：回溯法，在過程中記錄所尋找的點的**父節點**
    1. 對`key`節點**右**子樹的所有節點尋找最小值節點（最**左**葉節點）
    2. 對`key`節點**左**子樹的所有節點尋找最大值節點（最**右**葉節點）
    - 需注意的是，當`change_parent`（上述之父節點）與`key`節點（`target`）為同一個節點時，轉換的左右子樹會不同
```cpp
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
```

## [829. Consecutive Numbers Sum](/Problems/829_Consecutive_Numbers_Sum.cpp)
- 給定一數`n`，求連續正整數和為`n`的組數
- 技巧：從`x`到`x+k-1`（`k`個數），和為`n`
    - `(2x+k-1)*k=2n` → 對可整除`2n`的`k`，求出是否存在正整數`x`滿足此式
```cpp
class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        int result = 0;
        n <<= 1;
        for (int k = 1; k < sqrt(n); k++)
            if ((n % k == 0) && (((n / k) + 1 - k) & 1) == 0)
                result++;
        return result;
    }
};
```


## [867. Transpose Matrix](/Problems/867_Transpose_Matrix.cpp)
- 給定矩陣`matrix`，輸出轉置（transpose）矩陣
```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0;i<matrix[0].size();i++)
            for (int j = 0; j < matrix.size();j++)
                result[i][j] = matrix[j][i];
        return result;
    }
};
```
