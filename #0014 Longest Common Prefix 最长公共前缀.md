### 最长公共前缀
### Longest Common Prefix

> 编写一个函数来查找字符串数组中的最长公共前缀。  
> 如果不存在公共前缀，返回空字符串 `""`。

> Write a function to find the longest common prefix string amongst an array of strings.  
> If there is no common prefix, return an empty string `""`.  

----------

#### I 排序

简单来说，字符串的大小取决于每位字母的ASCII码，  
因此，可直接排序，并利用首位的字符串的公共子串求得结果

```cpp
string longestCommonPrefix(vector<string>& strs) 
{
    sort(strs.begin(), strs.end());
    string ret = "";
    int length = 0;
    int size = min(strs[0].size(), strs[strs.size() - 1].size());
    for(length = 0; length < size; ++length)
        if(strs[0][length] != strs[strs.size() - 1][length])
            break;
    return strs[0].substr(0, length);
}
```
