### 恢复二叉树
### Recover Binary Search Tree

> 给你二叉搜索树的根节点 `root`，该树中的**恰好**两个节点的值被错误地交换。*请在不改变其结构的情况下，恢复这棵树*。  

> You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. *Recover the tree without changing its structure**.  

----------

#### I 哈希表 + 排序

搜索二叉树中序遍历为递增数列，可以记录当前搜索二叉树的中序遍历结果，并按照递增的要求将树的节点进行更改  

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
private:
    unordered_map<int, TreeNode*> mp;
    vector<int> valRec;

public:
    void recoverTree(TreeNode* root) 
    {
        dfs(root);
        vector<int> tmp = valRec;
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < valRec.size(); ++i)
            if(valRec[i] != tmp[i])
                mp[valRec[i]]->val = tmp[i];
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        mp[root->val] = root;
        valRec.emplace_back(root->val);
        dfs(root->right);
    }
};
```
