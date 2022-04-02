### 有效的字母异位词
### Valid Anagram

> 给定两个字符串 `s` 和 `t`，编写一个函数来判断 `t` 是否是 `s` 的字母异位词。  
> 注意：若 `s` 和 `t` 中每个字符出现的次数都相同，则称 `s` 和 `t` 互为字母异位词。  

> Given two strings `s` and `t`, return *`true` if `t` is an anagram of `s`, and `false` otherwise*.  
> An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.  

---------

#### I 哈希表

利用哈希表记录每个数字出现的次数并返回即可  

```cpp
bool isAnagram(string s, string t) 
{
    vector<int> mp(26);
    for(auto& c : s)
        ++mp[c - 'a'];
    for(auto& c : t)
    {
        --mp[c - 'a'];
        if(mp[c - 'a'] < 0)
            return false;
    }
    return accumulate(mp.begin(), mp.end(), 0) == 0;
}
```
