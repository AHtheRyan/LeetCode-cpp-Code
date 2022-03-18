### 和为s的连续正数序列

> 输入一个正整数 `target`，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。  
> 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。  

----------

#### I 双指针

设置两个指针，`left` 和 `right`，并求两个指针区间内的总和 `sum`：  
- 如果 `sum > target`，说明总和偏大，此时需要减小，由于需要连续数组，所以此时可以将 `left` 指针右移  
- 如果 `sum < target`，说明总和偏小，此时需要增大，由于需要连续数组，所以此时可以将 `right` 指针右移  
- 如果 `sum == target`，可以将两个指针区间内的数字组成一个数组并返回  
- 当 `left` 指针与 `right` 指针重合，说明已不存在合适的乱序数组  

将上述数组返回即可  

```cpp
vector<vector<int>> findContinuousSequence(int target) 
{
    vector<vector<int>> ret;
    vector<int> cur;
    int left = 1;
    int right = 2;
    while(left < right)
    {
        int sum = (left + right) * (right - left + 1) / 2;
        if(sum == target)
        {
            cur.clear();
            for(int i = left; i <= right; ++i)
                cur.push_back(i);
            ret.push_back(cur);
            ++right;
        }
        else if(sum > target)
            ++left;
        else
            ++right;
    }
    return ret;
}
```
