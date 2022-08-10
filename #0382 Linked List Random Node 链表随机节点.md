### 链表随机节点
### Linked List Random Node

> 给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点**被选中的概率一样**。  
> 实现 `Solution` 类：  
> - `Solution(ListNode head)` 使用整数数组初始化对象。  
> - `int getRandom()` 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。  

> Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.  
> Implement the `Solution` class:  
> - `Solution(ListNode head)` Initializes the object with the head of the singly-linked list `head`.  
> - `int getRandom()` Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.  

----------

#### I 随机数

利确定好链表的长度后，利用随机数取值即可  

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
private:
    int cnt;
    ListNode* head;

public:
    Solution(ListNode* _head) 
    {
        head = _head;
        ListNode* phead = head;
        cnt = 0;
        ListNode* node = head;
        while(node)
        {
            ++cnt;
            node = node->next;
        }
    }
    
    int getRandom() 
    {
        int n = rand() % cnt;
        ListNode* tmp = head;
        for(int i = 0; i < n; ++i)
            tmp = tmp->next;
        return tmp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```
