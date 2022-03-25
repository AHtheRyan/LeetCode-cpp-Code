### 棒球比赛
### Baseball Game

> 你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。  
> 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 `ops`，其中 `ops[i]` 是你需要记录的第 `i` 项操作，`ops` 遵循下述规则：  
> 1. 整数 `x` - 表示本回合新获得分数 `x`  
> 2. `"+"` - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。  
> 3. `"D"` - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。  
> 4. `"C"` - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。  
> 
> 请你返回记录中所有得分的总和。  

> You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.  
> At the beginning of the game, you start with an empty record. You are given a list of strings `ops`, where `ops[i]` is the `ith` operation you must apply to the record and is one of the following:  
> An integer `x` - Record a new score of `x`.  
> `"+"` - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.  
> `"D"` - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.  
> `"C"` - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.  
> 
> Return *the sum of all the scores on the record*.  

----------

#### I 模拟

以数组模拟栈的运作并把相关的过程推进即可  

```cpp
int calPoints(vector<string>& ops) 
{
    int ret = 0;
    vector<int> score;
    for(auto& op : ops)
    {
        int n = score.size();
        switch(op[0])
        {
            case 'C':
                ret -= score[n - 1];
                score.pop_back();
                break;
            case 'D':
                ret += score[n - 1] * 2;
                score.push_back(score[n - 1] * 2);
                break;
            case '+':
                ret += score[n - 1] + score[n - 2];
                score.push_back(score[n - 1] + score[n - 2]);
                break;
            default:
                score.push_back(stoi(op));
                ret += score[n];
                break;
        }
    }
    return ret;
}
```
