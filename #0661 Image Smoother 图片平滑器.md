### 图片平滑器
### Image Smoother

> 图像平滑器 是大小为 `3 x 3` 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。  
> 每个单元格的**平均灰度**定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。  
> 如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。  
> 给你一个表示图像灰度的 `m x n` 整数矩阵 `img`，返回对图像的每个单元格平滑处理后的图像。  

> An **image smoother** is a filter of the size `3 x 3` that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).  
> Given an `m x n` integer matrix `img` representing the grayscale of an image, return *the image after applying the smoother on each cell of it*.  

----------

#### I 模拟

简单模拟

```cpp
class Solution 
{
public:
    int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ret(m, vector<int> (n));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int cur = img[i][j];
                int cnt = 1;
                for(int k = 0; k < 8; ++k)
                {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n)
                    {
                        cur += img[ni][nj];
                        ++cnt;
                    }
                }
                ret[i][j] = cur / cnt;
            }
        }
        return ret;
    }
};
```
