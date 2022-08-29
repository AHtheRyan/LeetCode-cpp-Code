### 重新排列数组
### Shuffle the Array

> 给你一个数组 `nums`，数组中有 `2n` 个元素，按 `[x1,x2,...,xn,y1,y2,...,yn]` 的格式排列。  
> 请你将数组按 `[x1,y1,x2,y2,...,xn,yn]` 格式重新排列，返回重排后的数组。  

> Given the array `nums` consisting of `2n` elements in the form `[x1,x2,...,xn,y1,y2,...,yn]`.  
> *Return the array in the form `[x1,y1,x2,y2,...,xn,yn]`*.  

----------

#### 双指针

利用双指针按序将每个元素插入新的数组即可

```cpp
vector<int> shuffle(vector<int>& nums, int n) 
{
    vector<int> ret(n * 2);
    for(int i = 0; i < n; ++i)
    {
        ret[2 * i] = nums[i];
        ret[2 * i + 1] = nums[n + i];
    }
    return ret;
}
```
