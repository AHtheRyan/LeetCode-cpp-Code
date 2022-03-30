### 找到处理最多请求的服务器
### Find Servers That Handled Most Number of Requests

> 你有 `k` 个服务器，编号为 `0` 到 `k-1`，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是**不能同时处理超过一个请求**。请求分配到服务器的规则如下：  
> - 第 `i` （序号从 0 开始）个请求到达。  
> - 如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。  
> - 如果第 (`i % k`) 个服务器空闲，那么对应服务器会处理该请求。  
> - 否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。比方说，如果第 `i` 个服务器在忙，那么会查看第 `(i+1)` 个服务器，第 `(i+2)` 个服务器等等。  
> 
> 给你一个**严格递增**的正整数数组 `arrival`，表示第 `i` 个任务的到达时间，和另一个数组 `load`，其中 `load[i]` 表示第 `i` 个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到**最繁忙的服务器**。最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。  
> 请你返回包含所有**最繁忙服务器**序号的列表，你可以以任意顺序返回这个列表。  

> You have `k` servers numbered from `0` to `k-1` that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but **cannot handle more than one request at a time**. The requests are assigned to servers according to a specific algorithm:  
> - The `ith` (0-indexed) request arrives.  
> - If all servers are busy, the request is dropped (not handled at all).  
> - If the `(i % k)th` server is available, assign the request to that server.  
> - Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the `ith` server is busy, try to assign the request to the `(i+1)th` server, then the `(i+2)th` server, and so on.  
> 
> You are given a **strictly increasing** array `arrival` of positive integers, where `arrival[i]` represents the arrival time of the `ith` request, and another array `load`, where `load[i]` represents the load of the ith request (the time it takes to complete). Your goal is to find the **busiest server(s)**. A server is considered **busiest** if it handled the most number of requests successfully among all the servers.  
> Return *a list containing the IDs (0-indexed) of the **busiest server(s)**. You may return the IDs in any order*.  

----------

#### I 优先队列

利用优先队列对处理时间进行排序，分别采用两个队列记录空闲服务器和不空闲服务器及其结束时间，再对每个请求进行匹配即可  

```cpp
vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) 
{
    vector<int> ret;
    priority_queue<int, vector<int>, greater<int>> available;
    for(int i = 0; i < k; ++i)
        available.push(i);
    vector<int> request(k, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy; 
    for(int i = 0; i < arrival.size(); ++i)
    {
        while(!busy.empty() && busy.top().first <= arrival[i])
        {
            auto [time, id] = busy.top();
            busy.pop();
            available.push(i + ((id - i) % k + k) % k);
        }
        if(available.empty())
            continue;
        int id = available.top() % k;
        available.pop();
        ++request[id];
        busy.push({arrival[i] + load[i], id});
    }
    int maxrequest = *max_element(request.begin(), request.end());
    for(int i = 0; i < k; ++i)
        if(maxrequest == request[i])
            ret.emplace_back(i);
    return ret;
}
```
