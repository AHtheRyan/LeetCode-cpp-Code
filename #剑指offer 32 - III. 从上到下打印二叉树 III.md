### 从上到下打印二叉树 III

> 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。  

----------

#### I 基于双端队列的BFS

基本思路与每层从左到右打印相似，只是由于这里需要之子型打印，所以采用双端队列的方式，按层的奇偶进行处理  

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
        deque<TreeNode* > q;
        q.push_back(root);
        while(!q.empty())
        {
            vector<int> cur;
            int n = q.size();
            if(ret.size() % 2 == 0)
            {
                for(int i = 0; i < n; ++i)
                {
                    auto node = q.front();
                    q.pop_front();
                    cur.push_back(node->val);
                    if(node->left)  q.push_back(node->left);
                    if(node->right) q.push_back(node->right);
                }
            }
            else
            {
                for(int i = 0; i < n; ++i)
                {
                    auto node = q.back();
                    q.pop_back();
                    cur.push_back(node->val);
                    if(node->right) q.push_front(node->right);
                    if(node->left)  q.push_front(node->left);
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};
```
