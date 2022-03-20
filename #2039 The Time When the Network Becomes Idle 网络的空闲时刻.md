### 网络空闲的时刻
### The Time When the Network Becomes Idle

> 给你一个有 `n` 个服务器的计算机网络，服务器编号为 `0` 到 `n - 1`。同时给你一个二维整数数组 `edges`，其中 `edges[i] = [ui, vi]` 表示服务器 `ui` 和 `vi` 之间有一条信息线路，在**一秒**内它们之间可以传输**任意**数目的信息。再给你一个长度为 `n` 且下标从**0**开始的整数数组 `patience`。  
> 题目保证所有服务器都是**相通**的，也就是说一个信息从任意服务器出发，都可以通过这些信息线路直接或间接地到达任何其他服务器。  
> 编号为 `0` 的服务器是**主**服务器，其他服务器为**数据**服务器。每个数据服务器都要向主服务器发送信息，并等待回复。信息在服务器之间按**最优**线路传输，也就是说每个信息都会以**最少时间**到达主服务器。主服务器会处理**所有**新到达的信息并**立即**按照每条信息来时的路线**反方向**发送回复信息。  
> 在 `0` 秒的开始，所有数据服务器都会发送各自需要处理的信息。从第 `1` 秒开始，每 一秒最**开始**时，每个数据服务器都会检查它是否收到了主服务器的回复信息（包括新发出信息的回复信息）：  
> - 如果还没收到任何回复信息，那么该服务器会周期性**重发**信息。数据服务器 `i` 每 `patience[i]` 秒都会重发一条信息，也就是说，数据服务器 `i` 在上一次发送信息给主服务器后的 `patience[i]` 秒**后**会重发一条信息给主服务器。  
> - 否则，该数据服务器**不会重发**信息。  
> 
> 当没有任何信息在线路上传输或者到达某服务器时，该计算机网络变为**空闲**状态。  
> 请返回计算机网络变为**空闲**状态的**最早秒数**。  

> There is a network of `n` servers, labeled from `0` to `n - 1`. You are given a 2D integer array `edges`, where `edges[i] = [ui, vi]` indicates there is a message channel between servers `ui` and `vi`, and they can pass **any** number of messages to **each other** directly in **one** second. You are also given a **0-indexed** integer array `patience` of length `n`.  
> All servers are **connected**, i.e., a message can be passed from one server to any other server(s) directly or indirectly through the message channels.  
> The server labeled `0` is the **master** server. The rest are **data** servers. Each data server needs to send its message to the master server for processing and wait for a reply. Messages move between servers **optimally**, so every message takes the **least amount of time** to arrive at the master server. The master server will process all newly arrived messages **instantly** and send a reply to the originating server via the **reversed path** the message had gone through.  
> At the beginning of second `0`, each data server sends its message to be processed. Starting from second `1`, at the **beginning** of **every** second, each data server will check if it has received a reply to the message it sent (including any newly arrived replies) from the master server:  
> - If it has not, it will **resend** the message periodically. The data server `i` will resend the message every `patience[i]` second(s), i.e., the data server `i` will resend the message if `patience[i]` second(s) have **elapsed** since the **last** time the message was sent from this server.  
> - Otherwise, **no more resending** will occur from this server.  
> 
> The network becomes **idle** when there are **no** messages passing between servers or arriving at servers.  
> Return *the **earliest second** starting from which the network becomes **idle***.  

----------

#### I 广度优先搜索

利用哈希表确定所有服务器之间的连接关系，接着利用队列，逐层确定与 `0` 号服务器距离为 `1 ~ n` 的服务器个数  
接着，遍历每个服务器确定发送的时间，最后返回总时长最长的服务器即可  

```cpp
int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) 
{
    int n = patience.size();
    vector<vector<int>> mp(n);
    vector<int> distance(n, 0);
    for(auto& edge : edges)
    {
        mp[edge[0]].emplace_back(edge[1]);
        mp[edge[1]].emplace_back(edge[0]);
    }
    queue<int> q;
    q.push(0);
    int layer = 0;
    while(!q.empty())
    {
        int size = q.size();
        ++layer;
        for(int k = 0; k < size; ++k)
        {
            int cur = q.front();
            q.pop();
            for(int i = 0; i < mp[cur].size(); ++i)
            {
                if(distance[mp[cur][i]] == 0)
                {
                    q.emplace(mp[cur][i]);
                    distance[mp[cur][i]] = layer;
                }
            }
        }
    }
    int ret = 0;
    for(int i = 1; i < n; ++i)
    {
        int cur = distance[i] * 2 + 1 + patience[i] * ((2 * distance[i] - 1) / patience[i]);
        ret = max(ret, cur);
    }
    return ret;
}
```
