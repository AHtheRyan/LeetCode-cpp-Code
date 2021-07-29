/*
    if you know the prefix sum of a two-dimensional array, this problem can be solved directly
*/
/*
    如果了解二维数组前缀和，则此题可以直接解出
*/

class NumMatrix
{
    vector<vector<int>> pre;
public:
    //construct a two-dimensional array prefix sum matrix
    //构建二维数组前缀和矩阵
    NumMatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        pre.resize(m + 1);
        for (int i = 0; i < m + 1; ++i)
            pre[i].resize(n + 1);
        for (int row = 1; row < m + 1; ++row)
            pre[row][1] = matrix[row - 1][0];
        for (int row = 1; row < m + 1; ++row)
            for (int col = 2; col < n + 1; ++col)
                pre[row][col] = pre[row][col - 1] + matrix[row - 1][col - 1];
        for (int row = 2; row < m + 1; ++row)
            for (int col = 1; col < n + 1; ++col)
                pre[row][col] += pre[row - 1][col];

        return;
    }

    //use two-dimensional array prefix sum to get the answer
    //利用二维数组前缀和求出解
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int x1 = row1;
        int y1 = col1;
        int x2 = row2 + 1;
        int y2 = col2 + 1;
        int ret = pre[x2][y2] + pre[x1][y1] - pre[x1][y2] - pre[x2][y1];
        return ret;
    }
};