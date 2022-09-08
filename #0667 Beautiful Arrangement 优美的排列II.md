### 优美的排列
### Beautiful Arrangement

> 给你两个整数 `n` 和 `k`，请你构造一个答案列表 `answer`，该列表应当包含从 `1` 到 `n` 的 `n` 个不同正整数，并同时满足下述条件：  
> - 假设该列表是 `answer = [a1, a2, a3, ... , an]`，那么列表 `[|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]` 中应该有且仅有 `k` 个不同整数。  
> 
> 返回列表 `answer`。如果存在多种答案，只需返回其中**任意一种**。  

> Given two integers `n` and `k`, construct a list `answer` that contains `n` different positive integers ranging from `1` to `n` and obeys the following requirement:  
> - Suppose this list is `answer = [a1, a2, a3, ... , an]`, then the list `[|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]` has exactly `k` distinct integers.  
> 
> Return *the list `answer`*. If there multiple valid answers, return **any of them**.

----------

#### I 模拟

由于需要出现 `k` 个不同的差值，我们可以对整个数组留下 `k - 1` 个数字先不分类，其他的数字都差值为 `1`  
剩下的数字差值可以从大到小分别为 `k` `k - 1` `k - 2` ... `2`，运用此规律设置数字即可  
值得注意的是，如果数字停在 `n`，则其后的数字必然为 `n + k`，再后面分别为 `n + k - 1` `n + k - 2`  
即差值数组为 `{k, k - 1, k - 2, k - 3, ...}`  
因此相应的数组为 `{n + k, n + 1, n + k - 1, n + 2, ...}`  
观察上面两个数组，可以看到对应数组差值为 `{k, 1 - k, k - 2, 3 - k}` 即 `{k, -(k - 1), k - 2, -(k - 3), ...}`  
可以将差值拆分为**递减的 `k`** 和 **`1/-1`** 两个参数  

```cpp
vector<int> constructArray(int n, int k) 
{
    vector<int> ret;
    int i = 1;
    for(; i <= n - k; ++i)
        ret.push_back(i);
    int dif = k;
    int fac = 1;
    for(; i <= n; ++i)
    {
        int cur = ret[i - 2] + (fac * dif);
        fac *= -1;
        --dif;
        ret.push_back(cur);
    }
    return ret;
}
```
