### 最大单词长度乘积
### Maximum Product of Word Lengths

> 给定一个字符串数组 `words`，找到 `length(word[i]) * length(word[j])` 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 `0`。  

> Given a string array `words`, return *the maximum value of `length(word[i]) * length(word[j])` where the two words do not share common letters*. If no such two words exist, return `0`.  

----------

#### I 位运算掩码

由于小写字母一共只有26位，因此可以利用位运算对字符和字符串的运算进行一定的简化  
利用 `1` 和 `0` 分别表示某个字母的出现与否，存储为一个长度为 `words.size()` 的数组，  
之后对数组的数字按顺序进行字母重复运算，利用 `&` 运算可以快速计算出是否有重复字母的出现（如果没有则运算结果为`0`），  
最后记录最长的无重复字母乘积即可

```cpp
int maxProduct(vector<string>& words) 
{
    int size = words.size();
    vector<int> mask(size);
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < words[i].size(); ++j)
            mask[i] |= (1 << (words[i][j] - 'a'));
    int maxLen = 0;
    for(int i = 0; i < size; ++i)
        for(int j = i + 1; j < size; ++j)
            if((mask[i] & mask[j]) == 0)
            {
                int cur = words[i].size() * words[j].size();
                maxLen = maxLen > cur ? maxLen : cur;
            }
    return maxLen;
}
```
