### 分割平衡字符串
### Split a String in Balaced Strings

> 在一个**平衡字符串**中，`'L'` 和 `'R'` 字符的数量是相同的。  
> 给你一个平衡字符串 `s`，请你将它分割成尽可能多的平衡字符串。  
> 注意：分割得到的每个字符串都必须是平衡字符串。  
> 返回可以通过分割得到的平衡字符串的 最大数量 。  

> **Balanced** strings are those that have an equal quantity of `'L'` and `'R'` characters.  
> Given a **balanced** string `s`, split it in the maximum amount of balanced strings.  
> Return *the maximum amount of split **balanced** strings*.  

----------

#### I 贪心

由于字符串确定为平衡的，所以首先 `'L'` 和 `'R'` 的数目相等，  
因此，可以设置 `'L'` 和 `'R'` 的二元计数器，分别赋值 `1` 与 `-1`，  
遍历字符串，利用 **Moore投票法** 的思路，每出现一次 `0` 获得一个平衡子串，最后返回总计数即可

```cpp
int balancedStringSplit(string s) 
{
    int ptr = 0;
    int vs = 0;
    int cnt = 0;
    while(ptr < s.size())
    {
        vs = s[ptr] == 'L' ? vs + 1 : vs - 1;
        if(vs == 0)
            ++cnt;
        ++ptr;
    }
    return cnt;
}
```
