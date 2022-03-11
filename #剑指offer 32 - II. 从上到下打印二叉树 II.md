### 从上到下打印二叉树 II

> 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。  

----------

#### I 基于队列的BFS

对于可以利用队列的性质，完成BFS打印，每层打印时，以队列的大小为循环次数进行打印，即可实现按层打印  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> floor;
            for(int i = 0; i < size; ++i)
            {
                auto cur = q.front();
                q.pop();
                floor.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ret.push_back(floor);
        }
        return ret;
    }
};
```
