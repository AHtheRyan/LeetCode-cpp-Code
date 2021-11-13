### 无重复字符的最长子串
### Longest Substring Withour Repeating Characters

> 给定一个字符串 `s`，请你找出其中不含有重复字符的 **最长子串** 的长度。  

> Given a string `s`, find the length of the **longest substring** without repeating characters.  

----------

#### I 滑动窗口

利用 `left` 和 `right` 两个指针，其中：  
- `left` 指针始终位于当前 `left` 和 `right` 形成的不含重复字符的子串的左侧，根据 `right` 指针指向的值进行调整
- `right` 指针不断向右遍历更新  

根据二者的关系，建立哈希表，记录每个元素最后出现的位置下标，则逻辑如下：  
1. 如果当前字母未出现过，则哈希表记录，子串长度加一，更新哈希表  
2. 如果当前字母出现过，则  
   - 如果当前字母上一个位置（记录在哈希表中）在 `left` 指针右侧，则 `left` 指针移动至该位置右侧  
   - 如果当前字母上一个位置在 `left` 指针左侧，则 `left` 指针不变  
   
   更新哈希表  

每次的子串长度为 `right - left + 1`  
根据此规律，遍历字符串并更新最长值即可

```cpp
int lengthOfLongestSubstring(string s) 
{
    int longest = 0;
    unordered_map<char, int> mp;
    int left = 0;
    int cur = 0;
    for(int right = 0; right < s.size(); ++right)
    {
        if(mp.find(s[right]) == mp.end())
            mp[s[right]] = right;
        else
        {
            if(mp[s[right]] >= left)
                left = mp[s[right]] + 1;
            mp[s[right]] = right;
        }
        cur = right - left + 1;
        longest = max(longest, cur);
    }
    return longest;
}
```
