### 重新排列单词间的空格
### Rearrange Space Between Words

> 给你一个字符串 `text`，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证 `text` **至少包含一个单词**。  
> 请你重新排列空格，使每对相邻单词之间的空格数目都**相等**，并尽可能**最大化**该数目。如果不能重新平均分配所有空格，请**将多余的空格放置在字符串末尾**，这也意味着返回的字符串应当与原 `text` 字符串的长度相等。  
> 返回**重新排列空格后的字符串**。  

> You are given a string `text` of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that `text` **contains at least one word**.  
> Rearrange the spaces so that there is an **equal** number of spaces between every pair of adjacent words and that number is **maximized**. If you cannot redistribute all the spaces equally, place the **extra spaces at the end**, meaning the returned string should be the same length as `text`.  
> Return *the string after rearranging the spaces*.  

----------

#### I 单词拆分重组

遍历原字符串，记下单词和空格的数目后重组即可  

```cpp
string reorderSpaces(string text) 
{
    int spaceCnt = 0;
    int n = text.size();
    vector<string> words;
    string word;
    for(int i  = 0; i < n; ++i)
    {
      if(text[i] == ' ')
      {
          ++spaceCnt;
          if(word.size() > 0)
          {
              words.emplace_back(word);
              word = "";
          }
      }
      else
          word += text[i];
    }
    if(word.size() > 0)
      words.emplace_back(word);
    int m = words.size();
    int avrg = m == 1 ? 0 : spaceCnt / (m - 1);
    int left = m == 1 ? spaceCnt : spaceCnt % (m - 1);
    string ret = words[0];
    for(int i = 1; i < m; ++i)
      ret += (string(avrg, ' ') + words[i]);
    ret += string(left, ' ');
    return ret;
}
```
