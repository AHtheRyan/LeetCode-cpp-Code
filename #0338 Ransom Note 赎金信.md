### 赎金信
### Ransom Note

> 为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。  
> 给你一个赎金信 (`ransomNote`) 字符串和一个杂志(`magazine`)字符串，判断 `ransomNote` 能不能由 `magazines` 里面的字符构成。  
> 如果可以构成，返回 `true`；否则返回 `false`。  
> `magazine` 中的每个字符只能在 `ransomNote` 中使用一次。  

> Given two stings `ransomNote` and `magazine`, return true if `ransomNote` can be constructed from `magazine` and `false` otherwise.  
> Each letter in `magazine` can only be used once in `ransomNote`.  

----------

#### I 哈希表 字母计数法

基本要求为：杂志中的每个字母的数量都大于赎金信中的数量，那么很简单，直接把杂质和赎金信中用到的字母数量记录并整合比较即可

```cpp
bool canConstruct(string ransomNote, string magazine) 
{
    vector<int> ran(26, 0);
    vector<int> mag(26, 0);
    for(auto c : ransomNote)
        ++ran[c - 'a'];
    for(auto c : magazine)
        ++mag[c - 'a'];
    for(int i = 0; i < 26; ++i)
        if(ran[i] > mag[i])
            return false;
    return true;
}
```
