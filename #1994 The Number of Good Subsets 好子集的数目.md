### 好子集的数目
### The Number of Good Subsets

> 给你一个整数数组 `nums`。如果 `nums` 的一个子集中，所有元素的乘积可以表示为一个或多个**互不相同的质数**的乘积，那么我们称它为**好子集**。  
> - 比方说，如果 `nums = [1, 2, 3, 4]`：  
>   - `[2, 3]`，`[1, 2, 3]` 和 `[1, 3]` 是**好**子集，乘积分别为 `6 = 2*3`，`6 = 2*3` 和 `3 = 3`。  
>   - `[1, 4]` 和 `[4]` 不是**好**子集，因为乘积分别为 `4 = 2*2` 和 `4 = 2*2`。  
>   
> 请你返回 `nums` 中不同的**好**子集的数目对 `10^9 + 7` **取余**的结果。  
> `nums` 中的**子集**是通过删除 `nums` 中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。如果两个子集删除的下标不同，那么它们被视为不同的子集。  

> You are given an integer array `nums`. We call a subset of `nums` **good** if its product can be represented as a product of one or more distinct prime numbers.  
> - For example, if `nums = [1, 2, 3, 4]`:  
>   - `[2, 3]`, `[1, 2, 3]`, and `[1, 3]` are **good** subsets with products `6 = 2*3`, `6 = 2*3`, and `3 = 3` respectively.  
>   - `[1, 4]` and `[4]` are not **good** subsets with products `4 = 2*2` and `4 = 2*2` respectively.  
>   
> Return *the number of different **good** subsets in `nums` **modulo** `10^9 + 7`*.  
> A **subset** of `nums` is any array that can be obtained by deleting some (possibly none or all) elements from `nums`. Two subsets are different if and only if the chosen indices to delete are different.  \

----------

#### I 状态压缩DP

先假定每个数字都只出现一次，则对于每一个数字 `n`，我们可以用如下方式找到其是否为满足条件的独立数字（已知小于`30`的质数共有`10`个）：  

1. 设置一个十位二进制数掩码 `subset = 0000000000`  
2. 对 `n` 进行除法运算，顺序为从小到大的各个质数：
   - 先用 `n` 除以**质数的平方**，如果能整除，说明 `n` 的某个质数因子超过 `1` 个，必然不可能为满足条件的独立数字  
   - 如果上述满足，则再用 `n` 除以质数本身，如果能整除，说明该质数为符合条件的 `n` 的因数

根据上述步骤，即可求出数字 `n` 的质因数构成，按顺序记录在 `subset` 中，例如如果第一个和第二个数字为 `n` 的质因数，则 `subset = 0000000011`  
此时亦可知道，数字 `n` 符合单独质因数的条件  

因此，可以对所有质因数构成的掩码进行判断，例如设置 `mask = 111111111` 并进行递减，每次递减前进行如下判断：  
**注意**：此时 `mask` 虽然看起来是二进制数，但实际上我们认为是*包含了 `k` 个不同的质因数的数字的掩码，其中 `k` 为 `1` 的数目*  
进行 `mask & subset` 操作：  
1. 如果结果仍为 `subset`，则所有符合条件的 `mask` 都包含了当前数字 `n` 作为因子，此时 `mask` 所代表的数字符合条件的子集数目包括两部分    
   - 原来的 `dp[mask]`  
   - 进行 `mask ^ subset` 操作，所得到的结果是完全不包含 `subset` 因数的剩余的 `mask` 的因数，该因数所包含的子集数目为 `dp[mask ^ subset]`  
   
   将两者进行加和，对 `mask` 进行递减操作  
2. 如果结果不为 `subset`，则直接进行递减操作  

因此，最后的子集数目即为 `dp[1] + ... + dp[mask_max - 1]` 的数目，其中 `mask_max == 1 << 质数数目`  
最后考虑出现重复数字：
1. 如果重复数字为 `1`，则单独处理，会使得原来的子集数目变为 `2 ^ (1的出现次数)`  
2. 如果重复数字为其他数字，则直接在 `dp[subset ^ mask]` 处进行 `dp[subset ^ mask] * 出现次数` 的运算即可  

```cpp
class Solution 
{
private:
    static constexpr array<int, 10> primNum{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    static constexpr int mod = 1000000007;

public:
    int numberOfGoodSubsets(vector<int>& nums) 
    {
        vector<int> numCnt(31);
        for(auto num : nums)
            ++numCnt[num];
        
        vector<int> dp(1 << primNum.size());
        dp[0] = 1;
        for(int i = 0; i < numCnt[1]; ++i)
            dp[0] = dp[0] * 2 % mod;
        
        for(int i = 2; i <= 30; ++i)
        {
            if(numCnt[i] == 0)
                continue;
            
            bool alone = true;
            int subset = 0;
            for(int j = 0; j < primNum.size(); ++j)
            {
                if(i % (primNum[j] * primNum[j]) == 0)
                {
                    alone = false;
                    break;
                }
                if(i % primNum[j] == 0)
                    subset |= (1 << j);
            }

            if(!alone)
                continue;

            for(int mask = (1 << primNum.size()) - 1; mask > 0; --mask)
                if((mask & subset) == subset)
                    dp[mask] = (dp[mask] + static_cast<long long> (dp[mask ^ subset]) * numCnt[i]) % mod;
        }

        int ret = 0;
        for(int mask = 1, mask_max = (1 << primNum.size()); mask < mask_max; ++mask)
            ret = (ret + dp[mask]) % mod;

        return ret;
    }
};
```
