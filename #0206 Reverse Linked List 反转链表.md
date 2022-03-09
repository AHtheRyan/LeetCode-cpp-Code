### 反转链表
### Reverse Linked List

> 给你单链表的头节点 `head`，请你反转链表，并返回反转后的链表。  

> Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.  

----------

#### I 迭代

首先，设置两个节点 `pre` 和 `cur`，分别表示前一节点和当前节点，由于首节点无前一节点，因此初始值为 `pre = nullptr` `cur = head`：  
![1646804765(1)](https://user-images.githubusercontent.com/46887748/157380291-78f9e9b7-3d3f-4ab3-9b07-4690f37e524c.png)  
接着，**进入循环**，具体过程如下：  
首先，设置节点 `nex` 表示当前节点的下一节点，注意，此节点需要变成当前节点的前一节点  
![1646804903(1)](https://user-images.githubusercontent.com/46887748/157380508-c056cbd9-5f85-470f-a036-94754ce758e4.png)  
然后，将当前节点的前一节点设置为其下一个节点  
![1646805018(1)](https://user-images.githubusercontent.com/46887748/157380663-bb87bc44-d537-4878-89ed-48d2f4435be7.png)  
之后，依次将 `pre` 和 `cur` 的节点值更新  
![1646805123(1)](https://user-images.githubusercontent.com/46887748/157380827-98aa0d23-cfe7-4453-afae-6b58ff4bee5c.png)  
按照上述思路将每个节点遍历，即可将链表翻转

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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};
```

#### II 递归

分析每个位置的节点在自己的递归过程中要做的事，以下图的节点 `3`(设置为 `head`)为例：  
![1646805470(1)](https://user-images.githubusercontent.com/46887748/157381443-9c467534-46ca-4d95-9bc5-7c47502dcc9e.png)  
首先，节点对 `head` 的后续部分求倒置，即 `reverseList(head->next)`，其结果如下：  
![1646805519(1)](https://user-images.githubusercontent.com/46887748/157381516-a1ef9e13-3159-4169-94a9-10eb4b03f257.png)  
随后，我们需要将 `head` 也加入当前的倒置中，第一步是将 `head` 后面的指针指向 `head`：  
![1646805557(1)](https://user-images.githubusercontent.com/46887748/157381580-05261e1d-a75a-4fe6-9ce8-afeeaae55314.png)  
接着是将 `head` 指向 `nullptr`：  
![1646805625(1)](https://user-images.githubusercontent.com/46887748/157381700-2af2eeda-8ff3-47c9-b4ed-6b69722793f4.png)  
当前递归完成  
按此规律逐个递归即可  

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
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* nextReversedNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nextReversedNode;
    }
};
```
