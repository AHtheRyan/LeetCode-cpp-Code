### 旅行终点站
### Destination City

> 给你一份旅游线路图，该线路图中的旅行线路用数组 `paths` 表示，其中 `paths[i] = [cityAi, cityBi]` 表示该线路将会从 `cityAi` 直接前往 `cityBi`。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。  
> 题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。  

> You are given the array `paths`, where `paths[i] = [cityAi, cityBi]` means there exists a direct path going from `cityAi` to `cityBi`.*Return the destination city, that is, the city without any path outgoing to another city*.  
> It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

----------

#### I 哈希表

将每个出发点和终点以哈希表的形式存储在 `map` 中，  
由于存在唯一终点，因此只需要随机取一个点开始（这里取旅游路线的第一个点），不断寻找下一个目的地，找到没有目的地的点即为旅行终点站  

```cpp
string destCity(vector<vector<string>>& paths) 
{
    unordered_map<string, string> hash;
    for(auto path : paths)
        hash[path[0]] = path[1];
    string st = paths[0][0];
    while(hash.find(st) != hash.end())
        st = hash[st];
    return st;
}
```
