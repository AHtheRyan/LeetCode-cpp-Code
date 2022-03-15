### 相交链表
### Intersection of Two Linked Lists

> 给你两个单链表的头节点 `headA` 和 `headB`，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null`。  

> Given the heads of two singly linked-lists `headA` and `headB`, return *the node at which the two lists intersect*. If the two linked lists have no intersection at all, return `null`.  

----------

#### I 哈希表

见[两个链表的第一个公共节点](./%23剑指offer%2052.%20两个链表的第一个公共节点.md)  

```cpp
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    if(headA == NULL || headB == NULL)
        return NULL;

    ListNode *pheadA = headA;
    ListNode *pheadB = headB;
    unordered_map<ListNode*, int> hash;
    while(pheadA)
    {
        hash[pheadA] = pheadA->val;
        pheadA = pheadA->next;
    }
    while(pheadB)
    {
        if(hash.find(pheadB) != hash.end())
            return pheadB;
        pheadB = pheadB->next;
    }
    return NULL;
}
```

#### II 双指针

见[两个链表的第一个公共节点](./%23剑指offer%2052.%20两个链表的第一个公共节点.md)  

```cpp
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode* ptr1 = headA;
    ListNode* ptr2 = headB;
    int count1 = 1;
    int count2 = 1;
    while(count1 < 3 && count2 < 3)
    {
        if(ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(!ptr1)
        {
            ptr1 = headB;
            ++count1;
        }
        if(!ptr2)
        {
            ptr2 = headA;
            ++count2;
        }
    }
    return NULL;
}
```
