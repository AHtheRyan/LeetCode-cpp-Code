### 迷你语法分析器
### Mini Parser

> 给定一个字符串 `s` 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 `NestedInteger`。  
> 列表中的每个元素只可能是整数或整数嵌套列表  

> Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized `NestedInteger`.  
> Each element is either an integer or a list whose elements may also be integers or other lists.  

----------

#### I 基于栈的DFS

本体的重点在于读懂  
这里的 `NestedInteger` 可以类比成 `vector<num>`，这样的话，`[2,[3]]` 可以理解为 `{2, {3}}`
我们需要做的事情是把每层的中括号展开，将里面的字符串变为数字的形式，可以利用递归或者基于栈的DFS完成转化工作  

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution 
{
public:
    NestedInteger deserialize(string s) 
    {
        if(s[0] != '[')
            return NestedInteger(stoi(s));
        stack<NestedInteger> stk;
        int num = 0;
        bool negative = false;
        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(c == '-')
                negative = true;
            else if(c == '[')
                stk.emplace(NestedInteger());
            else if(isdigit(c))
                num = num * 10 + c - '0';
            else if(c == ',' || c == ']')
            {
                if(isdigit(s[i - 1]))
                {
                    if(negative)
                        num *= -1;
                    stk.top().add(NestedInteger(num));
                }
                num = 0;
                negative = false;
                if(c == ']' && stk.size() > 1)
                {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
            }
        }
        return stk.top();
    }
};
```
