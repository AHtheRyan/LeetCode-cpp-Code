### 队列的最大值

> 请定义一个队列并实现函数 `max_value` 得到队列里的最大值，要求函数 `max_value`、`push_back` 和 `pop_front` 的**均摊**时间复杂度都是O(1)。  
> 若队列为空，`pop_front` 和 `max_value` 需要返回 `-1`  

----------

#### I 队列 + 双端队列模拟

利用一个队列行使队列的性质，再利用一个双端队列进行最大值的保存即可  

```cpp
class MaxQueue 
{
private:
    queue<int> q;
    deque<int> maxq;

public:
    MaxQueue() 
    {}
    
    int max_value() 
    {
        if(maxq.empty())
            return -1;
        return maxq.front();
    }
    
    void push_back(int value) 
    {
        while(!maxq.empty() && value > maxq.back())
            maxq.pop_back();
        q.push(value);
        maxq.push_back(value);
    }
    
    int pop_front() 
    {
        if(q.empty())
            return -1;
        int ret = q.front();
        q.pop();
        if(ret == maxq.front())
            maxq.pop_front();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```
