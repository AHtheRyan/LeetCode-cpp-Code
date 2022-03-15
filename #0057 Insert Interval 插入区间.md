### 插入区间
### Insert Interval

> 给你一个**无重叠的**，按照区间起始端点排序的区间列表。  
> 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。  

> You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.  
> Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).  
> Return `intervals` after the insertion.  

----------

#### I 单次遍历

遍历区间并比较，如果能将新区间插入则插入，否则直接跳过  
如果区间已经插入过了，则每次直接插入旧区间  
若需要进行区间融合，则直接融合即可

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    int n = intervals.size();
    bool placed = false;
    int left = newInterval[0];
    int right = newInterval[1];
    vector<vector<int>> ret;
    for(auto& interval : intervals)
    {
        if(right < interval[0])
        {
            if(!placed)
            {
                placed = true;
                ret.push_back({left, right});
            }
            ret.push_back(interval);
        }
        else if(interval[1] < left)
            ret.push_back(interval);
        else
        {
            left = min(interval[0], left);
            right = max(interval[1], right);
        }
    }
    if(!placed)
        ret.push_back({left, right});
    return ret;
}
```
