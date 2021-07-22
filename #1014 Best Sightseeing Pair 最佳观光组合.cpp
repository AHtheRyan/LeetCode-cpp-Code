/*
    score of sightseeing pair is values[i] + values[j] + i - j, which can be transformed into values[i] + i + values[j] - j,
    which means we can find maximum value of left = values[i] + i and maximum number of values[j] - j separately and then add them up,
    the tips is that i < j,
    we can create two variables to store maximum of left and maximum of value[j] - j, and we will find the result after traversing the number

*/
/*
    观光点的组合得分为 values[i] + values[j] + i - j，可以改变形式为 values[i] + i + values[j] - j，
    这也就意味着我们可以找到 left = values[i] + i 和 values[j] - j 的最大值加在一起即可，此外要注意 i < j 的基础需求
    本题可以引入两个变量，分别记录 left 的最大值和 当前left + 最大value[j] - j 的最大值，遍历数组即可找到最大值
*/

//A small trick is to find the maximum value of current pair first, and then update the value of left, which effectively avoids the situation where i == j
//一个小技巧是先求出组合最大值，再更新left的值，有效避免了 i == j 的情况
int maxScoreSightseeingPair(vector<int>& values)
{
    int left = values[0];
    int ret = INT_MIN;
    for (int i = 1; i < values.size(); ++i)
    {
        int cur = values[i] - i + left;
        ret = ret > cur ? ret : cur;
        left = left > values[i] + i ? left : values[i] + i;
    }
    return ret;
}