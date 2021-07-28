/*
    the smaller the balloon is, the less space it will take,
    so here we assume that the number of arrows we need is the same as the number of the balloons,
    then we sort the intervals on their right value,
    and then compare each left value of a balloon with the previous right value of ballon which needs to be sompared:
    1. if left > right, the balloons are overlapped, so the number of arrows to be used - 1
    2. if left < right, the balloons are not overlapped, so the current balloon can be set as the balloon which needs to be compared
*/
/*
    区间越短，区间所占的空间越少，这里我们可以先假设共需要的箭的数目等同于区间的数目，
    然后将区间按照右侧的数值排序，将每个区间的左边和上一个需要比较的区间的右边比较：
    1. 如果左边 > 右边，说明气球横向重合，则需要的箭数量 - 1
    2. 如果左边 < 右边，说明气球横向不重合，则将需要比较的气球设置为当前气球
    返回需要使用的箭的总数
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