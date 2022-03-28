### 最大矩形
### Maximal Rectangle

> 给定一个仅包含 `0` 和 `1`、大小为 `rows x cols` 的二维二进制矩阵，找出只包含 `1` 的最大矩形，并返回其面积。  

> Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return its area.  

----------

#### I 单调栈

对于每行，我们考虑其当前值，如果为 `0`，可视为高度为 `0` 的矩形，如果为 `1`，可视为在前一层的基础上矩形高度加一，则可以获得本行的“矩形高度”  
针对此举行高度，可以按照[柱状图中的最大矩形](./%230084%20Largest%20Rectangle%20in%20Histogram%20柱状图中最大的矩形.md)的规则进行最大值的求解  

```cpp
class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(n);
        for(int i = 0; i < n; ++i)
            row[i] = matrix[0][i] - '0';
        int ret = 0;
        for(int i = 0; i < m; ++i)
        {
            if(i != 0)
                for(int j = 0; j < n; ++j)
                    row[j] = (matrix[i][j] - '0' == 0) ? 0 : row[j] + (matrix[i][j] - '0');
            ret = max(ret, rowMax(row));
        }
        return ret;
    }

    int rowMax(vector<int>& row)
    {
        int n = row.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk;
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && row[stk.top()] >= row[i])
                stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int j = n - 1; j >= 0; --j)
        {
            while(!stk.empty() && row[stk.top()] >= row[j])
                stk.pop();
            right[j] = stk.empty() ? n : stk.top();
            stk.push(j);
        }
        int ret = 0;
        for(int i = 0; i < n; ++i)
            ret = max(ret, (right[i] - left[i] - 1) * row[i]);
        return ret;
    }
};
```
