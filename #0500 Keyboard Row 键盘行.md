### 键盘行
### Keyboard Row

> 给你一个字符串数组 `words`，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。  
> 美式键盘 中：  
> 第一行由字符 `"qwertyuiop"` 组成。  
> 第二行由字符 `"asdfghjkl"` 组成。  
> 第三行由字符 `"zxcvbnm"` 组成。  

> Given an array of strings `words`, return *the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below*.  
> In the **American keyboard**:  
> the first row consists of the characters `"qwertyuiop"`,  
> the second row consists of the characters `"asdfghjkl"`, and  
> the third row consists of the characters `"zxcvbnm"`.  

----------

#### I 哈希表

简单来说，利用哈希表存储每一行即可  
操作时有一个小trick，即通过记录26个字母对应的键盘行号，利用 **ASCII码 -> 行号** 的映射方式判断单词中字母的同行性  

```cpp
vector<string> findWords(vector<string>& words) 
{
    string lineNum = "12210111011122000010020202";
    vector<string> ret;
    for(auto word : words)
    {
        char cur = lineNum[tolower(word[0]) - 'a'];
        int index = 1;
        for(; index < word.size(); ++index)
            if(cur != lineNum[tolower(word[index]) - 'a'])
                break;
        if(index == word.size())
            ret.push_back(word);
    }
    return ret;
}
```
