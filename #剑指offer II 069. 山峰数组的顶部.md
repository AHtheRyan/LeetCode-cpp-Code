### 山峰数组的顶部

> 符合下列属性的数组 `arr` 称为 **山峰数组（山脉数组）**：  
> - `arr.length >= 3`  
> - 存在 `i`（`0 < i < arr.length - 1`）使得：  
>   - `arr[0] < arr[1] < ... arr[i-1] < arr[i]`  
>   - `arr[i] > arr[i+1] > ... > arr[arr.length - 1]`  
>   
> 给定由整数组成的山峰数组 `arr` ，返回任何满足 `arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]` 的下标 `i` ，即山峰顶部。  

----------

#### I 二分查找

简单二分查找

```cpp
int peakIndexInMountainArray(vector<int>& arr) 
{
    int left = 1;
    int right = arr.size() - 2;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            left = mid + 1;
        else if(arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
            right = mid - 1;
    }
    return -1;
}
```
