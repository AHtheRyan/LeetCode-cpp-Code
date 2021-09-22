### 分隔链表
### Split Linked List in Parts

> 给你一个头结点为 `head` 的单链表和一个整数 `k` ，请你设计一个算法将链表分隔为 `k` 个连续的部分。  
> 每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。  
> 这 `k` 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。  
> 返回一个由上述 `k` 部分组成的数组。  

> Given the `head` of a singly linked list and an integer `k`, split the linked list into `k` consecutive linked list parts.  
> The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.  
> The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.  
> Return an array of the `k` parts.  

----------

#### I 计数分割

分割链表长度的逻辑很简单，即：
- 将链表长度求出  
- 均分为 k 个  
- 将前 n 个数的链表长度加一，其中 n 为余数  

这样就可以得出每段链表的长度  
之后按照求出的长度将每段链表的首节点记录在数组中，并将尾结点位置的后一位先记录下来，再设置成 `nullptr` 即可  

```cpp
vector<ListNode*> splitListToParts(ListNode* head, int k) 
{
    ListNode* cNode = head;
    int cnt = 0;
    while(cNode)
    {
        ++cnt;
        cNode = cNode->next;
    }
    int part = cnt / k;
    vector<int> pos(k, part);
    int res = cnt % k;
    vector<ListNode*> ret(k, nullptr);
    ListNode* curNode = head;
    for(int i = 0; i < k && curNode != nullptr; ++i)
    {
        ret[i] = curNode;
        int size = part + (res-- <= 0 ? 0 : 1);
        for(int j = 1; j < size; ++j)
            curNode = curNode->next;
        ListNode* tmp = curNode->next;
        curNode->next = nullptr;
        curNode = tmp;
    }
    return ret;
}
```
