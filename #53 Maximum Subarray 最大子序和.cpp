/*
    according to the question, traverse the array in order, we can get different max_sum_subarray from every position
    E.G. in array [-2, 1, -3, 4, -1, 2, 1, -5, 4],
    max_subarray of index '0' is the value '-2',
    pmax_subarray of index '1' comes from 2 conditions: 1. the value '1' itself; 2. previous max_subarray plus current value, obviously the bigger one is the result,
    thus, the value of the max_subarray is the larger one between the value of the index value itself and the previous previous max_subarray plus the index value,
    so we can traverse the array and get max_subarray on each position(index), and return the maximum number of them.
*/
/*
    ������ĿҪ�󣬰�˳��������飬���±�0��ʼ���±�����λ�ã�ÿ��λ�ö��ж�Ӧ����������кͣ�
    ���磬������[-2, 1, -3, 4, -1, 2, 1, -5, 4]�У�
    �±� ��0�� ��Ӧ���������;��� ��-2����
    �±� ��1�� ��Ӧ���������ֿ��ܣ�1. ֻȡ������ ��1���� 2.ǰ����������ͼ��ϵ�ǰ���֣��� ��-1������Ȼ��ȡ�������ֵ���ɣ�����ͬ��
    ����ÿ���±���ԣ���ֹ����λ�õ��������͵�ֵ�ǵ���ȡ��λ�õ�ֵ����ǰ����������ͼ��ϸ�λ�õ�ֵ�нϴ���Ǹ���
    ��ˣ����Ա���һ�����飬�õ�ÿ��λ�õ��������ͣ�ȡ���е����ֵ��
*/

//v1.0
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();
    vector<int> dp(size);
    dp[0] = nums[0];
    for (int i = 1; i < size; ++i)
        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
    return *max_element(dp.begin(), dp.end());
}

//v1.1
//remove vector dp, use a single variable to store the result, which saves the memory
//ȡ����dp����Ĺ�����ʹ��һ�������ı����洢����Լ�˿ռ��ʹ��
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();
    int max = nums[0];
    int cur = max;
    for (int i = 1; i < size; ++i)
    {
        cur = nums[i] + cur > nums[i] ? nums[i] + cur : nums[i];
        max = cur > max ? cur : max;
    }
    return max;
}

