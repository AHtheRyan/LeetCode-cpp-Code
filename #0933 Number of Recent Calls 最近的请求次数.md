### 最近的请求次数
### Number of Recent Calls

> 写一个 `RecentCounter` 类来计算特定时间范围内最近的请求。  
> 请你实现 `RecentCounter` 类：  
> - `RecentCounter()` 初始化计数器，请求数为 `0`。  
> - `int ping(int t)` 在时间 `t` 添加一个新请求，其中 `t` 表示以毫秒为单位的某个时间，并返回过去 `3000` 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 `[t-3000, t]` 内发生的请求数。  
> 
> **保证**每次对 `ping` 的调用都使用比之前更大的 `t` 值。  

> You have a `RecentCounter` class which counts the number of recent requests within a certain time frame.  
> Implement the `RecentCounter` class:  
> - `RecentCounter()` Initializes the counter with zero recent requests.  
> - `int ping(int t)` Adds a new request at time `t`, where `t` represents some time in milliseconds, and returns the number of requests that has happened in the past `3000` milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range `[t - 3000, t]`.  
> 
> It is **guaranteed** that every call to `ping` uses a strictly larger value of `t` than the previous call.  

----------

#### I 队列

简单队列，每次将超时的请求记录出队列，再将队列中的请求总数返回即可  

```cpp
class RecentCounter 
{
public:
    RecentCounter() 
    {}
    
    int ping(int t) 
    {
        time.push(t);
        int cmp = t - 3000;
        while(time .front() < cmp)
            time.pop();
        return time.size();
    }

private:
    queue<int> time;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```
