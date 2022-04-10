### 不同的二叉搜索树
### Unique Binary Search Trees

> 给你一个整数 `n`，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的**二叉搜索树**有多少种？返回满足题意的二叉搜索树的种数。  

> Given an integer `n`, return *the number of structurally unique **BST**'s (binary search trees) which has exactly `n` nodes of unique values from `1` to `n`*.  

----------

#### I 动态规划

分别考虑以 1,2,3,4,5，……为根节点的树有多少个，  
以 n 为根节点时，左子树的元素数目为 n - 1 个，右子树 的元素数目为 总数 - n 个，  
依次遍历将每一次左右子树分布的可能性加在一起即可  

```cpp
int numTrees(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i] += dp[j - 1] * dp[i - j];
    return dp[n];
}
```
