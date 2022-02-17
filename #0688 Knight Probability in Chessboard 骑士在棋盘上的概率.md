### 骑士在棋盘上的概率
### Knight Probability in Chessboard

> 在一个 `n x n` 的国际象棋棋盘上，一个骑士从单元格 `(row, column)` 开始，并尝试进行 `k` 次移动。行和列是**从 0 开始**的，所以左上单元格是 `(0,0)`，右下单元格是 `(n - 1, n - 1)`。  
> 象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。  
![image](https://user-images.githubusercontent.com/46887748/154443059-e3bac60d-1dd4-482b-ae47-5ec62b7a0e82.png)  
> 每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。  
> 骑士继续移动，直到它走了 `k` 步或离开了棋盘。  
> 返回*骑士在棋盘停止移动后仍留在棋盘上的概率*。  

> On an `n x n` chessboard, a knight starts at the cell `(row, column)` and attempts to make exactly `k` moves. The rows and columns are **0-indexed**, so the top-left cell is `(0, 0)`, and the bottom-right cell is `(n - 1, n - 1)`.  
> A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.  
![image](https://user-images.githubusercontent.com/46887748/154443059-e3bac60d-1dd4-482b-ae47-5ec62b7a0e82.png)  
> Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.  
> The knight continues moving until it has made exactly `k` moves or has moved off the chessboard.  
> Return *the probability that the knight remains on the board after it has stopped moving*.

----------

#### I 动态规划

显然，第 `n` 步时棋子落在棋盘的概率取决于第 `n - 1` 步时棋子所在的位置，因此，第 `k` 步的棋子能落在棋盘上的概率取决于前面每一步的积累  
因此，可以利用动态规划，计算从第一步起每步的棋子落在棋盘内的概率，最后即可获得第 `k` 步时的概率

```cpp
class Solution 
{
public:
    vector<int> direction {-2, 1, 2, -1, -2, -1, 2, 1, -2};

    double knightProbability(int n, int k, int row, int column) 
    {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for(int step = 0; step <= k; ++step)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(step == 0)
                        dp[step][i][j] = 1;
                    else
                    {
                        for(int d = 0; d < 8; ++d)
                        {
                            int x = i + direction[d];
                            int y = j + direction[d + 1];
                            if(x >= 0 && x < n && y >= 0 && y < n)
                                dp[step][i][j] += dp[step - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};
```
