### K个一组翻转链表
### Reverse Nodes in k-Group

> 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。  
> k 是一个正整数，它的值小于或等于链表的长度。  
> 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。  
> **进阶：**  
> - 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
> - 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。  

> Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.  
> k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.  
> You may not alter the values in the list's nodes, only nodes themselves may be changed.  

----------

#### I 迭代

此题采用迭代的方式，基本思路类似于[#0024 Swap Nodes in Pairs 两两交换链表中的节点](./%230024%20Swap%20Nodes%20in%20Pairs%20两两交换链表中的节点.md)，建议做完后再思考此题  
由于翻转链表的要求从两两交换变成了 **k个一组**，因此我们可以先求出整个链表的长度，之后计算出以公会发生多少组 **k个一组** 的翻转，  
之后，我们利用循环，每次翻转k个节点即可，下面以 `[1, 2, 3, 4, 5]` 数组，`3` 个一组，加以图片举例，  
假设我们已经得到了长度 `5`，以及会进行 `5 / 3 = 1` 组翻转：  
1. 首先，为了便于返回操作，给链表赋予一个头结点 `ret`，同时创建一个用于迭代操作的拷贝 `pre'  ![1630506297(1)](https://user-images.githubusercontent.com/46887748/131688919-aa1551a1-2fb0-4f12-a493-df1bc457f188.png)  
2. 接着，将头结点之后的第一个节点赋予两个拷贝 `first` 和 `move`（原因稍后解释）  ![1630506406(1)](https://user-images.githubusercontent.com/46887748/131689204-a52d517c-ccd8-4fc8-af75-73ad63e9faef.png)  
3. 接下来可以进行以k为组的循环迭代操作（首先旋转 `1` 和 `2`）：  
   - 将 `move` 的下一个节点赋予拷贝 `tmp`  ![1630506531(1)](https://user-images.githubusercontent.com/46887748/131689555-8840643e-3c8e-4e78-95e7-ac1959f1a976.png)  
   - 将 `2` 的下一个节点变成 `1` 的下一个节点  ![1630506627(1)](https://user-images.githubusercontent.com/46887748/131689828-3c6953a6-deb0-4e1f-9dc9-f7cd7ef37a8c.png)  
   - 将 `2` 设置为第一个节点  ![1630506807(1)](https://user-images.githubusercontent.com/46887748/131690391-70c7d211-1017-4eeb-bffe-8ecad21fdebb.png)  
   - 将 `1` 节点设置为 `2` 节点的下一个节点  ![1630506854(1)](https://user-images.githubusercontent.com/46887748/131690530-c20fd0b7-d7a3-4d3f-96e7-7d503897ad7e.png)  
   - 将 `1` 节点的 `first` 属性的拷贝赋值给新的具有首节点属性的节点 `2`  ![1630506904(1)](https://user-images.githubusercontent.com/46887748/131690683-7a955e25-3686-48f4-b276-3c1dcf8b02b7.png)  
     整理后如下图  ![1630507037(1)](https://user-images.githubusercontent.com/46887748/131691083-73966abd-095d-4b12-bc90-ec43622ad6b5.png)  
这样就完成了一个小循环，接下来按照 *第3步* 的规则可以将节点 `3` 转移到 `1` 的前面，随后，内循环结束，  
4. 将节点 `1` 设置为新的 `pre` 节点，将其后面的节点设置为 `move` 和 `first` 拷贝节点，继续进行 *第3步* 的循环即可  

**解释为什么最开始节点 `1` 需要两个拷贝**：可以看到，节点 `1` 具有两个属性：  
一个是作为原来的首结点，最终会移动到本组节点的最后，但始终是节点 `1` 在移动的属性，另一个是作为第一个节点，会不断把这个身份转移给其他节点，但 `first` 的位置始终不变的属性，  
因此，我们设置了两个拷贝 `move` 和 `first`，一个作为不断移动的节点标志，一个作为本组节点第一个的标志，这样避免了处理链表返回节点时的麻烦  

```cpp
ListNode* reverseKGroup(ListNode* head, int k) 
{
    int len = 0;
    ListNode* cntHead = head;
    while(cntHead)
    {
        ++len;
        cntHead = cntHead->next;
    }
    ListNode* ret = new ListNode;
    ret->next = head;
    ListNode* pre = ret;
    ListNode* move = ret->next;
    ListNode* first = ret->next;
    for(int i = 0; i < len / k; ++i)
    {
        for(int j = 0; j < k - 1; ++j)
        {
            ListNode* tmp = move->next;
            move->next = tmp->next;
            pre->next = tmp;
            tmp->next = first;
            first = tmp;
        }
        pre = move;
        move = pre->next;
        first = pre->next;
    }
    return ret->next;
}
```

#### II 递归

基于 k 个一组进行递归翻转即可，具体递归操作见 [反转链表](./%230206%20Reverse%20Linked%20List%20反转链表.md)

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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int cnt = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            ++cnt;
            tmp = tmp->next;
        }
        int group = cnt / k;
        ListNode* ret;
        ListNode* phead = new ListNode;
        phead->next = head;
        for(int i = 0; i < group; ++i)
        {
            ListNode* nextNode = head;
            for(int i = 0; i < k; ++i)
                nextNode = nextNode->next;
            ListNode* tmp = reverseList(head, 1, k);
            phead->next = tmp;
            if(i == 0)
                ret = tmp;
            phead = head;
            head->next = nextNode;
            head = nextNode;
        }
        return ret;
    }
    
    ListNode* reverseList(ListNode* head, int cnt, int k)
    {
        if(k == cnt)
            return head;
        if(!head->next)
            return head;
        ListNode* cur = reverseList(head->next, cnt + 1, k);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};
```
