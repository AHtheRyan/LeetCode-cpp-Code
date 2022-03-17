### 将二叉搜索树转化为排序的双向链表
### Convert Binary Search Tree to Sorted Doubly Linked List

> 将一个**二叉搜索树**就地转化为一个**已排序的双向循环链表**。  
> 对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。  
> 特别地，我们希望可以**就地**完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中最小元素的指针。  

> Convert a **Binary Search Tree** to a sorted **Circular Doubly-Linked List** in place.  
> You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.  
> We want to do the transformation **in place**. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.  

----------

#### I 中序遍历

在二叉搜索数中按大小顺序排列实际上就是中序遍历过程，按规则DFS即可  

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
