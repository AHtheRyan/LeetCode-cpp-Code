### 杨辉三角 II
### Pascal's Triangle II

> 给定一个非负索引 `rowIndex`，返回「杨辉三角」的第 `rowIndex` 行。  
> 在「杨辉三角」中，每个数是它左上方和右上方的数的和。  

> Given an integer `rowIndex`, return the `rowIndexth` **(0-indexed)** row of the **Pascal's triangle**.  

----------

#### I 动态规划

由于每一行的值都与前一行有关（存在递推公式）+ 第一行固定为 1（存在初始条件），显然使用动态规划求解较为理想，  
在使用动态规划时需要注意：  
1. 每一行的第一个数字和最后一个数字都是 1，为固定值，需要先复制  
2. 除此之外每个位置 `i` 的值为前一行位置 `i` 和位置 `i - 1`上的数字之和  
按上述两个条件列出递推公式即可

```cpp
vector<int> getRow(int rowIndex)
{
    vector<int> cur(1, 1);
    vector<int> pre;
    for (int i = 1; i <= rowIndex; ++i)
    {
        pre = cur;
        cur.resize(i + 1);
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i; ++j)
            cur[j] = pre[j - 1] + pre[j];
    }
    return cur;
}
```

#### II 数学

另一种简单的方式是根据数学公式进行递推  
杨辉三角的公式实际等同于  
![CodeCogsEqn](https://user-images.githubusercontent.com/46887748/130482362-0fe12f5f-b3b7-4e82-b54e-e2a3cc5baba7.png)  
其中，C为行数，r为位数，  
因此，只需要简单求出该行中每个数字与前一个数字的递推关系，即可求得改行所有数字

```cpp
vector<int> getRow(int rowIndex) 
{
    vector<int> ret(rowIndex + 1);
    ret[0] = 1;
    for(int i = 1; i <= rowIndex; ++i)
        ret[i] = 1LL * ret[i - 1] * (rowIndex - i + 1) / i;
    return ret;
}
```
