### 二进制求和
### Add Binary

> 给你两个二进制字符串，返回它们的和（用二进制表示）。  
> 为**非空**字符串且只包含数字 `1` 和 `0`。  

> Given two binary strings `a` and `b`, return *their sum as a binary string*.  

----------

#### I 按位计算

将两个字符串倒转，按位进行计算，再将计算结果倒转即可  

```cpp
string addBinary(string a, string b) 
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int flag = 0;
    int index = 0;
    string ret = "";
    while(flag || index < a.size() || index < b.size())
    {
        int num1 = index < a.size() ? a[index] - '0' : 0;
        int num2 = index < b.size() ? b[index] - '0' : 0;
        int cur = num1 ^ num2 ^ flag;
        flag = (num1 + num2 + flag) / 2;
        ret += (cur + '0');
        ++index;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
```
