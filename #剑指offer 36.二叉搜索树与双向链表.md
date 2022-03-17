### 二叉搜索树与双向链表

> 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。  
> 链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。  
> 特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。  

----------

#### I 中序遍历

见[将二叉搜索树转化为排序的双向链表](./%230426%20Convert%20Binary%20Search%20Tree%20to%20Sorted%20Doubly%20Linked%20List%20将二叉搜索树转化为排序的双向链表.md)  

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution 
{
public:
    Node* treeToDoublyList(Node* root) 
    {
        if(!root)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node* head;
    Node* pre;

    void dfs(Node* root)
    {
        if(!root)
            return;
        dfs(root->left);
        if(pre != nullptr)
            pre->right = root;
        else
            head = root;
        root->left = pre;
        pre = root;
        dfs(root->right);
    }
};
```
