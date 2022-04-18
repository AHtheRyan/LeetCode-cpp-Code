### 火柴拼正方形
### Matchsticks to Square

> 你将得到一个整数数组 `matchsticks`，其中 `matchsticks[i]` 是第 `i` 个火柴棒的长度。你要用**所有的火柴棍**拼成一个正方形。你**不能折断**任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须**使用一次**。  
> 如果你能使这个正方形，则返回 `true`，否则返回 `false`。  

> You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.  
> Return `true` if you can make this square and `false` otherwise.  

----------

#### I 回溯

设置一个长度为 `4` 的数组，记录每个边的长度，进行回溯时，依次将每个数字加到四条边的其中一条，加完之后比较每条边的长度即可  

```cpp
class Solution 
{
public:
    int l[4] = {0, 0, 0, 0};
    int n;
    int possibleL;

    bool makesquare(vector<int>& matchsticks) 
    {
        this->n = matchsticks.size();
        if(n <= 3)
            return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4)
            return false;
        this->possibleL = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), [&](const int a, const int b){return a > b;});
        return divide(0, matchsticks);
    }

    bool divide(int index, vector<int>& matchsticks)
    {
        if(index >= n)
            return l[0] == l[1] && l[1] == l[2] && l[2] == l[3];
        for(int i = 0; i < 4; ++i)
        {
            if(l[i] + matchsticks[index] > possibleL)    continue;
            l[i] += matchsticks[index];
            if(divide(index + 1, matchsticks))  return true;
            l[i] -= matchsticks[index];
        }
        return false;
    }
};
```
