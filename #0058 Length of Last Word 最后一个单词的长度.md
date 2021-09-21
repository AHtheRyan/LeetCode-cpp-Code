### 最后一个单词的长度
### Length of Last Word

> 给你一个字符串 `s`，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。  
> **单词** 是指仅由字母组成、不包含任何空格字符的最大子字符串。  

> Given a string `s` consisting of some words separated by some number of spaces, return the length of the last word in the string.  
> A **word** is a maximal substring consisting of non-space characters only.  

----------

#### I 倒序遍历

根据规则，如果我们倒序遍历整个字符串，  
那么只需要将遇到的第一个字母到空格前的最后一个字母之间的长度和记录下来就可以，  
因此，我们不断跳过倒序开始的空格，并从第一个字母的位置开始计数，再次遇到空格时再直接返回，就可以得到单词的长度  

```cpp
int lengthOfLastWord(string s) 
{
    int size = s.size();
    int ret = 0;
    for(int i = size - 1; i >= 0; --i)
    {
        if(s[i] == ' ' && ret != 0)
            break;
        if(s[i] != ' ')
            ++ret;
    }
    return ret;
}
```
