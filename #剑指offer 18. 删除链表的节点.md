### 删除链表的节点

> 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。  
> 返回删除后的链表的头节点。  

----------

#### I 双指针

设置一个当前指针 `head` 和一个前指针 `pre`  
当 `head->val == val` 时，将 `pre` 节点的 `next` 设置为 `head` 节点的 `next`  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* deleteNode(ListNode* head, int val) 
    {
        ListNode* dummyhead = new ListNode;
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        while(head->val != val)
        {
            pre = pre->next;
            head = head->next;
        }
        pre->next = head->next;
        return dummyhead->next;
    }
};
```
