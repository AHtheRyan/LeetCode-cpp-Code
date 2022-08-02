### 有序队列
### Orderly Queue

> 给定一个字符串 `s` 和一个整数 `k`。你可以从 `s` 的前 `k` 个字母中选择一个，并把它加到字符串的末尾。  
> 返回*在应用上述步骤的任意数量的移动后，字典上最小的字符串*。  

> You are given a string `s` and an integer `k`. You can choose one of the first `k` letters of `s` and append it at the end of the string..  
> Return *the lexicographically smallest string you could have after applying the mentioned step any number of moves*.  

----------

#### I 分类讨论

- 当 `k` 为 `1` 时，可以简单计算出实际的字符串最小为所有情况的最小，可通过循环计算  
- 当 `k` 大于 `1` 时，实际上可以实现任意情况下的排列，因此只需要将字符串排成字典序排列就可以了  

```cpp
string orderlyQueue(string s, int k) 
{
    if(k > 1)
    {
        sort(s.begin(), s.end());
        return s;
    }
    string ret = s;
    int n = s.size();
    for(int i = 0; i < n; ++i)
    {
        string cur = s.substr(i + 1, n - i) + s.substr(0, i + 1);
        if(cur < ret)
            ret = cur;
    }
    return ret;
}
```
