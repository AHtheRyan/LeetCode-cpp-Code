### 链表中倒数第k个节点

> 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。  
> 例如，一个链表有 `6` 个节点，从头节点开始，它们的值依次是 `1、2、3、4、5、6`。这个链表的倒数第 `3` 个节点是值为 `4` 的节点。  

----------

#### I 双指针

倒数第k个节点即为最后一个节点往前第k个节点，  
因此，我们可以设置两个节点，一个表示倒数第一个节点，一个表示其前面的第k个节点，  
在链表中表现为两个共同前进的指针，其中一个晚于另一个k次循环后出发即可  

```cpp
ListNode* getKthFromEnd(ListNode* head, int k) 
{
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0; i < k; ++i)
        fast = fast->next;
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
```
