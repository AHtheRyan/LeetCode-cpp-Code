/*
    the shorter the interval is, the less space it will take, so here we sort the intervals on their right value,
    and then compare each left value of a interval with the previous right value of interval which needs to be sompared:
    1. if left > right, the intervals are overlapped, so the number of intervals to be deleted + 1
    2. if left < right, the intervals are not overlapped, so the current intervalcan be set as interval which needs to be compared
*/
/*
    ����Խ�̣�������ռ�Ŀռ�Խ�٣��������ǿ����Ƚ����䰴���Ҳ����ֵ����
    ֮��ÿ���������ߺ���һ����Ҫ�Ƚϵ�������ұ߱Ƚϣ�
    1. ������ > �ұߣ�˵����Ȼ�غϣ�����Ҫɾ������������ + 1
    2. ������ < �ұߣ�˵�����غϣ�����Ҫ�Ƚϵ���������Ϊ��ǰ����
    ������Ҫɾ������������
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