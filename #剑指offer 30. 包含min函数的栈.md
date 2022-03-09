### 包含min函数的栈

> 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。  

----------

#### I 双栈

见[最小栈](./%230155%20Min%20Stack%20最小栈.md)

```cpp
class MinStack 
{
private:
    stack<int> stk;
    stack<int> minstk;

public:
    /** initialize your data structure here. */
    MinStack()
    {}
    
    void push(int x) 
    {
        stk.push(x);
        if(minstk.empty() || x <= minstk.top())
            minstk.push(x); 
    }
    
    void pop() 
    {
        if(stk.top() == minstk.top())
            minstk.pop();
        stk.pop();
    }
    
    int top() 
    {
        return stk.top();
    }
    
    int min() 
    {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```
