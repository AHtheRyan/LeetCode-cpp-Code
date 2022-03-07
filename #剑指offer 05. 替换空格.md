### 替换空格

> 请实现一个函数，把字符串 `s` 中的每个空格替换成 `"%20"`。  

----------

#### I 单指针

遍历+替换，很基本的题目

```cpp
string replaceSpace(string s) 
{
    string ret;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != ' ')
            ret += s[i];
        else
            ret += "%20";
    }
    return ret;
}
```
