### 字典序排数
### Lexicographical Numbers

> 给你一个整数 `n`，按字典序返回范围 `[1, n]` 内所有整数。  

> Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.  

----------

#### I DFS

根据字典树，如果一个数字乘以 `100` 之后的数字在范围内，则一定要从该乘以 `10` 之后的数字再开始计数，可以由此进行DFS  
当数字数到当前位数的最后一位或者数字比范围大之后，将数字退回到上一个数字中即可  

```cpp
vector<int> lexicalOrder(int n) 
{
    vector<int> ret(n);
    int num = 1;
    for(int i = 0; i < n; ++i)
    {
        ret[i] = num;
        if(num * 10 <= n)
            num *= 10;
        else
        {
            while(num % 10 == 9 || num + 1 > n)
                num /= 10;
            ++num;
        }
    }
    return ret;
}
```
