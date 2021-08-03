### 判断子序列
### Is Subsequence

> 给定字符串 `s` 和 `t` ，判断 `s` 是否为 `t` 的子序列。  
> 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，`"ace"`是`"abcde"`的一个子序列，而`"aec"`不是）。  

> Given two strings `s` and `t`, return `true` if `s` is a subsequence of `t`, or `false` otherwise.  
> A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).  

----------

#### I 贪心 + 双指针

根据题意，子序列是需要严格遵循原序列顺序的，并且如果t序列中存在子序列为s，  
那么遍历一遍t序列一定可以在不同位置找到按顺序找到s的每个字符，  
因此，可以采用双指针，分别从s和t的最左端进行遍历，如果s和t的字符相同了，则将s和t的指针同时右移，否则只移动t的指针，  
如果在遍历完之后s的指针指向了尾后节点，那么必然存在子序列，  
否则如果s的指针未将s遍历完，则必然t中没有按顺序出现的字符串使得s为其子串

```cpp
bool isSubsequence(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();
    int sptr = 0;
    int tptr = 0;
    while (sptr < slen && tptr < tlen)
    {
        if (t[tptr] == s[sptr])
            ++sptr;
        ++tptr;
    }
    return slen == sptr;
}
```

#### II 动态规划

分析子序列的要求，不难发现，在t中寻找子序列s，实质上就是拿s中的元素依次和t做比较，  
其中，如果s[i]在t[j]的位置被找到，那么就继续拿s[i+1]和从t[j+1]开始的序列继续进行比较，  
根据这个逻辑，就可以实现处理字符串t：  
由于一共有26个字母，所以可以记录t字符串中每个位置之后出现的任意一个字母的下标，  
这样，s字符串在比较的时候就可以实现直接按照实现存储的下标进行“跳跃查找”，通过预处理字符串和使用空间减少匹配量，  
由于每个位置后面的第一次出现的字母下标与后面的子字符串有关，所以可以从后往前遍历，建立DP数组

```cpp
bool isSubsequence(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();
    vector<vector<int>> dp(tlen + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; ++i)
        dp[tlen][i] = tlen;
    for (int i = tlen - 1; i >= 0; --i)
        for (int j = 0; j < 26; ++j)
            dp[i][j] = (t[i] == j + 'a') ? i : dp[i + 1][j];

    int add = 0;
    for (int i = 0; i < slen; i++)
    {
        if (dp[add][s[i] - 'a'] == tlen)
            return false;
        add = dp[add][s[i] - 'a'] + 1;
    }
    return true;
}
```
