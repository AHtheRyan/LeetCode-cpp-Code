/*
    we can divide the question into two parts:
    1. maximum subarray(see question #53)
    2. maximum summary including the first and the last elements(form a ring)
    and the result is the bigger one of these two parts,
    we can analyse question 2 as shown below:
    1. the ring must include the first and the last elements
    2. the left n-2 numbers(assume that the array has n numbers) have a minimum subarray except the first and last elements
    3. the result of forming a ring is the summary of the whole array minus the summary of the minimum subarray, if the summary of minimum subarray is negative, then we get a bigger value,
    E.G. in array [5, -3, -4, 2, 5]:
    1. maximum subarray result is 7;
    2. when form a ring, summary of the whole array is 5+5+2-3-4=5,
       then considering minimum subarray of array [-3, -4, 2] (the ring must include the first and last number 5), it's easy to get the result -3-4=-7,
       so the maximum summary of forming a ring is 5-(-7)=12;
    3. compare the two results, we can return 12 as the maximum result.
*/
/*
    ��Ŀ���Բ�ֳ��������⣺
    1. ������������
    2. ����������λ����������
    �����֮������ֵ��
    ���� 1 ���Բμ� #53����⣬������ 2 �ķ������£�
    1. �����Ҫ���ǻ����������ô��Ȼ���������������λ����λ�õ����֣�
    2. �����������β���м�ʣ�µ� n-2 ���ٶ�������n��Ԫ�أ���������ɵ������Ȼ��һ����С����ͣ�
    3. �ɻ��Ľ��������������ĺͼ�ȥ��С����ͣ������С�������һ����������ô��Ȼ���Եõ����������
    ���磬������[5, -3, -4, 2, 5]�У�
    1. ������������õ��Ľ�Ϊ 7 ��
    2. �ɻ�ʱ����������ĺ�Ϊ 5+5+2-3-4=5����Ϊ�ɻ�����Ȼ������λ�������� 5 ���ٿ�������[-3, -4, 2]����С�����кͣ������׵õ�Ϊ -3-4=-7�����Գɻ������ֵΪ����ͼ�ȥ��С�����к�5-(-7)=12��
    3. �Ƚ�������������ֵ��ȻΪ12.
*/

int maxSubarraySumCircular(vector<int>& nums)
{
    int size = nums.size();
    if (size < 2)
        return nums[0];

    int max = nums[0];
    int cur = nums[0];
    for (int i = 1; i < size; ++i)
    {
        int pre = cur + nums[i];
        cur = pre > nums[i] ? pre : nums[i];
        max = max > cur ? max : cur;
    }

    int min = nums[1];
    int cur2 = nums[1];
    for (int k = 2; k < size - 1; ++k)
    {
        int pre = cur2 + nums[k];
        cur2 = pre < nums[k] ? pre : nums[k];
        min = min > cur2 ? cur2 : min;
    }

    int allsum = 0;
    for (auto num : nums)
        allsum += num;
    allsum = allsum - min;

    return max > allsum ? max : allsum;
}