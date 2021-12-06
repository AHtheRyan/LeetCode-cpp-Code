### 相对名次
### Relative Ranks

> 给你一个长度为 `n` 的整数数组 `score`，其中 `score[i]` 是第 `i` 位运动员在比赛中的得分。所有得分都 **互不相同**。  
> 运动员将根据得分 **决定名次**，其中名次第 `1` 的运动员得分最高，名次第 `2` 的运动员得分第 `2` 高，依此类推。运动员的名次决定了他们的获奖情况：  
> - 名次第 `1` 的运动员获金牌 `"Gold Medal"`。  
> - 名次第 `2` 的运动员获银牌 `"Silver Medal"`  
> - 名次第 `3` 的运动员获铜牌 `"Bronze Medal"`。  
> - 从名次第 `4` 到第 `n` 的运动员，只能获得他们的名次编号（即，名次第 `x` 的运动员获得编号 `"x"`）。  
> 
> 使用长度为 `n` 的数组 `answer` 返回获奖，其中 `answer[i]` 是第 `i` 位运动员的获奖情况。  

> You are given an integer array `score` of size n, where `score[i]` is the score of the `ith` athlete in a competition. All the scores are guaranteed to be **unique**.  
> The athletes are **placed** based on their scores, where the `1st` place athlete has the highest score, the `2nd` place athlete has the `2nd` highest score, and so on. The placement of each athlete determines their rank:  
> - The `1st` place athlete's rank is `"Gold Medal"`.  
> - The `2nd` place athlete's rank is `"Silver Medal"`.  
> - The `3rd` place athlete's rank is `"Bronze Medal"`.  
> - For the `4th` place to the `nth` place athlete, their rank is their placement number (i.e., the `xth` place athlete's rank is `"x"`).  
> 
> Return an array `answer` of size `n` where `answer[i]` is the **rank** of the ith athlete.

----------

#### I 哈希表

可以先记录下每个分数可以获得的名次，  
再按照原来的人的顺序将名次依次记录即可，  
因此，可以利用哈希表进行相关记录  

```cpp
vector<string> findRelativeRanks(vector<int>& score) 
{
    vector<int> process(score.size());
    copy(score.begin(), score.end(), process.begin());
    sort(process.begin(), process.end(), [&](int a, int b){return a > b;});
    unordered_map<int, int> rec;
    for(int i = 0; i < process.size(); ++i)
        rec[process[i]] = i + 1;
    vector<string> ret;
    for(int i = 0; i < score.size(); ++i)
    {
        if(rec[score[i]] == 1)
            ret.push_back("Gold Medal");
        else if(rec[score[i]] == 2)
            ret.push_back("Silver Medal");
        else if(rec[score[i]] == 3)
            ret.push_back("Bronze Medal");
        else
            ret.push_back(to_string(rec[score[i]]));
    }
    return ret;
}
```
