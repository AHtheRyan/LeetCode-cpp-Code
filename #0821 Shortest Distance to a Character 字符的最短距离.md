### 字符的最短距离
### Shortest Distance to a Character

> 给你一个字符串 `s` 和一个字符 `c`, `c` 是 `s` 中出现过的字符。  
> 返回一个整数数组 `answer`，其中 `answer.length == s.length` 且 `answer[i]` 是 `s` 中从下标 `i` 到离它**最近**的字符 `c` 的**距离**。  
> 两个下标 `i` 和 `j` 之间的**距离**为 `abs(i - j)`，其中 `abs` 是绝对值函数。  

> Given a string `s` and a character `c` that occurs in `s`, return *an array of integers `answer` where `answer.length == s.length` and `answer[i]` is the **distance** from index `i` to the **closest** occurrence of character `c` in `s`*.  
> The **distance** between two indices `i` and `j` is `abs(i - j)`, where `abs` is the absolute value function.  

----------

#### I 两次遍历

进行两次遍历，分别判断字符与其左侧最近的 `c` 的距离和字符与其右侧最近的 `c` 的距离即可  

```cpp
vector<int> shortestToChar(string s, char c) 
{
    int n = s.size();
    vector<int> ret(n);
    int index = -n;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == c)
            index = i;
        ret[i] = i - index;
    }
    index = 2 * n;
    for(int i = n - 1; i >= 0; --i)
    {
        if(s[i] == c)
            index = i;
        ret[i] = min(ret[i], index - i);
    }
    return ret;
}
```
