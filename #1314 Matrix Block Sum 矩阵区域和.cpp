/*
    if you know the prefix sum of a two-dimensional array, this problem can be solved directly
*/
/*
    如果了解二维数组前缀和，则此题可以直接解出
*/

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> matrix(m + 1, vector<int>(n + 1));
    for (int i = 1; i < m + 1; ++i)
        matrix[i][1] = mat[i - 1][0];
    for (int row = 1; row < m + 1; ++row)
        for (int col = 2; col < n + 1; ++col)
            matrix[row][col] = mat[row - 1][col - 1] + matrix[row][col - 1];
    for (int row = 2; row < m + 1; ++row)
        for (int col = 1; col < n + 1; ++col)
            matrix[row][col] += matrix[row - 1][col];

    vector<vector<int>> ret(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int lx = max(i - k, 0);
            int ly = max(j - k, 0);
            int rx = min(i + k + 1, m);
            int ry = min(j + k + 1, n);
            ret[i][j] = matrix[rx][ry] + matrix[lx][ly] - matrix[lx][ry] - matrix[rx][ly];
        }
    }
    return ret;
}