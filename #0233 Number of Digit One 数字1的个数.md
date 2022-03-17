### 数字1的个数
### Number of Digit One

> 给定一个整数 `n`，计算所有小于等于 `n` 的非负整数中数字 `1` 出现的个数。  

> Given an integer `n`, count *the total number of digit `1` appearing in all non-negative integers less than or equal to `n`*.  

----------

#### I 按位计算

对于数字 `abcd` 出现 `1` 的次数，可以分别计算每个位置 `1` 出现的次数，  
例如，对于十位 `c`，由于其具有前缀 `ab`，说明其至少会经过 `ab` 次 `0~99` 的循环，该循环中，`1` 出现了 `10` 次，分别为 `10 ~ 19` 中出现的 `1`，  
再分析后面的部分，对于 `cd` 部分，由上述分析可知：  
- 如果 `cd` 小于 `10`，必然没有新的 `1` 出现  
- 如果 `cd` 大于 `19`，必然有 `10` 个新的 `1` 出现  
- 如果 `cd` 在 `10` 和 `19` 中间，则会有 `cd - 10 + 1` 个 `1` 出现  

由上述可知，对于十位的 `1`，出现的总次数为 `ab * 10 + (判断cd)`，其他位可以按此规律完成，最后返回总值即可  

```cpp
int countDigitOne(int n) 
{
    int ret = 0;
    for(long k = 1; k <= n; k *= 10)
    {
        ret += n / (k * 10) * k;
        int candidate = n % (k * 10) - k + 1;
        candidate = candidate > 0 ? candidate : 0;
        candidate = candidate < k ? candidate : k;
        ret += candidate;
    }
    return ret;
}
```
