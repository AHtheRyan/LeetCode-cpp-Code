### 括号生成
### Generate Parentheses

> 数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且**有效的**括号组合。

> Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

----------

#### I 回溯

同一位置出现两种可能，首先想到的就是回溯算法  
既然需要回溯，那么就有两个必要条件：
1. 迭代的返回条件
2. 状态存储

我们可以设置两个计数变量，一个计量左半括号 `'('`，一个计量 右半括号 `')'`，满足：  
- 左半括号数目小于括号对数，则可以加左半括号
- 右半括号数目小于左半，则可以加右半括号

此时，只要半括号总数为括号对数的两倍即可视为一组合法括号组合  
利用回溯进行所有可能尝试即可

```cpp
class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;
        string s = "";
        parenthesis(s, n, 0, 0, ret);
        return ret;
    }

    void parenthesis(string& s, int n, int left, int right, vector<string>& ret)
    {
        if(left + right == n * 2)
        {
            ret.push_back(s);
            return ;
        }
        if(left < n)
        {
            string tmp = s;
            s += '(';
            parenthesis(s, n, left + 1, right, ret);
            s = tmp;
        }
        if(right < left)
        {
            string tmp = s;
            s += ')';
            parenthesis(s, n, left, right + 1, ret);
            s = tmp;
        }
    }
};
```
