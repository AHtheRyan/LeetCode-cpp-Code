### 最短补全词
### Shortest Completing Word

> 给你一个字符串 `licensePlate` 和一个字符串数组 `words`，请你找出并返回 `words` 中的 **最短补全词**。 
> **补全词** 是一个包含 `licensePlate` 中所有的字母的单词。在所有补全词中，最短的那个就是 **最短补全词**。  
> 在匹配 `licensePlate` 中的字母时：  
> - **忽略** `licensePlate` 中的 **数字和空格**。  
> - **不区分大小写**。  
> - 如果某个字母在 `licensePlate` 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。  
> 
> 例如：`licensePlate = "aBc 12c"`，那么它的补全词应当包含字母 `'a'`、`'b'` （忽略大写）和两个 `'c'`。可能的 **补全词** 有 `"abccdef"`、`"caaacab"` 以及 `"cbca"`。  
> 请你找出并返回 `words` 中的 **最短补全词**。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 `words` 中 **最靠前的** 那个。  

> Given a string `licensePlate` and an array of strings `words`, find the **shortest completing** word in `words`.  
> A **completing** word is a word that **contains all the letters** in licensePlate. **Ignore numbers and spaces** in `licensePlate`, and treat letters as **case insensitive**. If a letter appears more than once in `licensePlate`, then it must appear in the word the same number of times or more.  
> For example, if `licensePlate = "aBc 12c"`, then it contains letters `'a'`, `'b'` (ignoring case), and `'c'` twice. Possible **completing** words are `"abccdef"`, `"caaacab"`, and `"cbca"`.  
> Return *the shortest **completing** word in words*. It is guaranteed an answer exists. If there are multiple shortest **completing** words, return the **first** one that occurs in `words`.  

----------

#### I 哈希表

记录下原字符串中的各字母总数，并逐一与 `words` 中的单词比对，只要 `words` 中的单词各字母出现的次数都大于原字符串即可  

```cpp
class Solution 
{
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        string pureLetter;
        for(auto& s : licensePlate)
            if(isalpha(s))
                pureLetter += tolower(s);
        vector<int> cnt(26, 0);
        for(auto c : pureLetter)
            ++cnt[c - 'a'];
        int index = 0;
        int min = INT_MAX;
        for(int i = 0; i < words.size(); ++i)
        {
            int cur = judge(cnt, words[i]);
            if(cur < min)
            {
                min = cur;
                index = i;
            }
        }
        return words[index];
    }

    int judge(vector<int> cnt, string& word)
    {
        for(auto& c : word)
            cnt[c - 'a'] = cnt[c - 'a'] > 0 ?cnt[c - 'a'] - 1 : 0;
        if(accumulate(cnt.begin(), cnt.end(), 0) > 0)
            return INT_MAX;
        return word.size();
    }
};
```
