### 颠倒字符串中的单词
### Reverse Words in a String

> 给你一个字符串 `s`，颠倒字符串中**单词**的顺序。  
> **单词**是由非空格字符组成的字符串。`s`中使用至少一个空格将字符串中的**单词**分隔开。  
> 返回**单词**顺序颠倒且**单词**之间用单个空格连接的结果字符串。  
> 注意：输入字符串`s`中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。  

> Given an input string `s`, reverse the order of the **words**.  
> A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.  
> Return *a string of the words in reverse order concatenated by a single space*.  
> **Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.  

----------

#### I 利用栈进行倒序

可以通过循环嵌套的方式确定字符串内的单词，没确定一个单词，将其入栈，  
当单词入栈完毕后，按顺序出栈，同时加入空格即可  

```cpp
string reverseWords(string s) 
{
    stack<string> stk;
    string cur;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != ' ')
            cur += s[i];
        else if(!cur.empty())
        {
            stk.push(cur);
            cur = "";
        }
    }
    if(!cur.empty())
        stk.push(cur);
    string ret;
    while(!stk.empty())
    {
        ret += stk.top();
        stk.pop();
        if(!stk.empty())
            ret += ' ';
    }
    return ret;
}
```

#### II 两次反转

可以先将整个字符串颠倒，然后再依次将每个单词颠倒  

```cpp
string reverseWords(string s) 
{
    reverse(s.begin(), s.end());
    int index = 0;
    for(int start = 0; start < s.size(); ++start)
    {
        if(s[start] != ' ')
        {
            if(index != 0)
                s[index++] = ' ';
            int end = start;
            while(end < s.size() && s[end] != ' ')
                s[index++] = s[end++];
            reverse(s.begin() + index - (end - start), s.begin() + index);
            start = end;
        }
    }
    s.erase(s.begin() + index, s.end());
    return s;
}
```
