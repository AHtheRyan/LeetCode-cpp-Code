### 打乱数组
### Shuffle an Array

> 给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。  
> 实现 `Solution` class:  
> - `Solution(int[] nums)` 使用整数数组 `nums` 初始化对象  
> - `int[] reset()` 重设数组到它的初始状态并返回  
> - `int[] shuffle()` 返回数组随机打乱后的结果  

> Given an integer array `nums`, design an algorithm to randomly shuffle the array. All permutations of the array should be **equally likely** as a result of the shuffling.  
> Implement the `Solution` class:  
> - `Solution(int[] nums)` Initializes the object with the integer array `nums`.  
> - `int[] reset()` Resets the array to its original configuration and returns it.  
> - `int[] shuffle()` Returns a random shuffling of the array.  

----------

#### I 洗牌算法

初始化和返回初始版本都很简单，重点是如何进行打乱操作，以下为洗牌算法：  
从第 `i` 位开始，任选一个位置 `j < i`，将两个数字交换，  
可以利用 `rand()` 函数，进行 `rand() % i` 操作，可获得余数 `j < i`，  
通过次方法遍历，并将每个位置的值逐一与之前任意位置交换即可

```cpp
class Solution 
{
    vector<int> original;

public:
    Solution(vector<int>& nums) 
    {
        original = nums;
    }
    
    vector<int> reset() 
    {
        return original;
    }
    
    vector<int> shuffle() 
    {
        vector<int> numsAfterShuffle = original;
        for(int i = 1; i < numsAfterShuffle.size(); ++i)
        {
            int j = rand() % (i + 1);
            if(j != i)
                swap(numsAfterShuffle[j], numsAfterShuffle[i]);
        }
        return numsAfterShuffle;
    }
};
```
