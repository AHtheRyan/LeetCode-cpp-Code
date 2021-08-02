/*
    ����˫ָ�룬�ֱ����������������ң���������ߵĺ�
    1. ����ʹ���Ŀ��ͣ���˵������ƫ�󣬽��Ҳ�ָ��ǰ��
    2. �����С��Ŀ��ͣ���˵������ƫС�������ָ�����
    3. ����͵���Ŀ��ͣ�ֱ�ӷ��������±�+1
*/ 

vector<int> twoSum(vector<int>& numbers, int target)
{
    int size = numbers.size();
    int left = 0;
    int right = size - 1;
    int sum = numbers[left] + numbers[right];
    while (sum != target)
    {
        if (sum > target)
            --right;
        else
            ++left;
        sum = numbers[left] + numbers[right];
    }
    return { left + 1, right + 1 };
}