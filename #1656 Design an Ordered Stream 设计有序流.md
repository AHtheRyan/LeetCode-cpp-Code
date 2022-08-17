### 设计有序流
### Design an Ordered Stream

> 有 `n` 个 `(id, value)` 对，其中 `id` 是 `1` 到 `n` 之间的一个整数，`value` 是一个字符串。不存在 `id` 相同的两个 `(id, value)` 对。  
> 设计一个流，以**任意**顺序获取 `n` 个 `(id, value)` 对，并在多次调用时**按 `id` 递增的顺序**返回一些值。  
> 实现 `OrderedStream` 类：  
> - `OrderedStream(int n)` 构造一个能接收 `n` 个值的流，并将当前指针 `ptr` 设为 `1`。  
> - `String[] insert(int id, String value)` 向流中存储新的 `(id, value)` 对。存储后：  
>   - 如果流存储有 `id = ptr` 的 `(id, value)` 对，则找出从 `id = ptr` 开始的**最长 id 连续递增序列**，并**按顺序**返回与这些 id 关联的值的列表。然后，将 `ptr` 更新为最后那个 `id + 1`。  
>   - 否则，返回一个空列表。  

> There is a stream of `n` `(idKey, value)` pairs arriving in an **arbitrary** order, where `idKey` is an integer between `1` and `n` and `value` is a string. No two pairs have the same `id`.  
> Design a stream that returns the values in **increasing order of their IDs** by returning a **chunk** (list) of values after each insertion. The concatenation of all the **chunks** should result in a list of the sorted values.  
> Implement the `OrderedStream` class:  
> - `OrderedStream(int n)` Constructs the stream to take `n` values.  
> - `String[] insert(int idKey, String value)` Inserts the pair `(idKey, value)` into the stream, then returns the **largest possible chunk** of currently inserted values that appear next in the order.  

----------

#### I 数组

利用数组下标及其空间记录 `(idkey, value)` 模拟即可  

```cpp
class OrderedStream 
{
private:
    vector<string> flow;
    int ptr;
    int size;
    int last;

public:
    OrderedStream(int n): ptr(1), size(n), last(0)
    {
        flow.resize(size);
    }
    
    vector<string> insert(int idKey, string value) 
    {
        flow[idKey - 1] = value;
        if(idKey == ptr)
        {
            vector<string> ret;
            for(; idKey - 1 < size && flow[idKey - 1] != ""; ++idKey)
                ret.push_back(flow[idKey - 1]);
            ptr = idKey;
            return ret;
        }
        return {};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
```
