/*
    根据矩阵的知识我们知道，旋转矩阵等同于先将矩阵进行 对称 + 转置 操作，
    因此，分两步将原矩阵元素互换即可
*/

void rotate(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size / 2; ++j)
            swap(matrix[i][j], matrix[i][size - 1 - j]);
}

