### 移除链表元素
### Remove Linked List Elements

> 给你一个链表的头节点 `head` 和一个整数 `val`，请你删除链表中所有满足 `Node.val == val` 的节点，并返回**新的头节点**。  

> Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return *the new head*.  

----------

#### I 迭代判断

设置一个头结点后进行简单迭代判断即可  

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
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummyhead = new ListNode;
        ListNode* cur = dummyhead;
        dummyhead->next = head;
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                if(cur->next->next)
                    cur->next = cur->next->next;
                else
                    cur->next = nullptr;
            }
            else
                cur = cur->next;
        }
        return dummyhead->next;
    }
};
```
