### 重复的字符串
### Repeated Substring Pattern

> 给定一个非空的字符串 `s`，检查是否可以通过由它的一个子串重复多次构成。  

> Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.  

----------

#### I KMP算法

基于KMP算法进行字符串匹配：  
将原字符串扩展为两倍的重复长度，再用原字符串匹配，如果能在中间匹配到，则字符串重复，否则不重复  

```cpp
class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        return kmp(s + s, s);
    }

    bool kmp(const string& s, const string& mod)
    {
        int n = mod.size();
        vector<int> next(n);
        int cmpPtr = 0;
        int curPtr = 1;
        while(curPtr < mod.size())
        {
            if(mod[cmpPtr] == mod[curPtr])
            {
                ++cmpPtr;
                next[curPtr] = cmpPtr;
                ++curPtr;
            }
            else if(cmpPtr > 0)
                cmpPtr = next[cmpPtr - 1];
            else
                ++curPtr;
        }

        int m = s.size();
        int sptr = 1;
        int modptr = 0;
        while(sptr < s.size() && modptr < mod.size())
        {
            if(s[sptr] == mod[modptr])
            {
                ++sptr;
                ++modptr;
            }
            else if(modptr > 0)
                modptr = next[modptr - 1];
            else
                ++sptr;
        }
        return modptr == mod.size() && sptr != s.size();
    }
};
```
