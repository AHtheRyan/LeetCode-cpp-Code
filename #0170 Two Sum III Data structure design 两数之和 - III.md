### 两数之和 - III
### Two Sum III Data structure design

> 设计一个接收整数流的数据结构，该数据结构支持检查是否存在两数之和等于特定值。  
> 实现 `TwoSum` 类：  
> - `TwoSum()` 使用空数组初始化 `TwoSum` 对象  
> - `void add(int number)` 向数据结构添加一个数 `number`  
> - `boolean find(int value)` 寻找数据结构中是否存在一对整数，使得两数之和与给定的值相等。如果存在，返回 `true`；否则，返回 `false`。  

> Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.  
> Implement the `TwoSum` class:  
> - `TwoSum()` Initializes the `TwoSum` object, with an empty array initially.  
> - `void add(int number)` Adds `number` to the data structure.  
> - `boolean find(int value)` Returns `true` if there exists any pair of numbers whose sum is equal to `value`, otherwise, it returns `false`.  

----------

#### I 哈希表

简单哈希

```cpp
class TwoSum 
{
private:
    unordered_map<long, int> nums;

public:
    TwoSum() 
    {}
    
    void add(int number) 
    {
        ++nums[number];
    }
    
    bool find(int value) 
    {
        for(auto& p : nums)
        {
            if(nums.find(value - p.first) != nums.end())
            {
                if(value == p.first * 2 && nums[p.first] == 1)
                    continue;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```
