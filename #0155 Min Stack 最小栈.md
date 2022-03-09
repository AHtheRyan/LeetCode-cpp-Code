### 最小栈
### Min Stack

> 设计一个支持 `push`，`pop`，`top`操作，并能在常数时间内检索到最小元素的栈。  
> 实现 `MinStack` 类:  
> - `MinStack()` 初始化堆栈对象。  
> - `void push(int val)` 将元素 `val` 推入堆栈。  
> - `void pop()` 删除堆栈顶部的元素。  
> - `int top()` 获取堆栈顶部的元素。  
> - `int getMin()` 获取堆栈中的最小元素。  

> Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.  
> Implement the `MinStack` class:  
> - `MinStack()` initializes the stack object.  
> - `void push(int val)` pushes the element `val` onto the stack.  
> - `void pop()` removes the element on the top of the stack.  
> - `int top()` gets the top element of the stack.  
> - `int getMin()` retrieves the minimum element in the stack.  

----------

#### I 双栈

采用两个栈，一个 `stk` 正常记录所有的数字，另一个 `minstk` 记录**当前最小的数字**  
即每当新入栈的元素比当前的值更小，才进入 `minstk`，  
每当元素出栈时，如果该元素与栈顶元素 `minstk` 一样，则两个栈都出，否则只有 `stk` 出栈  
这样可以实现栈内最小元素的记录  

```cpp
class MinStack 
{
private:
    stack<int> stk;
    stack<int> minstk;

public:
    MinStack() 
    {}
    
    void push(int val) 
    {
        stk.push(val);
        if(minstk.empty() || val <= minstk.top())
            minstk.push(val); 
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
    
    int getMin() 
    {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
