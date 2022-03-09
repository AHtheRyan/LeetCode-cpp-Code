### 矩阵中的路径

> 给定一个 `m x n` 二维字符网格 `board` 和一个字符串单词 `word`。如果 `word` 存在于网格中，返回 `true`；否则，返回 `false`。  
> 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。  

----------

#### I DFS回溯

可以利用回溯来解决问题，我们可以提前设置二维 `bool` 矩阵 `check` 来验证任意位置是否被使用过，  
此外，设置标志位 `index` 表明当前匹配的是 `word` 的第几个位置的字母，对于每一层回溯，考虑的条件如下：  
1. 如果当前的 `board` 的下标越界，直接返回 `false`  
2. 如果当前的 `board` 对应的位置的字母与 `word` 在第 `index` 位不同，则返回 `false`  
3. 如果当前的位置已经使用过了，则返回 `false`  
4. 如果上述条件都不满足，说明此时的 `board` 对应的位置与 `word` 的 `index` 位对应，此时：  
   - 如果 `index` 为 `word` 的长度，说明每一位都适配了，返回 `true`  
   - 如果 `index` 不为 `word` 的长度，则对上下左右四个方位进行验证，重复上述步骤  

最后返回结果即可  

```cpp
class Solution 
{
public:
    vector<int> dir{-1, 0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> check(m, vector<bool> (n, false));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(explore(board, i, j, 0, word, check))
                    return true;
        return false;
    }

    bool explore(vector<vector<char>>& board, int row, int col, int index, string& word, vector<vector<bool>>& check)
    {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if(board[row][col] != word[index])
            return false;
        if(check[row][col])
            return false;
        if(index == word.size() - 1)
            return true;
        bool ret = false;
        check[row][col] = true;
        for(int i = 0; i < 4; ++i)
        {
            int x = row + dir[i];
            int y = col + dir[i + 1];
            ret = ret || explore(board, x, y, index + 1, word, check);
        }
        check[row][col] = false;
        return ret;
    }
};
```
