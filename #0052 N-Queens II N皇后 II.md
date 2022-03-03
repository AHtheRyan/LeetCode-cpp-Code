### N皇后 II
### N-Queens II

> **n 皇后问题**研究的是如何将 `n` 个皇后放置在 `n × n` 的棋盘上，并且使皇后彼此之间不能相互攻击。  
> 给你一个整数 `n`，返回**n 皇后问题**不同的解决方案的数量。  

> The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.  
> Given an integer `n`, return *the number of distinct solutions to the **n-queens puzzle***.  

----------

#### I 回溯

与 [N皇后](./%230051%20N-Queens%20N皇后.md) 问题几乎没有任何区别  

```cpp
class Solution 
{
private:
    vector<bool> col;
    vector<bool> leftDiag;
    vector<bool> rightDiag;

public:
    int totalNQueens(int n) 
    {
        col.resize(n);
        leftDiag.resize(2 * n - 1);
        rightDiag.resize(2 * n - 1);
        vector<vector<string>> ret;
        vector<string> cur(n, string(n, '.'));
        return backTrack(ret, cur, 0, n);
    }

    int backTrack(vector<vector<string>>& ret, vector<string>& cur, int line, int n)
    {
        if(line == n)
            return 1;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(col[i] || leftDiag[line + i] || rightDiag[i - line + n - 1])
                continue;
            col[i] = true;
            leftDiag[line + i] = true;
            rightDiag[i - line + n - 1] = true;
            cur[line][i] = 'Q';
            ans += backTrack(ret, cur, line + 1, n);
            cur[line][i] = '.';
            rightDiag[i - line + n - 1] = false;
            leftDiag[line + i] = false;
            col[i] = false;
        }
        return ans;
    }
};
```
