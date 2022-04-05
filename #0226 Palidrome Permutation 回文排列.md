### 回文排列
### Palidrome Permutation

> 给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。  

> Given a string `s`, return `true` if a permutation of the string could form a palindrome.  

----------

#### I 哈希表

利用哈希表记录每个字符出现的次数，再判断奇数个字符的数量是否小于等于 `1` 即可  

```cpp
bool canPermutePalindrome(string s) 
{
    unordered_map<char, int> mp;
    for(auto& c : s)
        ++mp[c];
    bool flag = false;
    for(auto& p :mp)
    {
        if(p.second % 2 == 1)
        {
            if(!flag)
                flag = !flag;
            else
                return false;
        }
    }
    return true;
}
```
