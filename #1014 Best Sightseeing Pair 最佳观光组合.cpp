/*
    score of sightseeing pair is values[i] + values[j] + i - j, which can be transformed into values[i] + i + values[j] - j,
    which means we can find maximum value of left = values[i] + i and maximum number of values[j] - j separately and then add them up,
    the tips is that i < j,
    we can create two variables to store maximum of left and maximum of value[j] - j, and we will find the result after traversing the number

*/
/*
    �۹�����ϵ÷�Ϊ values[i] + values[j] + i - j�����Ըı���ʽΪ values[i] + i + values[j] - j��
    ��Ҳ����ζ�����ǿ����ҵ� left = values[i] + i �� values[j] - j �����ֵ����һ�𼴿ɣ�����Ҫע�� i < j �Ļ�������
    ����������������������ֱ��¼ left �����ֵ�� ��ǰleft + ���value[j] - j �����ֵ���������鼴���ҵ����ֵ
*/

//A small trick is to find the maximum value of current pair first, and then update the value of left, which effectively avoids the situation where i == j
//һ��С�����������������ֵ���ٸ���left��ֵ����Ч������ i == j �����
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