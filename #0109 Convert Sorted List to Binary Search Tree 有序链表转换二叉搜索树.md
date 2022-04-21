### 有序链表转换二叉搜索树
### Convert Sorted List to Binary Search Tree

> 给定一个单链表的头节点 `head`，其中的元素**按升序排序**，将其转换为高度平衡的二叉搜索树。  

> Given the `head` of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.  

----------



#### I 分治 + 中序遍历优化

对链表进行分治处理  
先计算其长度 `len`，之后对整个链表进行分治，其过程类似于[将有序数组转化为二叉搜索树](./%230108%20Convert%20Sorted%20Array%20to%20Binary%20Search%20Tree%20将有序数组转化为二叉搜索树.md)  
区别在于，当前处理的数据结构为链表，因此，可以给尚未出现的数字留下一个“空位”，待出现后再将其补上，具体见下方代码  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        int len = 0;
        ListNode* node = head;
        while(node)
        {
            ++len;
            node = node->next;
        }
        return build(head, 0, len - 1);
    }

    TreeNode* build(ListNode*& head, int left, int right)
    {
        if(left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* cur = new TreeNode;
        cur->left = build(head, left, mid - 1);
        cur->val = head->val;
        head = head->next;
        cur->right = build(head, mid + 1, right);
        return cur;
    }
};
```
