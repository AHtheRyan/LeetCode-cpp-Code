### 赎金信
### Ransome Note

> 为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。  
> 给你一个赎金信 (`ransomNote`) 字符串和一个杂志(`magazine`)字符串，判断 `ransomNote` 能不能由 `magazines` 里面的字符构成。  
> 如果可以构成，返回 `true`；否则返回 `false`。  
> `magazine` 中的每个字符只能在 `ransomNote` 中使用一次。  

> Given two stings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed from `magazine` and `false` otherwise.  
> Each letter in `magazine` can only be used once in `ransomNote`.  

----------

#### I 字符统计

对两边的26个字母出现的次数进行统计，只要满足每个字母在 `magzine` 中出现的次数都大于 `ransomenote` 即可  
可以利用正负号减少结构的使用量优化空间

```cpp
bool canConstruct(string ransomNote, string magazine) 
{
    vector<int> cnt(26, 0);
    for(auto c : magazine)
        ++cnt[c - 'a'];
    for(auto c : ransomNote)
    {
        --cnt[c - 'a'];
        if(cnt[c - 'a'] < 0)
            return false;
    }
    return true;
}
```
