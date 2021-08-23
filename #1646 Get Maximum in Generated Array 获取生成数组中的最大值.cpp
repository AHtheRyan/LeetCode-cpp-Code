/*
    ������Ŀ����ֱ�ӽ���ģ�⼴��
*/ 

int getMaximumGenerated(int n)
{
    if (n == 0 || n == 1)
        return n;
    vector<int> ret(n + 1);
    ret[1] = 1;
    int max = 0;
    for (int i = 2; i <= n; ++i)
    {
        ret[i] = ret[i / 2] + i % 2 * ret[(i + 1) / 2];
        max = max > ret[i] ? max : ret[i];
    }
    return max;
}