### 特殊的二进制序列
### Special Binary String

> 特殊的二进制序列是具有以下两个性质的二进制序列：  
> - 0 的数量与 1 的数量相等。  
> - 二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。  
> 
> 给定一个特殊的二进制序列 `S`，以字符串形式表示。定义一个*操作*为首先选择 `S` 的两个连续且非空的特殊的子串，然后将它们交换。（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)  
> 在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？  

> Special binary strings are binary strings with the following two properties:  
> - The number of `0`'s is equal to the number of `1`'s.  
> - Every prefix of the binary string has at least as many `1`'s as `0`'s.  
> 
> You are given a **special binary** string `s`.  
> A move consists of choosing two consecutive, non-empty, special substrings of `s`, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.  
> Return *the lexicographically largest resulting string possible after applying the mentioned operations on the string*.  

----------

#### I 分治

根据题意，实际的排序必然会变成首位为 `1`，末尾为 `0` 的字符串  
而交换的字符串一定是 `'1' * n + '0' * n` 这种形式，所以可以采用分治的方式，  
先将字符串按照满足特殊字符串的字串分段，再对分段进行同样的处理，分段最小之后进行排序，获得最大的二进制序列  

```cpp
string makeLargestSpecial(string s) 
{
    if(s.size() < 2)
        return s;
    int cnt = 0;
    int left = 0;
    vector<string> sub;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '1')
            ++cnt;
        else
        {
            --cnt;
            if(cnt == 0)
            {
                sub.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                left = i + 1;
            }
        }
    }
    sort(sub.begin(), sub.end(), [](string a, string b){return a > b;});
    string ret = accumulate(sub.begin(), sub.end(), string(""));
    return ret;
}
```
