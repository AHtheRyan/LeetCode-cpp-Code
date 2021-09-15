### 通过删除字母匹配到字典里最长单词
###  Longest Word in Dictionary through Deleting

> 给你一个字符串 `s` 和一个字符串数组 `dictionary` 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 `s` 中的某些字符得到。  
> 如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。  

> Given a string `s` and a string array `dictionary`, return *the longest string in the dictionary that can be formed by deleting some of the given string characters*. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.  

----------

#### I 双指针

最直接暴力的方式就是利用双指针匹配 `s` 和字典中的每一个单词，  
遍历整个字典，最终返回最长且字典序最小的那个单词即可  

```cpp
string findLongestWord(string s, vector<string>& dictionary) 
{
    string ret;
    int max = 0;
    for(auto word : dictionary)
    {
        int wptr = 0;
        int sptr = 0;
        while(wptr < word.size() && sptr < s.size())
        {
            if(s[sptr] == word[wptr])
                ++wptr;
            ++sptr;
        }
        if(wptr == word.size() && (word.size() > max || word.size() == max && word < ret))
        {
            ret = word;
            max = word.size();
        }
    }
    return ret;
}
```

#### II 排序 + 双指针

暴力法的步骤改良  
因为需要考虑**字典序**和**长度**两个属性，  
我们可以使用内置的 `sort` 函数进行排序，同时，使用lamda表达式将排序的规则定义为 **长度降序 + 字典序升序**，  
这样，只需要返回能够匹配的第一个单词即可  

```cpp
string findLongestWord(string s, vector<string>& dictionary) 
{
    sort(dictionary.begin(), dictionary.end(), [&](string a, string b){return a.size() > b.size() || a.size() == b.size() && a < b;});
    for(auto word : dictionary)
    {
        int wptr = 0;
        int sptr = 0;
        while(wptr < word.size() && sptr < s.size())
        {
            if(word[wptr] == s[sptr])
                ++wptr;
            ++sptr;
        }
        if(wptr == word.size())
            return word;
    }
    return "";
}
```

#### III 动态规划

动态规划在解决单个匹配问题上效率不够高，  
如果将问题改成得到每一个单词，则其效率会随着字典的规模上升而提升，  
对于动态规规划数组，我们设置一个二维数组 `dp[x][y]`：
1. `x` 为字符串 `s` 的第 `x` 个字母  
2. `y` 为 26 个字母
3. 对于每个 `dp[x][y]`，我们定义其值为在字符串的下标 `x` 处的下一个 `y` 字母所在的位置在字符串中的下标  

这样，从后往前遍历数组，最后可以得到一个字符串的每个字母位置的动态规划表  
对于字典中的每个单词 `word`，我们可以在字符串中不断寻找每个字母对应的下标是否存在，  
如果不存在，则该单词不能通过删除 `s` 的字母得到  
否则，该单词可以得到  
再对符合的单词进行判断即可  

```cpp
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        int size = s.size();
        vector<vector<int>> alphabet(size + 1, vector<int> (26, -1));
        for(int i = size - 1; i >= 0; --i)
        {
            char c = s[i];
            for(int j = 0; j < 26; ++j)
            {
                if(j == c - 'a')
                    alphabet[i][j] = i;
                else
                    alphabet[i][j] = alphabet[i + 1][j];
            }
        }
        string ret = "";
        int len = 0;
        for(auto word : dictionary)
        {
            int wptr = 0;
            int aptr = 0;
            while(wptr < word.size())
            {
                if(alphabet[aptr][word[wptr] - 'a'] == -1)
                    break;
                else
                    aptr = alphabet[aptr][word[wptr++] - 'a'] + 1;
            }
            if(wptr == word.size() && (wptr > len || wptr == len && word < ret))
            {
                ret = word;
                len = word.size();
            }
        }
        return ret;
    }
```
