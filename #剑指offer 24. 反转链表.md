### 反转链表

> 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

----------

#### I 迭代（具体分析见[反转链表](./%230206%20Reverse%20Linked%20List%20反转链表.md)）

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};
```

#### II 递归（具体分析见[反转链表](./%230206%20Reverse%20Linked%20List%20反转链表.md)）

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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* nextReversedNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nextReversedNode;
    }
};
```
