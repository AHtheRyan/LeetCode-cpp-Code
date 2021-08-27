### 两数相加
### Add Two Numbers

> 给你两个**非空**的链表，表示两个非负的整数。它们每位数字都是按照**逆序**的方式存储的，并且每个节点只能存储**一位**数字。  
> 请你将两个数相加，并以相同形式返回一个表示和的链表。  
> 你可以假设除了数字 `0` 之外，这两个数都不会以 `0` 开头。  

> You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.  
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.

----------

#### I 迭代

求加法的过程中，需要在乎的点有两个：  
1. 进位
2. 如果一个数字的位数大于另一个数字，则不进行加法运算  

解决方法如下：  
1. 设置进位变量 `flag`，并初始化为 `0`，每次加法都加上该进位，如果溢出，则 `flag` 变为 `1`，否则仍旧为 `0`
2. 每次加法前判断是否某一链表到头，如果已经到达末尾，则设置某一加数为 `0`  

另外需要注意：  
末尾出现**和大于10**的情况时，即使两个链表都已经到达末尾，也需要额外增加一节链表给多出来的进位 `flag`

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head = new ListNode;
    ListNode* dummyHead = head;
    int flag = 0;
    while (l1 || l2 || flag)
    {
        int left = l1 ? l1->val : 0;
        int right = l2 ? l2->val : 0;
        int sum = left + right + flag;
        flag = sum / 10;
        head->val = sum % 10;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
        if (l1 || l2 || flag)
        {
            head->next = new ListNode;
            head = head->next;
        }
    }
    return dummyHead;
}
```

#### II 递归

递归的终极问题在于，对于每一个递归的子环节，递归到该环节时需要做什么操作，  
结合*方法I*中的加法过程，很容易看到：  
1. 递归过程的子过程为两个链表节点的相加
2. 此时如果考虑进位，则每个递归的子环节必须事先知道递归的进位信息  

以此为约束条件进行递归函数的分析：  
考虑递归的的变量：**两个相加的链表节点**以及**进位**  
考虑递归的边界：当两个链表节点都不存在时，则终止  
考虑递归的过程：分别判断两个节点是否为空，如果不为空则将其加在**进位**上，并取下一个节点  
考虑未达到边界的处理：相加后，创建一个新的链表，对该链表进行本轮相同的逻辑操作，同时将**进位**传递给接下来的递归函数  

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    return add(l1, l2, 0);
}

ListNode* add(ListNode* l1, ListNode* l2, int flag)
{
    if (!l1 && !l2)
        return flag == 0 ? nullptr : new ListNode(flag);
    if (l1)
    {
        flag += l1->val;
        l1 = l1->next;
    }
    if (l2)
    {
        flag += l2->val;
        l2 = l2->next;
    }
    return (new ListNode(flag % 10, add(l1, l2, flag / 10)));
}
```
