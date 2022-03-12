### N叉树的后序遍历
### N-ary Tree Postorder Traversal

> 给定一个 n 叉树的根节点 `root`，返回*其节点值的**后序遍历***。  
> n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 `null` 分隔。  

> Given the `root` of an n-ary tree, return *the postorder traversal of its nodes' values*.  
> Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value.  

----------

#### I 栈

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
    vector<int> postorder(Node* root) 
    {
        vector<int> ret;
        stack<Node* > stk;
        unordered_map<Node*, int> index;
        Node* cur = root;
        while(!stk.empty() || cur)
        {
            while(cur)
            {
                stk.push(cur);
                if(!cur->children.empty())
                {
                    index[cur] = 0;
                    cur = cur->children[0];
                }
                else
                    cur = nullptr;
            }
            cur = stk.top();
            ++index[cur];
            if(index[cur] < cur->children.size())
                cur = cur->children[index[cur]];
            else
            {
                ret.push_back(cur->val);
                stk.pop();
                cur = nullptr;
            }
        }
        return ret;
    }
};
```
