### 有效的括号
### Valid Parentheses

> 给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s`，判断字符串是否有效。  
> 有效字符串需满足：  
> 1. 左括号必须用相同类型的右括号闭合。  
> 2. 左括号必须以正确的顺序闭合。  

> Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.  
> An input string is valid if:  
> 1. Open brackets must be closed by the same type of brackets.  
> 2. Open brackets must be closed in the correct order.  

----------

#### I 栈

利用栈的基本规则：  
- 栈为空或者字符为左半括号，则字符入栈
- 字符与栈顶匹配，则字符出栈

最后根据栈是否为空输出结果即可

```cpp
class Solution 
{
public:
    unordered_map<char, char> parentheses
    {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };

    bool isValid(string s)
    {
        stack<char> stk;
        for(auto c : s)
        {
            if(stk.empty() || c == '(' || c == '{' || c == '[')
                stk.push(c);
            else if(parentheses[stk.top()] == c)
                stk.pop();
            else
                return false;
        }
        return stk.empty();
    }
};
```
