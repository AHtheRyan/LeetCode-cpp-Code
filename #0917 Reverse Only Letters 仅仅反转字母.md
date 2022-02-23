### 仅仅反转字母
### Reverse Only Letters

> 给你一个字符串 `s`，根据下述规则反转字符串：  
> - 所有非英文字母保留在原有位置。  
> - 所有英文字母（小写或大写）位置反转。  
> 
> 返回反转后的 `s`。  

> Given a string `s`, reverse the string according to the following rules:  
> - All the characters that are not English letters remain in the same position.  
> - All the English letters (lowercase or uppercase) should be reversed.  
> 
> Return *`s` after reversing it*.  

----------

#### I 双指针

利用左右两个指针向中间收拢，遇到字母就交换，否则指针直接变化一位就可以  

```cpp
string reverseOnlyLetters(string s) 
{
    int n = s.size();
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        while(!isalpha(s[left]) && left < right)
            ++left;
        while(!isalpha(s[right]) && left < right)
            --right;
        swap(s[left++], s[right--]);
    }
    return s;
}
```
