### 密钥格式化
### License Key Formatting

> 有一个密钥字符串 `S`，只包含字母，数字以及 `'-'`（破折号）。其中，`N` 个 `'-'` 将字符串分成了 `N+1` 组。  
> 给你一个数字 `K`，请你重新格式化字符串，使每个分组恰好包含 `K` 个字符。特别地，第一个分组包含的字符个数必须小于等于 `K`，但至少要包含 `1` 个字符。两个分组之间需要用 `'-'`（破折号）隔开，并且将所有的小写字母转换为大写字母。  
> 给定非空字符串 `S` 和数字 `K`，按照上面描述的规则进行格式化。  

> You are given a license key represented as a string `s` that consists of only alphanumeric characters and dashes. The string is separated into `n + 1` groups by `n` dashes. You are also given an integer `k`.  
> We want to reformat the string `s` such that each group contains exactly `k` characters, except for the first group, which could be shorter than `k` but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.  
> Return *the reformatted license key*.

----------

#### I 模拟

首先，需要求出原字符串中非 `'-'` 的字符总数，同时将每个字母都转换为大写，这里可以利用ASCII码的特性进行转换，  
之后，求出每个分组的字母数，可以发现，除了第一个分组外，其他分组的字母数为 `s.size() / k`：  
如果能整除，则第一个分组不存在，如果不能整除，则第一个分组的字母数为 `s.size() % k`  
之后按顺序将每个分组的字母填上即可

```cpp
string licenseKeyFormatting(string s, int k) 
{
    int count = 0;
    string cle = "";
    for(auto c : s)
    {
        if(c != '-')
        {
            ++count;
            cle += (c - '9' <= 0 ? c : (c & 0xDF));
        }
    }
    int ave = count / k;
    int first = count % k;
    string ret = "";
    int ptr = 0;
    if(first != 0)
    {
        while(ptr < first)
            ret += cle[ptr++];
        if(ave != 0)
            ret += '-';
    }
    for(; ptr < cle.size(); ++ptr)
    {
        ret += cle[ptr];
        if((ptr - first + 1) % k == 0 && ptr != cle.size() - 1)
            ret += '-';
    }
    return ret;
}
```
