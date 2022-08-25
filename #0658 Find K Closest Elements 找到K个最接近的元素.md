### 找到 K 个最接近的元素
### Find K Closest Elements

> 给定一个**排序好**的数组 `arr`，两个整数 `k` 和 `x`，从数组中找到最靠近 `x`（两数之差最小）的 `k` 个数。返回的结果必须要是按升序排好的。  
> 整数 `a` 比整数 `b` 更接近 `x` 需要满足：  
> - `|a - x| < |b - x|` 或者  
> - `|a - x| == |b - x|` 且 `a < b`  

> Given a sorted integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.  
> An integer `a` is closer to `x` than an integer `b` if:  
> - `|a - x| < |b - x|`, or  
> - `|a - x| == |b - x|` and `a < b`  

----------

#### I 二分

利用二分，找到从左往右第一个满足 `x - nums[i] <= nums[i + k] - x` 的数字即可  

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    int left = 0;
    int right = arr.size() - k;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}
```
