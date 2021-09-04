### 斐波那契数列

> 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：  
> `F(0) = 0,   F(1) = 1`  
> `F(N) = F(N - 1) + F(N - 2), 其中 N > 1.`  
> 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。  
> 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。  

----------

#### I 动态规划

斐波那契数列的递推公式其实是很明确的，我们可以直接采用并递推出结果

```cpp
int fib(int n) 
{
    if(n < 2)
        return n;
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; ++i)
    {
        c = (a + b) % mod;
        a = b;
        b = c;
    }
    return c;
}
```

#### II 矩阵快速幂

利用矩阵快速幂的方法可以将时长从 `o(n)` 缩短到 `o(log n)`  
根据线性代数的基础知识可以知道，斐波那契数列的变化过程可以通过矩阵描述为  
![image](https://user-images.githubusercontent.com/46887748/132101932-a9ab28d9-3dcb-47e2-a2f4-b9c3fe88dacb.png)  
以此类推，我们可以根据矩阵左乘的方式获得第 `n` 位的斐波那契数，即  
![image](https://user-images.githubusercontent.com/46887748/132101956-8230deec-3788-441b-9206-912ae077aad5.png)  
将矩阵的指数转化为二进制并分解，例如，如果要求矩阵的6次幂：  
![image](https://user-images.githubusercontent.com/46887748/132102078-b0ba37f5-e3eb-4440-97b7-9482f94508eb.png)  
进一步转化为  
![image](https://user-images.githubusercontent.com/46887748/132102124-9508b242-0451-45e0-896f-070f3c2e53bf.png)  
分析每一个乘法项，可以得到如下性质：  
1. 所有的矩阵基底相同，只有幂存在二次幂的幂的递进关系
2. 对于任意幂![image](https://user-images.githubusercontent.com/46887748/132102174-71ecdc73-2bbe-4152-9ae5-402f257dd6bf.png)，其含有系数 `1` 或 `0`，且存在第 `n` 项是第 `n - 1` 项的平方的递进关系  

因此，可以构建矩阵快速幂，即设计函数，以单位矩阵为初始结果，并将其幂进行二进制的如上分解：  
- 如果该矩阵的2次幂的项数为 `0`，则说明此项最终并未影响最终结果（此项幂结果为单位阵）
- 如果该矩阵的2次幂的项数为 `1`，则说明此项乘在了结果中，需要将结果乘上当前的项作为新结果  

在处理完当前项后，只需要将结果进行2次方乘法即可得到下一个乘法项，因此，确定了**初始结果**、**2次幂的系数**和**总项数**之后就可以通过迭代获得最终结果

```cpp
class Solution 
{
public:
    const int MOD = 1000000007;

    int fib(int n) 
    {
        if(n < 2)
            return n;
        vector<vector<long>> ini = {{1, 1}, {1, 0}};
        vector<vector<long>> ret = quikPower(ini, n - 1);
        return ret[0][0];
    }

    vector<vector<long>> quikPower(vector<vector<long>>& ini, int n)
    {
        vector<vector<long>> ret{{1, 0}, {0, 1}};
        while(n)
        {
            if(n & 1)
                ret = multiply(ret, ini);
            n >>= 1;
            ini = multiply(ini, ini);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b)
    {
        vector<vector<long>> ret{{0, 0}, {0, 0}};
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                ret[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
        return ret;
    }
};
```
