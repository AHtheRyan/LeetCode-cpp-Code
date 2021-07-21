/*
    the algorithm is similar to #53 Maximum Subarray,
    difference is that multiplication involves condition of Negative Makes Positive, which results in bigger number,
    so the exceptional case is summary of subarray multiplies a negative number, and we get a minimum instead of maximum,
    so we need an additional array to store minimum of every subarray,
    so the elements of comparision are divided into 3:
    1. maximum × current value
    2. minimum × current value
    3 current value
    E.G. in array [2, -2, -2, 3, 5, -1], the maximum and minimum of the first position is 2, considering the scond position:
    1. maximum × current value = 2 × -2 = -4
    2. minimum × current value = 2 × -2 = -4
    3 current value = -2
    and we can update maximum to 8 and minimum to -2,
    thus we can get a new array of maximum subarray, ad we can return its maximum value.
*/
/*
    此题解法类似于 #53最大子序和，
    不同的是，当考虑乘积最大时，存在【偶数个负数】的情况，使得整个子数组的乘积可以负负得正，有更大结果的可能，
    那么需要额外考虑的情况就是数组乘上了一个负数，此时得到的值不是【极大值】而是【极小值】，但是此极小值在后续的乘法过程中，可能出现再乘以一个负数从而负负得正的情况，
    因此，对于此题来说，需要额外增加一个数组来记录每个位置的最小乘积之和，
    那么在每个位置需要比较的内容变成了 3 个：
    1. 最大乘积 × 当前值
    2. 最小乘积 × 当前值
    3. 当前值
    例如在数组[2, -2, -2, 3, 5, -1]中，第一个位置的最大和最小乘积都为 2 ，考虑第二个位置：
    1. 最大乘积 × 当前值 = 2 × -2 = -4
    2. 最小乘积 × 当前值 = 2 × -2 = -4
    3. 当前值 = -2
    此时可以更新最大乘积 -2，最小乘积为 -4，
    同理，第三个位置可以更新最大乘积子数组为 8，最小乘积子数组为 -2，
    以此类推，得到一个新的最大乘积组成的数组，返回其中最大值即可
*/ 

int maxProduct(vector<int>& nums)
{
    int size = nums.size();
    vector<int> max(size);
    vector<int> min(size);
    max[0] = min[0] = nums[0];
    for (int i = 1; i < size; ++i)
    {
        int curmax = max[i - 1] * nums[i];
        int curmin = min[i - 1] * nums[i];
        int maxcmp = curmax > nums[i] ? curmax : nums[i];
        int mincmp = curmin < nums[i] ? curmin : nums[i];
        max[i] = maxcmp > curmin ? maxcmp : curmin;
        min[i] = mincmp < curmax ? mincmp : curmax;
    }
    return *max_element(max.begin(), max.end());
}