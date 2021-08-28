### 反转字符串 II
### Reverse String II

> 给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每 `2k` 个字符反转前 `k` 个字符。
> - 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
> - 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。  

> Given a string `s` and an integer `k`, reverse the first `k` characters for every `2k` characters counting from the start of the string.  
> - If there are fewer than `k` characters left, reverse all of them.  
> - If there are less than `2k` but greater than or equal to `k` characters, then reverse the first `k` characters and left the other as original.  

----------

#### I 模拟

题目要求先反转 `k` 个字符，再保持不变 `k` 个字符，再反转 `k` 个字符，……，只到遍历结束字符串，  
因此，可以利用 `reverse` 函数，根据题意分间隔将原字符串反转  

```cpp
string reverseStr(string s, int k) 
{
    int slen = s.size();
    for(int i = 0; i < slen; i += 2 * k)
        reverse(s.begin() + i, s.begin() + min(i + k, slen));
    return s;
}
```
