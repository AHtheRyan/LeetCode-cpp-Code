/*
    1. 创建初始全部为 0 的二维矩阵，用来填补数字
    2. 按照右->下->左->上的顺序填补数字，填补时满足两个条件
        2.1 下一个要填补的位置上的数字为 0
        2.2 当前的行数和列数在二维矩阵的范围内
    3. 如果不满足上面的任意条件，则根据上述顺序转变方向
*/

vector<vector<int>> generateMatrix(int n)
{
    int row = 0;
    int col = 0;
    bool right = true;
    bool down = false;
    bool left = false;
    bool up = false;
    vector<vector<int>> ret(n, vector<int>(n));
    for (int i = 0; i < n * n; ++i)
    {
        if (right)
        {
            if (col < n - 1 && ret[row][col + 1] == 0)
                ret[row][col++] = i + 1;
            else
            {
                right = false;
                down = true;
                ret[row++][col] = i + 1;
            }
        }
        else if (down)
        {
            if (row < n - 1 && ret[row + 1][col] == 0)
                ret[row++][col] = i + 1;
            else
            {
                down = false;
                left = true;
                ret[row][col--] = i + 1;
            }
        }
        else if (left)
        {
            if (col > 0 && ret[row][col - 1] == 0)
                ret[row][col--] = i + 1;
            else
            {
                left = false;
                up = true;
                ret[row--][col] = i + 1;
            }
        }
        else if (up)
        {
            if (row > 0 && ret[row - 1][col] == 0)
                ret[row--][col] = i + 1;
            else
            {
                up = false;
                right = true;
                ret[row][col++] = i + 1;
            }
        }
    }
    return ret;
}