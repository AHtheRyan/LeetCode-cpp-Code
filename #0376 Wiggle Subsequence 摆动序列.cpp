/*
    ������֮ǰ���Ȳ��� #152�˻����������
    ��������ƣ�������������Ҫ���������Ϊ 3 �ࣺ
    1. ǰһ���γɵ�����Ϊ����
    2. ǰһ���γɵ�����Ϊ�ݼ�
    3. ǰһ�����в��仯
    ���������ǰڶ��ģ��ݼ������������Ҫ��ǰһ�εĵ�����������������Ҫ��ǰһ�εĵݼ���
    �������еĵ�һ��Ԫ�س�ʼ������DP���鼴��
*/

int wiggleMaxLength(vector<int>& nums)
{
    int size = nums.size();
    int inc = 1;
    int dec = 1;
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] - nums[i - 1] > 0)
            inc = max(dec + 1, inc);
        else if (nums[i] - nums[i - 1] < 0)
            dec = max(dec, inc + 1);
    }
    return max(inc, dec);
}