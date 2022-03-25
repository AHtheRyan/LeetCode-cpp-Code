### 杨辉三角
### Pascal's Triangle

> 给定一个非负整数 `numRows`，生成「杨辉三角」的前 `numRows` 行。  
> 在「杨辉三角」中，每个数是它左上方和右上方的数的和。  

> Given an integer `numRows`, return the first numRows of **Pascal's triangle**.  
> In **Pascal's triangle**, each number is the sum of the two numbers directly above it.  

----------

#### I 数学

用动态规划的角度考虑此题就很简单，直接按每行递推即可，状态方程已经由杨辉三角的题目条件给出

```cpp
vector<vector<int>> generate(int numRows) 
{
    vector<vector<int>> ret;
    for(int i = 0; i < numRows; ++i)
    {
        vector<int> cur(i + 1);
        cur[0] = cur[i] = 1;
        for(int j = 1; j < cur.size() - 1; ++j)
            cur[j] = ret[i - 1][j - 1] + ret[i - 1][j];
        ret.emplace_back(cur);
    }
    return ret;
}
```
