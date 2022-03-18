### 翻转单词顺序

> 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。  

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
