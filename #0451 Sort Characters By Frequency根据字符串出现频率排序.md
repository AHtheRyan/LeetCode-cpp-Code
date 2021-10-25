### 根据字符出现的频率排序
### Sort Characters By Frequency

> 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。  

> Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.  
> Return *the sorted string*. If there are multiple answers, return *any of them*.

----------

#### I 桶排序

先利用哈希表记录下每个字母的出现次数，  
随后设置不同次数为不同的“桶”，将字母反向装入桶中，  
最后按字母出现的次数降序输出即可

```cpp
string frequencySort(string s) 
{
    unordered_map<char, int> mp;
    int maxele = 0;
    for(auto c : s)
        maxele = max(maxele, ++mp[c]);
    vector<vector<char>> barrel(maxele + 1);
    for(auto it : mp)
        barrel[it.second].push_back(it.first);
    string ret;
    for(int i = maxele; i >= 0; --i)
    {
        for(auto n : barrel[i])
            ret += string(i, n);
    }
    return ret;
}
```
