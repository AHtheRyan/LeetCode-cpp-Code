### 分割字符串的最大得分
### Maximum Score After Splitting a String 

> 给你一个由若干 0 和 1 组成的字符串 `s`，请你计算并返回将该字符串分割成两个**非空**子字符串（即**左**子字符串和**右**子字符串）所能获得的最大得分。  
> 「分割字符串的得分」为**左**子字符串中**0**的数量加上**右**子字符串中**1**的数量。  

> Given a string `s` of zeros and ones, return *the maximum score after splitting the string into two **non-empty** substrings* (i.e. **left** substring and **right** substring).  
> The score after splitting a string is the number of **zeros** in the **left** substring **plus** the number of ones in the **right** substring.  

----------

#### I 双指针

利用两个数组分别记录在不同位置分割后左右的得分，再进行累加比较即可  

```cpp
int maxScore(string s) 
{
    int n = s.size();
    vector<int> left(n);
    vector<int> right(n);
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '0')
            left[i] = i == 0 ? 1 : left[i - 1] + 1;
        else
            left[i] = i == 0 ? 0 : left[i - 1];
        if(s[n - 1 - i] == '1')
            right[n - 1 - i] = i == 0 ? 1 : right[n - i] + 1;
        else
            right[n - 1 - i] = i == 0 ? 0 : right[n - i];
    }
    int ret = 0;
    for(int i = 0; i < n - 1; ++i)
        ret = max(ret, left[i] + right[i + 1]);
    return ret;
}
```
