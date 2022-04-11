### 统计各位数字都不同的数字个数
### Count Numbers with Unique Digits

> 给你一个整数 `n`，统计并返回各位数字都不同的数字 `x` 的个数，其中 `0 <= x < 10^n`。  

> Given an integer `n`, return the count of all numbers with unique digits, `x`, where `0 <= x < 10^n`.  

----------

#### I 动态规划 + 排列组合

因为要求所有数字，所以需要求从 `0` 到当前位数产生的符合条件的数字总和  
同时，进行排列组合时，除第一位外，每一位能选择的数字数量为前一位能选择的数字数量减去`1`，  
例如，对于一个两位数，其第一位能选择 `1~9` 共 `9` 种，第二位能选择 `0~9` 中除去第一位的剩下 `9` 个数字，而一个三位数视为在其后再添加一个数字，能选择 `0~9` 中除了第二位和第一位中的剩下 `8` 个数字  
以此类推，可见每次可选的数字都减少了，按此规律进行乘法运算并与之前的总数累加，即可得到当前位数符合条件的数字总和数量  

```cpp
int countNumbersWithUniqueDigits(int n) 
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 10;
    int sum = 10;
    int fac = 9;
    int cur = 9;
    for(int i = 2; i <= n; ++i)
    {
        cur *= (fac - i + 2);
        sum = cur + sum;
    }
    return sum;
}
```
