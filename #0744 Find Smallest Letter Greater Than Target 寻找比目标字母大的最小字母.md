### 寻找比目标字母大的最小字母
### Find Smallest Letter Greater Than Target

> 给你一个排序后的字符列表 `letters`，列表中只包含小写英文字母。另给出一个目标字母 `target`，请你寻找在这一有序列表里比目标字母大的最小字母。  
> 在比较时，字母是依序循环出现的。举个例子：  
> - 如果目标字母 `target = 'z'` 并且字符列表为 `letters = ['a', 'b']`，则答案返回 `'a'`  

> Given a characters array `letters` that is sorted in **non-decreasing** order and a character `target`, return *the smallest character in the array that is larger than `target`*.  
> **Note** that the letters wrap around.  
> - For example, if `target == 'z'` and `letters == ['a', 'b']`, the answer is `'a'`.  

----------

#### I 二分查找

披着字母大小皮的数字查找，简单二分即可  

```cpp
char nextGreatestLetter(vector<char>& letters, char target) 
{
    if(target >= letters.back())
        return letters[0];
    int left = 0;
    int right = letters.size() - 1;
    while(left <= right)
    {
        int mid = left + (right -left) / 2;
        if(letters[mid] > target && (mid == 0 || letters[mid - 1] <= target))
            return letters[mid];
        else if(letters[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return ' ';
}
```
