/*
    环形链表问题的基本解决思路就是利用快慢指针，创建两个指针，满指针每次前进一格，快指针每次前进两格，
    如果两个指针能够相遇，则一定是有环在链表中，如果快指针走到末尾，则一定无环，
    考虑相遇点：
    假设非环部分长度为 x，环部分慢指针走了 y，剩下部分为 z
    1. 慢指针走的路包括 x + y
    2. 快指针走的路包括 2(x + y) = x + y + z + y
    3. 所以根据快指针的关系式可得 x = z，也就是非环部分的距离是慢指针在环中没走的路
    4. 再创建一个指针，从起点开始走到 x，慢指针继续前进，则两个指针会在环的起点相遇
    5. 返回环的起点节点
*/ 

ListNode* detectCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ListNode* ret = head;
            while (slow != ret)
            {
                slow = slow->next;
                ret = ret->next;
            }
            return ret;
        }
    }
    return NULL;
}