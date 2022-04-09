### 唯一摩尔斯密码词
### Unique Morse Code Words

> 国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串  
> 给你一个字符串数组 `words`，每个单词可以写成每个字母对应摩尔斯密码的组合。  
> - 例如，`"cab"` 可以写成 `"-.-..--..."`，(即 `"-.-."` + `".-"` + `"-..."` 字符串的结合)。我们将这样一个连接过程称作**单词翻译**。  
> 
> 对 `words` 中所有单词进行单词翻译，返回不同**单词翻译**的数量。  

> International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes  
> Given an array of strings `words` where each word can be written as a concatenation of the Morse code of each letter.  
> - For example, `"cab"` can be written as `"-.-..--..."`, which is the concatenation of `"-.-."`, `".-"`, and `"-..."`. We will call such a concatenation the **transformation** of a word.  
> 
> Return *the number of different transformations among all words we have*.  

----------

#### I 哈希表

简单哈希  

```cpp
int uniqueMorseRepresentations(vector<string>& words) 
{
    unordered_set<string> st;
    int ret = 0;
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(auto& word : words)
    {
        string cur;
        for(auto& c : word)
            cur += morse[c - 'a'];
        if(st.count(cur) == 0)
        {
            ++ret;
            st.insert(cur);
        }
    }
    return ret;
}
```
