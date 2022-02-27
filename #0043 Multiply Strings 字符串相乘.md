### 字符串相乘
### Multiply Strings

> 给定两个以字符串形式表示的非负整数 `num1` 和 `num2`，返回 `num1` 和 `num2` 的乘积，它们的乘积也表示为字符串形式。  

> Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.  

----------

#### I 标准乘法运算

按照标准乘法的运算规则进行运算  
将某一个乘数拆分成一位一位，分别与另一个乘数进行乘法运算  
最后将所有乘法的结果相加即可  

```cpp
class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        if(num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size();
        reverse(num1.begin(), num1.end());
        string ret;
        for(int i = 0; i < n; ++i)
        {
            string cur(i, '0');
            cur += multi(num1[i] - '0', num2);
            ret = add(ret, cur);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string multi(int factor, string num)
    {
        int flag = 0;
        reverse(num.begin(), num.end());
        string ret;
        for(int i = 0; i < num.size(); ++i)
        {
            int sum = flag + factor * (num[i] - '0');
            ret += sum % 10 + '0';
            flag = sum / 10;
        }
        if(flag > 0)
            ret += to_string(flag);
        return ret;
    }

    string add(string ret, string cur)
    {
        int n = ret.size() > cur.size() ? ret.size() : cur.size();
        int ptr = 0;
        int flag = 0;
        string s;
        while(ptr < n)
        {
            int num1 = ptr < ret.size() ? ret[ptr] - '0' : 0;
            int num2 = ptr < cur.size() ? cur[ptr] - '0' : 0;
            int sum = num1 + num2 + flag;
            s += sum % 10 + '0';
            flag = sum / 10;
            ++ptr;
        }
        if(flag > 0)
            s += to_string(flag);
        return s;
    }
};
```
#### II 标准乘法运算v2.0

1. 两个分别为 `m` 和 `n` 位的数字相乘，其积的位数不会超过 `m + n` 位  
2. 两个数字相乘可以看做某个数字的每一位分别与另一个数字相乘后求和  

利用上面两个性质，可以快速得出相乘的算法  
需要注意的是：  
1. 字符串中数字是高位到低位排列的  
2. 两个数字的第 `i` 位和第 `j` 位相乘，其结果应该位于第 `i + j - 1` 位  

```cpp
string multiply(string num1, string num2)
{
    if (num1[0] == '0' || num2[0] == '0')
        return "0";
    int size1 = num1.size();
    int size2 = num2.size();
    vector<int> digit(size1 + size2);
    for (int i = size1 - 1; i >= 0; --i)
    {
        int a = num1[i] - '0';
        for (int j = size2 - 1; j >= 0; --j)
        {
            int b = num2[j] - '0';
            digit[i + j + 1] += a * b;
        }
    }
    for (int i = size1 + size2 - 1; i > 0; --i)
    {
        digit[i - 1] += digit[i] / 10;
        digit[i] = digit[i] % 10;
    }
    string ret;
    int start = digit[0] == 0 ? 1 : 0;
    for (; start < size1 + size2; ++start)
        ret += to_string(digit[start]);
    return ret;
}
```
