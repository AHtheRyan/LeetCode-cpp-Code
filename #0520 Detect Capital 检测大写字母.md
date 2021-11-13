### 检测大写字母
### Detect Capital

> 我们定义，在以下情况时，单词的大写用法是正确的：  
> - 全部字母都是大写，比如 `"USA"`。  
> - 单词中所有字母都不是大写，比如 `"leetcode"`。  
> - 如果单词不只含有一个字母，只有首字母大写， 比如 `"Google"`。  
> 
> 给你一个字符串 `word`。如果大写用法正确，返回 `true`；否则，返回 `false`。  

> We define the usage of capitals in a word to be right when one of the following cases holds:  
> - All letters in this word are capitals, like `"USA"`.  
> - All letters in this word are not capitals, like `"leetcode"`.  
> - Only the first letter in this word is capital, like `"Google"`.  
> 
> Given a string `word`, return `true` if the usage of capitals in it is right.  

----------

#### I 简单遍历

根据题意：  
1. 只有一个字母的单词必然符合
2. 从第二个字母开始，每个字母的大小写都应该和第二个字母一样
3. 如果第一个字母为小写，则后续必须为小写

根据这三个规律编写即可

```cpp
bool detectCapitalUse(string word) 
{
    if(word.size() > 1)
    {
        if(islower(word[0]) && isupper(word[1]))
            return false;
        for(int i = 2; i < word.size(); ++i)
            if((islower(word[1]) ^ islower(word[i])))
                return false;
    }
    return true;
}
```
