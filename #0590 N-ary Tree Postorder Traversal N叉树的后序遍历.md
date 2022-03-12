### N叉树的后序遍历
### N-ary Tree Postorder Traversal

> 给定一个 n 叉树的根节点 `root`，返回*其节点值的**后序遍历***。  
> n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 `null` 分隔。  

> Given the `root` of an n-ary tree, return *the postorder traversal of its nodes' values*.  
> Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value.  

----------

#### I 栈 + 哈希表

 后序遍历的基本规则是先输出一个几点的子节点，再输出一个节点的根节点  
 对于N叉树，为了通过栈完成后序遍历，可以进行如下考虑：  
 1. 对于任意节点，我们需要找到其最深处的第一个子节点，这个步骤可以由 `while` 循环完成  
 2. 当找到最底层的节点后，我们需要做的是再依次输出最底层节点的兄弟节点，这里需要注意，由于兄弟节点由 `vector` 表示，所以我们可以利用哈希表记录每个节点的子节点遍历到的下标序号  
 3. 如果当前子节点遍历完，说明此节点是当前后序遍历的最底层，可以记录下来，同时将栈顶节点弹出（此节点的所有子节点机器本身都计算过了）  
 4. 如果当前子节点未遍历完，则将下标增加，之后经历步骤1的循环，找到其最深处的节点  

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
