### 如果相邻两个颜色均相同则删除当前颜色
### Removed Colored Pieces if Both Neighbors are the Same Color

> 总共有 `n` 个颜色片段排成一列，每个颜色片段要么是 `'A'` 要么是 `'B'`。给你一个长度为 `n` 的字符串 `colors`，其中 `colors[i]` 表示第 `i` 个颜色片段的颜色。  
> Alice 和 Bob 在玩一个游戏，他们**轮流**从这个字符串中删除颜色。Alice**先手**。  
> - 如果一个颜色片段为 `'A'` 且**相邻两个颜色**都是颜色 `'A'`，那么 Alice 可以删除该颜色片段。Alice 不可以 删除任何颜色 `'B'` 片段。  
> - 如果一个颜色片段为 `'B'` 且**相邻两个颜色**都是颜色 `'B'`，那么 Bob 可以删除该颜色片段。Bob 不可以 删除任何颜色 `'A'` 片段。  
> - Alice和Bob**不能**从字符串两端删除颜色片段。  
> - 如果其中一人无法继续操作，则该玩家**输**掉游戏且另一玩家**获胜**。  
> 
> 假设 Alice 和 Bob 都采用最优策略，如果 Alice 获胜，请返回 `true`，否则 Bob 获胜，返回 `false`。  

> There are `n` pieces arranged in a line, and each piece is colored either by `'A'` or by `'B'`. You are given a string `colors` of length `n` where `colors[i]` is the color of the `ith` piece.  
> Alice and Bob are playing a game where they take **alternating turns** removing pieces from the line. In this game, Alice moves **first**.  
> - Alice is only allowed to remove a piece colored `'A'` if **both its neighbors** are also colored `'A'`. She is **not allowed** to remove pieces that are colored `'B'`.  
> - Bob is only allowed to remove a piece colored `'B'` if **both its neighbors** are also colored `'B'`. He is not allowed to remove pieces that are colored `'A'`.  
> - Alice and Bob **cannot** remove pieces from the edge of the line.  
> - If a player cannot make a move on their turn, that player **loses** and the other player **wins**.  
> 
> Assuming Alice and Bob play optimally, return *`true` if Alice wins, or return `false` if Bob wins*.  

----------

#### I 一次遍历

遍历一次数组，找出所有被同种棋子夹在中间的棋子并计数，根据胜负规则判断即可  

```cpp
bool winnerOfGame(string colors) 
{
    int cntA = 0;
    int cntB = 0;
    for(int i = 1; i < colors.size() - 1; ++i)
    {
        if(colors[i] == 'A' && colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
            ++cntA;
        if(colors[i] == 'B' && colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
            ++cntB;
    }
    return cntA > cntB;
}
```
