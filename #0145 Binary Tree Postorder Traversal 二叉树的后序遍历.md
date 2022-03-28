### 二叉树的后序遍历
### Binary Tree Postorder Traversal

> 给你一棵二叉树的根节点 `root`，返回其节点值的**后序遍历**。  

> Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.  

----------

#### I 递归

简单递归

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        dfs(ret, root);
        return ret;
    }

    void dfs(vector<int>& ret, TreeNode* root)
    {
        if(!root)
            return;
        dfs(ret, root->left);
        dfs(ret, root->right);
        ret.emplace_back(root->val);
    }
};
```

#### II 迭代

基于栈进行迭代计算，迭代时需要对每个根节点进行判断，计算其是否为第二次被遍历到（即考虑完了左右节点之后），如果是，则可以将其值记录并计算其根节点的值  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<int> ret;
        stack<TreeNode* > stk;
        TreeNode* pre = nullptr;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(!root->right || root->right == pre)
            {
                ret.emplace_back(root->val);
                pre = root;
                root = nullptr;
            }
            else
            {
                stk.push(root);
                root = root->right;
            }
        }
        return ret;
    }
};
```

#### III Morris遍历

Morris遍历的基本思路为运用空指针，将树模拟为单链表进行数值记录和输出  
对于一棵树，可以设置两个节点 `cur = root` 和 `pre = nullptr`，并进行如下操作：  
1. 设 `pre` 为 `cur->left` 的节点，迭代判断 `pre` 节点是否存在右子节点并取该节点到最右端，将最右端的子节点的 `right` 节点即为 `cur` 节点  
2. 循环上述步骤，每次都将 `cur` 节点的 `left` 节点的最右子节点的 `right` 节点指向 `cur` 节点  
3. 完成上述最后一遍循环之后，可以逐步回退 `cur`，每次将 `cur->left` 的右子节点群输出并翻转即可  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<int> ret;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while(cur)
        {
            pre = cur->left;
            if(pre)
            {
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right)
                {
                    pre->right = cur;
                    cur = cur->left;
                    continue;
                }
                else
                {
                    pre->right = nullptr;
                    addPath(ret, cur->left);
                }
            }
            cur = cur->right;
        }
        addPath(ret, root);
        return ret;
    }

    void addPath(vector<int>& ret, TreeNode* root)
    {
        int count = 0;
        while(root)
        {
            ++count;
            ret.emplace_back(root->val);
            root = root->right;
        }
        reverse(ret.end() - count, ret.end());
    }
};
```
