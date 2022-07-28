### 数组序号转换
### Rank Transform of an Array

> 给你一个整数数组 `arr`，请你将数组中的每个元素替换为它们排序后的序号。  
> 序号代表了一个元素有多大。序号编号的规则如下：  
> - 序号从 1 开始编号。  
> - 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。  
> - 每个数字的序号都应该尽可能地小。  

> Given an array of integers `arr`, replace each element with its rank.  
> The rank represents how large the element is. The rank has the following rules:  
> - Rank is an integer starting from 1.  
> - The larger the element, the larger the rank. If two elements are equal, their rank must be the same.  
> - Rank should be as small as possible.  

----------

#### I 排序 + 哈希

排序后利用哈希记住每个数字的大小顺序，再将数字的大小次序变成一个新的数组即可  

```cpp
vector<int> arrayRankTransform(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> ret(n, 0);
    unordered_map<int, int> index;
    vector<int> narr = arr;
    sort(narr.begin(), narr.end());
    int k = 1;
    for(auto& num : narr)
        if(!index.count(num))
            index[num] = k++;
    for(int i = 0; i < n; ++i)
        ret[i] = index[arr[i]];
    return ret;
}
```
