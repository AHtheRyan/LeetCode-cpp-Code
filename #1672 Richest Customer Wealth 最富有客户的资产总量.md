### 最富有客户的资产总量
### Richest Customer Wealth

> 给你一个 `m x n` 的整数网格 `accounts`，其中 `accounts[i][j]` 是第 `i` 位客户在第 `j` 家银行托管的资产数量。返回最富有客户所拥有的**资产总量**。  
> 客户的**资产总量**就是他们在各家银行托管的资产数量之和。最富有客户就是**资产总量**最大的客户。  

> You are given an `m x n` integer grid accounts where `accounts[i][j]` is the amount of money the `ith` customer has in the `jth` bank. Return *the **wealth** that the richest customer has*.  
> A customer's **wealth** is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum **wealth**.  

----------

#### I 模拟

简单模拟

```cpp
int maximumWealth(vector<vector<int>>& accounts) 
{
    int ret = 0;
    for(auto& account : accounts)
    {
        int cur = accumulate(account.begin(), account.end(), 0);
        ret = max(cur, ret);
    }
    return ret;
}
```
