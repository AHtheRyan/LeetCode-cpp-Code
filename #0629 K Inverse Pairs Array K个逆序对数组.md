### K个逆序对数组
### K Inverse Pairs Array

> 给出两个整数 `n` 和 `k`，找出所有包含从 `1` 到 `n` 的数字，且恰好拥有 `k` 个逆序对的不同的数组的个数。  
> 逆序对的定义如下：对于数组的第 `i` 个和第 `j` 个元素，如果满 `i < j` 且 `a[i] > a[j]`，则其为一个逆序对；否则不是。  
> 由于答案可能很大，只需要返回 答案 mod 10^9 + 7 的值。  

> For an integer array `nums`, an **inverse pair** is a pair of integers `[i, j]` where `0 <= i < j < nums.length` and `nums[i] > nums[j]`.  
> Given two integers n and k, return the number of different arrays consist of numbers from `1` to `n` such that there are exactly `k` **inverse pairs**. Since the answer can be huge, return it **modulo** `10^9 + 7`.  

----------

#### I 动态规划

为了找到题目的规律，我们先对数字较少的排列情况确定逆序对数组的实际取值：  
| 数字范围 | 0对逆序数 | 1对逆序数 | 2对逆序数 | 3对逆序数 | 4对逆序数 | 5对逆序数 | 6对逆序数 |  
| --- | --- | --- | --- | --- | --- | --- | --- |  
| 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |  
| 2 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |  
| 3 | 1 | 2 | 2 | 1 | 0 | 0 | 0 |  
| 4 | 1 | 3 | 5 | 6 | 5 | 3 | 1 |  

在我们观察 `1 -> 2` `2 -> 3` `3 -> 4` 的逆序数对增长的过程中可以发现，当数字范围增加 `1` 之后，相关的逆序数对的数目增长与该数字所处的位置有关系，  
因此，应该可以通过动态规划的方式解决这个增长规律的问题  
接下来是寻找动态规划规律的环节：  
考虑三个数字 `x/y/z`，如果增加第四个数字 `m`，则由于 `m > x/y/z`，因此，无论 `x/y/z` 三个数字如何排列，都必然满足 **`m`左边的数字都不与其构成逆序数对，`m`右边的数字都与其构成逆序数对** 这一规律  
例如，对于 `1/2/3`，如果加入数字 `4`，则 `4 1 2 3 / 4 1 3 2 / 4 2 1 3 / 4 2 3 1 / 4 3 1 2 / 4 3 2 1` 都是 `4` 与另外三个数字构成逆序数对，  
而 `1 4 2 3 / 1 4 3 2 / 2 4 1 3 / 2 4 3 1 / 3 4 1 2/ 3 4 2 1` 这些情况则都满足 `4` 与后面两个数字构成逆序数对，与前面的数字无关，  
综合上面的分析可以看到，只需要考虑把 `4` 插入到从左往右数第 `a` 位时，右边有几个逆序数即可，同时 `4` 的左边需要满足补充逆序数对，  
换句话说，先把 `4` 拿走，考虑前三个数字的逆序数关系，如果需要 `k = 4` 个逆序数对，则可以：  
- 由三个数字构成 `4` 个逆序数对并在最右端的空位加上 `4`，即 `x y z 4`    
- 由三个数字构成 `3` 个逆序数对并在从右往左第二个空位加上 `4`，即 `x y 4 z`  
- 由三个数字构成 `2` 个逆序数对并在从右往左第三个空位加上 `4`，即 `x 4 y z`  
- 由三个数字构成 `1` 个逆序数对并在最左端的空位加上 `4`，即 `4 x y z`
- **注意**：不能再减少了，因为 `4` 最多和后面构成 `3` 个逆序数对

将所有情况加和，即可获得最终结果  
由此可拓展到一般情况，即对于范围为 `i` 的数字，如果其需要有 `j` 对逆序数对，则存在的组合方式有  
![1636633181(1)](https://user-images.githubusercontent.com/46887748/141296972-b7608031-cee6-415e-9641-ff1b83378a2c.png)    
其中，`[i-1]` 是为了表明去掉最后一个数字之后的逆序数总数，便于考虑加上最后一个数字之后的总数关系，  
`[j - (i- k)]` 是为了得到数字范围为 `i - 1` 时的逆序数对的数目，可以按此规律求出结果  
考虑到原递推公式有如下关系：  
![1636633181(1)](https://user-images.githubusercontent.com/46887748/141296979-d0fecdbb-e790-4e71-b1e1-175aa99a6bd0.png)  
![1636633028(1)](https://user-images.githubusercontent.com/46887748/141296783-8d1a04d3-7da0-43b1-8a9f-c32b934a5a2b.png)  
根据两者可得  
![1636633619(1)](https://user-images.githubusercontent.com/46887748/141297956-f5919f97-3644-4812-991b-49229ee1d9c4.png)  
可以依此来降低时间复杂度  

```cpp
class Solution 
{
public:
    static constexpr int mod = 1000000007;

    int kInversePairs(int n, int k) 
    {
        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[0][0] = 1;
        int pre = 1;
        int cur = 0;
        for(int i = 1; i < n + 1; ++i)
        {
            pre ^= 1;
            cur ^= 1;
            for(int j = 0; j < k + 1; ++j)
            {
                int x = j - i >= 0 ? dp[pre][j - i]: 0;
                int y = j - 1 >= 0 ? dp[cur][j - 1]: 0;
                dp[cur][j] = y - x + dp[pre][j];
                if(dp[cur][j] >= mod)
                    dp[cur][j] -= mod;
                else if(dp[cur][j] < 0)
                    dp[cur][j] += mod;
            }
        }
        return dp[cur][k];
    }
};
```
