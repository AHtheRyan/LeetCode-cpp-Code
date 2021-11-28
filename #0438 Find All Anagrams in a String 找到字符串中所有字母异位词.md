### 找到字符串中所有字母异位词
### Find All Anagrams in a String

> 给定两个字符串 `s` 和 `p`，找到 `s` 中所有 `p` 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。  
> **异位词** 指由相同字母重排列形成的字符串（包括相同的字符串）。  

> Given two strings `s` and `p`, return *an array of all the start indices of `p`'s anagrams in `s`*. You may return the answer in **any order**.  
> An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.  

----------

#### I 滑动窗口

可以利用滑动窗口，滑动比对 `s` 中的字符和 `p` 中的字符，并记录同一字符出现的次数是否能够抵消，能抵消记为 `0`，否则记为 `1`  
如果在 `p.size()` 的长度内两边字符完全抵消，则记为和为 `0`，记录初始字符子串位置  

```cpp
vector<int> findAnagrams(string s, string p) 
{
    if(s.size() < p.size())
        return {};
    vector<int> cnt(26, 0);
    vector<int> ret;
    int diff = 0;
    for(int i = 0; i < p.size(); ++i)
    {
        ++cnt[s[i] - 'a'];
        --cnt[p[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i)
        if(cnt[i] != 0)
            ++diff;
    if(diff == 0)
        ret.push_back(0);
    for(int i = 0; i < s.size() - p.size(); ++i)
    {
        if(cnt[s[i] - 'a'] == 1)
            --diff;
        else if(cnt[s[i] - 'a'] == 0)
            ++diff;
        --cnt[s[i] - 'a'];
        if(cnt[s[i + p.size()] - 'a'] == -1)
            --diff;
        else if(cnt[s[i + p.size()] - 'a'] == 0)
            ++diff;
        ++cnt[s[i + p.size()] - 'a'];
        if(diff == 0)
            ret.push_back(i + 1);
    }
    return ret;
}
```
