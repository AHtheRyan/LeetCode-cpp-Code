/*
    两个区间 A 与 B 可以合并的条件：
    1. A 的左区间小于 B 的左区间
    2. A 的右区间大于 B 的左区间
    这样，B 区间必然是与 A 区间交叉的，
    因此，可以对所有区间排序，这样就获得了左区间从小到大的顺序排列
    之后，比较前一区间的右区间和后一区间的左区间：
    1. 符合上述条件，则将取两左区间较小者为左区间，两右区间较大者为右区间
    2. 不符合上述条件，则将区间加进返回的vector，取当前区间与后面的区间进行比较
*/

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    int size = intervals.size();
    if (intervals.size() == 0)
        return {};

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ret;
    vector<int> cur{ intervals[0][0], intervals[0][1] };
    for (int i = 1; i < size; ++i)
    {
        if (cur[1] >= intervals[i][0])
        {
            cur[0] = min(cur[0], intervals[i][0]);
            cur[1] = max(cur[1], intervals[i][1]);
        }
        else
        {
            ret.push_back(cur);
            cur[0] = intervals[i][0];
            cur[1] = intervals[i][1];
        }
    }
    ret.push_back(cur);
    return ret;
}