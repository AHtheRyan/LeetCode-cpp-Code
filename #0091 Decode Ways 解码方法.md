### 解码方法
### Decode Ways

> 一条包含字母 `A-Z` 的消息通过以下映射进行了**编码**：  
> - 'A' -> "1"  
> - 'B' -> "2"  
> - ...  
> - 'Z' -> "26"  
> 
> 要**解码**已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，`"11106"` 可以映射为：  
> - `"AAJF"`，将消息分组为 `(1 1 10 6)`  
> - `"KJF"`，将消息分组为 `(11 10 6)`  
> 
> 注意，消息不能分组为 `(1 11 06)`，因为 `"06"` 不能映射为 `"F"`，这是由于 `"6"` 和 `"06"` 在映射中并不等价。  
> 给你一个只含数字的**非空**字符串 `s`，请计算并返回**解码**方法的**总数**。  

> A message containing letters from `A-Z` can be **encoded** into numbers using the following mapping:  
> - 'A' -> "1"  
> - 'B' -> "2"  
> - ...  
> - 'Z' -> "26"  
> 
> To **decode** an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"11106"` can be mapped into:  
> - `"AAJF"` with the grouping `(1 1 10 6)`  
> - `"KJF"` with the grouping `(11 10 6)`  
> 
> Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.  
> Given a string `s` containing only digits, return *the **number** of ways to **decode** it*.

----------

#### I 动态规划

显然，对于不同长度的数字串，可以解码的数量是存在累加关系的，故直接采用动态规划的思路，  
对每个位置产生的新的解码方案数量，推导关系如下：  
```cpp
当前数字    0           1               2               3               4               5               6               7               8               9
前一数字        
  0        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
  1     dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]
  2     dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]     dp[i-1]         dp[i-1]         dp[i-1]
  3        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
  4        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
  5        0        dp[i-1]         dp[i-1]         ......
  6        0        dp[i-1]         dp[i-1]         ......
  7        0        dp[i-1]         dp[i-1]         ......
  8        0        dp[i-1]         dp[i-1]         ......
  9        0        dp[i-1]         dp[i-1]         ......
```
- 如果数字不能和之前的数字联合编码，那么该数字单纯为编码增加了一位，比如 `"78"` 中，数字 `8` 单纯给编码加了一位但是没有增加编码的方式  
- 如果数字能和之前的数字联合编码，那么该数字为编码方式增加了一整个 `dp[i-2]`，比如 `"12"` 中，在数字 `1` 之前的编码方式可以看做直接被乘 `2`  
- 如果之前的数字为 `“1”` 或者 `“2”`，当前数字为 `“0”`，那么本数字必须与前一数字合在一起，所以反而使得方案减少了，退回 `dp[i-2]` 时的方案数目  
- 如果形成的数字为 `"30"` 及以上的整十，那么无法解码，所以方案只有 `0` 种  

按此思路构建dp数组即可  

```cpp
int numDecodings(string s)
{
    int size = s.size();
    if (size == 1)
        return !(s[0] == '0');
    vector<int> dp(size + 1);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < size + 1; ++i)
    {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        if (s[i - 2] != '0' && (s[i - 1] - '0' + (s[i - 2] - '0') * 10) <= 26)
            dp[i] += dp[i - 2];
    }
    return dp.back();
}
```
