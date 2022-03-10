### 验证栈序列
### Validate Stack Sequences  

> 给定 `pushed` 和 `popped` 两个序列，每个序列中的**值都不重复**，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 `true`；否则，返回 `false`。  

> Given two integer arrays `pushed` and `popped` each with distinct values, return `true` *if this could have been the result of a sequence of push and pop operations on an initially empty stack, or `false` otherwise*.  

----------

#### I 栈模拟

见[栈的压入、弹出序列](./%23剑指offer%2031.%20栈的压入、弹出序列.md)  

```cpp
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    stack<int> stk;
    int index = 0;
    for(auto& num : pushed)
    {
        stk.push(num);
        while(!stk.empty() && stk.top() == popped[index])
        {
            stk.pop();
            ++index;
        }
    }
    return stk.empty();
}
```
