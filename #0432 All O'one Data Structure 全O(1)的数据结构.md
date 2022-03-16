### 全O(1)的数据结构
### All O'one Data Structure

> 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。  
> 实现 `AllOne` 类：  
> - `AllOne()` 初始化数据结构的对象。  
> - `inc(String key)` 字符串 `key` 的计数增加 `1`。如果数据结构中尚不存在 `key`，那么插入计数为 `1` 的 `key`。  
> - `dec(String key)` 字符串 `key` 的计数减少 `1`。如果 `key` 的计数在减少后为 `0`，那么需要将这个 `key` 从数据结构中删除。测试用例保证：在减少计数前，`key` 存在于数据结构中。  
> - `getMaxKey()` 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 `""`。  
> - `getMinKey()` 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 `""`。  

> Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.  
> Implement the `AllOne` class:  
> - `AllOne()` Initializes the object of the data structure.  
> - `inc(String key)` Increments the count of the string `key` by `1`. If `key` does not exist in the data structure, insert it with count `1`.  
> - `dec(String key)` Decrements the count of the string `key` by `1`. If the count of `key` is `0` after the decrement, remove it from the data structure. It is guaranteed that `key` exists in the data structure before the decrement.  
> - `getMaxKey()` Returns one of the keys with the maximal count. If no element exists, return an empty string `""`.  
> - `getMinKey()` Returns one of the keys with the minimum count. If no element exists, return an empty string `""`.  

----------

#### I 双向链表 + 哈希表

此题总体思路与[LRU缓存](./%230146%20LRU%20Cache%20LRU缓存.md)相似，可以参考，具体数据结构为双向链表和哈希表

```cpp
class AllOne 
{
private:
    list<pair<unordered_set<string>, int>> lst;
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> mp;

//双链表中出现次数越多越靠后，越少越靠前
public:
    AllOne() 
    {}
    
    void inc(string key) 
    {
        if(mp.count(key) == 0)
        {
            if(lst.empty() || lst.begin()->second > 1)
            {
                unordered_set<string> cur({key});
                lst.emplace_front(cur, 1);
            }
            else
                lst.begin()->first.emplace(key);
            mp[key] = lst.begin();
        }
        else
        {
            auto cur = mp[key];
            auto nxt = next(cur);
            if(nxt == lst.end() || nxt->second > cur->second + 1)
            {
                unordered_set<string> s({key});
                mp[key] = lst.emplace(nxt, s, cur->second + 1);
            }
            else
            {
                nxt->first.emplace(key);
                mp[key] = nxt;
            }
            cur->first.erase(key);
            if(cur->first.empty())
                lst.erase(cur);
        }
    }
    
    void dec(string key) 
    {
        auto cur = mp[key];
        if(cur->second == 1)
            mp.erase(key);
        else
        {
            auto pre = prev(cur);
            if(cur == lst.begin() || pre->second < cur->second - 1)
            {
                unordered_set<string> s({key});
                mp[key] = lst.emplace(cur, s, cur->second - 1);
            }
            else
            {
                pre->first.emplace(key);
                mp[key] = pre;
            }
        }
        cur->first.erase(key);
        if(cur->first.empty())
            lst.erase(cur);
    }
    
    string getMaxKey() 
    {
        return lst.empty() ? "" : *lst.rbegin()->first.begin();
    }
    
    string getMinKey() 
    {
        return lst.empty() ? "" : *lst.begin()->first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
```
