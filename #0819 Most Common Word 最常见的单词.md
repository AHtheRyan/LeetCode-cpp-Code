### 最常见的单词
### Most Common Word

> 给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。  
> 题目保证至少有一个词不在禁用列表中，而且答案唯一。  
> 禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。  

> Given a string `paragraph` and a string array of the banned words `banned`, return *the most frequent word that is not banned*. It is **guaranteed** there is **at least one word** that is not banned, and that the answer is **unique**.  
> The words in `paragraph` are **case-insensitive** and the answer should be returned in **lowercase**.  

----------

#### I 哈希表

利用哈希表记录禁用的单词，再利用哈希表对句子进行计数，返回最长单词即可  

```cpp
string mostCommonWord(string paragraph, vector<string>& banned) 
{
    unordered_map<string, int> cnt;
    unordered_set<string> st;
    for(auto& word : banned)
        st.insert(word);
    string ret;
    int cntmax = 0;
    string cur = "";
    for(int i = 0; i < paragraph.size(); ++i)
    {
        char c = tolower(paragraph[i]);
        if(isalpha(c))
        {
            cur += c;
            if(i == paragraph.size() - 1 || !isalpha(paragraph[i + 1]))
            {
                if(st.count(cur) == 0)
                {
                    ++cnt[cur];
                    if(cnt[cur] > cntmax)
                    {
                        cntmax = cnt[cur];
                        ret = cur;
                    }
                }
                cur = "";
            }
        }
    }
    return ret;
}
```
