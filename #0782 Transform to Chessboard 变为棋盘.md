### 变成棋盘
### Transform to Chessboard

> 一个 `n x n` 的二维网络 `board` 仅由 `0` 和 `1` 组成 。每次移动，你能任意交换两列或是两行的位置。  
> 返回*将这个矩阵变为 **“棋盘”** 所需的最小移动次数*。如果不存在可行的变换，输出 `-1`。  
> “棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。  

> You are given an `n x n` binary grid `board`. In each move, you can swap any two rows with each other, or any two columns with each other.  
> Return *the minimum number of moves to transform the board into a **chessboard board***. If the task is impossible, return `-1`.  
> A **chessboard board** is a board where no `0`'s and no `1`'s are 4-directionally adjacent.  

----------

#### I 模拟

首先需要判断棋盘上目前的数字能否通过变换成为一个符合条件的棋盘，假设棋盘规格为 `n`，根据要求，判断标准如下：  
1. 棋盘上每一行的 `1` 和 `0` 的数目差的绝对值不大于 `1`  
2. 棋盘上的每一行如果记录为二进制序列，则每行和第一行不是相同就是完全相反，如 `1001` 和 `0110`，否则变换不可能成立  
3. 棋盘上与第一行相同的序列和不同的序列的数目差的绝对值不大于 `1`  
4. 行与列判断条件一样  

根据上述规则可构造函数 `checkValid`，判断是否满足条件  
如果满足条件，可以计算变换的次数，计算的方法如下：  
- 如果棋盘行列为偶数，则只需要 `1` 和 `0` 的数目相同即可，此时：  
  - 可以计算 `1` 开头的二进制最终结果和 `0` 开头的二进制最终结果，分别记为 `mask1` `mask0`，如 `1010` 和 `0101`  
  - 计算第一行的二进制表示 `curRow`  
  - 需要变换的次数为第一行变为 `1` 开头的序列的次数和第一行变为 `0` 开头的序列的次数的较小值，如第一行为 `0110`，则其变为 `1010` 和 `0101` 的代价相同，都为一次  
    注意，由于第一行变换后每列都发生变化，所以只需要考虑第一行的变换次数即可  
    可以用 `mask1` 和 `mask0` 分别与 `curRow` 做逻辑与运算，如果有 `1` 出现，说明该位置的 `1` 不需要更换，因此我们只需要将总的 `1` 出现次数减去计算后的 `1` 出现的次数即可  
    例如 `0110 & 1010 = 0010`，此时需要变换 `2 - 1 = 1` 次，`0110 & 0101 = 0100`，此时需要变换 `2 - 1 = 1` 次，返回较小值 `1` 即可  
  - 列计算同行  
- 如果棋盘行列为奇数，判断方法同上，不过需要针对行/列中的 `1` 或 `0` 较多进行分类讨论  

根据上述规则可构造函数 `cntStep`  

```cpp
class Solution 
{
public:
    int movesToChessboard(vector<vector<int>>& board) 
    {
        if(!checkValid(board))
            return -1;
        return cntStep(board);
    }

    int cntStep(vector<vector<int>>& board)
    {
        int n = board.size();
        int rowStep = 0;
        int colStep = 0;
        if(n % 2 == 0)
        {
            int mask1 = 0;
            int mask0 = 0;
            int curRow = 0;
            int curCol = 0;
            for(int i = 0; i < n; ++i)
            {
                curRow = curRow << 1 | board[0][i];
                curCol = curCol << 1 | board[i][0];
                mask1 <<= 1;
                mask0 <<= 1;
                if(i % 2)
                    mask1 |= 1;
                else
                    mask0 |= 1;
            }
            rowStep = n / 2 - max(__builtin_popcount(mask1 & curRow), __builtin_popcount(mask0 & curRow));
            colStep = n / 2 - max(__builtin_popcount(mask1 & curCol), __builtin_popcount(mask0 & curCol));
        }
        else
        {
            int cntRow1 = 0;
            int cntCol1 = 0;
            int curRow = 0;
            int curCol = 0;
            for(int i = 0; i < n; ++i)
            {
                if(board[0][i] == 1)
                    ++cntRow1;
                if(board[i][0] == 1)
                    ++cntCol1;
                curRow = curRow << 1 | board[0][i];
                curCol = curCol << 1 | board[i][0];
            }
            int maskWhile1 = 0;
            int maskWhile0 = 0;
            for(int i = 0; i < n; ++i)
            {
                maskWhile1 <<= 1;
                maskWhile0 <<= 1;
                if(i % 2 == 0)
                    maskWhile1 |= 1;
                else
                    maskWhile0 |= 1;
            }
            if(cntRow1 * 2 > n)
                rowStep = n / 2 + 1 - __builtin_popcount(maskWhile1 & curRow);
            else
                rowStep = n / 2 - __builtin_popcount(maskWhile0 & curRow);
            if(cntCol1 * 2 > n)
                colStep = n / 2 + 1 - __builtin_popcount(maskWhile1 & curCol);
            else
                colStep = n / 2 - __builtin_popcount(maskWhile0 & curCol);
        }
        return rowStep + colStep;
    }

    bool checkValid(vector<vector<int>>& board)
    {
        int n = board.size();
        //检查行与列
        int cnt1inFirstRow = 0;
        int cnt1inFirstCol = 0;
        for(int i = 0; i < n; ++i)
        {
            if(board[0][i] == 1)
                ++cnt1inFirstRow;
            if(board[i][0] == 1)
                ++cnt1inFirstCol;
        }
        //行与列中的1和0的数目的差值不大于1
        if(abs(n - cnt1inFirstRow * 2) > 1 || abs(n - cnt1inFirstCol * 2) > 1)
            return false;
        //每一行都与第一行相同或完全相反
        //相同的行与不同的行的数目的差值不大于1
        int cntSameinRow = 1;
        int cntSameinCol = 1;
        int maskRow = 0;
        int maskCol = 0;
        int maxMask = 0;
        for(int i = 0; i < n; ++i)
        {
            maskRow = maskRow << 1 | board[0][i];
            maskCol = maskCol << 1 | board[i][0];
            maxMask = maxMask << 1 | 1;
        }
        for(int i = 1; i < n; ++i)
        {
            int curRow = 0;
            int curCol = 0;
            for(int j = 0; j < n; ++j)
            {
                curRow = curRow << 1 | board[i][j];
                curCol = curCol << 1 | board[j][i];
            }
            if(curRow == maskRow)
                ++cntSameinRow;
            else if((curRow ^ maskRow) != maxMask)
                return false;
            if(curCol == maskCol)
                ++cntSameinCol;
            else if((curCol ^ maskCol) != maxMask)
                return false;
        }
        if(abs(n - cntSameinRow * 2) > 1 || abs(n - cntSameinCol * 2) > 1)
            return false;
        return true;
    }
};
```
