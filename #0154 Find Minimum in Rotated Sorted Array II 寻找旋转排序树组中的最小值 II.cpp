/*
    ���������� #81 ������ת��������II������ͬ�����ö��ַ�������⣬
    �� mid ָ��λ�õ����ֽ��м��
    1. �����λ�������Ҳ���ͬ�������Ҳ��ָ�� right ��һ
    2. ��� mid ָ���Ӧ�����ִ��� right ָ���Ӧ�����֣���˵���Ҳ�ö����д��ڵݼ����У��� left ָ���һ��������ж��ֲ���
    3. ��� mid ָ���Ӧ������С�� right ָ���Ӧ�����֣���˵���Ҳ�ö�����Ϊ�������У��� right ָ���һ��������ж��ֲ���
*/ 

int findMin(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[right])
            --right;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}