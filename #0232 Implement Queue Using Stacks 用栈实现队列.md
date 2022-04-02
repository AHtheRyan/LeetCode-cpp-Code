### 用栈实现队列
### Implement Queue Using Stacks

> 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：  
> 实现 `MyQueue` 类：  
> - `void push(int x)` 将元素 `x` 推到队列的末尾  
> - `int pop()` 从队列的开头移除并返回元素  
> - `int peek()` 返回队列开头的元素  
> - `boolean empty()` 如果队列为空，返回 `true`；否则，返回 `false`  

> Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).  
> Implement the MyQueue class:  
> - `void push(int x)` Pushes element x to the back of the queue.  
> - `int pop()` Removes the element from the front of the queue and returns it.  
> - `int peek()` Returns the element at the front of the queue.  
> - `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.  

----------

#### I 简单模拟

将数字在两个栈中来回倒一次就可以实现先进后出的规律  

```cpp
class MyQueue 
{
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    MyQueue() 
    {}
    
    void push(int x) 
    {
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    int pop() 
    {
        int ret = stk1.top();
        stk1.pop();
        return ret;
    }
    
    int peek() 
    {
        return stk1.top();
    }
    
    bool empty() 
    {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
