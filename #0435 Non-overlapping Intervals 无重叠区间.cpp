/*
    the shorter the interval is, the less space it will take, so here we sort the intervals on their right value,
    and then compare each left value of a interval with the previous right value of interval which needs to be sompared:
    1. if left > right, the intervals are overlapped, so the number of intervals to be deleted + 1
    2. if left < right, the intervals are not overlapped, so the current intervalcan be set as interval which needs to be compared
*/
/*
    区间越短，区间所占的空间越少，这里我们可以先将区间按照右侧的数值排序，
    之后将每个区间的左边和上一个需要比较的区间的右边比较：
    1. 如果左边 > 右边，说明必然重合，则需要删除的区间数量 + 1
    2. 如果左边 < 右边，说明不重合，则将需要比较的区间设置为当前区间
    返回需要删除的区间总数
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    if (intervals.empty())
        return 0;
    sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b) {return a[1] < b[1]; });

    int size = intervals.size();
    int ret = 0;
    int pre = intervals[0][1];
    for (int i = 1; i < size; ++i)
    {
        if (intervals[i][0] < pre)
            ++ret;
        else
            pre = intervals[i][1];
    }
    return ret;
}