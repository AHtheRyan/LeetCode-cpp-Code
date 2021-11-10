### 提莫攻击
### Teemo Attacking

> 在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄。他的攻击可以让敌方英雄艾希进入中毒状态。  
> 当提莫攻击艾希，艾希的中毒状态正好持续 `duration` 秒。  
> 正式地讲，提莫在 t 发起发起攻击意味着艾希在时间区间 `[t, t + duration - 1]`（含 `t` 和 `t + duration - 1`）处于中毒状态。如果提莫在中毒影响结束 **前** 再次攻击，中毒状态计时器将会 **重置**，在新的攻击之后，中毒影响将会在 `duration` 秒后结束。  
> 给你一个 **非递减** 的整数数组 `timeSeries`，其中 `timeSeries[i]` 表示提莫在 `timeSeries[i]` 秒时对艾希发起攻击，以及一个表示中毒持续时间的整数 `duration`。  
> 返回艾希处于中毒状态的 **总** 秒数。  

> Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly `duration` seconds. More formally, an attack at second `t` will mean Ashe is poisoned during the inclusive time interval `[t, t + duration - 1]`. If Teemo attacks again **before** the poison effect ends, the timer for it is **reset**, and the poison effect will end `duration` seconds after the new attack.  
> You are given a **non-decreasing** integer array timeSeries, where `timeSeries[i]` denotes that Teemo attacks Ashe at second `timeSeries[i]`, and an integer `duration`.  
> Return *the **total** number of seconds that Ashe is poisoned*.  

----------

#### I 简单遍历

按照中毒规则遍历整个攻击时间数组即可

```cpp
int findPoisonedDuration(vector<int>& timeSeries, int duration) 
{
    int total = 0;
    int pre = 0;
    for(int i = 0; i < timeSeries.size(); ++i)
    {
        if(timeSeries[i] > pre)
            total += duration;
        else
            total += duration - pre + timeSeries[i];
        pre = timeSeries[i] + duration;
    }
    return total;
}
```
