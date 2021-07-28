/*
    the smaller the balloon is, the less space it will take,
    so here we assume that the number of arrows we need is the same as the number of the balloons,
    then we sort the intervals on their right value,
    and then compare each left value of a balloon with the previous right value of ballon which needs to be sompared:
    1. if left > right, the balloons are overlapped, so the number of arrows to be used - 1
    2. if left < right, the balloons are not overlapped, so the current balloon can be set as the balloon which needs to be compared
*/
/*
    ����Խ�̣�������ռ�Ŀռ�Խ�٣��������ǿ����ȼ��蹲��Ҫ�ļ�����Ŀ��ͬ���������Ŀ��
    Ȼ�����䰴���Ҳ����ֵ���򣬽�ÿ���������ߺ���һ����Ҫ�Ƚϵ�������ұ߱Ƚϣ�
    1. ������ > �ұߣ�˵����������غϣ�����Ҫ�ļ����� - 1
    2. ������ < �ұߣ�˵����������غϣ�����Ҫ�Ƚϵ���������Ϊ��ǰ����
    ������Ҫʹ�õļ�������
*/

int findMinArrowShots(vector<vector<int>>& points)
{
    int count = points.size();
    int size = count;
    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
    int comp = points[0][1];
    for (int i = 1; i < size; ++i)
    {
        if (points[i][0] <= comp)
            --count;
        else
            comp = points[i][1];
    }
    return count;
}