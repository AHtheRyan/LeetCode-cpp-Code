### 从头到尾打印链表

> 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。  

----------

#### I 栈

栈具有先进后出的特性，现将链表元素入栈，然后依次出栈加入返回数组中即可  

```cpp
vector<int> reversePrint(ListNode* head) 
{
    stack<int> stk;
    vector<int> ret;
    while(head)
    {
        stk.push(head->val);
        head = head->next;
    }
    while(!stk.empty())
    {
        ret.push_back(stk.top());
        stk.pop();
    }
    return ret;
}
```
