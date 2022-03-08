### 蜡烛之间的盘子
### Plates Between Candles

> 给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从**0**开始的字符串 `s`，它只包含字符 `'*'` 和 `'|'`，其中 `'*'` 表示一个**盘子**，`'|'` 表示一支**蜡烛**。  
> 同时给你一个下标从**0**开始的二维整数数组 `queries`，其中 `queries[i] = [lefti, righti]` 表示**子字符串**`s[lefti...righti]`（包含左右端点的字符）。对于每个查询，你需要找到**子字符串中**在**两支蜡烛之间**的盘子的**数目**。如果一个盘子在**子字符串中**左边和右边**都**至少有一支蜡烛，那么这个盘子满足在**两支蜡烛之间**。  
> - 比方说，`s = "||**||**|*"`，查询 `[3, 8]`，表示的是子字符串 `"*||**|"`。子字符串中在两支蜡烛之间的盘子数目为 `2`，子字符串中右边两个盘子在它们左边和右边**都**至少有一支蜡烛。  
> 
> 请你返回一个整数数组 `answer` ，其中 `answer[i]` 是第 `i` 个查询的答案。  

> There is a long table with a line of plates and candles arranged on top of it. You are given a **0-indexed** string `s` consisting of characters `'*'` and `'|'` only, where a `'*'` represents a **plate** and a `'|'` represents a **candle**.  
> You are also given a **0-indexed** 2D integer array `queries` where `queries[i] = [lefti, righti]` denotes the **substring** `s[lefti...righti]`(**inclusive**). For each query, you need to find the **number** of plates **between candles** that are in the substring. A plate is considered between candles if there is at least one candle to its left **and** at least one candle to its right **in the substring**.  
> 
> - For example, `s = "||**||**|*"`, and a query `[3, 8]` denotes the substring `"*||**|"`. The number of plates between candles in this substring is `2`, as each of the two plates has at least one candle **in the substring** to its left **and** right.  
> Return *an integer array `answer` where `answer[i]` is the answer to the `ith` query*.  

----------

#### I 前缀记录

对于任意位置的物件，我们先设置一个前缀和，表示从该位置从左往右看起，共有多少个盘子是有效的，  
例如，对于 `"**|**|**|**"`，我们可以得到一个前缀和数组 `44422200000`  
但可以发现一个问题，当单纯这样算区间内的有效盘子数目时，例如 `[1, 6]` 范围内，即 `"*|**|*"`  
利用前缀和计算，会导致计算结果为 `4 - 0 = 4`，显然错误  
仔细观察，不难发现，错误的原因在于，对于位置 `6` 而言，其在作为减数时，不能看其右侧有多少个有效的盘子  
而是应该看其左侧最近的蜡烛右侧有多少个盘子，  
因此，我们可以在处理获得一个数组，此数组每个位置都代表其左侧最近的蜡烛右侧有多少个有效盘子，  
在任意区间计算时，只要将两个数组的有效盘子数相减即可，如果结果大于 `0`，则该结果直接使用，否则结果为 `0`  

```cpp
vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
{
    int n = s.size();
    vector<int> pospre(n);
    int cnt = 0;
    int index = n - 1;
    while(index >= 0 && s[index] == '*')
        --index;
    for(int i = index - 1; i >= 0; --i)
    {
        if(s[i] == '*')
        {
            pospre[i] = pospre[i + 1];
            ++cnt;
        }
        else
        {
            pospre[i] = pospre[i + 1] + cnt;
            cnt = 0;
        }
    }
    vector<int> candpre = pospre;
    index = 0;
    while(index < n && s[index] == '*')
        ++index;
    for(int i = index; i < n; ++i)
        if(s[i] == '*')
            candpre[i] = candpre[i - 1];
    vector<int> ret;
    for(auto& query : queries)
    {
        int cur = pospre[query[0]] - candpre[query[1]];
        ret.push_back(cur < 0 ? 0 : cur);
    }
    return ret;
}
```
