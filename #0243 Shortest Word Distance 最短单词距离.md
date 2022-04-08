### 最短单词距离
### Shortest Word Distance

> 给定一个字符串数组 `wordDict` 和两个已经存在于该数组中的不同的字符串 `word1` 和 `word2`。返回列表中这两个单词之间的最短距离。  

> Given an array of strings `wordsDict` and two different strings that already exist in the array `word1` and `word2`, return *the shortest distance between these two words in the list*.  

----------

#### I 双指针

在列表中按顺序找到每次单词出现的位置，并比较距离即可  

```cpp
int shortestDistance(vector<string>& wordsDict, string word1, string word2) 
{
    int w1ptr = -1;
    int w2ptr = -1;
    int ret = wordsDict.size();
    for(int i = 0; i < wordsDict.size(); ++i)
    {
        if(wordsDict[i] == word1)
            w1ptr = i;
        if(wordsDict[i] == word2)
            w2ptr = i;
        if(w1ptr >= 0 && w2ptr >= 0)
            ret = min(abs(w2ptr - w1ptr), ret);
    }
    return ret;
}
```
