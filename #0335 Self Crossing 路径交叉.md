### 路径交叉
### Self Crossing

> 给你一个整数数组 `distance`。  
> 从 **X-Y** 平面上的点 `(0,0)` 开始，先向北移动 `distance[0]` 米，然后向西移动 `distance[1]` 米，向南移动 `distance[2]` 米，向东移动 `distance[3]` 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。  
> 判断你所经过的路径是否相交。如果相交，返回 `true`；否则，返回 `false`。  

> You are given an array of integers `distance`.  
> You start at point `(0,0)` on an **X-Y** plane and you move `distance[0]` meters to the north, then `distance[1]` meters to the west, `distance[2]` meters to the south, `distance[3]` meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.  
> Return `true` if your path crosses itself, and `false` if it does not.  

----------

#### I 枚举

可以发现所有交叉的情况可以分为三类，分别是路径转折 `4`、`5`、`6` 次后交叉，具体见下：  
![1635735257(1)](https://user-images.githubusercontent.com/46887748/139615387-0cf5e301-ba91-4682-a1ed-2a0eedb97d39.png)  
假设第 `x` 次发生交叉，可以发现，所有的交叉情况都可以归于其中，则：  
1. 此时只需要第 `x` 次的路径长度大于等于第 `x - 2` 次，且第 `x - 1` 次小于等于第 `x - 3` 次即可
2. 此时只需要第 `x - 1` 次的路径长度等于第 `x - 3` 次，且第 `x` 次和第 `x - 4` 次的长度和大于等于第 `x - 2` 次即可
3. 此时只需要第 `x` 次和第 `x - 4` 次的长度和大于等于第 `x - 2` 次、第 `x - 2` 次的长度和大于第 `x - 4` 次、第 `x` 次和第 `x - 3` 次的长度和大于第 `x - 1` 次，且第 `x - 1` 次和第 `x - 5` 次的长度和大于第 `x - 3` 次


```cpp
bool isSelfCrossing(vector<int>& distance) 
{
    for(int i = 3; i < distance.size(); ++i)
    {
        if(distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
            return true;
        else if(i >= 4 && distance[i] + distance[i - 4] >= distance[i - 2] && distance[i - 1] == distance[i - 3])
            return true;
        else if(i >= 5 && distance[i - 1] + distance[i - 5] >= distance[i - 3] && distance[i - 1] < distance[i - 3] && distance[i - 2] > distance[i - 4] && distance[i - 4] + distance[i] >= distance[i - 2])
            return true;
    }
    return false;
}
```
