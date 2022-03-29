### Excel表列序号
### Excel Sheet Column Number

> 给你一个字符串 `columnTitle`，表示Excel表格中的列名称。返回*该列名称对应的列序号*。  

> Given a string `columnTitle` that represents the column title as appear in an Excel sheet, return *its corresponding column number*.  

----------

#### I 模拟进制转换

一个简单的26进制转换过程

```cpp
int titleToNumber(string columnTitle) 
{
    int ret = 0;
    for(auto& c : columnTitle)
        ret = ret * 26 + (c - 'A' + 1);
    return ret;
}
```
