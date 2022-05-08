### 最小基因变化
### Minimum Genetic Mutation

> 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 `'A'`、`'C'`、`'G'` 和 `'T'` 之一。  
> 假设我们需要调查从基因序列 `start` 变为 `end` 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。  
> - 例如，`"AACCGGTT" --> "AACCGGTA"` 就是一次基因变化。  
> 
> 另有一个基因库 `bank` 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。  
> 给你两个基因序列 `start` 和 `end`，以及一个基因库 `bank`，请你找出并返回能够使 `start` 变化为 `end` 所需的最少变化次数。如果无法完成此基因变化，返回 `-1`。  
> 注意：起始基因序列 `start` 默认是有效的，但是它并不一定会出现在基因库中。  

> A gene string can be represented by an 8-character long string, with choices from `'A'`, `'C'`, `'G'`, and `'T'`.  
> Suppose we need to investigate a mutation from a gene string `start` to a gene string `end` where one mutation is defined as one single character changed in the gene string.  
> - For example, `"AACCGGTT" --> "AACCGGTA"` is one mutation.  
> 
> There is also a gene bank `bank` that records all the valid gene mutations. A gene must be in `bank` to make it a valid gene string.  
> Given the two gene strings `start` and `end` and the gene bank `bank`, return *the minimum number of mutations needed to mutate from `start` to `end`*. If there is no such a mutation, return `-1`.  
> Note that the starting point is assumed to be valid, so it might not be included in the bank.  

----------

#### I BFS + 哈希

判断从 `start` 开始的每个字符串是否与当前字符串只差一个字符，如果是就记录，并将其标记为 `checked`  
利用此方法不断更新当前字符串，知道所有字符串都被遍历或者出现 `end` 即可  

```cpp
int minMutation(string start, string end, vector<string>& bank) 
{
    if(start == end)
        return 0;
    int n = bank.size();
    unordered_set<string> checked;
    unordered_set<string> st;
    for(auto& gene : bank)
        st.insert(gene);
    if(!st.count(end))
        return -1;
    int ret = 0;
    char key[4] = {'A', 'C', 'G', 'T'};
    queue<string> q;
    q.push(start);
    while(!q.empty())
    {
        ++ret;
        int m = q.size();
        for(int k = 0; k < m; ++k)
        {
            auto cur = q.front();
            q.pop();
            checked.emplace(cur);
            for(int i = 0; i < 8; ++i)
            {
                for(int j = 0; j < 4; ++j)
                {
                    if(cur[i] != key[j])
                    {
                        string next = cur;
                        next[i] = key[j];
                        if(next == end)
                            return ret;
                        else if(st.count(next) && !checked.count(next))
                            q.emplace(next);
                    }
                }
            }
        }
    }
return -1;
}
```
