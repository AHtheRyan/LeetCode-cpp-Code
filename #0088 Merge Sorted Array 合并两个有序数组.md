### 合并两个有序数组
### Merge Sorted Array

> 给你两个按**非递减顺序**排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n`，分别表示 `nums1` 和 `nums2` 中的元素数目。  
> 请你**合并** `nums2` 到 `nums1` 中，使合并后的数组同样按**非递减顺序**排列。  
> **注意**：最终，合并后数组不应由函数返回，而是存储在数组 `nums1` 中。为了应对这种情况，`nums1` 的初始长度为 `m + n`，其中前 `m` 个元素表示应合并的元素，后 `n` 个元素为 `0`，应忽略。`nums2` 的长度为 `n`。  

> You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.  
> **Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.  
> The final sorted array should not be returned by the function, but instead *be stored inside the array* `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.  

----------

#### I 双指针

利用双指针按次序从后往前比较两个数组中的数字，按顺序加入 `nums1` 即可  

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int index = m + n - 1;
    while(index >= 0)
    {
        int a = m >= 1 ? nums1[m - 1] : INT_MIN;
        int b = n >= 1 ? nums2[n - 1] : INT_MIN;
        if(b >= a) 
        {
            nums1[index--] = b;
            --n;
        }
        else
        {
            nums1[index--] = a;
            --m;
        }
    }
}
```
