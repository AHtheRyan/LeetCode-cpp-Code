### 删除排序链表中的重复元素II
### Remove Duplicates from Sorted List II

> 给定一个已排序的链表的头 `head`，*删除原始链表中所有重复数字的节点，只留下不同的数字*。返回*已排序的链表*。  

> Given the `head` of a sorted linked list, *delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list*. Return *the linked list **sorted** as well*.  

----------

#### I 迭代

按顺序遍历每一个节点，并按照要求跳过重复节点即可  

```cpp
ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* dummyhead = new ListNode;
    dummyhead->next = head;
    ListNode* roll = dummyhead;
    while(roll->next && roll->next->next)
    {
        if(roll->next->val == roll->next->next->val)
        {
            ListNode* cur = roll->next->next;
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            cur = cur->next;
            roll->next = cur;
        }
        else
            roll = roll->next;
    }
    return dummyhead->next;
}
```
