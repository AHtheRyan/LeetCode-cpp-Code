### 解码方法II
### Decode Ways II

> 一条包含字母 A-Z 的消息通过以下的方式进行了编码：  
> > 'A' -> 1  
> > 'B' -> 2  
> > ...  
> > 'Z' -> 26  
>  
>  要 **解码** 一条已编码的消息，所有的数字都必须分组，然后按原来的编码方案反向映射回字母（可能存在多种方式）。例如，`"11106"` 可以映射为：  
>  - `"AAJF"` 对应分组 `(1 1 10 6)`  
>  - `"KJF"` 对应分组 `(11 10 6)`
> 
> 注意，像 `(1 11 06)` 这样的分组是无效的，因为`"06"`不可以映射为`'F'`，因为`"6"`与`"06"`不同。  
> **除了** 上面描述的数字字母映射方案，编码消息中可能包含 `'*'` 字符，可以表示从 `'1'` 到 `'9'` 的任一数字（不包括 `'0'`）。例如，编码字符串 `"1*"` 可以表示 `"11"`、`"12"`、`"13"`、`"14"`、`"15"`、`"16"`、`"17"`、`"18"` 或 `"19"` 中的任意一条消息。对 `"1*"` 进行解码，相当于解码该字符串可以表示的任何编码消息。  
> 给你一个字符串 `s` ，由数字和 `'*'` 字符组成，返回 **解码** 该字符串的方法 **数目**。  
> 由于答案数目可能非常大，返回对 `10^9 + 7` **取余** 的结果。

> A message containing letters from `A-Z` can be encoded into numbers using the following mapping:  
> >'A' -> "1"  
> > 'B' -> "2"  
> > ...  
> > 'Z' -> "26"  
> 
> To **decode** an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"11106"` can be mapped into:  
> `"AAJF"` with the grouping `(1 1 10 6)`  
> `"KJF"` with the grouping `(11 10 6)`  
> 
> Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.  
> **In addition** to the mapping above, an encoded message may contain the `'*'` character, which can represent any digit from `'1'` to `'9'` (`'0'` is excluded). For example, the encoded message `"1*"` may represent any of the encoded messages `"11"`, `"12"`, `"13"`, `"14"`, `"15"`, `"16"`, `"17"`, `"18"`, or `"19"`. Decoding `"1*"` is equivalent to decoding **any** of the encoded messages it can represent.  
> Given a string `s` consisting of digits and `'*'` characters, return *the **number** of ways to **decode** it*.  
> Since the answer may be very large, return it **modulo** `10^9 + 7`.

----------

#### I 模拟

显然，某个长度的字符串的解码方式是短于其的某种长度的字符串的解码方式的加和，因此此处采用动态规划的方法  
假设第 `n` 位的字符前 `n - 1` 位字符的解码方式有 `x` 种，前 `n - 2` 为字符的解码方式有 `y` 种，则可得关系表：  
![1633538663(1)](https://user-images.githubusercontent.com/46887748/136247689-8d9f9193-067e-4938-b590-3c1d5ab95bf6.png)  
其中，绿色为当前字符，黄色为前一字符  
按照此表格构建动态规划数组即可  

```cpp
class Solution 
{
public:
    static constexpr int mod = 1000000007;
    int numDecodings(string s) 
    {
        int len = s.size();
        vector<long long> dp(len + 1);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : (s[0] == '0' ? 0 : 1);
        for(int i = 2; i < len + 1; ++i)
        {
            long long pre, cur;
            pre = s[i - 1] == '*' ? 9 : (s[i - 1] == '0' ? 0 : 1);
            if(s[i - 2] == '*')
                cur = s[i - 1] == '*' ? 15 : (s[i - 1] - '0' < 7 ? 2 : 1);
            else if(s[i - 1] == '*')
            {
                int n = s[i - 2] - '0';
                cur = n == 1 ? 9 : (n == 2 ? 6 : 0);
            }
            else
            {
                int num = (s[i - 1] - '0') + (s[i - 2] - '0') * 10;
                cur = (num >= 10 && num <= 26) ? 1 : 0;
            }
            dp[i] = cur * dp[i - 2] + pre * dp[i - 1];
            dp[i] %= mod;
        }
        return dp[len];
    }
};
```
