### 扰乱字符串
### Scramble String

> 使用下面描述的算法可以扰乱字符串 `s` 得到字符串 `t`：  
> 1. 如果字符串的长度为 1 ，算法停止  
> 2. 如果字符串的长度 > 1 ，执行下述步骤：  
>    - 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 `s`，则可以将其分成两个子字符串 `x` 和 `y`，且满足 `s = x + y`。  
>    - **随机**决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，`s` 可能是 `s = x + y` 或者 `s = y + x`。  
>    - 在 `x` 和 `y` 这两个子字符串上继续从步骤 1 开始递归执行此算法。  
> 
> 给你两个**长度相等**的字符串 `s1` 和 `s2`，判断 `s2` 是否是 `s1` 的扰乱字符串。如果是，返回 `true`；否则，返回 `false`。  

> We can scramble a string s to get a string t using the following algorithm:  
> 1. If the length of the string is 1, stop.  
> 2. If the length of the string is > 1, do the following:  
>    - Split the string into two non-empty substrings at a random index, i.e., if the string is `s`, divide it to `x` and `y` where `s = x + y`.  
>    - Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, `s` may become `s = x + y` or `s = y + x`.  
>    - Apply step 1 recursively on each of the two substrings `x` and `y`.  
> Given two strings `s1` and `s2` of the same length, return `true` if `s2` is a scrambled string of `s1`, otherwise, return `false`.  

----------

#### I 动态规划

基于分治的思想，对字符串进行分割比较，分割的过程可以采用动态规划的方式实现  

```cpp
class Solution 
{
private:
    string s1, s2;
    int memo[30][30][31];

public:
    bool isScramble(string s1, string s2) 
    {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }

    bool check(int i1, int i2, int length)
    {
        unordered_map<char, int> mp;
        for(int i = i1; i < i1 + length; ++i)
            ++mp[s1[i]];
        for(int i = i2; i < i2 + length; ++i)
            --mp[s2[i]];
        if(any_of(mp.begin(), mp.end(), [](const auto& entry){return entry.second != 0;}))
            return false;
        return true;
    }

    bool dfs(int i1, int i2, int length) 
    {
        if (memo[i1][i2][length])
            return memo[i1][i2][length] == 1;
        if (s1.substr(i1, length) == s2.substr(i2, length)) 
        {
            memo[i1][i2][length] = 1;
            return true;
        }
        if (!check(i1, i2, length)) 
        {
            memo[i1][i2][length] = -1;
            return false;
        }
        for (int i = 1; i < length; ++i) 
        {
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) 
            {
                memo[i1][i2][length] = 1;
                return true;
            }
            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) 
            {
                memo[i1][i2][length] = 1;
                return true;
            }
        }
        memo[i1][i2][length] = -1;
        return false;
    }
};
```
