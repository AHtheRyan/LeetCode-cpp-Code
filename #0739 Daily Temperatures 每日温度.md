### 每日温度
### Daily Temperatures

> 给定一个整数数组 `temperatures`，表示每天的温度，返回一个数组 `answer`，其中 `answer[i]` 是指在第 `i` 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。  

> Given an array of integers `temperatures` represents the daily temperatures, return *an array `answer` such that `answer[i]` is the number of days you have to wait after the `ith` day to get a warmer temperature*. If there is no future day for which this is possible, keep `answer[i] == 0` instead.  

----------

#### I 单调栈

简单单调栈

```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    int n = temperatures.size();
    stack<int> stk;
    vector<int> ret(n);
    for(int i = n - 1; i >= 0; --i)
    {
        while(!stk.empty() && temperatures[stk.top()] <= temperatures[i])
            stk.pop();
        if(stk.empty())
            ret[i] = 0;
        else
            ret[i] = stk.top() - i;
        stk.push(i);
    }
    return ret;
}
```
