### 亲密字符串
### Buddy Strings

> 给你两个字符串 `s` 和 `goal`，只要我们可以通过交换 `s` 中的两个字母得到与 `goal` 相等的结果，就返回 `true`；否则返回 `false`。  
> 交换字母的定义是：取两个下标 `i` 和 `j`（下标从 `0` 开始）且满足 `i != j`，接着交换 `s[i]` 和 `s[j]` 处的字符。  
> - 例如，在 `"abcd"` 中交换下标 `0` 和下标 `2` 的元素可以生成 `"cbad"`。 

> Given two strings `s` and `goal`, return `true` *if you can swap two letters in `s` so the result is equal to `goal`, otherwise, return `false`*.  
> Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `s[i]` and `s[j]`.  
> - For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.  

----------

#### I 枚举

针对两个原字符串进行枚举即可，满足题目条件的字符串有两种情况：
1. 正好有两对字母不同
2. 完全相同，但某个字母出现次数大于等于 `2` 次（这样可以交换相同的字母但不改变原有的字符串）  

以此为基础进行枚举即可

```cpp
bool buddyStrings(string s, string goal) 
{
    if(s.size() != goal.size())
        return false;
    int ptr = 0;
    int cnt = 0;
    int i1 = -1;
    int i2 = -1;
    vector<int> letter(26, 0);
    bool flag = false;
    while(ptr < s.size())
    {
        if(s[ptr] != goal[ptr])
        {
            if(cnt == 0)    i1 = ptr;
            else if(cnt == 1)   i2 = ptr;
            else    return false;
            ++cnt;
        }
        else if(++letter[s[ptr] - 'a'] == 2)    
            flag = true;
        ++ptr;
    }
    if(cnt == 0 && flag || cnt == 2 && s[i1] == goal[i2] && s[i2] == goal[i1])
        return true;
    return false;
}
```
