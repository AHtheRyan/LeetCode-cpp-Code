### 分隔链表
### Partition List

> 给你一个链表的头节点 `head` 和一个特定值 `x`，请你对链表进行分隔，使得所有**小于** `x` 的节点都出现在**大于或等于** `x` 的节点之前。  
> 你应当**保留**两个分区中每个节点的初始相对位置。  

> Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.  
> You should **preserve** the original relative order of the nodes in each of the two partitions.  

----------

#### I 模拟

将链表分别记录在两个链表中，一个记录值小于 `x` 的节点，另一个记录值大于等于 `x` 的节点即可  

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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* l = new ListNode;
        ListNode* g = new ListNode;
        ListNode* dummyhead = l;
        ListNode* dummyhead2 = g;
        while(head)
        {
            if(head->val < x)
            {
                l->next = head;
                l = l->next;
            }
            else
            {
                g->next = head;
                g = g->next;
            }
            head = head->next;
        }
        l->next = dummyhead2->next;
        g->next = nullptr;
        return dummyhead->next;
    }
};
```
