### 最长特殊序列 I
### Longest Uncommon Subsequence I

> 给你两个字符串 `a` 和 `b`，请返回*这两个字符串中**最长的特殊序列***。如果不存在，则返回 `-1`。  
> **「最长特殊序列」** 定义如下：该序列为**某字符串独有的最长子序列（即不能是其他字符串的子序列）**。  
> 字符串 `s` 的子序列是在从 `s` 中删除任意数量的字符后可以获得的字符串。  
> - 例如，`“abc”` 是 `“aebdc”` 的子序列，因为您可以删除 `“aebdc”` 中的下划线字符来得到 `“abc”`。`“aebdc”` 的子序列还包括 `“aebdc”`、`“aeb”` 和 `“”` (空字符串)。  

> Given two strings `a` and `b`, return *the length of the **longest uncommon subsequence** between `a` and `b`*. If the longest uncommon subsequence does not exist, return `-1`.  
> An **uncommon subsequence** between two strings is a string that is **a subsequence of one but not the other**.  
> A **subsequence** of a string `s` is a string that can be obtained after deleting any number of characters from `s`.  
> - For example, `"abc"` is a subsequence of `"aebdc"` because you can delete the underlined characters in `"aebdc"` to get `"abc"`. Other subsequences of `"aebdc"` include `"aebdc"`, `"aeb"`, and `""` (empty string).  

----------

#### I 直接比较

根据定义，只有当两个字符串相同时才返回 `-1`  
否则直接返回较长字符串的长度，因为其必然不在另一字符串子串中  

```cpp
int findLUSlength(string a, string b) 
{
    return a == b ? -1 : max(a.size(), b.size());
}
```
