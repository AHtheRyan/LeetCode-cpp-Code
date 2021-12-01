### 连续字符
### Consecutive Characters

> 给你一个字符串 `s`，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。  
> 请你返回字符串的能量。  

> The **power** of the string is the maximum length of a non-empty substring that contains only one unique character.  
> Given a string `s`, return *the **power** of `s`*.  

----------

#### I 简单遍历

遍历字符串，按照每个字母连续出现的次数累加，并返回出现次数最多的单词即可

```cpp
int maxPower(string s) 
{
    int ret = 1;
    int cnt = 1;
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == s[i - 1])
        {
            ++cnt;
            ret = max(ret, cnt);
        }
        else
            cnt = 1;
    }
    return ret;
}
```
