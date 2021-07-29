/*
    use greedy algorithm to traverse the array and count the no-decreasing sequence,
    if there is no-decreasing sequence after the sequence, return false,
    the tips is that if the second number in the no-decreasing sequence is smaller than the number in the previous of the first number,
    we need to change the second number into the first number and continue traversing
*/
/*
    ����̰���㷨���������飬ֱ�ӶԷǵݼ����м���������÷ǵݼ����к��滹�зǵݼ����У���ֱ�ӷ���false��
    ע�������ǣ�����ǵݼ����к�һ������С��ǰһ������֮ǰ�����֣���ô��Ҫ����һ�����ָ���Ϊǰһ�������ټ�����������
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