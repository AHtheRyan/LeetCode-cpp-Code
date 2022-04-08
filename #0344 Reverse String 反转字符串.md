### 反转字符串
### Reverse String

> 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `s` 的形式给出。  

> Write a function that reverses a string. The input string is given as an array of characters `s`.  

----------

#### I 简单遍历

每次将当前位置 `i` 和 `n - i - 1` 位置的字符交换，遍历到一半时停止即可  

```cpp
void reverseString(vector<char>& s) 
{
    int n = s.size();
    for(int i = 0; i < n / 2; ++i)
        swap(s[i], s[n - i - 1]);
}
```
