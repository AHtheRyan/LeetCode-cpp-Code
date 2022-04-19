### 乘法表中第k小的数
### Kth Smallest Number in Multiplication Table

> 给定高度 `m`、宽度 `n` 的一张 `m * n` 的乘法表，以及正整数 `k`，你需要返回表中第 `k` 小的数字。  

> Given three integers `m`, `n`, and `k`, return *the `kth` smallest element in the `m x n` multiplication table*.  

----------

#### I 二分查找

对于任意一个数字 `k`，我们可以利用类似于[搜索二维矩阵II](%230240%20Search%20a%202D%20Matrix%20II%20搜索二维矩阵%20II.md)  中的方式进行查找  
简单来说，就是根据每行数字递增的特性，按行确认当前行比当前数字 `k` 小的数字的个数并将每行的总数加起来  
寻找数字 `k` 的过程可以利用二分法减少查找次数  

```cpp
class Solution 
{
public:
    int findKthNumber(int m, int n, int k) 
    {
        int left = 1;
        int right = m * n;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(enough(m, n, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int enough(int m, int n, int k)
    {
        int i = 1;
        int j = n;
        int ret = 0;
        while(j > 0 && i <= m)
        {
            if(i * j > k)
                --j;
            else
            {
                ret += j;
                ++i;
            }
        }
        return ret;
    }
};
```
