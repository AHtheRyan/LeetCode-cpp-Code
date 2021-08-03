/*
    ��򵥵�˫ָ���㷨���ǣ�����ָ��ֱ�������Һʹ������������
    ��������������һ��Ϊ�������ֵ�Ҳ����к�������Сֵ�����������ļ��ϣ�
    Ҳ����������������˵�ֵһ������������Сֵ�������������Ҷ˵�ֵһ�������������ֵС
*/

int findUnsortedSubarray(vector<int>& nums)
{
    int size = nums.size();
    int maxn = INT_MIN;
    int minn = INT_MAX;
    int left = -1;
    int right = -1;
    for (int i = 0; i < size; ++i)
    {
        if (maxn > nums[i])
            right = i;
        else
            maxn = nums[i];
        if (minn < nums[size - 1 - i])
            left = size - 1 - i;
        else
            minn = nums[size - 1 - i];
    }
    return right == -1 ? 0 : right - left + 1;
}
