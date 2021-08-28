### 救生艇
### Boats to Save People

> 第 `i` 个人的体重为 `people[i]`，每艘船可以承载的最大重量为 `limit`。  
> 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 `limit`。  
> 返回载到每一个人所需的最小船数。(保证每个人都能被船载)。  

> You are given an array `people` where `people[i]` is the weight of the `ith` person,  
> and an **infinite number of boats** where each boat can carry a maximum weight of `limit`.  
> Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most `limit`.
> Return *the minimum number of boats to carry every given person*.  

----------

#### I 贪心

题目给出了两个限制条件：  
1. 一艘船最多载 `2` 人  
2. 每艘船可承载的最大重量为 `limit`  

由此可知，每艘船首先要考虑拉较重的人，拉完之后如果剩余重量允许最轻的人上船，则可以加上该人，  
这样可以最大化利用每一条船的载重量，实现用船最少  

```cpp
int numRescueBoats(vector<int>& people, int limit) 
{
    sort(people.begin(), people.end());
    int size = people.size();
    int count = 0;
    int left = 0;
    int right = size - 1;
    while(left <= right)
    {
        int sum = people[left] + people[right];
        if(sum > limit)
        {
            --right;
            ++count;
        }
        else
        {
            ++left;
            --right;
            ++count;
        }
    }
    return count;
}
```
