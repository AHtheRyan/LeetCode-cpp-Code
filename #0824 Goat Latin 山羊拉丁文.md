### 山羊拉丁文
### Goat Latin

> 给你一个由若干单词组成的句子 `sentence`，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。  
> 请你将句子转换为 “山羊拉丁文（Goat Latin）”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。山羊拉丁文的规则如下：  
> - 如果单词以元音开头（`'a'`, `'e'`, `'i'`, `'o'`, `'u'`），在单词后添加 `"ma"`。  
>   - 例如，单词 `"apple"` 变为 `"applema"`。  
> - 如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加 `"ma"`。  
>   - 例如，单词 `"goat"` 变为 `"oatgma"`。  
> - 根据单词在句子中的索引，在单词最后添加与索引相同数量的字母 `'a'`，索引从 `1` 开始。  
>   - 例如，在第一个单词后添加 `"a"`，在第二个单词后添加 `"aa"`，以此类推。  
> 
> 返回将 `sentence` 转换为山羊拉丁文后的句子。  

> You are given a string `sentence` that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.  
> We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:  
> - If a word begins with a vowel (`'a'`, `'e'`, `'i'`, `'o'`, or `'u'`), append `"ma"` to the end of the word.  
>   - For example, the word `"apple"` becomes `"applema"`.  
> - If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add `"ma"`.  
>   - For example, the word `"goat"` becomes `"oatgma"`.  
> - Add one letter `'a'` to the end of each word per its word index in the sentence, starting with `1`.  
>   - For example, the first word gets `"a"` added to the end, the second word gets `"aa"` added to the end, and so on.  
> 
> Return *the final sentence representing the conversion from sentence to Goat Latin*.  

----------

#### I 一次遍历

遍历过程中记录每个单词，根据规则进行转化再记录进需要返回的字符串中即可  

```cpp
class Solution 
{
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string toGoatLatin(string sentence) 
    {
        int n = sentence.size();
        int wordIndex = 1;
        string cur = "";
        string ret = "";
        for(int i = 0; i < n; ++i)
        {
            char c = sentence[i];
            if(c == ' ')
                continue;
            cur += c;
            if(i == n - 1 || sentence[i + 1] == ' ')
            {
                if(st.count(cur[0]) != 0)
                    ret += cur;
                else
                {
                    string word = cur.substr(1, cur.size() - 1);
                    ret += word + cur[0];
                }
                ret += "ma" + string(wordIndex++, 'a') + ' ';
                cur = "";
            }
        }
        ret.pop_back();
        return ret;
    }
};
```
