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
    题目可以拆分成两个问题：
    1. 最大子序和问题
    2. 连接数组首位的最大和问题
    这二者之间的最大值，
    问题 1 可以参见 #53的题解，对问题 2 的分析如下：
    1. 如果需要考虑环的情况，那么必然包含整个数组的首位两个位置的数字；
    2. 如果不考虑首尾，中间剩下的 n-2 （假定数组有n个元素）个数字组成的数组必然有一个最小子序和；
    3. 成环的结果就是整个数组的和减去最小子序和，如果最小子序和是一个负数，那么必然可以得到更大的数字
    例如，在数组[5, -3, -4, 2, 5]中，
    1. 最大子序和问题得到的解为 7 ；
    2. 成环时，整个数组的和为 5+5+2-3-4=5，因为成环，必然包括首位两个数字 5 ，再考虑数组[-3, -4, 2]的最小子序列和，很容易得到为 -3-4=-7，所以成环的最大值为数组和减去最小子序列和5-(-7)=12；
    3. 比较两个情况，最大值显然为12.
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