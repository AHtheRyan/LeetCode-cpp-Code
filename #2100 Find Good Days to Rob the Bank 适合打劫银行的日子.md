### 适合打劫银行的日子
### Find Good Days to Rob the Bank

> 你和一群强盗准备打劫银行。给你一个下标从**0**开始的整数数组 `security`，其中 `security[i]` 是第 `i` 天执勤警卫的数量。日子从 `0` 开始编号。同时给你一个整数 `time`。  
> 如果第 `i` 天满足以下所有条件，我们称它为一个适合打劫银行的日子：  
> - 第 `i` 天前和后都分别至少有 `time` 天。  
> - 第 `i` 天前连续 `time` 天警卫数目都是非递增的。  
> - 第 `i` 天后连续 `time` 天警卫数目都是非递减的。  
> 
> 更正式的，第 `i` 天是一个合适打劫银行的日子当且仅当：`security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time]`.  
> 请你返回一个数组，包含 所有 适合打劫银行的日子（下标从**0**开始）。返回的日子可以**任意**顺序排列。  

> You and a gang of thieves are planning on robbing a bank. You are given a **0-indexed** integer array `security`, where `security[i]` is the number of guards on duty on the `ith` day. The days are numbered starting from `0`. You are also given an integer `time`.  
> The `ith` day is a good day to rob the bank if:  
> - There are at least `time` days before and after the `ith` day,  
> - The number of guards at the bank for the time days **before** `i` are **non-increasing**, and  
> - The number of guards at the bank for the time days **after** `i` are **non-decreasing**.  
> 
> More formally, this means day `i` is a good day to rob the bank if and only if `security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time]`.  
> Return *a list of **all** days **(0-indexed)** that are good days to rob the bank. The order that the days are returned in does **not** matter*.  

----------

#### I DP

设置两个数组，分别判断前置递减和后置递增即可，DP规则比较简单  

```cpp
vector<int> goodDaysToRobBank(vector<int>& security, int time) 
{
    int n = security.size();
    vector<int> ret;
    vector<int> incDay(n);
    vector<int> decDay(n);
    for(int i = 1; i < n; ++i)
    {
        if(security[i] <= security[i - 1])
            incDay[i] = incDay[i - 1] + 1;
        if(security[n - i - 1] <= security[n - i])
            decDay[n - 1 - i] = decDay[n - i] + 1;
    }
    for(int k = 0; k < n; ++k)
        if(incDay[k] >= time && decDay[k] >= time)
            ret.push_back(k);
    return ret;
}
```

#### II 单指针

跟DP思路相同，这次采用一个指针正序和倒序各遍历一次即可  

```cpp
vector<int> goodDaysToRobBank(vector<int>& security, int time) 
{
    int n = security.size();
    vector<int> ret;
    vector<bool> incDay(n);
    vector<bool> decDay(n);
    vector<int> stk;
    for(int i = 0; i < n; ++i)
    {
        if(!stk.empty() && security[i] > stk.back())
            stk.clear();
        if(stk.size() >= time)
            incDay[i] = true;
        stk.push_back(security[i]);
    }
    stk.clear();
    for(int j = n - 1; j >= 0; --j)
    {
        if(!stk.empty() && security[j] > stk.back())
            stk.clear();
        if(stk.size() >= time)
            decDay[j] = true;
        stk.push_back(security[j]);
    }
    for(int k = 0; k < n; ++k)
        if(incDay[k] && decDay[k])
            ret.push_back(k);
    return ret;
}
```
