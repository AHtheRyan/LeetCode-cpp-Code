### 同构字符串
### Isomorphic Strings

> 给定两个字符串 `s` 和 `t`，判断它们是否是同构的。  
> 如果 `s` 中的字符可以按某种映射关系替换得到 `t`，那么这两个字符串是同构的。  
> 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。  

> Given two strings `s` and `t`, determine if they are isomorphic.  
> Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.  
> All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.  

----------

#### I 哈希表

利用哈希表记录两个字符串中字符的哈希映射关系，如果没有出现同一个字符对应两个映射关系，即可认为两个字符串是同构字符串  

```cpp
bool isIsomorphic(string s, string t) 
{
    if(s.size() != t.size())
        return false;
    unordered_map<char, char> mp;
    unordered_map<char, char> rmp;
    for(int i = 0; i < s.size(); ++i)
    {
        if(!mp.count(s[i]) && !rmp.count(t[i]))
        {
            mp[s[i]] = t[i];
            rmp[t[i]] = s[i];
        }
        else if(mp[s[i]] != t[i] || rmp[t[i]] != s[i])
            return false;
    }
    return true;
}
```
