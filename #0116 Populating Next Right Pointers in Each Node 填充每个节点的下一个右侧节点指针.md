### 填充每个节点的下一个右侧节点指针
### Populating Next Right Pointers in Each Node

> 给定一个**完美二叉树**，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```
> 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL`。  
> 初始状态下，所有 next 指针都被设置为 `NULL`。  

> You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:  
```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```
> Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.  
> Initially, all next pointers are set to `NULL`.  

----------

#### I 队列 + BFS

简单BFS

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                auto cur = q.front();
                q.pop();
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
                if(i < n - 1)
                    cur->next = q.front();
            }
        }
        return root;
    }
};
```

#### II 迭代

利用完美二叉树的性质可以快速处理每个节点，同时不需要额外的空间  
由于完美二叉树在每一层都是满的，因此其必然每个非叶子结点都有左右子节点，可以根据此性质，按层迭代处理  

```cpp

```
