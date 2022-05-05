### 排序链表
### Sort List

> 给你链表的头结点 `head`，请将其按**升序**排列并返回**排序后的链表**。  

> Given the `head` of a linked list, return *the list after sorting it in **ascending order***.  

----------

#### I 转化为数组

将链表数字记录在数组中并排序  
重新构建链表将排序后的数字加入链表即可  

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
    ListNode* sortList(ListNode* head) 
    {
        vector<int> ret;
        while(head)
        {
            ret.emplace_back(head->val);
            head = head->next;
        }
        sort(ret.begin(), ret.end());
        ListNode* dummyhead = new ListNode;
        ListNode* tmp = dummyhead;
        for(int i = 0; i < ret.size(); ++i)
        {
            ListNode* cur = new ListNode(ret[i]);
            tmp->next = cur;
            tmp = tmp->next;
        }
        return dummyhead->next;
    }
};
```

#### II 自上而下分治排序

基于分治原理进行排序，排序方法为依次比较链表头的元素大小  
比较的两个链表通过递归排序完毕  

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
    ListNode* sortList(ListNode* head) 
    {
        return divide(head, nullptr);
    }

    ListNode* divide(ListNode* head, ListNode* tail)
    {
        if(head == nullptr)
            return nullptr;
        if(head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != tail)
                fast = fast->next;
        }
        ListNode* mid = slow;
        return merge(divide(head, mid), divide(mid, tail));
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyhead = new ListNode;
        ListNode* head = dummyhead;
        while(l1 || l2)
        {
            int n1 = l1 ? l1->val : INT_MAX;
            int n2 = l2 ? l2->val : INT_MAX;
            ListNode* cur = new ListNode;
            if(n1 < n2)
            {
                l1 = l1->next;
                cur->val = n1;
            }
            else
            {
                l2 = l2->next;
                cur->val = n2;
            }
            head->next = cur;
            head = head->next;
        }
        return dummyhead->next;
    }
};
```
