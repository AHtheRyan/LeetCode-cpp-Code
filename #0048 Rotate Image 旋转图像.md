### 旋转图像
### Rotate Image

> 给定一个 `n × n` 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 `90` 度。  
> 你必须在**原地**旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要**使用另一个矩阵来旋转图像。  

> You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).  
> You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.  

----------

#### I 转置 + 对称

根据矩阵的知识我们知道，旋转矩阵等同于先将矩阵进行 对称 + 转置 操作，
因此，分两步将原矩阵元素互换即可

```cpp
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
```
