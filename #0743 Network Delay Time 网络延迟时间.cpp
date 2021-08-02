/*
    ����Djikstra�㷨��ÿ�θ��¿�ʼ�ڵ㣬�����ʼ�ڵ㵽ÿ���ѱ����ڵ��������룬�����Զ���Ǹ��������
*/

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    const int inf = INT_MAX / 2;
    vector<vector<int>> path(n, vector<int>(n, inf));
    for (int i = 0; i < times.size(); ++i)
        path[times[i][0] - 1][times[i][1] - 1] = times[i][2];

    vector<int> distance(n, inf);
    distance[k - 1] = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i)
    {
        int start = -1;
        for (int pos = 0; pos < n; ++pos)
            if (!used[pos] && (start == -1 || distance[pos] < distance[start]))
                start = pos;
        used[start] = true;
        for (int end = 0; end < n; ++end)
            distance[end] = min(distance[end], distance[start] + path[start][end]);
    }
    int ret = *max_element(distance.begin(), distance.end());
    return ret == inf ? -1 : ret;
}