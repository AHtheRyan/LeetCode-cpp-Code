### 打印从1到最大的n位数

> 输入数字 `n`，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。  

----------

#### I 模拟

不考虑大数则无脑模拟即可  

```cpp
vector<int> printNumbers(int n) 
{
    int limit = 1;
    while(n-- > 0)
        limit *= 10;
    vector<int> ret(limit - 1);
    for(int i = 0; i < limit - 1; ++i)
        ret[i] = i + 1;
    return ret;
}
```
