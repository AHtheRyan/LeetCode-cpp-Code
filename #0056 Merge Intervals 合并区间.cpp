/*
    �������� A �� B ���Ժϲ���������
    1. A ��������С�� B ��������
    2. A ����������� B ��������
    ������B �����Ȼ���� A ���佻��ģ�
    ��ˣ����Զ������������������ͻ�����������С�����˳������
    ֮�󣬱Ƚ�ǰһ�����������ͺ�һ����������䣺
    1. ����������������ȡ���������С��Ϊ�����䣬��������ϴ���Ϊ������
    2. ����������������������ӽ����ص�vector��ȡ��ǰ����������������бȽ�
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