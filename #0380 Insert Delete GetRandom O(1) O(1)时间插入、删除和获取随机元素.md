### O(1)时间插入、删除和获取随机元素
### Insert Delete GetRandom O(1)

> 实现 `RandomizedSet` 类：  
> - `RandomizedSet()` 初始化 `RandomizedSet` 对象  
> - `bool insert(int val)` 当元素 `val` 不存在时，向集合中插入该项，并返回 `true`；否则，返回 `false`。  
> - `bool remove(int val)` 当元素 `val` 存在时，从集合中移除该项，并返回 `true`；否则，返回 `false`。  
> - `int getRandom()` 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有**相同的概率**被返回。  
> 
> 你必须实现类的所有函数，并满足每个函数的**平均**时间复杂度为 `O(1)`。  

> Implement the `RandomizedSet` class:  
> - `RandomizedSet()` Initializes the RandomizedSet object.  
> - `bool insert(int val)` Inserts an item `val` into the set if not present. Returns `true` if the item was not present, `false` otherwise.  
> - `bool remove(int val)` Removes an item `val` from the set if present. Returns `true` if the item was present, `false` otherwise.  
> - `int getRandom()` Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the **same probability** of being returned.  
> 
> You must implement the functions of the class such that each function works in **average** `O(1)` time complexity.  

----------

#### I 哈希表 + 数组

利用数组记录每个数字，并利用哈希表记录数字和下标的关系  
进行插入时，利用哈希表确认值的存在情况，不存在则在数组最后加入数字并记录  
进行移除时，将数字和数组最后一个元素交换，更新哈希表的值并把数组最后的元素删除  
随机获取数字可以利用系统的 `rand()` 函数，并基于时间变量  

```cpp
class RandomizedSet 
{
private:
    vector<int> nums;
    unordered_map<int, int> index;

public:
    RandomizedSet() 
    {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) 
    {
        if(index.count(val) != 0)
            return false;
        nums.push_back(val);
        index[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) 
    {
        if(index.count(val) == 0)
            return false;
        int rmvIndex = index[val];
        int last = nums.size() - 1;
        swap(nums[rmvIndex], nums[last]);
        nums.pop_back();
        index[val] = last;
        index[nums[rmvIndex]] = rmvIndex;
        index.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        int n = nums.size();
        return nums[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
