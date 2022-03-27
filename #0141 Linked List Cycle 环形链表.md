### 环形链表
### Linkede List Cycle

> 给你一个链表的头节点 `head`，判断链表中是否有环。  
> 如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。  
> *如果链表中存在环*，则返回 `true`。 否则，返回 `false`。  

> Given `head`, the head of a linked list, determine if the linked list has a cycle in it.  
> There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.   
> Return `true` *if there is a cycle in the linked list*. Otherwise, return `false`.  

----------

#### I 哈希表

遍历链表，并利用哈希表记录每个节点，如果某个节点被记录并被遍历到，说明出现了循环，则返回 `true`，否则返回 `false`  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        unordered_set<ListNode* > st;
        while(head)
        {
            if(st.count(head))
                return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};
```

#### II 双指针

利用快慢指针进行遍历，如果不存在环，则快指针必然会先到达末尾节点  
如果存在环，则由于快指针每次前进两步，慢指针每次前进一步，则两个指针必然会在跑环的途中相遇，可以此为依据确定是否存在环  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
```
