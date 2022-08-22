### 检查单词是否为句中其他单词的前缀
### Check If a Word Occurs As a Prefix of Any Word in a Sentence

> 给你一个字符串 `sentence` 作为句子并指定检索词为 `searchWord`，其中句子由若干用**单个空格**分隔的单词组成。请你检查检索词 `searchWord` 是否为句子 `sentence` 中任意单词的前缀。  
> 如果 `searchWord` 是某一个单词的前缀，则返回句子 `sentence` 中该单词所对应的下标 **（下标从 1 开始）**。如果   searchWord   是多个单词的前缀，则返回匹配的第一个单词的下标 **（最小下标）**。如果 `searchWord` 不是任何单词的前缀，则返回 `-1`。  
> 字符串 `s` 的**前缀**是 `s` 的任何前导连续子字符串。  

> Given a `sentence` that consists of some words separated by a **single space**, and a `searchWord`, check if `searchWord` is a prefix of any word in `sentence`.  
> Return *the index of the word in `sentence` (**1-indexed**) where `searchWord` is a prefix of this word*. If `searchWord` is a prefix of more than one word, return the index of the first word (**minimum index**). If there is no such word return `-1`.  
> A **prefix** of a string `s` is any leading contiguous substring of `s`.  

----------

#### I 分割 + 模拟

将句子按照空格分割，并比较每个单词的前缀即可  

```cpp
int isPrefixOfWord(string sentence, string searchWord) 
{
    int index = 0;
    int n = sentence.size();
    int cnt = 0;
    while(index < n)
    {
        string word = "";
        while(index < n && sentence[index] != ' ')
            word += sentence[index++];
        ++index;
        ++cnt;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < word.size() && ptr2 < searchWord.size())
        {
            if(word[ptr1] == searchWord[ptr2])
            {
                ++ptr1;
                ++ptr2;
            }
            else
                break;
        }
        if(ptr2 == searchWord.size())
            return cnt;
    }
    return -1;
}
```
