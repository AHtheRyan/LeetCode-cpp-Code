### 翻转游戏
### Flip Game

> 你和朋友玩一个叫做「翻转游戏」的游戏。游戏规则如下：  
> 给你一个字符串 `currentState`，其中只含 `'+'` 和 `'-'`。你和朋友轮流将**连续**的两个 `"++"` 反转成 `"--"`。当一方无法进行有效的翻转时便意味着游戏结束，则另一方获胜。  
> 计算并返回**一次有效操作**后，字符串 `currentState` 所有的可能状态，返回结果可以按**任意顺序**排列。如果不存在可能的有效操作，请返回一个空列表 `[]`。  

> You are playing a Flip Game with your friend.  
> You are given a string `currentState` that contains only `'+'` and `'-'`. You and your friend take turns to flip **two consecutive** `"++"` into `"--"`. The game ends when a person can no longer make a move, and therefore the other person will be the winner.  
> Return all possible states of the string `currentState` after **one valid move**. You may return the answer in **any order**. If there is no valid move, return an empty list `[]`.  

----------

#### I 一次遍历模拟

遍历字符串，如果发现有连续的 `'+'` 就更改并记录即可  

```cpp
vector<string> generatePossibleNextMoves(string currentState) 
{
    int n = currentState.size();
    if(n <= 1)
        return {};
    vector<string> ret;
    for(int i = 0; i < n; ++i)
    {
        if(currentState[i] == '+')
        {
            if(i > 0 && currentState[i - 1] == '+')
            {
                string cur = currentState;
                cur[i] = cur[i - 1] = '-';
                ret.emplace_back(cur);
            }
        }
    }
    return ret;
}
```
