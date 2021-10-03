### 数字转换为十六进制数
### Convert a Number to Hexadecimal

> 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。  
> 注意:  
> 1. 十六进制中所有字母(`a-f`)都必须是小写。  
> 2. 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符`'0'`来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。   
> 3. 给定的数确保在32位有符号整数范围内。  
> 4. **不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法**。

> Given an integer `num`, return *a string representing its hexadecimal representation*. For negative integers, two’s complement method is used.  
> All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.  
> **Note**: You are not allowed to use any built-in library method to directly solve this problem.  

----------

#### I 位运算 + 模拟

由于返回字符串，我们可以从高位到低位每4位二进制数进行转换，从第一个不为0的数字开始记录字符串，  
由于从最高位开始，可以利用 `>>` 和 `&` 运算符，将从高到低位置的数字依次单独记录下来，每次利用 `'0' + val` 或者 `'0' + val - 10` 的方式将其转化为字符，  
待从低位到高位所有位置的数字都遍历结束后，可以获得完整的转化字符串  

```cpp
string toHex(int num) 
{
    if(num == 0)
        return "0";
    string ret;
    for (int i = 7; i >= 0; i --)
    {
        int val = (num >> (4 * i)) & 0xf;
        if(ret.length() > 0 || val > 0)
        {
            char digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10);
            ret.push_back(digit);
        }
    }
    return ret;
}
```
