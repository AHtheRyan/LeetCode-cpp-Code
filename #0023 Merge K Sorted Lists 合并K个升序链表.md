### 合并K个升序链表
### Merge K Sorted Lists

> 给你一个链表数组，每个链表都已经按升序排列。  
> 请你将所有链表合并到一个升序链表中，返回合并后的链表。  

> You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.  
> *Merge all the linked-lists into one sorted linked-list and return it*.  

----------

#### I 朴素递归

利用递归的方式，在数组里寻找最小的第一个元素值，找到后记下下标，  
并将其接在返回的链表节点后面，  
以此类推，最后将长链表返回即可  
整个寻找的过程可以采用递归的方式  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* ret = new ListNode;
        merge(lists, ret);
        return ret->next;
    }

    void merge(vector<ListNode*>& lists, ListNode* ret)
    {
        int cur = 10001;
        int index = -1;
        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i] && lists[i]->val < cur)
            {
                cur = lists[i]->val;
                index = i;
            }
        }
        if(index == -1)
            return;
        ret->next = new ListNode;
        ret = ret->next;
        ret->val = cur;
        lists[index] = lists[index]->next;
        merge(lists, ret);
    }
};
```

#### II 分治

可以采用分治的思想，将链表两两先排序，这样链表的规模可以对半减小，效率为 `log` 级别  

```cpp
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge2(ListNode* l1, ListNode* l2)
    {
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        ListNode* dummyhead = new ListNode;
        ListNode* movehead = dummyhead;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                movehead->next = l1;
                l1 = l1->next;
            }
            else
            {
                movehead->next = l2;
                l2 = l2->next;
            }
            movehead = movehead->next;
        }
        movehead->next = l1 ? l1 : l2;
        return dummyhead->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right)
            return lists[left];
        if(left > right)
            return nullptr;
        int mid = (left + right) / 2;
        return merge2(merge(lists, left, mid), merge(lists, mid + 1, right));
    }
};
```
