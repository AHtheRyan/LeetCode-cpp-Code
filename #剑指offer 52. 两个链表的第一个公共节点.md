### 两个链表的公共节点

> 输入两个链表，找出它们的第一个公共节点。  

----------

#### I 哈希表

先遍历其中一个链表，将所有节点记录，之后遍历另一个链表，并在哈希表中进行匹配，如果匹配成果，则说明遇到了第一个公共节点  

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    unordered_set<ListNode* > st;
    while(headA)
    {
        st.insert(headA);
        headA = headA->next;
    }
    while(headB)
    {
        if(st.find(headB) != st.end())
            return headB;
        headB = headB->next;
    }
    return nullptr;
}
```

#### II 双指针

设置两个指针，一个先遍历A后遍历B，一个先遍历B后遍历A，  
只要两个链表有交集，则最后一定可以相较于某一节点，该节点即为链表的第一个公共节点  

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode* tmpA = headA;
    ListNode* tmpB = headB;
    int cntA = 0;
    int cntB = 0;
    while(cntA < 2 && cntB < 2)
    {
        if(headA == headB)
            return headA;
        if(headA)
            headA = headA->next;
        if(headB)
            headB = headB->next;
        if(!headA)
        {
            headA = tmpB;
            ++cntA;
        }
        if(!headB)
        {
            headB = tmpA;
            ++cntB;
        }
    }
    return nullptr;
}
```
