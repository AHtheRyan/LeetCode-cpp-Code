### 截断句子
### TRuncate Sentence

> **句子** 是一个单词列表，列表中的单词之间用单个空格隔开，且不存在前导或尾随空格。每个单词仅由大小写英文字母组成（不含标点符号）。
> - 例如，`"Hello World"`、`"HELLO"` 和 `"hello world hello world"` 都是句子。  
> 
> 给你一个句子 `s` 和一个整数 `k`，请你将 `s` **截断**，使截断后的句子仅含**前** `k` 个单词。返回 **截断** `s` 后得到的句子。  

> A **sentence** is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of **only** uppercase and lowercase English letters (no punctuation).  
> - For example, `"Hello World"`, `"HELLO"`, and `"hello world hello world"` are all sentences.  
> 
> You are given a sentence `s` and an integer `k`. You want to truncate `s` such that it contains only the first `k` words. Return `s` after truncating it.  

----------

#### I 遍历截断

按照规则，只有可能出现两种情况：  
1. 出现 `k` 个以外的单词，只需要保留 `k` 个
2. 单词数目不足，则返回所有单词  

根据实际技术情况返回子串或者字符串本身即可

```cpp
string truncateSentence(string s, int k) 
{
    int index = 0;
    for(; k > 0 && index < s.size(); ++index)
        if(s[index] == ' ')
            --k;
    return k == 0 ? s.substr(0, index - 1) : s;
}
```
