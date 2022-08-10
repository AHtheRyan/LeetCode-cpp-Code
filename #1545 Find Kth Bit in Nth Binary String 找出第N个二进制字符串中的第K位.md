### 找出第N个二进制字符串中的第K位
### Find Kth Bit in Nth Binary String

> 给你两个正整数 n 和 k，二进制字符串  Sn 的形成规则如下：  
> - `S1 = "0"`  
> - 当 `i > 1` 时，`Si = Si-1 + "1" + reverse(invert(Si-1))`  
> 
> 其中 `+` 表示串联操作，`reverse(x)` 返回反转 `x` 后得到的字符串，而 `invert(x)` 则会翻转 `x` 中的每一位（0 变为 1，而 1 变为 0）。  
> 例如，符合上述描述的序列的前 4 个字符串依次是：  
> - `S1 = "0"`  
> - `S2 = "011"`  
> - `S3 = "0111001"`  
> - `S4 = "011100110110001"`  
> 
> 请你返回 `Sn` 的**第 `k` 位字符**，题目数据保证 `k` 一定在 `Sn` 长度范围以内。  

> Given two positive integers `n` and `k`, the binary string `Sn` is formed as follows:  
> - `S1 = "0"`  
> - `Si = Si - 1 + "1" + reverse(invert(Si - 1))` for `i > 1`  
> 
> Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string `x`, and `invert(x)` inverts all the bits in `x` (`0` changes to `1` and `1` changes to `0`).  
> For example, the first four strings in the above sequence are:  
> - `S1 = "0"`  
> - `S2 = "011"`  
> - `S3 = "0111001"`  
> - `S4 = "011100110110001"`  
> 
> Return *the `kth` bit in `Sn`*. It is guaranteed that `k` is valid for the given `n`.  

----------

#### I 模拟

基于变换规则对字符串进行模拟

```cpp
char findKthBit(int n, int k) 
{
    string s = "0";
    for(int i = 0; i < n; ++i)
    {
        int m = s.size();
        string cur;
        for(int k = m - 1; k >= 0; --k)
            cur += s[k] == '1' ? '0' : '1';
        s = s + '1' + cur;
    }
    return s[k - 1];
}
```

#### II 递归

对任意位置的字符，其来源只有两种：  
1. 形成规则中增加的 `1`  
2. 最开始的 `0` 的复制或者其转换字符  

因此，可以利用递归，找到最开始的字符为 `1` 还是 `0` 即可  

```cpp
class Solution 
{
public:
    char findKthBit(int n, int k) 
    {
        if(k == 1)
            return '0';
        int pos = 1 << (n - 1);
        if(k == pos)
            return '1';
        else if(k < pos)
            return findKthBit(n - 1, k);
        else
        {
            k = 2 * pos - k;
            return revert(findKthBit(n - 1, k));
        }
    }

    char revert(char c)
    {
        return c == '1' ? '0' : '1';
    }
};
```
