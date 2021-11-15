### 寻找两个正序数组的中位数
### Median of To Sorted Arrays

> 给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数**。  
> 算法的时间复杂度应该为 `O(log (m+n))`。  

> Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.  
> The overall run time complexity should be `O(log (m+n))`.  

----------

#### I 二分查找 + 递归

求两个数组中的中位数，两个数组的长度分别为 m 和 n，  
由于中位数为奇数第 (m + n + 1) / 2 个数，偶数第 (m + n) / 2 和 (m + n + 2) / 2 个数之和，  
根据计算机的整型变量计算性质，可以设置数组中两个位置的数字，分别为第 left = (m + n + 1) / 2 位和第 right = (m + n + 2) / 2位：  
1. m + n 为奇数时，left = right = (m + n + 1) / 2  
2. m + n 为偶数时，left = (m + n) / 2, right = (m + n + 2) / 2  

因此，位于两个位置的数字并求平均数可以将奇数和偶数的情况一般化  
接下来考虑如何在 o(log n) 的时间内求得第 pos 大的数字，考虑二分法：  
由于存在两个数组，故拼接等方式会让时间变为 o(n)，所以这里不对数组做二分操作，转而对 pos 进行二分操作：  
1. 分别求位于两个数组第 pos / 2 大的数字 a 和 b  
   - 如果 a > b，那么说明 b 及 b 前面的数字都小于 a，所以肯定不是第 pos 大的数字，所以都不考虑  
   - 如果 a < b，思考同上  
2. 无论是上述哪一种情况，后面都只需要求除了 b 之前的数字以外的所有数字中第 pos - pos / 2 大的数字即可  
3. 使得二分结束的条件有两种  
   - 某次循环的 pos - pos / 2 = 1，此时直接返回两个起始位置较小的那个数字即可  
   - 某个数组到了结尾，此时直接返回另一数组距起始位置 pos - pos / 2 的数字即可  

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int left = (m + n + 1) / 2;
    int right = (m + n + 2) / 2;
    double a = findpos(nums1, 0, nums2, 0, left);
    double b = findpos(nums1, 0, nums2, 0, right);
    return (a + b) / 2.0;
}

double findpos(vector<int> nums1, int start1, vector<int> nums2, int start2, int pos)
{
    if (start1 >= nums1.size())
        return nums2[start2 + pos - 1];
    if (start2 >= nums2.size())
        return nums1[start1 + pos - 1];
    if (pos == 1)
        return min(nums1[start1], nums2[start2]);
    int mid = pos / 2 - 1;
    int cmp1 = start1 + mid >= nums1.size() ? INT_MAX : nums1[start1 + mid];
    int cmp2 = start2 + mid >= nums2.size() ? INT_MAX : nums2[start2 + mid];
    if (cmp1 < cmp2)
        return findpos(nums1, start1 + pos / 2, nums2, start2, pos - pos / 2);
    else
        return findpos(nums1, start1, nums2, start2 + pos / 2, pos - pos / 2);
}
```
