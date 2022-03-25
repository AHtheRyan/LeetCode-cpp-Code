### 验证回文串
### Valid Palindrome

> 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。  
> **说明**：本题中，我们将空字符串定义为有效的回文串。  

> A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.  
> Given a string `s`, return `true` *if it is a **palindrome**, or `false` otherwise*.  

----------

#### I 双指针

按照规则进行模拟，使用双指针从字符串两边进行遍历  

```cpp
bool isPalindrome(string s) 
{
    int left = 0;
    int right = s.size() - 1;
    while(left < right)
    {
        while(left < right && !isalpha(s[left]) && !isdigit(s[left]))
            ++left;
        while(left < right && !isalpha(s[right]) && !isdigit(s[right]))
            --right;
        if(toupper(s[left++]) != toupper(s[right--]))
            return false;
    }
    return true;
}
```
