### 旋转链表
### Rotate List

> 给你一个链表的头节点 `head`，旋转链表，将链表每个节点向右移动 `k` 个位置。  

> Given the `head` of a linked list, rotate the list to the right by `k` places.  

----------

#### I 成环 + 解环

将原链表成环，并计算链表长度 `cnt`，则初始链表的实际右移位置为 `cnt - k % cnt`，  
再通过对节点进行 `next` 操作，找到最终的初始节点的位置，并将前一位置的 `next` 节点设为 `nullptr`  即可

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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(k == 0 || !head || !head->next)
            return head;
        int cnt = 1;
        ListNode* tmp = head;
        while(tmp->next)
        {
            ++cnt;
            tmp = tmp->next;
        }
        int realMove = cnt - k % cnt;
        if(realMove == cnt)
            return head;
        tmp->next = head;
        while(realMove--)
            tmp = tmp->next;
        ListNode* ret = tmp->next;
        tmp->next = nullptr;
        return ret;
    }
};
```
