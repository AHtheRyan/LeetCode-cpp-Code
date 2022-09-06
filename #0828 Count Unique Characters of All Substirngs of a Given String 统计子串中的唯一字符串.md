### 统计子串中的唯一字符串
### Count Unique Characters of All Substirngs of a Given String 

> 我们定义了一个函数 `countUniqueChars(s)` 来统计字符串 `s` 中的唯一字符，并返回唯一字符的个数。  
> 例如：`s = "LEETCODE"`，则其中 `"L"`, `"T"`,`"C"`,`"O"`,`"D"` 都是唯一字符，因为它们只出现一次，所以 `countUniqueChars(s) = 5`。  
> 本题将会给你一个字符串 `s`，我们需要返回 `countUniqueChars(t)` 的总和，其中 `t` 是 `s` 的子字符串。输入用例保证返回值为 32 位整数。  
> 注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 `s` 的所有子字符串中的唯一字符）。  

> Let's define a function `countUniqueChars(s)` that returns the number of unique characters on `s`.  
> - For example, calling `countUniqueChars(s)` if `s = "LEETCODE"` then `"L"`, `"T"`, `"C"`, `"O"`, `"D"` are the unique characters since they appear only once in `s`, therefore `countUniqueChars(s) = 5`.  
> 
> Given a string `s`, return the sum of `countUniqueChars(t)` where `t` is a substring of `s`. The test cases are generated such that the answer fits in a 32-bit integer.  
> Notice that some substrings can be repeated so in this case you have to count the repeated ones too.  

----------

#### I 逐个计算

每个字符能对字符串作出的贡献在于其左右两侧什么时候遇到跟自己相同的字符，  
例如在 `j` 位置找到字符 `c`，其左边位置 `i` 和右边位置 `k` 都可以找到字符 `c`，则次字符对于总结果能做出的贡献为 `(j - i) * (k - j)`  
以此计算每个位置的字符并求和即可  

```cpp
int uniqueLetterString(string s) 
{
    int n = s.size();
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i)
    {
        if(mp.count(s[i] - 'A') == 0)
            mp[s[i] - 'A'].emplace_back(-1);
        mp[s[i] - 'A'].emplace_back(i);
    }
    int ret = 0;
    for(auto& p : mp)
    {
        p.second.emplace_back(n);
        for(int i = 1; i < p.second.size() - 1; ++i)
            ret += (p.second[i] - p.second[i - 1]) * (p.second[i + 1] - p.second[i]);
    }
    return ret;
}
```
