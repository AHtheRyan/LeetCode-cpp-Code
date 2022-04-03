### 回文链表
### Palindrome Linked List

> 给你一个单链表的头节点 `head`，请你判断该链表是否为回文链表。如果是，返回 `true`；否则，返回 `false`。  

> Given the `head` of a singly linked list, return `true` if it is a palindrome.  

----------

### I 双向指针逐位比较

可以找到链表的中间节点，再从该位置向左右两侧进发，比较链表，分为几个步骤：  
1. 确认链表长度  
2. 将链表分为两段  
3. 将左侧链表反转  
4. 将两个链表进行比较  

可将四个步骤拆分为四个函数，完成整个回文链表的比较过程  

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
    bool isPalindrome(ListNode* head) 
    {
        int len = findLen(head);
        if(len <= 1)
            return true;
        ListNode* lHead = findMidNode(head, len);
        ListNode* rHead;
        if(len % 2)
            rHead = lHead->next->next;
        else
            rHead = lHead->next;
        lHead->next = nullptr;
        lHead = reverseListNode(head);
        return compare(lHead, rHead);
    }

    int findLen(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            ++len;
            head = head->next;
        }
        return len;
    }

    ListNode* findMidNode(ListNode* head, int len)
    {
        int mid = len / 2;
        while(--mid > 0)
            head = head->next;
        return head;
    }

    ListNode* reverseListNode(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nex = head->next;
        while(nex)
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;
        return cur;
    }
    
    bool compare(ListNode* l, ListNode* r)
    {
        while(l && r)
        {
            if(l->val != r->val)
                return false;
            l = l->next;
            r = r->next;
        }
        return true;
    }
};
```
