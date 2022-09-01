### 供暖器
### Heaters

> 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。  
> 在加热器的加热半径范围内的每个房屋都可以获得供暖。  
> 现在，给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。  
> 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。  

> Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.  
> Every house can be warmed, as long as the house is within the heater's warm radius range.   
> Given the positions of `houses` and `heaters` on a horizontal line, return *the minimum radius standard of heaters so that those heaters could cover all houses*.  
> **Notice** that all the `heaters` follow your radius standard, and the warm radius will the same.  

----------

#### I 模拟

剪枝条件1：当确定一个供暖器的半径后，后面的房子也可以被照顾到，如果后面的照顾不到再考虑下一个供暖器  
剪枝条件2：下一个供暖器可能会覆盖范围过大，迭代直到找到能覆盖下一个房子的最近供暖器  

```cpp
int findRadius(vector<int>& houses, vector<int>& heaters) 
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    int hi = 0;
    for(int i = 0; i < houses.size(); ++i)
    {
        if(heaters[hi] - radius <= houses[i] && heaters[hi] + radius >= houses[i])
            continue;
        while(hi < heaters.size() - 1 && abs(heaters[hi] - houses[i]) >= abs(heaters[hi + 1] - houses[i]))
            hi = hi + 1;
        int curRadius = abs(heaters[hi] - houses[i]);
        radius = max(curRadius, radius);
    }
    return radius;
}
```
