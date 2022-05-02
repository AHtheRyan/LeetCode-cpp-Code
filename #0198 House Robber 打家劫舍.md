### 打家劫舍
### House Robber

> 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果**两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。  
> 给定一个代表每个房屋存放金额的非负整数数组，计算你**不触动警报装置的情况下**，一夜之内能够偷窃到的最高金额。  

> You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.  
> Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.  

----------

#### I 动态规划

经典动态规划问题  
到第 `i` 个房子时，能偷到的钱数目有两种可能：  
1. 第 `i - 1` 个房子偷了，此处不偷  
2. 第 `i - 1` 个房子没偷，此处偷  

比较两者哪个偷到的更多并取该值即可  

```cpp
int rob(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> dp(n + 1);
    dp[1] = nums[0];
    for(int i = 1; i < n; ++i)
        dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
    return dp[n];
}
```
