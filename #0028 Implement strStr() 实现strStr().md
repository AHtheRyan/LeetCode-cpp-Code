### 实现strStr()
### Implement strStr()

> 实现 `strStr()` 函数。  
> 给你两个字符串 `haystack` 和 `needle`，请你在 `haystack` 字符串中找出 `needle` 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  `-1`。  

> Implement `strStr()`.  
> Return the index of the first occurrence of needle in haystack, or `-1` if `needle` is not part of `haystack`.  

----------

#### I KMP算法

暴力解法很简单，这里不提了  
为了节约时间，可以采用KMP算法进行相关的字符串匹配  
KMP算法的核心在于将匹配字符串 `needle` 进行预处理，得到字符串中不同位置开始重复的部分，在匹配时按重复的部分进行移动匹配，  
这样就减少了匹配的次数  
KMP算法在《数据结构》课上有讲过，或者可以通过 [知乎](https://www.zhihu.com/question/21923021)等途径进行学习理解

```cpp
class Solution 
{
public:
    int strStr(string& haystack, string& needle) 
    {
        if(needle.size() == 0)
            return 0;
        vector<int> next = makeNext(needle);
        int m = haystack.size();
        int n = needle.size();
        int index = 0;
        int cmp = 0;
        while(index < m)
        {
            while(cmp > 0 && haystack[index] != needle[cmp])
                cmp = next[cmp - 1];
            if(haystack[index] == needle[cmp])
                ++cmp;
            if(cmp == n)
                return index - cmp + 1;
            ++index;
        }
        return -1;
    }

    vector<int> makeNext(string& s)
    {
        int n = s.size();
        vector<int> next(n);
        int cmp = 0;
        for(int index = 1; index < n; ++index)
        {
            while(cmp > 0 && s[index] != s[cmp])
                cmp = next[cmp - 1];
            if(s[index] == s[cmp])
                ++cmp;
            next[index] = cmp;
        }
        return next;
    }
};
```
