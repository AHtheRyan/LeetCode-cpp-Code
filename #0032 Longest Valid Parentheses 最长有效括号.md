### 最长有效括号
### Longest Valid Parentheses

> 给你一个只包含 `'('` 和 `')'` 的字符串，找出最长有效（格式正确且连续）括号子串的长度。  

> Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.  

----------

#### I 栈

显然，可以利用栈进行括号匹配，  
考虑 `'('` 和 `')'` 两种情况：  
1. 如果当前为 `')'`，则需要判断是否有括号在栈内进行匹配
   - 如果有，则可以将其弹出，计算当前子串长
   - 如果没有，则此时子串中断
2. 如果当前为 `'('`，则直接将其堆入栈中，等待匹配

```cpp
int longestValidParentheses(string s) 
{
    stack<int> stk;
    int max = 0;
    stk.push(-1);
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(')
            stk.push(i);
        else
            stk.pop();
        if(stk.empty())
            stk.push(i);
        else
            max = max > i - stk.top() ? max : i - stk.top();
    }
    return max;
} 
```
