### 反转每对括号间的字串
### Reverse Substrings Between Each Pair of Parentheses

> 给出一个字符串 `s`（仅含有小写英文字母和括号）。  
> 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。  
> 注意，您的结果中**不应**包含任何括号。  

> You are given a string `s` that consists of lower case English letters and brackets.  
> Reverse the strings in each pair of matching parentheses, starting from the innermost one.  
> Your result should **not** contain any brackets.  

----------

#### I 栈

基于栈对字符串进行处理，每当遇到一个 `'('`，就将当前字符串存在栈中，每当遇到一个 `')'`，就将当前字符串反转并取出上一次存在字符串中的栈  
遍历完整个字符串后即可得到需要的结果  

```cpp
string reverseParentheses(string s) 
{
    stack<string> stk;
    string ret;
    for(auto& c : s)
    {
        if(c == '(')
        {
            stk.push(ret);
            ret = "";
        }
        else if(c == ')')
        {
            reverse(ret.begin(), ret.end());
            ret = stk.top() + ret;
            stk.pop();
        }
        else
            ret += c;
    }
    return ret;
}
```

#### II 预处理括号

对括号进行预处理，将每个括号对应另一半括号的下标记录  
之后，对字符串进行遍历，如果遇到括号，则从其对应括号位置进行遍历，且遍历方向改变  
完成遍历后，即可获得反转后的字符串  

```cpp
string reverseParentheses(string s) 
{
    int n = s.size();
    vector<int> counterpart(n);
    stack<int> stk;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(')
            stk.push(i);
        if(s[i] == ')')
        {
            int pair = stk.top();
            stk.pop();
            counterpart[i] = pair;
            counterpart[pair] = i;
        }
    }
    string ret;
    int index = 0;
    int step = 1;
    while(index < n)
    {
        if(s[index] == '(' || s[index] == ')')
        {
            index = counterpart[index];
            step = -step;
        }
        else
            ret += s[index];
        index += step;
    }
    return ret;
}
```
