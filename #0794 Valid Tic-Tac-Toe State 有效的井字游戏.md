### 有效的井字棋游戏
### Valid Tic-Tac-Toe State

> 给你一个字符串数组 `board` 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 `board` 所显示的状态时，才返回 `true`。  
> 井字游戏的棋盘是一个 `3 x 3` 数组，由字符 `' '`，`'X'` 和 `'O'` 组成。字符 `' '` 代表一个空位。  
> 以下是井字游戏的规则：  
> - 玩家轮流将字符放入空位（`' '`）中。  
> - 玩家 1 总是放字符 `'X'`，而玩家 2 总是放字符 `'O'`。  
> - `'X'` 和 `'O'` 只允许放置在空位中，不允许对已放有字符的位置进行填充。  
> - 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。  
> - 当所有位置非空时，也算为游戏结束。  
> - 如果游戏结束，玩家不允许再放置字符。  

> Given a Tic-Tac-Toe board as a string array `board`, return `true` if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.  
> The board is a `3 x 3` array that consists of characters `' '`, `'X'`, and `'O'`. The `' '` character represents an empty square.  
> Here are the rules of Tic-Tac-Toe:  
> - Players take turns placing characters into empty squares `' '`.  
> - The first player always places `'X'` characters, while the second player always places `'O'` characters.  
> - `'X'` and `'O'` characters are always placed into empty squares, never filled ones.  
> - The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.  
> - The game also ends if all squares are non-empty.  
> - No more moves can be played if the game is over.  

----------

#### I 规则遍历

规则遍历，即确认所有的错误方式，并将其表现出来即可，总结可得错误方式有三种：
1. 结算时棋子数目不对，即棋盘上两种棋子不满足 `'X' == 'O'` 或者 `'X' == 'O' + 1`（根据规则 `'X'` 先手，所以只会出现这两种）
2. 结算时两者都胜利，即棋盘上两种棋子都能通过某种方式三连
3. 结算时一方的胜利条件冲突，即 `'X'` 取胜但 `'X'` 的数目不比 `'O'` 多 `1`，或者 `'O'` 取胜但 `'O'` 的数目不与 `'X'` 相同

将三中情况表示出来即可

```cpp
bool validTicTacToe(vector<string>& board) 
{
    //计算两个棋子的总数
    int countO = 0;
    int countX = 0;
    //计算斜对边的两个棋子数
    int countLeft = 0;
    int countRight = 0;
    //计算三条纵向方向的棋子数
    int cntRow0 = 0;
    int cntRow1 = 0;
    int cntRow2 = 0;
    //判断两个棋子是否符合基础胜利条件：三连
    bool Xwin = false;
    bool Owin = false;
    //遍历棋盘
    for(int i = 0; i < 3; ++i)
    {
        //设置变量记录当前行两种棋子
        int countL = 0;
        for(int j = 0; j < 3; ++j)
        {
            //记录斜对角边
            if(i == j)
                countLeft = board[i][j] == 'X' ? countLeft + 1 : (board[i][j] == 'O' ? countLeft - 1 : countLeft);
            if(i + j == 2)
                countRight = board[i][j] == 'X' ? countRight + 1 : (board[i][j] == 'O' ? countRight - 1 : countRight);
            //记录纵向棋盘
            if(j == 0)
                cntRow0 = board[i][j] == 'X' ? cntRow0 + 1 : (board[i][j] == 'O' ? cntRow0 - 1 : cntRow0);
            else if(j == 1)
                cntRow1 = board[i][j] == 'X' ? cntRow1 + 1 : (board[i][j] == 'O' ? cntRow1 - 1 : cntRow1);
            else if(j == 2)
                cntRow2 = board[i][j] == 'X' ? cntRow2 + 1 : (board[i][j] == 'O' ? cntRow2 - 1 : cntRow2);
            //记录横向和总量
            if(board[i][j] == 'X')
            {
                ++countX;
                ++countL;
            }    
            else if(board[i][j] == 'O')
            {
                ++countO;
                --countL;
            }
            //判断两种棋子是否符合胜利条件
            if(countL == 3 || countLeft == 3 || countRight == 3 || cntRow0 == 3 || cntRow1 == 3 || cntRow2 == 3)
                Xwin = true;
            else if(countL == -3 || countLeft == -3 || countRight == -3 || cntRow0 == -3 || cntRow1 == -3 || cntRow2 == -3)
                Owin = true;
        }
    }
    //结算时棋子数目不对（不符合下棋顺序）则返回false
    if(countX != countO && countX != countO + 1)
        return false;
    //结算时两者都胜利则返回false
    if(Xwin && Owin)
        return false;
    //某一棋子胜利，棋盘上棋子数目不符合下棋顺序则返回false
    if(Xwin && countX == countO || Owin && countX != countO)
        return false;
    return true;
}
```
