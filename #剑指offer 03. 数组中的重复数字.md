### 数组中的重复数字

> 找出数组中重复的数字。  
> 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。  

----------

#### I 哈希表（构造哈希表）

构造哈希表记录每次出现的数字，如果出现第二次就直接返回即可  

```cpp
int findRepeatNumber(vector<int>& nums) 
{
    unordered_map<int, bool> mp;
    for(auto& num : nums)
    {
        if(!mp[num])
            mp[num] = true;
        else
            return num;
    }
    return -1;
}
```

#### II 哈希表（原地哈希）

如果要求空间复杂度为 `o(1)`，则可以采用原地哈希的方式，具体构造思路如下：  
由于共有 `n` 个数字，且数字的范围为 `0 ~ n-1`，可以发现数字范围恰好对应数组总大小的下标范围  
这样就可以采用原地哈希的方式，每遍历到一个数字，就对**以该数字所表示的下标对应的数字**进行处理，将其**变为负数并减一**  
这样如果我们遍历到重复的数字，就可以直接发现以其作为下标的数字是负数，此时返回该数字即可  
**注意**：如果遇到了负数，则需要将其变回正数，再以其作为下标进行判断  

```cpp
int findRepeatNumber(vector<int>& nums)
{
    int n = nums.size();
    for(auto& num : nums)
    {
        if(num >= 0)
        {
            if(nums[num] < 0)
                return num;
            nums[num] = -abs(nums[num]) - 1;
        }
        else
        {
            if(nums[-num - 1] < 0)
                return -num - 1;
            nums[-num - 1] = -abs(nums[-num - 1]) - 1;
        }
    }
    return -1;
}
```
