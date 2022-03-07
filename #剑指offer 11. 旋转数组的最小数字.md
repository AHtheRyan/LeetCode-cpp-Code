### 旋转数组的最小数字

> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。  
> 给你一个可能存在 重复 元素值的数组 `numbers`，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 `[3,4,5,1,2]` 为 `[1,2,3,4,5]` 的一次旋转，该数组的最小值为1。  

----------

#### I 二分查找

以二分法的思路分析数组，可以发现，对于最小值，其左右元素都不小于它  
因此，可利用 `mid` 与 `right` 指针指向的值比较  
如果 `right` 大，说明 `right` 右侧的数字都不为最小，否则说明 `left` 左侧的数字都不为最小  
如果遇到相等，可将 `right` 左移一位，继续判断  

```cpp
int minArray(vector<int>& numbers) 
{
    int n = numbers.size();
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(numbers[mid] > numbers[right])
            left = mid + 1;
        else if(numbers[mid] < numbers[right])
            right = mid;
        else
            --right;
    }
    return numbers[left];
}
```
