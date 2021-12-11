### 在线选举
### Onine Election

> 给你两个整数数组 `persons` 和 `times`。在选举中，第 `i` 张票是在时刻为 `times[i]` 时投给候选人 `persons[i]` 的。  
> 对于发生在时刻 `t` 的每个查询，需要找出在 `t` 时刻在选举中领先的候选人的编号。  
> 在 `t` 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。  
> 实现 `opVotedCandidate` 类：  
> - `TopVotedCandidate(int[] persons, int[] times)` 使用 `persons` 和 `times` 数组初始化对象。  
> - `int q(int t)` 根据前面描述的规则，返回在时刻 t 在选举中领先的候选人的编号。  

> You are given two integer arrays `persons` and `times`. In an election, the `ith` vote was cast for `persons[i]` at time `times[i]`.  
> For each query at a time `t`, find the person that was leading the election at time `t`. Votes cast at time t will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.  
> Implement the `TopVotedCandidate` class:  
> - `TopVotedCandidate(int[] persons, int[] times)` Initializes the object with the `persons` and times `arrays`.  
> - `int q(int t)` Returns the number of the person that was leading the election at time `t` according to the mentioned rules.  

----------

#### I 哈希表 + 二分查找

由于 `times` 中的时间和 `persons` 中的人一一对应，因此，这里我们直接对 `persons` 中的得票情况进行计算并记录，该结果会自动与 `times` 建立映射  
对于任意时刻，可以发现，该时刻与上次投票时的领先者是对应的  
因此，可以利用哈希表记录每个人的实时得票，并与当前最高票数进行比对，如果发生变化，则记录不同的人，否则记录上一个人  
最后利用二分查找找到最接近时刻的领先者即可

```cpp
class TopVotedCandidate 
{
public:
    vector<int> top;
    vector<int> moments;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) 
    {
        moments.resize(times.size());
        copy(times.begin(), times.end(), moments.begin());
        unordered_map<int, int> cnt;
        int max = -1;
        for(auto& p : persons)
        {
            ++cnt[p];
            if(cnt[p] >= max)
            {
                max = cnt[p];
                top.push_back(p);
            }
            else
                top.push_back(top.back());
        };
    }
    
    int q(int t) 
    {
        int index = upper_bound(moments.begin(), moments.end(), t) - moments.begin() - 1;
        return top[index];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```
