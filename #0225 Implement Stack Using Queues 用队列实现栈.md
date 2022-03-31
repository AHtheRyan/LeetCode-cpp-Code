### 用队列实现栈
### Implement Stack Using Queues

> 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。  
> 实现 `MyStack` 类：  
> - `void push(int x)` 将元素 `x` 压入栈顶。  
> - `int pop()` 移除并返回栈顶元素。  
> - `int top()` 返回栈顶元素。  
> - `boolean empty()` 如果栈是空的，返回 `true`；否则，返回 `false`。  

> Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).  
> Implement the `MyStack` class:  
> - `void push(int x)` Pushes element x to the top of the stack.  
> - `int pop()` Removes the element on the top of the stack and returns it.  
> - `int top()` Returns the element on the top of the stack.  
> - `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.  

----------

#### I 模拟

利用一个队列保存新元素，之后将另一个队列的所有元素依次放在保存新元素的队列中，可以让元素的顺序保持为**最新的元素始终在队列最前端**，从而实现栈的模拟  

```cpp
class MyStack 
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() 
    {
        while(!q1.empty())
            q1.pop();
        while(!q2.empty())
            q2.pop();
    }
    
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() 
    {
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    int top() 
    {
        int ret = q1.front();
        return ret;
    }
    
    bool empty() 
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
