### 有效的数独
### Valid Sudoku

> 请你判断一个 `9x9` 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。  
> 1. 数字 `1-9` 在每一行只能出现一次。  
> 2. 数字 `1-9` 在每一列只能出现一次。
> 3. 数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。  
> 
> 数独部分空格内已填入了数字，空白格用 `'.'` 表示。  

> Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:  
> 1. Each row must contain the digits `1-9` without repetition.  
> 2. Each column must contain the digits `1-9` without repetition.  
> 3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.  

----------

#### I 哈希表

遍历整个数独表，使用哈希表存储**行**、**列**、**3x3块**三个不同的区域的出现的数字，采用数组的形式，先设置每个数字都为 `false`  
对于行：直接记录  
对于列：直接记录  
对于块：  
我们设置从左到右，从上到下的块依次为 `1 ~ 9`，则不同的坐标为：  
`(0~2, 0~2)` `(0~2, 3~5)` `(0~2, 6~8)`  
`(3~5, 0~2)` `(3~5, 3~5)` `(3~5, 6~8)`  
`(6~8, 0~2)` `(6~8, 3~5)` `(6~8, 6~8)`  
显然，块的横纵坐标都是以 `3` 为单位划分的，我们可以将每个块的值除以 `3`，根据c++的除法规则可得：  
`(0, 0)` `(0, 1)` `(0, 2)`  
`(1, 0)` `(1, 1)` `(1, 2)`  
`(2, 0)` `(2, 1)` `(2, 2)`  
可见，经过处理之后， `1 ~ 9` 分别变成了 `00, 01, 02, 10, 11, 12, 20, 21, 22`，  
而我们需要表示的数字为 `1, 2, 3, 4, 5, 6, 7, 8, 9`，  
因此，将处理后的数字视为3进制，进行机制转换即可完成分块的处理， 每次判断数字是否是唯一的，遍历整个表即可

```cpp
bool isValidSudoku(vector<vector<char>>& board) 
{
    vector<vector<vector<bool>>> hash(3, vector<vector<bool>>(9, vector<bool> (9, false)));
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1;
                int block = i / 3 * 3 + j / 3;
                if(hash[0][i][num] || hash[1][j][num] || hash[2][block][num])
                    return false;
                else
                {
                    hash[0][i][num] = true;
                    hash[1][j][num] = true;
                    hash[2][block][num] = true;
                }
            }
        }
    }
    return true;
}
```
