### 转换成小写字母
### To Lower Case

> 给你一个字符串 `s`，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。  

> Given a string `s`, return *the string after replacing every uppercase letter with the same lowercase letter*.  

----------

#### I 位运算

可以发现，所有大小写对应字母的低四位都相同，高四位只有第 2 位不同（一个为 `0`，一个为 `1`）  
可以直接利用位运算求解

```cpp
string toLowerCase(string s) 
{
    for(auto& c: s)
        if(isalpha(c))
            c |= 0x20;
    return s;
}
```
