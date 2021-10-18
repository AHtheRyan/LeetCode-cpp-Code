### 数字的补数
### Number of Complement

> 给你一个**正**整数`num`，输出它的补数。补数是对该数的二进制表示取反。  

> The **complement** of an integer is the integer you get when you flip all the `0's` to `1's` and all the `1's` to `0's` in its binary representation.  
> - For example, The integer `5` is `"101"` in binary and its complement is `"010"` which is the integer `2`.  
> 
> Given an integer `num`, return *its complement*.  

----------

#### I 位运算

取反可直接用位运算符 `^` 进行，唯一需要进行的是求出数字的二进制位数，再进行求补数的操作

```cpp
int findComplement(int num) 
{
    int cnt = 0;
    int tmp = num;
    while(num)
    {
        ++cnt;
        num >>= 1;
    }
    int rep = 0;
    while(cnt)
    {
        rep <<= 1;
        rep |= 1;
        --cnt;
    }
    return tmp ^ rep;
}
```
