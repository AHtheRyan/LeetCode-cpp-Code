### 重新格式化字符串
### Reformat the String

> 给你一个混合了数字和字母的字符串 `s`，其中的字母均为小写英文字母。  
> 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。  
> 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个**空字符串**。  

> You are given an alphanumeric string `s`. (Alphanumeric string is a string consisting of lowercase English letters and digits).  
> You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.  
> Return *the reformatted string* or return **an empty string** if it is impossible to reformat the string.  

----------

#### I 字符串拆分重组

将字符串按照数字和字母进行拆分，再根据实际情况进行重组即可  

```cpp
string reformat(string s) 
{
    string digit, alpha;
    for(auto& c : s)
    {
        if(isdigit(c))
            digit += c;
        else
            alpha += c;
    }
    int m = digit.size();
    int n = alpha.size();
    if(abs(m - n) > 1)
        return "";
    string ret;
    for(int i = 0; i < min(m, n); ++i)
        ret = ret + digit[i] + alpha[i];
    if(m > n)
        ret += digit[m - 1];
    if(m < n)
        ret = alpha[n - 1] + ret;
    return ret;
}
```
