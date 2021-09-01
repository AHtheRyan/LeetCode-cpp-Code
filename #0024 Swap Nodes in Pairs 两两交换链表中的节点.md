### 两两交换链表中的节点
### Swap Nodes in Pairs

> 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。    
> **你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。  

> Given a linked list, swap every two adjacent nodes and return its head.  
> You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)  

----------

#### I 迭代

对于链表类的题目，使用迭代法时新变量的创建是必不可少的，  
而在本题中，想要两两交换链表节点，那么就涉及到 **第一个节点之前的节点 `pre`、需要交换的两个节点 `1` `2`、第二个节点之后的节点 `next`** 四个节点，  
首先，我们初始化创建第一个节点的头结点，之后迭代的过程如下（文字表述较为复杂，结合图片理解）：  
![1630487092(1)](https://user-images.githubusercontent.com/46887748/131643995-7edac4e8-d393-42e3-9cf5-4b1d63d42e42.png)
1. 创建 `tmp` 变量作为 **第一个节点** 的另一个变量名  ![1630487720(1)](https://user-images.githubusercontent.com/46887748/131645631-bc3c7ed7-98f4-43d2-8651-6d0aae023db4.png)  
2. 将 **第一个节点** 的下一个节点赋值给 **第一个节点之前的节点** 的下一个节点  **注意**如果这里不创建 `tmp`，则会失去指向 **第一个节点** 的指针，之后就找不到该节点了  ![1630487777(1)](https://user-images.githubusercontent.com/46887748/131645805-909fe85e-539c-4e3b-a7a2-d77253913db2.png)  
3. 将 **第二个节点之后的节点** 的值赋给 **第一个节点的下一个节点**  此时很容易看到节点 `1` 变成“孤岛”，需要另外一个变量名方式丢失  ![1630487847(1)](https://user-images.githubusercontent.com/46887748/131645968-fd31ee8e-08c7-4d56-b846-6b53b88fc56d.png)  
4. 将 **第一个节点** 的值赋给 **第一个节点之前的节点的下下一个节点**  ![1630487936(1)](https://user-images.githubusercontent.com/46887748/131646193-24c3b922-ab96-4bc0-8804-b7ef65e49381.png)  
5. 将 `1` 节点设置为 `pre` 节点，准备下一轮迭代  

```cpp
ListNode* swapPairs(ListNode* head) 
{
    ListNode* dummyhead = new ListNode;
    dummyhead->next = head;
    ListNode* phead = dummyhead;
    while(phead->next && phead->next->next)
    {
        ListNode* tmp = phead->next;
        phead->next = tmp->next;
        tmp->next = phead->next->next;
        phead->next->next = tmp;
        phead = phead->next->next;
    }
    return dummyhead->next;
}
```

#### II 递归

分析递归需要注意三点：  
1. 递归函数的作用
2. 边界条件
3. 本次递归需要做什么  

首先考虑递归函数的作用：根据题目条件，显然为交换两个节点，并返回交换后排在前面的节点（可以通过考虑只有两个节点的情况得出）  
接下来考虑边界条件：当交换的节点小于两个时，直接返回即可（可以通过考虑有一个或者只有 `nullptr` 的情况得出）  
最后分析本轮递归做什么，假设需要交换的两个节点分别为 `1` `2`：  
1. 将 `1` 节点的下一个节点赋值为 `2` 节点的下一个节点  **注意**：由于 `2` 的下量个节点也需要进行同样的函数过程，我们因此直接将 `1` 的下一个节点设置为 `swapPairs(2 -> next)`  
2. 将 `2` 节点的下一个节点赋值为 `1` 节点  

即可完成本轮递归

```cpp
ListNode* swapPairs(ListNode* head) 
{
    if(!head || !head->next)
        return head;
    ListNode* tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return tmp;
}
```
