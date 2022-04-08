### 比特位计数
### Counting Bits

> 给你一个整数 `n`，对于 `0 <= i <= n` 中的每个 `i`，计算其二进制表示中 `1` 的个数 ，返回一个长度为 `n + 1` 的数组 `ans` 作为答案。  

> Given an integer `n`, return *an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the **number of `1`'s** in the binary representation of `i`*.  

----------

#### I 简单遍历求位数

遍历每个数字，分别对其求位数即可  

```cpp
vector<int> countBits(int n) 
{
    vector<int> ret;
    for(int i = 0; i <= n; ++i)
    {
        int cur = 0;
        int x = i;
        while(x)
        {
            ++cur;
            x &= (x - 1);
        }
        ret.emplace_back(cur);
    }
    return ret;
}
```

#### II 动态规划 + 高位标志位

观察数字位数规律：  
| 数字 | 二进制位 | 1的个数 |
| ---- | ---- | ---- |
| 0 | 0000 | 0 |
| | 分界线 | |
| 1 | 0001 | 1 | 
| | 分界线 | |
| 2 | 0010 | 1 |
| 3 | 0011 | 2 |
| | 分界线 | |
| 4 | 0100 | 1 |
| 5 | 0101 | 2 |
| 6 | 0110 | 2 |
| 7 | 0111 | 3 |
| | 分界线 | |
| 8 | 1000 | 1 |
| 9 | 1001 | 2 |
| 10 | 1010 | 2 |
| 11 | 1011 | 3 |
| 12 | 1100 | 2 |
| 13 | 1101 | 3 |
| 14 | 1110 | 3 |
| 15 | 1111 | 4 |

可以发现，我们以 **“数字进一位”** 为分界线，则  
每出现一次分界线，就可以视为 `1` 的个数从最初的 `0000` 开始，在当前的最高位位置加了一个，  
因此，只要我们确定最高位的位置，就可以利用此性质进行dp方程的构建  

```cpp
vector<int> countBits(int n) 
{
    vector<int> ret(n + 1);
    int highBit = 0;
    for(unsigned i = 1; i <= n; ++i)
    {
        if(((i - 1) & i) == 0)
            highBit = i;
        ret[i] = ret[i - highBit] + 1;
    }
    return ret;
}
```
