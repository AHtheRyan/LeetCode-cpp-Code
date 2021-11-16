### 最长回文子串
### Longest Palindromic Substring

> 给你一个字符串 `s`，找到 `s` 中最长的回文子串。  

> Given a string `s`, return the longest palindromic substring in `s`.

----------

#### I 动态规划

任意回文串去掉左右两边的字母一定还是回文串，所以这里可以采用动态规划，先记录最短长度的回文串，再根据该回文串进行两端拓展的判断  
1. 单个字符一定是回文，所以直接确定其为回文串，即对任意位置`i`，`dp[i][i] = 1`，可将其视为**动态规划数组dp**的初始化  
2. 接下来以子串长度为`2`开始进行遍历：  
   - 考虑连续两个字符，如果两字符相同，则一定是回文串  
   - 考虑连续三个字符，如果字符串的第一个和第三个字符相同，则一定是回文串  
3. 字符串长度超过 `3` 时，比较左右两侧两个字符  
   - 如果两个字符串不同，则显而易见该段字符串一定不是回文串  
   - 如果两个字符相同，即 `s[i] = s[j]`，则  
     - 如果去掉位置 `i` 和 `j` 之后的字符串为回文串，即 `dp[i+1][j-1]` 为回文串，则扩展后也是回文串  
     - 如果起吊位置 `i` 和 `j` 之后的字符串不为回文串，即 `dp[i+1][j-1]` 不为回文串，则扩展后不是回文串  

```cpp
string longestPalindrome(string s)
{
    int len = s.size();
    if (len < 2)
        return s;

    vector<vector<bool>> dp(len, vector<bool>(len));
    for (int i = 0; i < len; ++i)
        dp[i][i] = true;

    int max = 1;
    int start = 0;
    for (int substrLen = 2; substrLen <= len; ++substrLen)
    {
        for (int left = 0; left < len; ++left)
        {
            int right = left + substrLen - 1;
            if (right >= len)
                break;
            if (s[right] != s[left])
                dp[left][right] = false;
            else
            {
                if (right - left < 3)
                    dp[left][right] = true;
                else
                    dp[left][right] = dp[left + 1][right - 1];
            }
            if (dp[left][right] && right - left + 1 > max)
            {
                max = right - left + 1;
                start = left;
            }
        }
    }
    return s.substr(start, max);
}
```

#### II 中心拓展

根据回文串的定义可知，回文串必然存在对称中心，因此，可以分别以每一个字符为对称中心，向两边拓展来判断是否回文，  
为了方便处理，我们设计一个专门进行拓展的函数 `expand`，以输入的字符串起始位置开始进行判断：  
1. 如果两边的字符相同，则记录两边的位置，继续向两边拓展  
2. 如果两边的字符不同，或者遇到了字符串的边界（开头与结尾），则记录两边的位置并停止拓展
3. 将记录的位置作为返回值  

值得注意的是，存在单字符作为对称中心与双字符作为对称中心两种模式，即 `aba` 与 `aa` 两种模式，  
因此，输入的拓展起始点应该包括两种模式，  
接下来在主函数中，可以遍历整个字符串，并不断更新字符串的回文长度，最后返回最大的长度所在的子串即可  

```cpp
vector<int> expand(string &s, int start1, int start2)
{
    int left = start1;
    int right = start2;
    while(left >=0 && right <= s.size() - 1 && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

string longestPalindrome(string s) 
{
    int retleft = 0; 
    int retright = 0;
    vector<int> palidrome1(2);
    vector<int> palidrome2(2);
    for(int i = 0; i < s.size(); ++i)
    {
        palidrome1 = expand(s, i, i);
        palidrome2 = expand(s, i, i + 1);
        if(palidrome1[1] - palidrome1[0] > retright - retleft)
        {
            retleft = palidrome1[0];
            retright = palidrome1[1];
        }
        if(palidrome2[1] - palidrome2[0] > retright - retleft)
        {
            retleft = palidrome2[0];
            retright = palidrome2[1];
        }
    }
    return s.substr(retleft, retright - retleft + 1);
}
```

#### III Manacher算法

此方法是中心拓展法的优化延伸  
在进行中心拓展的过程中，我们对把一个位置的字符作为对称中心进行了回文串的判断，  
但是这样就导致了一种资源的浪费，例如：  
对于一个较长的回文子串 `……abacaba……`，根据中心拓展法，我们首先确定了 `aba` 为一个子串，之后确定了 `abacaba` 为一个回文子串，  
那么，当我们判断到右侧的 `b` 的时候，因为右侧的 `aba` 与左侧的 `aba` 关于 `c` 中心对称，  
所以右侧中心拓展的时候如果从 `b` 开始，就会导致资源的浪费，  
也即，右侧可以从左侧获得对称信息，之后直接从两个 `a` 的左右两侧开始进行中心对称的拓展即可，不需要再从 `b` 开始，  
因此，可以设置一个数组 `arm` 记录每个位置的对称的臂的长度，并设置变量 `end` 单独记录回文串对应的臂长所在的最右端点的位置，  
再设置变量 `center` 记录当前最长回文串的对称中心，`expand` 函数与中心拓展法相同，只不过现在返回的是某位置的对称长度。  
主函数的遍历过程如下：  
1. 分析该字符的下标
   - 如果比 `end` 大，即该字符已经不存在可以事先利用的对称中心，则直接进行中心拓展操作  
   - 如果比 `end` 小，则查找该位置关于对称中心的位置的对称点的对称臂的长度，考虑边界情况，取 `end - i` 和对称点臂长中的较小者  
   - 在 `arm` 中存下该位置对应的对称臂的长度  
2. 如果当前字符下标 + 对称臂长度 > 原来的最右端 `end`，则更新 `end`  
3. 如果当前子回文串长度大于原来记录的回文串，则更新左右端点  

遍历结束后返沪最长子串即可  
分析上面可以看到，如果回文子串长度为偶数，即 `abba`，此种类型就不存在独立的对称中心，  
我们可以预处理字符串，在每一个字符中间加上不相关的字符如 `#`，这样就可以使得所有字符串都变成奇数长度。  

```cpp
int expand(string &s, int left, int right)
{
    while(left >=0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return (right - left - 2) / 2;
}

string longestPalindrome(string s) 
{
    string t = "#";
    for(auto c : s)
        t = t + c + '#';
    int left = 0;
    int right = 0;
    vector<int> arm;
    int end = -1;
    int center = 0;
    for(int i = 0; i < t.size(); ++i)
    {
        int cur = 0;
        if(i > end)
            cur = expand(t, i, i);
        else
        {
            int i_sym = 2 * center - i;
            int curminarm = min(arm[i_sym], end - i);
            cur = expand(t, i - curminarm, i + curminarm);
        }
        arm.push_back(cur);
        if(i + cur > end)
        {
            end = i + cur;
            center = i;
        }
        if(2 * cur > right - left)
        {
            right = i + cur;
            left = i - cur;
        }
    }
    string ret = "";
    for(int i = left; i <= right; ++i)
        if(t[i] != '#')
            ret += t[i];
    return ret;
}
```
