### 反转链表 II
### Reverse Linked List

> 给你单链表的头指针 `head` 和两个整数 `left` 和 `right`，其中 `left <= right`。请你反转从位置 `left` 到位置 `right` 的链表节点，返回**反转后的链表**。  

> Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.  

----------

#### I 迭代

设定三个指针指向不同的链表进行迭代即可  

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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        int cnt = 0;
        ListNode* dummyhead = new ListNode;
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        while(cnt < left - 1)
        {
            ++cnt;
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* nex;
        for(int i = 0; i < right - left; ++i)
        {
            nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummyhead->next;
    }
};
```
