### 单词的压缩编码
### Short Encoding of Words

> 单词数组 `words` 的**有效编码**由任意助记字符串 `s` 和下标数组 `indices` 组成，且满足：  
> - `words.length == indices.length`  
> - 助记字符串 `s` 以 `'#'` 字符结尾  
> - 对于每个下标 `indices[i]`，`s` 的一个从 `indices[i]` 开始、到下一个 `'#'` 字符结束（但不包括 `'#'`）的 子字符串 恰好与 `words[i]` 相等  
> 
> 给你一个单词数组 `words`，返回成功对 `words` 进行编码的最小助记字符串 `s` 的长度。  

> A **valid encoding** of an array of `words` is any reference string `s` and array of `indices` indices such that:  
> - `words.length == indices.length`  
> - The reference string `s` ends with the `'#'` character.  
> - For each index `indices[i]`, the **substring** of `s` starting from `indices[i]` and up to (but not including) the next `'#'` character is equal to `words[i]`.  
> 
> Given an array of `words`, return *the **length of the shortest reference string `s`** possible of any **valid encoding** of `words`*.  

----------

#### I 排序比较

根据题意，不单独编码的单词是需要编码的单词的后缀子串，例如 `words` 和 `rds`，因此，我们可以将字符串数组中的单词倒序，再比较是否有包含关系  
只要存在包含关系，则较短的子串不需要放在编码中，最后有效的编码长度为 `所有单词长度+单词个数`  

```cpp
class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        vector<string> reversewords(words);
        for(auto& word : reversewords)
            reverse(word.begin(), word.end());
        sort(reversewords.begin(), reversewords.end());
        string cur = reversewords[0];
        int cntWords = 0;
        int wordLen = 0;
        int n = reversewords.size();
        for(int i = 1; i < reversewords.size(); ++i)
        {
            if(!check(cur, reversewords[i]))
            {
                ++cntWords;
                wordLen += cur.size();
            }
                cur = reversewords[i];
        }
        return wordLen + cntWords + reversewords[n - 1].size() + 1;
    }

    bool check(string& s1, string& s2)
    {
        int index1 = 0;
        int index2 = 0;
        while(index1 < s1.size() && index2 < s2.size())
            if(s1[index1++] != s2[index2++])
                return false;
        return true;
    }
};
```
