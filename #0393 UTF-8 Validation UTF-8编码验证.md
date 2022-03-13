### UTF-8 编码验证
### UTF-8 Validation

> 给定一个表示数据的整数数组 `data`，返回它是否为有效的**UTF-8**编码。  
> **UTF-8**中的一个字符可能的长度为 **1** 到 **4** 字节，遵循以下的规则：  
> 1. 对于 **1 字节** 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。  
> 2. 对于 **n 字节** 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。  
> 
> 这是 UTF-8 编码的工作方式：  
> ![1647178174(1)](https://user-images.githubusercontent.com/46887748/158061619-5a94ec2d-f5c1-47be-85cc-1238b65a94c6.png)  
> **注意**：输入是整数数组。只有每个整数的**最低 8 个有效位**用来存储数据。这意味着每个整数只表示 1 字节的数据。  

> Given an integer array `data` representing the data, return whether it is a valid **UTF-8** encoding.  
> A character in **UTF8** can be from **1 to 4 bytes** long, subjected to the following rules:  
> 1. For a **1-byte** character, the first bit is a `0`, followed by its Unicode code.  
> 2. For an **n-bytes** character, the first `n` bits are all one's, the `n + 1` bit is `0`, followed by `n - 1` bytes with the most significant `2` bits being `10`.  
> 
> This is how the UTF-8 encoding would work:  
> ![1647178174(1)](https://user-images.githubusercontent.com/46887748/158061619-5a94ec2d-f5c1-47be-85cc-1238b65a94c6.png)  
> Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.  

----------

#### I 迭代判断

可以利用位运算判断每个数字在 UTF-8 编码中的“身份”，再对其后面的 `0~3` 组数进行判断，迭代进行，知道判断整个数组  

```cpp
class Solution 
{
public:
    bool validUtf8(vector<int>& data) 
    {
        int n = data.size();
        for(int i = 0; i < n; ++i)
        {
            int cur = checkDigit(data[i]);
            if(cur == -1)
                return false;
            if(cur == 1)
                continue;
            if(cur == 2)
            {
                if(i + 1 < n && checkValid(data[i + 1]))
                    i = i + 1;
                else
                    return false;
            }
            if(cur == 3)
            {
                if(i + 2 < n && checkValid(data[i + 1]) && checkValid(data[i + 2]))
                    i = i + 2;
                else
                    return false;
            }
            if(cur == 4)
            {
                if(i + 3 < n && checkValid(data[i + 1]) && checkValid(data[i + 2]) && checkValid(data[i + 3]))
                    i = i + 3;
                else
                    return false;
            }
        }
        return true;
    }

    int checkDigit(int x)
    {
        int mask = (1 << 7);
        if((x & mask) == 0)   
            return 1;
        int n = 0;
        while((x & mask) != 0)
        {
            ++n;
            if(n > 4)
                return -1;
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }

    bool checkValid(int x)
    {
        return (x & 0xC0 ^ 0x80) == 0;
    }
};
```
