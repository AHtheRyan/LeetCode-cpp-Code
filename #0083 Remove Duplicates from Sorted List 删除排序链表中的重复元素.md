### 删除排序链表中的重复元素
### Remove Duplicates from Sorted List

> 给定一个已排序的链表的头 `head`，*删除所有重复的元素，使每个元素只出现一次*。返回*已排序的链表*。  

> Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.  

----------

#### I 模拟

按顺序删除即可

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummyhead = new ListNode;
        dummyhead->next = head;
        while(head)
        {
            if(head->next && head->val == head->next->val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return dummyhead->next;
    }
};
```
