/*
    ������Ȼ��˫ָ���ܿ��������� left �� right �����������������£�
    1. ��� s[left] == s[right]��ʼ�ճ��������������󷵻� true ����
    2. ��� s[left] != s[right]��
        2.1 ����ͬ����˼·����ʼ��˫ָ�����Ϊ left + 1��right������һ��
        2.2 ����ͬ����˼·����ʼ��˫ָ�����Ϊ left��right - 1������һ��
        2.3 ������α��������ǻ��ģ��򷵻�false�����򷵻�true
*/

bool validPalindrome(string s)
{
    int size = s.size();
    int left = 0;
    int right = size - 1;
    bool check1 = true;
    bool check2 = true;
    while (left <= right)
    {
        if (s[left] != s[right])
        {
            check1 = check(left, right - 1, s);
            check2 = check(left + 1, right, s);
            break;
        }
        ++left;
        --right;
    }
    return check1 || check2;
}

bool check(int start, int end, string s)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            break;
        ++start;
        --end;
        if (start >= end)
            return true;
    }
    return false;
}