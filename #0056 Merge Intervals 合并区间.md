### 合并区间
### Merge Intervals

> 以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]`。请你合并所有重叠的区间，并返回*一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间*。

> Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.  

----------

#### I 排序 + 贪心

两个区间 `A` 与 `B` 可以合并的条件：  
1. `A` 的左区间小于 `B` 的左区间  
2. `A` 的右区间大于 `B` 的左区间  

这样，`B` 区间必然是与 `A` 区间交叉的，  
因此，可以对所有区间排序，这样就获得了左区间从小到大的顺序排列  
之后，比较前一区间的右区间和后一区间的左区间：  

1. 符合上述条件，则将取两左区间较小者为左区间，两右区间较大者为右区间  
2. 不符合上述条件，则将区间加进返回的vector，取当前区间与后面的区间进行比较  

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> ret;
    int size = intervals.size();
    sort(intervals.begin(), intervals.end());
    int left = intervals[0][0];
    int right = intervals[0][1];
    for(int i = 1; i < size; ++i)
    {
        if(intervals[i][0] > right)
        {
            ret.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
        else
            right = max(right, intervals[i][1]);
    }
    ret.push_back({left, right});
    return ret;
}
```
