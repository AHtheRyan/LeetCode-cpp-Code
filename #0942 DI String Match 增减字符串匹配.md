### 增减字符串匹配
### DI String Match

> 由范围 `[0,n]` 内所有整数组成的 `n + 1` 个整数的排列序列可以表示为长度为 `n` 的字符串 `s`，其中:  
> - 如果 `perm[i] < perm[i + 1]`，那么 `s[i] == 'I'`  
> - 如果 `perm[i] > perm[i + 1]`，那么 `s[i] == 'D'`  
> 
> 给定一个字符串 `s`，重构排列 `perm` 并返回它。如果有多个有效排列perm，则返回其中**任何一个**。  

> A permutation `perm` of `n + 1` integers of all the integers in the range `[0, n]` can be represented as a string `s` of length `n` where:  
> - `s[i] == 'I'` if `perm[i] < perm[i + 1]`, and  
> - `s[i] == 'D'` if `perm[i] > perm[i + 1]`.  
> 
> Given a string `s`, reconstruct the permutation `perm` and return it. If there are multiple valid permutations perm, return **any of them**.  

----------

#### 贪心

- 每当遇到 `'I'`，我们总取可以取得最小的值，并将最小值加一  
- 每当遇到 `'D'`，我们总取可以取的最大的值，并将最大值减一  
按此规律进行贪心模拟即可  

```cpp
vector<int> diStringMatch(string s) 
{
    int n = s.size();
    vector<int> ret(n + 1);
    int left = 0;
    int right = n;
    for(int i = 0; i < n + 1; ++i)
    {
        if(s[i] == 'I')
            ret[i] = left++;
        else
            ret[i] = right--;
    }
    return ret;
}
```
