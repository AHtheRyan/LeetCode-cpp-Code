/*
    根据Moore投票法，多数元素所在的数字遇到其他元素则抵消，最后数组中剩下的元素只有多数元素，
    我们当然不能把元素删除（太费时间），但是我们可以遍历整个数组，
    先默认第一个数字为多数元素，如果下一个数字不等于他，则抵消，利用一个记号count计算当前选定的数字在遍历的过程中是否大于0，
    如果该数字减为0并且后面的数字不等于该选定的多数元素，那么就将新数字当做多数元素，
    遍历到最后即可知道没被抵消的元素是多少
*/ 

int majorityElement(vector<int>& nums)
{
    int cur = nums[0];
    int size = nums.size();
    int count = 1;
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] == cur)
            ++count;
        else if (nums[i] != cur && count)
            --count;
        else
        {
            cur = nums[i];
            ++count;
        }
    }
    return cur;
}