### Merge Two Sorted Lists
### 合并两个有序链表

> 将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  

> You are given the heads of two sorted linked lists `list1` and `list2`.  
> Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.  
> Return *the head of the merged linked list*.

----------

#### I 迭代

按顺序比较两个链表中的元素，并依次组合即可

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode;
        ListNode* dummyhead = new ListNode(0, head);
        while(l1 || l2)
        {
            int n1 = l1 ? l1->val : 101;
            int n2 = l2 ? l2->val : 101;
            if(n1 > n2)
            {
                head->next = l2;
                l2 = l2->next;
            }
            else
            {
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        return dummyhead->next->next;
    }
};
```

#### II 递归

与迭代同理，按顺序比较两个链表的元素即可

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```
