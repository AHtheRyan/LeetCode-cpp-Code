### 旋转字符串
### Rotate String

> 给定两个字符串, `s` 和 `goal`。如果在若干次旋转操作之后，`s` 能变成 `goal`，那么返回 `true`。  
> `s` 的**旋转操作**就是将 `s` 最左边的字符移动到最右边。   
> - 例如, 若 `s = 'abcde'`，在旋转一次之后结果就是`'bcdea'`。  

> Given two strings `s` and `goal`, return *`true` if and only if `s` can become `goal` after some number of **shifts** on `s`*.  
> A **shift** on `s` consists of moving the leftmost character of `s` to the rightmost position.  
> - For example, if `s = "abcde"`, then it will be `"bcdea"` after one shift.  

----------

#### I 模拟

满足旋转关系的前提条件是两个字符串的长度相等，之后可以将其中一个字符串成环，如果环中找到了另一字符串，则满足旋转关系  

```cpp
bool rotateString(string s, string goal) 
{
    return s.size() == goal.size() && (s + s).find(goal) != string::npos;
}
```
