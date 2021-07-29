/*
    use greedy algorithm to traverse the array and count the no-decreasing sequence,
    if there is no-decreasing sequence after the sequence, return false,
    the tips is that if the second number in the no-decreasing sequence is smaller than the number in the previous of the first number,
    we need to change the second number into the first number and continue traversing
*/
/*
    利用贪心算法，遍历数组，直接对非递减序列计数，如果该非递减序列后面还有非递减序列，则直接返回false，
    注意的情况是，如果非递减序列后一个数字小于前一个数字之前的数字，那么需要将后一个数字更改为前一个数字再继续遍历数组
*/ 

bool checkPossibility(vector<int>& nums)
{
    int size = nums.size();
    int count = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        int cur = nums[i];
        int nex = nums[i + 1];
        if (cur > nex)
        {
            ++count;
            if (count > 1)
                return false;
            if (i > 0 && nex < nums[i - 1])
                nums[i + 1] = cur;
        }
    }
    return true;
}