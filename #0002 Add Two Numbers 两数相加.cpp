/*
    求加法的过程中，需要在乎的点有两个：
    1. 进位
    2. 如果一个数字的位数大于另一个数字，则不进行加法运算
    解决方法如下：
    1. 设置进位变量 flag，并初始化为 0，每次加法都加上该进位，如果溢出，则 flag 变为 1，否则仍旧为 0
    2. 每次加法前判断是否某一链表到头，如果已经到头，则设置某一加数为 0
    另外需要注意：
    末尾出现 >10 的情况时，即时两个链表都已经到头，也需要额外增加一节链表给多出来的进位
*/ 

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