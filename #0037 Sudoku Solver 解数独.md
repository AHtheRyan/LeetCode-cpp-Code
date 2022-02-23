### 解数独
### Sudoku Solver

> 编写一个程序，通过填充空格来解决数独问题。  
> 数独的解法需**遵循如下规则**：  
> 1. 数字 `1-9` 在每一行只能出现一次。  
> 2. 数字 `1-9` 在每一列只能出现一次。  
> 3. 数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。  
> 
> 数独部分空格内已填入了数字，空白格用 `'.'` 表示。  

> Write a program to solve a Sudoku puzzle by filling the empty cells.  
> A sudoku solution must satisfy **all of the following rules**:  
> 1. Each of the digits `1-9` must occur exactly once in each row.  
> 2. Each of the digits `1-9` must occur exactly once in each column.  
> 3. Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.  
> 
> The `'.'` character indicates empty cells.  

----------

### I 回溯

回溯的基本思路：  
确认每个位置可以填写的数字，依次填入进行尝试，如果某步无法进行（即前面某处填写错误），则回溯到之前的状态进行尝试  
这里我们可以利用三个不同的数组 `line` `column` 和 `block` 分别记录某个数字是否存在与某行、某列或者某个 `3×3` 的范围内  
首先对 `board` 做预处理，将已有的数字按照上述规则记录，然后利用回溯，依次将 `0~9` 尝试填入空白位置，每填写好一个数字，则对下一个空白位置进行判断  
经过回溯可得到唯一的答案，具体代码功能见注释    

```cpp
class Solution 
{
private:
//三个数组分别记录数字在行、列、块的存在情况
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];

//记录空白位置的坐标
    vector<pair<int, int>> space;

//是否找到解的标志位
    bool valid;

public:
    void backTrack(vector<vector<char>>& board, int pos)
    {
    //开始判断回溯条件，如果找到解，就直接改变标志位并返回
        if(pos == space.size())
        {
            valid = true;
            return;
        }
    //如果没找到解，则进行数字填写，先读取当前的坐标位置
        auto [i, j] = space[pos];
    //以 0~9 依次在当前位置进行填写
        for(int num = 0; num < 9 && !valid; ++num)
        {
        //如果该点可以填写当前数字，则进行填写，并进行回溯过程
            if(!line[i][num] && !column[j][num] && !block[i / 3][j / 3][num])
            {
                line[i][num] = true;
                column[j][num] = true;
                block[i / 3][j / 3][num] = true;
                board[i][j] = num + '0' + 1;
                backTrack(board, pos + 1);
                line[i][num] = false;
                column[j][num] = false;
                block[i / 3][j / 3][num] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
    //初始化三个数组和标志位
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;
        for(int row = 0; row < 9; ++row)
        {
            for(int col = 0; col < 9; ++col)
            {
                if(board[row][col] == '.')
                    space.push_back({row, col});
                else
                {
                    int num = board[row][col] - '0' - 1;
                    line[row][num] = true;
                    column[col][num] = true;
                    block[row / 3][col / 3][num] = true;
                }
            }
        }
    //进行回溯
        backTrack(board, 0);
    }
};
```
