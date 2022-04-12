### 写字符串需要的行数
### Number of Lines To Write String

> 我们要把给定的字符串 `S` 从左到右写到每一行上，每一行的最大宽度为100个单位，如果我们在写某个字母的时候会使这行超过了100 个单位，那么我们应该把这个字母写到下一行。我们给定了一个数组 `widths`，这个数组 widths[0] 代表 'a' 需要的单位， widths[1] 代表 'b' 需要的单位，...， widths[25] 代表 'z' 需要的单位。  
> 现在回答两个问题：至少多少行能放下S，以及最后一行使用的宽度是多少个单位？将你的答案作为长度为2的整数列表返回。  

> You are given a string `s` of lowercase English letters and an array `widths` denoting **how many pixels wide** each lowercase English letter is. Specifically, `widths[0]` is the width of `'a'`, `widths[1]` is the width of `'b'`, and so on.  
> You are trying to write `s` across several lines, where **each line is no longer than `100` pixels**. Starting at the beginning of `s`, write as many letters on the first line such that the total width does not exceed 100 pixels. Then, from where you stopped in s, continue writing as many letters as you can on the second line. Continue this process until you have written all of `s`.  
> Return *an array `result` of length 2 where*:  
> - `result[0]` *is the total number of lines*.  
> - `result[1]` *is the width of the last line in pixels*.  

----------

#### I 模拟

简单模拟

```cpp
vector<int> numberOfLines(vector<int>& widths, string s) 
{
    int line = 0;
    int curLen = 0;
    for(auto& c : s)
    {
        if(curLen + widths[c - 'a'] <= 100)
            curLen += widths[c - 'a'];
        else
        {
            ++line;
            curLen = widths[c - 'a'];
        }
    }
    return {line + 1, curLen};
}
```
