### 最小覆盖子串
### Minimum Window Substring

> 给你一个字符串 `s`、一个字符串 `t`。返回 `s` 中涵盖 `t` 所有字符的最小子串。如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串 `""`。  
> **注意**：  
> - 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量。  
> - 如果 `s` 中存在这样的子串，我们保证它是唯一的答案。  

> Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the **minimum window substring** of `s` such that every character in `t` (**including duplicates**) is included in the window. If there is no such substring, return the empty string `""`*.  
> The testcases will be generated such that the answer is **unique**.  
> A **substring** is a contiguous sequence of characters within the string.  

----------

#### I 哈希表 + 滑动窗口

被覆盖子串中的主要参数有两个，一个是不同的字母，一个是不同字母出现的次数，  
因此，如果要处理长字符串，应该事先将被覆盖子串的这两个参数记录，这样可以方便对长字符串的处理，  
处理长字符串时，可以利用双指针，其中 `left` 先不动，`right` 右移，直到能够完全覆盖被覆盖串，  
之后，将 `left` 指针向右移动，比较长字符串子串与记录的最短子串的长度，取较短者，直到取到最短，  
按照此思路遍历整个字符串即可  

```cpp
string minWindow(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();
    int minleft = -1;
    int length = INT_MAX;
    int left = 0;
    int allcount = 0;
    vector<int> count(58);
    vector<bool> hash(58);
    for (int i = 0; i < tlen; ++i)
    {
        count[t[i] - 'A']++;
        hash[t[i] - 'A'] = true;
    }
    for (int right = 0; right < slen; ++right)
    {
        if (hash[s[right] - 'A'])
            if (--count[s[right] - 'A'] >= 0)
                ++allcount;
        while (allcount == tlen)
        {
            if (right - left + 1 < length)
            {
                length = right - left + 1;
                minleft = left;
            }
            if (hash[s[left] - 'A'] && ++count[s[left] - 'A'] > 0)
                --allcount;
            ++left;
        }
    }
    return length > slen ? "" : s.substr(minleft, length);
}
```
