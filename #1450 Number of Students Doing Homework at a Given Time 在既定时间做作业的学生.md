### 在既定时间做作业的学生
### Number of Students Doing Homework at a Given Time

> 给你两个整数数组 `startTime`（开始时间）和 `endTime`（结束时间），并指定一个整数 `queryTime` 作为查询时间。  
> 已知，第 `i` 名学生在 `startTime[i]` 时开始写作业并于 `endTime[i]` 时完成作业。  
> 请返回在查询时间 `queryTime` 时正在做作业的学生人数。形式上，返回能够使 `queryTime` 处于区间 `[startTime[i], endTime[i]]`（含）的学生人数。  

> Given two integer arrays `startTime` and `endTime` and given an integer `queryTime`.  
> The `ith` student started doing their homework at the time `startTime[i]` and finished it at time `endTime[i]`.  
> Return the number of students doing their homework at time `queryTime`. More formally, return the number of students where `queryTime` lays in the interval `[startTime[i], endTime[i]]` inclusive.  

----------

#### I 差分数组

利用差分数组，可以确定每个学生开始和结束的时间区间  
之后将差分数组进行累加即可  

```cpp
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) 
{
    int n = startTime.size();
    int maxEndTime = *max_element(endTime.begin(), endTime.end());
    vector<int> cnt(maxEndTime + 2);
    for(int i = 0; i < n; ++i)
    {
        cnt[startTime[i]]++;
        cnt[endTime[i] + 1]--;
    }
    int ret = 0;
    for(int i = 0; i < cnt.size() && i <= queryTime; ++i)
        ret += cnt[i];
    return ret;
}
```
