/*
    常规的 排序+遍历 的模式很简单，这里考虑位运算：
    根据位运算的规则，任何一个数和他自己的异或等于0，任何数和0的异或等于数字本身，
    因此可以将数组中的数按顺序遍历并异或，最后剩下的数字必然为单独的数字
*/ 

int singleNumber(vector<int>& nums)
{
    int ret = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it)
        ret ^= *it;
    return ret;
}