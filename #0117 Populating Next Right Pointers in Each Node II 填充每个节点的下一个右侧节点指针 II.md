### 填充每个节点的下一个右侧节点指针 II
### Populating Next Right Pointers in Each Node II

> 给定一个二叉树  
```cpp
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```
> 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL`。  
> 初始状态下，所有 next 指针都被设置为 `NULL`。  

> Given a binary tree
```cpp
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

#### I 迭代

利用 `next` 指针的性质进行迭代即可  

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
    void handle(Node*& last, Node*& cur, Node*& nexthead)
    {
        if(!nexthead)
            nexthead = cur;
        if(last)
            last->next = cur;
        last = cur;
    }

    Node* connect(Node* root) 
    {
        if(!root)
            return nullptr;
        Node* head = root;
        while(head)
        {
            Node* last = nullptr;
            Node* nexthead = nullptr;
            for(Node* p = head; p != nullptr; p = p->next)
            {
                if(p->left)
                    handle(last, p->left, nexthead);
                if(p->right)
                    handle(last, p->right, nexthead);
            }
            head = nexthead;
        }
        return root;
    }
};
```
