/*
    ����ʹ�� ��ϣ�� + ˫ָ�� �������Ŀ��
    �ֱ����������ұ��������ַ���������Ԫ����ĸʱ�����߽�����
    �����ָ�����������ָ����ұߣ���ֹͣ����
*/

string reverseVowels(string s)
{
    unordered_set<char> rec{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int left = 0;
    int right = s.size() - 1;
    while (left <= right)
    {
        while (rec.find(s[left]) == rec.end() && left <= right)
            ++left;
        while (rec.find(s[right]) == rec.end() && left <= right)
            --right;
        if (rec.find(s[left]) != rec.end() && rec.find(s[right]) != rec.end())
            swap(s[left++], s[right--]);
    }
    return s;
}