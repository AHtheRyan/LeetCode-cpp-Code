### 字符串解码
### Decode String

> 给定一个经过编码的字符串，返回它解码后的字符串。  
> 编码规则为: `k[encoded_string]`，表示其中方括号内部的 `encoded_string` 正好重复 `k` 次。注意 `k` 保证为正整数。  
> 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。  
> 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 `k`，例如不会出现像 `3a` 或 `2[4]` 的输入。  

> Given an encoded string, return its decoded string.  
> The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.  
> You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.  
> Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.  

----------

#### I 栈模拟

类似于括号问题，利用栈进行模拟即可  

```cpp
string decodeString(string s) 
{
    stack<string> stk;
    int n = s.size();
    int index = 0;
    string cur = "";
    while(index < n)
    {
        if(isdigit(s[index]))
        {
            if(cur != "")
            {
                stk.push(cur);
                cur = "";
            }
            while(index < n && isdigit(s[index]))
            {
                cur += s[index];
                ++index;
            }
            stk.push(cur);
            cur = "";
        }
        else if(isalpha(s[index]))
        {
            while(index < n && isalpha(s[index]))
            {
                cur += s[index];
                ++index;
            }
        }
        else if(s[index] == '[')
            ++index;
        else if(s[index] == ']')
        {
            if(isalpha(stk.top()[0]))
            {
                cur = stk.top() + cur;
                stk.pop();
            }
            string cnt = stk.top();
            stk.pop();
            int num = 0;
            for(int i = 0; i < cnt.size(); ++i)
                num = num * 10 + cnt[i] - '0';
            string str;
            for(int i = 0; i < num; ++i)
                str += cur;
            cur = str;
            ++index;
        }
    }
    while(!stk.empty())
    {
        cur = stk.top() + cur;
        stk.pop();
    }
    return cur;
}
```
