### 在二叉树中增加一行
### Add One Row to Tree

> 给定一个二叉树的根 `root` 和两个整数 `val` 和 `depth`，在给定的深度 `depth` 处添加一个值为 `val` 的节点行。  
> 注意，根节点 `root` 位于深度 `1`。  
> 加法规则如下:  
> - 给定整数 `depth`，对于深度为 `depth - 1` 的每个非空树节点 `cur`，创建两个值为 `val` 的树节点作为 `cur` 的左子树根和右子树根。  
> - `cur` 原来的左子树应该是新的左子树根的左子树。  
> - `cur` 原来的右子树应该是新的右子树根的右子树。  
> - 如果 `depth == 1` 意味着 `depth - 1` 根本没有深度，那么创建一个树节点，值 `val` 作为整个原始树的新根，而原始树就是新根的左子树。  

> Given the `root` of a binary tree and two integers `val` and `depth`, add a row of nodes with value `val` at the given depth `depth`.  
> Note that the root node is at depth 1.  
> The adding rule is:  
> - Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.  
> - `cur`'s original left subtree should be the left subtree of the new left subtree root.  
> - `cur`'s original right subtree should be the right subtree of the new right subtree root.  
> - If `depth == 1` that means there is no depth `depth - 1` at all, then create a tree node with value `val` as the new root of the whole original tree, and the original tree is the new root's left subtree.  

----------

#### I BFS

利用BFS找到预定深度上面一层，然后对其左右子树进行更改，并将之前的左右字树接在新的左右字树的左或右子树位置即可  

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
            return new TreeNode(val, root, nullptr);
        queue<TreeNode* > q;
        q.push(root);
        for(int i = 1; i < depth - 1; ++i)
        {
            int n = q.size();
            for(int j = 0; j < n; ++j)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
        }
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            cur->left = new TreeNode(val, cur->left, nullptr);
            cur->right = new TreeNode(val, nullptr, cur->right);
        }
        return root;
    }
};
```
