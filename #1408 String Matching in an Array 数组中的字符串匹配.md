### 数组中的字符串匹配
### String MAtching in an Array

> 给你一个字符串数组 `words`，数组中的每个字符串都可以看作是一个单词。请你按**任意**顺序返回 `words` 中是其他单词的子字符串的所有单词。  
> 如果你可以删除 `words[j]` 最左侧和/或最右侧的若干字符得到 `word[i]`，那么字符串 `words[i]` 就是 `words[j]` 的一个子字符串。  

> Given an array of string `words`. Return all strings in `words` which is substring of another word in **any** order.   
> String `words[i]` is substring of `words[j]`, if can be obtained removing some characters to left and/or right side of `words[j]`.  

----------

#### I 暴力枚举

简单枚举即可

```cpp
vector<string> stringMatching(vector<string>& words) 
{
    vector<string> ret;
    int n = words.size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i != j && words[j].find(words[i]) != string::npos)
            {
                ret.push_back(words[i]);
                break;
            }
        }
    }
    return ret;
}
```
