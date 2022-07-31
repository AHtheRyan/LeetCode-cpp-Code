### 生成每种字符都是奇数个的字符串
### Generate a String With Characters That Have Odd Counts

> 给你一个整数 `n`，请你返回一个含 `n` 个字符的字符串，其中每种字符在该字符串中都恰好出现**奇数次**。  
> 返回的字符串必须只含小写英文字母。如果存在多个满足题目要求的字符串，则返回其中任意一个即可。  

> Given an integer `n`, *return a string with `n` characters such that each character in such string occurs **an odd number of times***.  
> The returned string must contain only lowercase English letters. If there are multiples valid strings, return **any** of them.  

----------

#### I 模拟

简单模拟

````cpp
string generateTheString(int n) 
{
    if(n % 2)
        return string(n, 'a');
    else
        return string(n - 1, 'a') + "b";
}
```
