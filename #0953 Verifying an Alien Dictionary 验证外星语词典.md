### 验证外星语词典
### Verifying an Alien Dictionary

> 某种外星语也使用英文小写字母，但可能顺序 `order` 不同。字母表的顺序（`order`）是一些小写字母的排列。  
> 给定一组用外星语书写的单词 `words`，以及其字母表的顺序 `order`，只有当给定的单词在这种外星语中按字典序排列时，返回 `true`；否则，返回 `false`。  

> In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.  
> Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographically in this alien language.  

----------

#### I 哈希表 + 模拟

利用哈希表记录每个字母在外星语词典中的词典序，然后对单词按照该顺序进行比较即可  

```cpp
bool isAlienSorted(vector<string>& words, string order) 
{
    int index = 0;
    int n = words.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < 26; ++i)
        mp[order[i]] = i;
    while(index < n - 1)
    {
        string w1 = words[index];
        string w2 = words[index + 1];
        if(mp[w1[0]] < mp[w2[0]])
            ++index;
        else if(mp[w1[0]] > mp[w2[0]])
            return false;
        else
        {
            int n1 = w1.size();
            int n2 = w2.size();
            int i = 0;
            bool flag = false;
            while(i < n1 && i < n2)
            {
                if(w1[i] == w2[i])
                {
                    ++i;
                    if(i == n1 || i == n2)
                    {
                        flag = true;
                        break;
                    }
                }
                else if(mp[w1[i]] < mp[w2[i]])
                    break;
                else if(mp[w1[i]] > mp[w2[i]])
                    return false;
            }
            if(flag && n1 > n2)
                return false;
            ++index;
        }
    }
    return true;
}
```
