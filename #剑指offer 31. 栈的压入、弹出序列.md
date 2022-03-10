### 栈的压入、弹出序列

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。  

----------

#### I 栈模拟

按照 `pushed` 的顺序将元素入栈，每入栈一个元素，就根据 `popped` 验证栈顶与 `poped` 当前顺次的数字是否相等：  
- 如果相等就出栈并循环判断  
- 如果不等就继续将 `pushed` 指向的新元素入栈重复判断   

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
