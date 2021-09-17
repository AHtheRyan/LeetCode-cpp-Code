### 单词搜索
### Word Search

> 给定一个 `m x n` 二维字符网格 `board` 和一个字符串单词 `word`。如果 `word` 存在于网格中，返回 `true`；否则，返回 `false` 。  
> 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。  

> Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` *exists in the grid*.  
> The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.  

----------

#### I 回溯算法 + 哈希表存储状态

显然需要利用回溯算法来计算每个位置能构成的单词是否符合条件，  
遍历整个数组，一次以每个字母为起点，从上下左右四个方向进行遍历，对于接下来的字母也以此规则进行遍历，  
如果某个位置的字母与 `word` 在该下标 `index` 的字母相同则继续递归，否则终止迭代  
利用一个额外的哈希表 `check` 保存每次遍历时的字母是否遍历的状态即可  

```cpp
bool exist(vector<vector<char>>& board, string word) 
{
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> check(row, vector<bool>(col, false));
    bool flag = false;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            backTrack(i, j, word, check, board, 0, flag);
    return flag;
}

void backTrack(int x, int y, string& word, vector<vector<bool>>& check, vector<vector<char>>& board, int count, bool& flag)
{
    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        return ;
    if(check[x][y] || flag || board[x][y] != word[count])
        return ;
    if(count == word.size() - 1)
    {
        flag = true;
        return;
    }
    check[x][y] = true;
    backTrack(x + 1, y, word, check, board, count + 1, flag);
    backTrack(x - 1, y, word, check, board, count + 1, flag);
    backTrack(x, y + 1, word, check, board, count + 1, flag);
    backTrack(x, y - 1, word, check, board, count + 1, flag);
    check[x][y] = false;
}
```
