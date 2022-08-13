### 最多能完成排序的块
### Max Chunks to Make Sorted

> `arr` 是一个可能包含重复元素的整数数组，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。  
> 我们最多能将数组分成多少块？  

> We split `arr` into some number of chunks (i.e., partitions), and individually sort each **chunk**. After concatenating them, the result should equal the sorted array.  
> Return *the largest number of chunks we can make to sort the array*.  

----------

#### I 排序 + 哈希

根据要求，原始数组分组后，其区间内最小值和最大值必然在排序前的位置区间内  
因此，可以利用哈希表，先记录数组中每个数字的所在位置  
之后分析原始数组，只要原始数组区间内的最大值与当前划定区间内的末尾值相同，就可以视为分成了一组  
例如：  
对于数组 `origin = [2, 1, 4, 3]`，显然排序后为 `[1, 2, 3, 4]`  
我们可以记录每个数字排序后的下标 `mp`，即 `mp[1] = 0` ...  
之后分析原数组：目测可知前两个数字可以分为一组，即 `[1, 2]`  
其中的逻辑在于，截止到 `origon[1] = 1` 为止，最大的数字为 `2`，其为第 `2` 大的数字，即上面的 `mp[2] = 1`，且遍历到了 `origin` 数组中下标为 `2` 的位置  
同样分析后两个数字，截止到 `origin[3] = 4` 位置，最大的数字为 `4`，其为第 `4` 大的数字，即 `mp[4] = 3`，且遍历到了 `origin` 数组中下标为 `3` 的位置  
所以，对于任意数组，我们只需要找到截止遍历位置 `index`，恰好遍历到的最大值为 `mp[index]` 的值，此时可以完成一个分组  

```cpp
int maxChunksToSorted(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> origin(arr);
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i)
        if(i == 0 || arr[i] != arr[i - 1])
            mp[arr[i]] = i;
    int index = 0;
    int ret = 0;
    int end = 0;
    while(index < n)
    {
        int endNum = origin[index];
        end = mp[origin[index]]++;
        while(index < n && index != end)
        {
            ++index;
            end = max(end, mp[origin[index]]++);
        }
        ++index;
        ++ret;
    }
    return ret;
}
```
