### 跳跃游戏II
### Jump Game II

> 给你一个非负整数数组 `nums`，你最初位于数组的第一个位置。  
> 数组中的每个元素代表你在该位置可以跳跃的最大长度。  
> 你的目标是使用最少的跳跃次数到达数组的最后一个位置。  
> 假设你总是可以到达数组的最后一个位置。  

> Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.  
> Each element in the array represents your maximum jump length at that position.  
> Your goal is to reach the last index in the minimum number of jumps.  
> You can assume that you can always reach the last index.  

----------

#### I 贪心

一言以蔽之，就是要使得每次往前跳跃的时候，所取的起跳位置都是能跳最远的  
例如，对于数组 `[2, 3, 1, 1, 4]`，我们会先从 `2` 开始起跳，会跳到两个位置：
1. `index == 1`，此时可跳的最远位置为 `nums[index] + index == 3 + 1 == 4`  
2. `index == 2`，此时可跳的最远位置为 `nums[index] + index == 2 + 1 == 3`  

显然，选择先跳到 `index == 1` 的位置会更快  
因此，我们可以遍历数组，每次比较当前位置所能跳到的最远位置和之前所确定的能跳到的最远位置，  
如果当前能跳的更远，则更新，否则最远位置不变  
接着判断当前位置的下标 `index` 是否到达了之前可以跳到的最远位置，  
如果达到了，说明下一步的前进需要发生新的跳跃，此时将步数 `step` 加一  
最后返回步数即可  

```cpp
int jump(vector<int>& nums) 
{
    int n = nums.size();
    int step = 0;
    int index = 0;
    int maxPower = 0;
    int curEnd = 0;
    while(index < n - 1)
    {
        maxPower = max(maxPower, index + nums[index]);
        if(index == curEnd)
        {
            curEnd = maxPower;
            ++step;
        }
        ++index;
    }
    return step;
}
```
