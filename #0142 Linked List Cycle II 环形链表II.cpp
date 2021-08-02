/*
    ������������Ļ������˼·�������ÿ���ָ�룬��������ָ�룬��ָ��ÿ��ǰ��һ�񣬿�ָ��ÿ��ǰ������
    �������ָ���ܹ���������һ�����л��������У������ָ���ߵ�ĩβ����һ���޻���
    ���������㣺
    ����ǻ����ֳ���Ϊ x����������ָ������ y��ʣ�²���Ϊ z
    1. ��ָ���ߵ�·���� x + y
    2. ��ָ���ߵ�·���� 2(x + y) = x + y + z + y
    3. ���Ը��ݿ�ָ��Ĺ�ϵʽ�ɵ� x = z��Ҳ���Ƿǻ����ֵľ�������ָ���ڻ���û�ߵ�·
    4. �ٴ���һ��ָ�룬����㿪ʼ�ߵ� x����ָ�����ǰ����������ָ����ڻ����������
    5. ���ػ������ڵ�
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