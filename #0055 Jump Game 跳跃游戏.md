### 跳跃游戏
### Jump Game

> 给定一个非负整数数组 `nums`，你最初位于数组的**第一个下标**。  
> 数组中的每个元素代表你在该位置可以跳跃的最大长度。  
> 判断你是否能够到达最后一个下标。  

> You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.  
> Return *`true` if you can reach the last index, or `false` otherwise*.  

----------

#### I 贪心

此题类似 [跳跃游戏II](./%230045%20Jump%20Game%20II%20跳跃游戏%20II.md)  
数组中每个位置代表当前位置可以前进的距离，根据规则，每前进一格，就会消耗一个值（我们可以看做能量），  
例如，在数组 `[2, 3, 1, 1, 4]` 中，从 `"2"` 前进到 `"3"`，则消耗 `1` 点“能量”。
考虑前进到第一个数字 `"1"`：  
1. 从 `"2"` 前进到第一个 `"1"`，则消耗 `2` 点“能量”，到 `"1"` 可重新获得 `1` 点能量  
2. 先从 `"2"` 到 `"3"`， 再从 `"3"` 再到 `"1"`，此时消耗 `1` 点能量，但可以继续前进不停留，试图获得更多能量，直到找到能量最高的位置停下来  

也就是说，最终考虑的就是按顺序到达每个位置可以获得的最大能量是多少，直到没有能量或者到终点，  
因此，可以利用贪心的思路，记录每个位置的能量最大值，考虑情况 `1` 和 `2`，能量值为前一格直接前进的能量（即路过不停留）和当前格子的能量（停在此格获得能量）两者的较大者，  
如果根本无法路过，也就是前一格的剩余能量为 `0`，则直接无法前进，返回 `false` ，否则遍历到最后，返回 `true`  

```cpp
bool canJump(vector<int>& nums)
{
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i <= rightmost)
        {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1)
                return true;
        }
    }
    return false;
```
