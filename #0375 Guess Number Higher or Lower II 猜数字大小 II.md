### 猜数字大小II
### Guess Number Higher or Lower II

> 我们正在玩一个猜数游戏，游戏规则如下：  
> 1. 我从 `1` 到 `n` 之间选择一个数字。  
> 2. 你来猜我选了哪个数字。  
> 3. 如果你猜到正确的数字，就会 赢得游戏 。  
> 4. 如果你猜错了，那么我会告诉你，我选的数字比你的 **更大或者更小**，并且你需要继续猜数。  
> 5. 每当你猜了数字 `x` 并且猜错了的时候，你需要支付金额为 `x` 的现金。如果你花光了钱，就会 **输掉游戏**。  
> 
> 给你一个特定的数字 `n`，返回能够 **确保你获胜** 的最小现金数，**不管我选择那个数字**。  

> We are playing the Guessing Game. The game will work as follows:  
> 1. I pick a number between `1` and `n`.  
> 2. You guess a number.  
> 3. If you guess the right number, **you win the game**.  
> 4. If you guess the wrong number, then I will tell you whether the number I picked is **higher or lower**, and you will continue guessing.  
> 5. Every time you guess a wrong number `x`, you will pay `x` dollars. If you run out of money, **you lose the game**.  
> 
> Given a particular `n`, return *the minimum amount of money you need to **guarantee a win regardless of what number I pick***.  

----------

#### I 动态规划

先对较小的数字进行猜数模拟，寻找规律：
| n | 最坏情况下的最小开销 |
| --- | --- |
| 1 | 0 |
| 2 | 1 |
| 3 | 2 |
| 4 | 4 |
| 5 | 6 |

这样看不太好找规律，我们分析一下每个数字的最小开销寻找过程（最小开销以 `min(x, y)` 代替，`x` `y` 分别指代数字区间的左右节点）：
- 数字 1：直接猜数字 `1` 即可，为 `min(1, 1) = 0`
- 数字 2：可以猜数字 `1` 或者 `2`，都只需要猜一次，最小开销为 `min(1, 2) = 1`
- 数字 3：
  - 如果猜数字 `1`，则考虑还要再从 `2` 和 `3` 中考虑一次，这样最小开销为 `1 + min(2, 3)`，可以计算 `min(2, 3) = 2`，规则同上，则结果为 `1 + 2 = 3`    
  - 如果猜数字 `2`，则不需要进一步考虑，这样最小开销为 `2 + max(min(1, 1) + min(3, 3))`  
  - 如果猜数字 `3`，则考虑还要再从 `1` 和 `2` 中考虑一次，这样最小开销为 `3 + min(1, 2)`，根据上面的结果，为 `3 + 1 = 4`  

由此可见，实际的开销计算可以被分解为 `当前考虑的数字 + max(当前考虑的数字前面的数组最小开销， 当前考虑的数字后面的数组最小开销)`  
而前后的开销可以根据前面的内容直接获得，故考虑用动态规划解决  
根据上面的规律可以看到，对于数字范围到 `m ~ n` 的最小开销寻找，当我们先选数字 `k`，则所需要的开销为 `k` + (`m ~ k-1` 和 `k+1 ~ n`中的较大者)  
显然数字范围越短越好找，可以按长度为 `1 -> 2 -> 3 -> ...` 的次序进行动态规划  

```cpp
int getMoneyAmount(int n) 
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int row = n - 1; row > 0; --row)
    {
        for(int col = row + 1; col <= n; ++col)
        {
            int money = INT_MAX;
            for(int k = row; k < col; ++k)
            {
                int cur = k + max(dp[k + 1][col], dp[row][k - 1]);
                money = min(money, cur);
            }
            dp[row][col] = money;
        }
    }
    return dp[1][n];
}
```
