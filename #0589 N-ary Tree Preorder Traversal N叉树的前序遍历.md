### N叉树的前序遍历
### N-ary Tree Preorder Traversal

> 给定一个n叉树的根节点 `root`，返回 其节点值的***前序遍历***。  
> n叉树在输入中按层序遍历进行序列化表示，每组子节点由空值 `null` 分隔。  

> Given the `root` of an n-ary tree, return *the preorder traversal of its nodes' values*.  
> Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value.  

----------

### I 迭代

**递归比较简单，这里就不写了**  
迭代的思路也很简单，利用栈进行操作即可，每次倒序将根节点的子节点堆入栈中，之后再依次检索其是否有子节点并将相关值记录即可    

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
    vector<int> preorder(Node* root) 
    {
        if(!root)
            return {};
        vector<int> ret;
        stack<Node* > stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node* cur = stk.top();
            stk.pop();
            for(int i = (cur->children).size() - 1; i >= 0; --i)
                stk.push(cur->children[i]);
            ret.push_back(cur->val);
        }
        return ret;
    }
};
```
