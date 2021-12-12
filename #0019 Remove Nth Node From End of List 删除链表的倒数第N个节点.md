### 删除链表的倒数第N个节点
### Remove Nth Node From End of List

> 给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。  

> Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.  

----------

#### I 双指针

最简单的方法是确认链表的长度，然后减去 `n`，得到正向长度再处理，这里不提  
可见，倒数第 `n` 节点始终处于尾结点的前面第 `n - 1` 个位置，  
因此，可以设置两个指针，一个在另一个往后前进 `n` 次后再开始前进，  
这样，只要快的指针到达末尾，那么慢的指针必然会到需要处理的位置

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummyhead = new ListNode;
        dummyhead->next = head;
        ListNode* pioneer = dummyhead;
        ListNode* process = dummyhead;
        for(int i = 0; i <= n; ++i)
            pioneer = pioneer->next;
        while(pioneer)
        {
            pioneer = pioneer->next;
            process = process->next;
        }
        process->next = process->next->next;
        return dummyhead->next;
    }
};
```

#### II 栈

栈的方法与直接计数类似，只要将链表节点进栈，再逆向弹出，则可以找到倒数第 `n` 个节点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        stack<ListNode*> stk;
        ListNode* dummyhead = new ListNode(0, head);
        ListNode* tmp = dummyhead;
        while(tmp)
        {
            stk.push(tmp);
            tmp = tmp->next;
        }
        for(int i = 0; i < n; ++i)
            stk.pop();
        ListNode* process = stk.top();
        process->next = process->next->next;
        ListNode* ret = dummyhead->next;
        delete dummyhead;
        return ret;
    }
};
```
