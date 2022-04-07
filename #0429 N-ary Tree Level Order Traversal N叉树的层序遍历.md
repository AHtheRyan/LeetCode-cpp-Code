### N叉树的层序遍历
### N-ary Tree Level Order Traversal

> 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。  

> Given an n-ary tree, return the level order traversal of its nodes' values.  

----------

#### I BFS

简单BFS

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)
            return {};
        vector<vector<int>> ret;
        queue<Node* > q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; ++i)
            {
                auto cur = q.front();
                q.pop();
                tmp.emplace_back(cur->val);
                for(int j = 0; j < cur->children.size(); ++j)
                    q.push(cur->children[j]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
```
