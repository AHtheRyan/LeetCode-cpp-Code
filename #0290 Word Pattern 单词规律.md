### 单词规律
### Word Pattern

> 给定一种规律 `pattern` 和一个字符串 `str` ，判断 `str` 是否遵循相同的规律。  
> 这里的**遵循**指完全匹配，例如， `pattern` 里的每个字母和字符串 `str` 中的每个非空单词之间存在着双向连接的对应规律。  

> Given a `pattern` and a string `s`, find if `s` follows the same pattern.  
> Here follow means a full match, such that there is a bijection between a letter in `pattern` and a non-empty word in `s`.

----------

#### I 哈希表

显然，如果某个字母对应的单词已经确定，那么后面只要检查出现的单词是否有对应的字母即可，故采用哈希表解决  
创建两个哈希表 `mp` 和 `rmp`，分别用来进行 单词->字母 和 字母->单词 的索引，  
遍历模式字符串 `pattern`：  
1. 取得单词字符串 `s` 中的对应位置单词 `cur`  
2. 检查该单词和字母在两个互相映射的哈希表中的存在情况  
   - 如果不存在，则建立两者的相互映射关系，即将字母和单词分别存入对应的映射中：`mp[单词] = 字母` 和 `rmp[字母] = 单词`  
   - 如果已存在此对应关系，但是新的字母和旧的单词或者旧的字母和新的单词建立了映射关系，则意味着出现了不同的映射，直接返回 `false`  
模式字符串遍历结束后，检查是否单词数量超界，如果超界，则返回 `false`，否则返回 `true`  

```cpp
bool wordPattern(string pattern, string s) 
{
    unordered_map<char, string> mp;
    unordered_map<string, char> rmp;
    int ptr = 0;
    for(auto c : pattern)
    {
        string cur = "";
        while(s[ptr] != ' ' && ptr < s.size())
            cur += s[ptr++];
        ++ptr;
        if(mp.find(c) == mp.end() && rmp.find(cur) == rmp.end())
        {
            mp[c] = cur;
            rmp[cur] = c;
        }
        else if(mp[c] != cur)
            return false;
    }
    return ptr == s.size() + 1 ? true : false;
}
```
