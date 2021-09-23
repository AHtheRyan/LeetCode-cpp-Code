### 只有两个键的键盘
### 2 Keys Keyboard

> 最初记事本上只有一个字符 `'A'` 。你每次可以对这个记事本进行两种操作：  
> - `Copy All`（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。  
> - `Paste`（粘贴）：粘贴 上一次 复制的字符。  
> 
> 给你一个数字 `n` ，你需要使用最少的操作次数，在记事本上输出 恰好 `n` 个 `'A'` 。返回能够打印出 `n` 个 `'A'` 的最少操作次数。  

> There is only one character `'A'` on the screen of a notepad. You can perform two operations on this notepad for each step:  
> - Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).  
> - Paste: You can paste the characters which are copied last time.  
> 
> Given an integer n, return the minimum number of operations to get the character `'A'` exactly `n` times on the screen.

----------

#### I 动态规划

根据规则找规律，易知只有 `n` 为质数时才会需要进行 `n` 次 **复制+粘贴** 操作，如果为合数，则其可以由其质因数的乘积构成，  
如果遇到质数，则只能直接经过该数字次操作完成复制粘贴，  
如果遇到合数，则可以通过找到其质因数中需要操作次数最少的那种组合，  
例如对于数字 `12`，可以得到 `'AAA' × 4`，`'AAAA' × 3`，`'AA' × 6`，`'AAAAAA' × 2` 四种操作，  
而显然，他们之间两两是对应的，即 3x4 和 4x3，2x6 和 6x2，  
因此，对于 `A` 的个数 `n`，我们可以遍历 `0 ~ √n` 为除数的操作次数，如果遇到约数则进行一次对应的商作为除数的操作，  
利用动态规划求得最小值即可  

```cpp
int minSteps(int n) 
{
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j <= sqrt(i); ++j)
            if(i % j == 0)
            {
                dp[i] = min(dp[j] + i / j, dp[i]);
                dp[i] = min(dp[i], dp[i / j] + j);
            }
    return dp[n];
}
```

#### II 贪心

如果我们不考虑复制粘贴为两种操作，则 `A` 的数量从 `n` 变为 `kn` 共需要的次数固定为 `k` 次，  
根据上面的分析，对于一个合数 `n`，每求得一个质因数 `a`，则我们都可以看成对 `n / a` 个 `'A'` 操作了 `a` 次获得 `n`，  
因此，我们可以不断自顶向下求出子合数，直到获得不能除尽的因数 `c` 或者 **1**，  
然后我们对一个 `'A'` 进行操作获得 `c` 个 `'A'` 或者直接用 `'A'` 进行操作即可  

```cpp
int minSteps(int n) 
{
    int ret = 0;
    for(int i = 2; i < n; ++i)
    {
        while(n % i == 0)
        {
            ret += n / (n / i);
            n /= i;
        }
    }
    return n == 1 ? ret : ret + n;
}
```
