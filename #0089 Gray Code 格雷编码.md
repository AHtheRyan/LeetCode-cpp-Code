### 格雷编码
### Gray Code

> **n位格雷码序列**是一个由 `2^n` 个整数组成的序列，其中：  
> - 每个整数都在范围 `[0, 2n - 1]` 内（含 `0` 和 `2^n - 1`）  
> - 第一个整数是 `0`  
> - 一个整数在序列中出现**不超过一次**  
> - 每对**相邻**整数的二进制表示**恰好一位不同**，且  
> - **第一个**和**最后一个**整数的二进制表示**恰好一位不同**  
> 
> 给你一个整数 `n`，返回任一有效的 **n 位格雷码序列**。  

> An **n-bit gray code sequence** is a sequence of `2^n` integers where:  
> - Every integer is in the **inclusive** range `[0, 2n - 1]`,  
> - The first integer is `0`,  
> - An integer appears **no more than once** in the sequence,  
> - The binary representation of every pair of **adjacent** integers differs by **exactly one bit**, and  
> - The binary representation of the **first** and **last** integers differs by **exactly one bit**.  
> 
> Given an integer `n`, return *any valid **n-bit gray code sequence***.  

----------

#### I 对称构造

每当添加更高以为的数字时，可视为对之前的所有数字按镜像堆成在最高位加上一个 `1`  
具体解释可见图，图源自[Gray Code （镜像反射法，图解）](https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/)  
![1649227739(1)](https://user-images.githubusercontent.com/46887748/161912734-e887e2aa-4fef-4f75-b919-bc2f27111971.png)  

```cpp
vector<int> grayCode(int n) 
{
    vector<int> ret;
    ret.reserve(1 << n);
    ret.push_back(0);
    for (int i = 1; i <= n; i++) 
    {
        int m = ret.size();
        for (int j = m - 1; j >= 0; j--)
            ret.push_back(ret[j] | (1 << (i - 1)));
    }
    return ret;
}
```

#### II 二进制转换格雷编码

依照二进制和格雷编码的对应关系，任意数字 `i` 的对应格雷编码为 `(i >> 1) ^ i`  

```cpp
vector<int> grayCode(int n) 
{
    vector<int> ret(1 << n);
    for(int i = 0; i < ret.size(); ++i)
        ret[i] = (i >> 1) ^ i;
    return ret;
}
```
