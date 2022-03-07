### 用两个栈实现队列

> 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 `appendTail` 和 `deleteHead`，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，`deleteHead` 操作返回 `-1`)  

----------

#### I 双栈

队列的运作方式为，先进后出，因此，为了用栈模拟，可以一个栈行使进的功能，一个栈行使出的功能  
对于进的栈 `stk1`，每当有新元素，则直接将其堆入 `stk1` 即可  
对于出的栈 `stk2`，每当有元素需要出队列，对 `stk2` 进行判断：  
- 如果 `stk1` 和 `stk2` 为空栈，说明当前队列为空，直接返回 `-1`  
- 如果 `stk1` 不为空而 `stk2` 为空，可将 `stk1` 中的元素依次出栈并堆入 `stk2`，再将 `stk2` 最上层的元素出栈返回即可  
- 如果 `stk2` 不为空，则直接将 `stk2` 的元素出栈即可，因为此时 `stk2` 中包含的元素已经是入栈的元素倒序了   

```cpp
class CQueue 
{
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    CQueue() 
    {}
    
    void appendTail(int value) 
    {
        stk1.push(value);
    }
    
    int deleteHead() 
    {
        if(stk2.empty())
        {
            if(stk1.empty())
                return -1;
            while(!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int ret = stk2.top();
        stk2.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```
