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
   - 如果没有，则此时子串中断，将栈底更新为当前阻断的 `')'` 的位置  
2. 如果当前为 `'('`，则直接将其堆入栈中，等待匹配  

**注意**：只有实时更新最长子串才能考虑完全  

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
#### II 动态规划

显然，某个位置的最长有效括号子串的长度与之前的长度都有关，这里我们可以才用动态规划的方式  
考虑过程如下：
1. 如果当前位置为 `'('`，则不需要考虑子串长度，肯定为 `0`  
2. 如果当前位置为 `')'`，则
   - 如果上一个位置为 `'('`，则此时必然能形成一对括号，子串长度至少为 `2`，再考虑 `'('` 之前的字串长度，则当前位置的字串长度为两者加和 `dp[i -2] + 2`  
   - 如果上一个位置为 `')'`，则此时形成括号的条件是：**在当前位置与前面合法子串长度成对称位置的位置为 `'('`**  
     例如，对 `"((((()))))"`，如果考虑到了最后一个 `')'`（假定下标为 `i`），则此时考虑的对应位置为 `i - dp[i - 1] - 1`，即为最左端的 `'('`的位置  
     再考虑左侧括号左侧的子串长度，则当前位置的子串长度为 `dp[i - dp[i - 1] - 2 + 2 + dp[i - 1]`  
     其中，`2` 是新增的括号对，`dp[i - 1]` 是被新增括号对囊括的子串，`dp[i - dp[i - 1] - 2]` 是新增括号对左侧的最长子串的长度  

根据上述规则，即可求得最长子串的值  

```cpp
 int longestValidParentheses(string s) 
 {
     int n = s.size();
     int max = 0;
     vector<int> dp(n, 0);
     for(int i = 1; i < n; ++i)
     {
         if(s[i] == ')')
         {
             if(s[i - 1] == '(')
                 dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
             else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                 dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
         }
         max = max > dp[i] ? max : dp[i];
     }
     return max;
 }
```
