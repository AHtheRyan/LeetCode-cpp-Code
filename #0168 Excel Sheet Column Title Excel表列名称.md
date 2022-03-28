### Excel表列名称
### Excel Sheet Column Title

> 给你一个整数 `columnNumber`，返回它在 Excel 表中相对应的列名称。  

> Given an integer `columnNumber`, return *its corresponding column title as it appears in an Excel sheet*.  

----------

#### I 进制转换模拟

显然这是一个以 `26` 为进位的**数字->字母**的进制转换，按照进制转换进行模拟即可  

```cpp
string convertToTitle(int columnNumber) 
{
    string ret = "";
    while(columnNumber--)
    {
        ret += ((columnNumber % 26) + 'A');
        columnNumber /= 26;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
```
