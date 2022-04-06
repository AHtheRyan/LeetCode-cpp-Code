### 会议室
### Meeting Rooms

> 给定一个会议时间安排的数组 `intervals`，每个会议时间都会包括开始和结束的时间 `intervals[i] = [starti, endi]`，请你判断一个人是否能够参加这里面的全部会议。  

> Given an array of meeting time `intervals` where `intervals[i] = [starti, endi]`, determine if a person could attend all meetings.  

----------

#### I 排序

简单排序比较题

```cpp
bool canAttendMeetings(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end());
    for(int i = 1; i < intervals.size(); ++i)
        if(intervals[i][0] < intervals[i - 1][1])
            return false;
    return true;
}
```
