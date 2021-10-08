### 重复的DNA序列
### Repeated DNA Sequences

> 所有 DNA 都由一系列缩写为 `'A'`，`'C'`，`'G'` 和 `'T'` 的核苷酸组成，例如：`"ACGAATTCCG"`。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。  
> 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 `s` 中出现次数超过一次。  

> The **DNA sequence** is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.  
> - For example, `"ACGAATTCCG"` is a **DNA sequence**.  
> 
> When studying **DNA**, it is useful to identify repeated sequences within the DNA.  
> Given a string `s` that represents a **DNA sequence**, return all the **`10`-letter-long** sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in **any order**.  

----------

#### I 哈希表

遍历字符串，将每个长度为 10 的子串都记录在哈希表中，如果某个字符串出现的次数超过 1 次，则将其加入返回队列中  

```cpp
vector<string> findRepeatedDnaSequences(string s) 
{
  unordered_map<string, int> hash;
  for(int i = 0; s.size() > 9 && i < s.size() - 9; ++i)
  {
      string cur = s.substr(i, 10);
      ++hash[cur];
  }
  vector<string> ret;
  for(auto h : hash)
      if(h.second > 1)
          ret.push_back(h.first);
  return ret;
}
```

#### II 滑动窗口 + 位运算

方法I中，当我们遍历字符串，很多字符会被使用10次（作为字符串的末尾->作为字符串的开头）  
因此，可以采用数字代替字符，通过滑动窗口重复利用字符串中一直存在的数字  
由于只存在四种碱基，可以将其设置成二进制数字，每个字符占据两个位，这样就极大节约了空间  
我们可以依此构建数据，将其存入哈希表，剩下部分同方法I

```cpp
vector<string> findRepeatedDnaSequences(string s) 
{
    int len = s.size();
    if(len <= 10)
        return {};
    unordered_map<char, int> tsfm{{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};
    int cur = 0;
    unordered_map<int, int> cnt;
    vector<string> ret;
    for(int ptr = 0; ptr < 9; ++ptr)
        cur = (cur << 2) | tsfm[s[ptr]];
    for(int ptr = 0; ptr < len - 9; ++ptr)
    {
        cur = ((cur << 2) | tsfm[s[ptr + 9]]) & ((1 << 20) - 1);
        ++cnt[cur];
        if(cnt[cur] == 2)
            ret.push_back(s.substr(ptr, 10));
    }
    return ret;
}
```
