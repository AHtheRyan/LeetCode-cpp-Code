### N皇后
### N-Queens

> n 皇后问题 研究的是如何将 `n` 个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。  
> 给你一个整数 `n` ，返回所有不同的 **n皇后问题** 的解决方案。  
> 每一种解法包含一个不同的 `n` 皇后问题 的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。  

> The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.  
> Given an integer `n`, return *all distinct solutions to the n-queens puzzle*. You may return the answer in **any order**.  
> Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.  

----------

#### I 回溯算法

可以从棋盘的第一行开始，依次在每一列放入棋子，再判断下面的行的每一列是否可放，  
采用三个 `vector<bool>` 数组保存状态，分别作为列、左斜对角、右斜对角是否被占用的标记，其中：  
列：直接用列表示  
左对角：一共有 `2n - 1` 条，可以以每个点的横纵坐标之和表示来进行区分  
右对角：一共有 `2n - 1` 条，可以以每个点的横纵坐标只差加总行数减一表示来进行区分  
之后简单对每行的每一列使用回溯即可  

```cpp
class Solution 
{
private:
    vector<bool> col;
    vector<bool> leftDiag;
    vector<bool> rightDiag;

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        col.resize(n);
        leftDiag.resize(2 * n - 1);
        rightDiag.resize(2 * n - 1);
        vector<vector<string>> ret;
        vector<string> cur(n, string(n, '.'));
        backTrack(ret, cur, 0, n);
        return ret;
    }

    void backTrack(vector<vector<string>>& ret, vector<string>& cur, int line, int n)
    {
        if(line == n)
        {
            ret.push_back(cur);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(col[i] || leftDiag[line + i] || rightDiag[i - line + n - 1])
                continue;
            col[i] = true;
            leftDiag[line + i] = true;
            rightDiag[i - line + n - 1] = true;
            cur[line][i] = 'Q';
            backTrack(ret, cur, line + 1, n);
            cur[line][i] = '.';
            rightDiag[i - line + n - 1] = false;
            leftDiag[line + i] = false;
            col[i] = false;
        }
    }
};
```
