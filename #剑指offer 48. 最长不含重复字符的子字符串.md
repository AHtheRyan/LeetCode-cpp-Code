### 最长不含重复字符的子字符串

> 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。  

----------

#### I 滑动窗口

见[无重复字符的最长子串](./%230003%20Longest%20Substring%20Without%20Repeating%20Characters%20无重复字符的最长子串.md)

```
int lengthOfLongestSubstring(string s) 
{
    unordered_map<char, bool> mp;
    int left = 0;
    int right = 0;
    int n = s.size();
    int ret = 0;
    while(right < n)
    {
        if(mp.count(s[right]) == 0 || !mp[s[right]])
            mp[s[right]] = true;
        else
        {
            while(s[left] != s[right])
                mp[s[left++]] = false;
            ++left;
        }
        ++right;
        ret = max(ret, right - left);
    }
    return ret;
}
```
