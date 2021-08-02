/*
    由于第一个数组后面都是0，所以可以对两个数组从后往前进行遍历比较，将较大的数字放在 num1 数组的后面
    1. 如果最后都是 nums1 的数字，则不需要再考虑边界
    2. 如果最后都是 nums2 的数字，则可以直接将 nums2 的数字放到 nums1 的前面
*/ 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int right = m + n - 1;
    while (right >= 0 && m && n)
    {
        if (nums1[m - 1] > nums2[n - 1])
            nums1[right--] = nums1[--m];
        else
            nums1[right--] = nums2[--n];
    }
    while (n)
        nums1[right--] = nums2[--n];
}