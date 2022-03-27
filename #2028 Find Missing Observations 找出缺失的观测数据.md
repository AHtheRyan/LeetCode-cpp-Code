### 找出缺失的观测数据
### Find Missing Observations

> 现有一份 `n + m` 次投掷单个**六面**骰子的观测数据，骰子的每个面从 `1` 到 `6` 编号。观测数据中缺失了 `n` 份，你手上只拿到剩余 `m` 次投掷的数据。幸好你有之前计算过的这 `n + m` 次投掷数据的**平均值**。  
> 给你一个长度为 `m` 的整数数组 `rolls`，其中 `rolls[i]` 是第 `i` 次观测的值。同时给你两个整数 `mean` 和 `n`。  
> 返回一个长度为 `n` 的数组，包含所有缺失的观测数据，且满足这 `n + m` 次投掷的**平均值**是 `mean`。如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。  
> `k` 个数字的**平均值**为这些数字求和后再除以 `k`。  
> 注意 `mean` 是一个整数，所以 `n + m` 次投掷的总和需要被 `n + m` 整除。  

> You have observations of `n + m` **6-sided** dice rolls with each face numbered from `1` to `6`. `n` of the observations went missing, and you only have the observations of `m` rolls. Fortunately, you have also calculated the **average value** of the `n + m` rolls.  
> You are given an integer array `rolls` of length `m` where `rolls[i]` is the value of the `ith` observation. You are also given the two integers `mean` and `n`.  
> Return *an array of length n containing the missing observations such that the **average value** of the `n + m` rolls is **exactly** `mean`*. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.  
> The **average value** of a set of  `k` numbers is the sum of the numbers divided by `k`.  
> Note that `mean` is an integer, so the sum of the `n + m` rolls should be divisible by `n + m`.  

----------

#### I 模拟

直接根据条件模拟即可，由于确定的骰子是 `1~6` 六种情况，所以可以根据最大最小值 `6 * n` 和 `1 * n` 确定范围，如果剩余的总和不在此范围内则直接返回空数组  
如果剩余的值在此范围内，由于需要几个整数，因此可以先求平均数作为基数，再确定余数，将余数个数的基数加 `1`，并将所有的数字作为最后的返回结果  

```cpp
vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
{
    int m = rolls.size();
    int sum = (m + n) * mean;
    int knownSum = accumulate(rolls.begin(), rolls.end(), 0);
    int remnant = sum - knownSum;
    if(n * 6 < remnant || n * 1 > remnant)
        return {};
    int average = remnant / n;
    int mod = remnant % n;
    vector<int> ret;
    for(int i = 0; i < n; ++i)
    {
        if(mod > 0)
        {
            ret.emplace_back(average + 1);
            --mod;
        }
        else
            ret.emplace_back(average);
    }
    return ret;
}
```
