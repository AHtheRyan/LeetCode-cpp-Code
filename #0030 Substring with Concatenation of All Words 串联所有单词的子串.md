### 串联所有单词的子串
### Substring with Concatenation of All Words

> 给定一个字符串 `s` 和一些 长度相同 的单词 `words`。找出 `s` 中恰好可以由 `words` 中所有单词串联形成的子串的起始位置。  
> 注意子串要与 `words` 中的单词完全匹配，**中间不能有其他字符**，但不需要考虑 `words` 中单词串联的顺序。  

> You are given a string `s` and an array of strings `words` of **the same length**. Return all starting indices of substring(s) in `s` that is a concatenation of each word in `words` **exactly once**, **in any order**, and **without any intervening characters**.  
> You can return the answer in **any order**.  

----------

#### I 哈希表 + 双指针

核对原字符串与单词表的单词数目有两种方案：
1. 哈希表存储比较  
2. 单词计数  

为了节约比较时间，我们采用哈希表存储，同时使用单词计数的方式进行比较  
实际的比较过程较为简单，直接利用**滑动窗口 + 双指针**，固定左侧指针，只要单词对上就移动右指针，满足条件就记录即可，注意：  
1. 当满足条件后，左右指针可以各自只移动一个单词长度，且计数哈希表可以不清空，节约时间效率  
2. 如果某个位置单词突然对不上，则必须全部清空计数表，从右指针的位置直接开始即可  
3. 起始位置会发生变化，变化范围为 `0 ~ 单词长度`  

```cpp
vector<int> findSubstring(string s, vector<string>& words) 
{
    int start = 0;
    int wordLen = words[0].size();
    int wordNum = words.size();
    unordered_map<string, int> strCnt;
    vector<int> ret;
    for(auto& word : words)
        ++strCnt[word];
    while(start < wordLen)
    {
        int index = start;
        int curpos = start;
        int curWordNum = 0;
        unordered_map<string, int> check;
        while(curpos + wordLen <= s.size())
        {
            string cur = s.substr(curpos, wordLen);
            curpos += wordLen;
            if(strCnt.count(cur) == 0)
            {
                index = curpos;
                check.clear();
                curWordNum = 0;
            }
            else
            {
                ++check[cur];
                ++curWordNum;
                while(check[cur] > strCnt[cur])
                {
                    string indexCur = s.substr(index, wordLen);
                    index += wordLen;
                    --check[indexCur];
                    --curWordNum;
                }
                if(wordNum == curWordNum)
                    ret.push_back(index);
            }
        }
        ++start;
    }
    return ret;
}
```
