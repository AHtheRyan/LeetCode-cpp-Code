### 搜索二维矩阵
### Search a 2D Matrix

> 编写一个高效的算法来判断 `m x n` 矩阵中，是否存在一个目标值。该矩阵具有如下特性：  
> - 每行中的整数从左到右按升序排列。  
> - 每行的第一个整数大于前一行的最后一个整数。  

> Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:  
> - Integers in each row are sorted from left to right.  
> - The first integer of each row is greater than the last integer of the previous row.  

----------

#### I 二分查找

由于每行每列都是递增的，因此可以看做一行，进行二分查找  

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        int x = mid / n;
        int y = mid % n;
        if(matrix[x][y] == target)
            return true;
        else if(matrix[x][y] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}
```
