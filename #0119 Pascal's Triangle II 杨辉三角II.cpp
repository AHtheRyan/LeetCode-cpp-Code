/*
    it's easy to consider how to solve this problem with DP,
    we directly make recursion in order, and the state function has already been given by the quiz
*/
/*
    �ö�̬�滮�ĽǶȿ��Ǵ���ͺܼ򵥣�ֱ�Ӱ�ÿ�е��Ƽ��ɣ�״̬�����Ѿ���������ǵ���Ŀ��������
*/

vector<int> getRow(int rowIndex)
{
    vector<int> cur(1, 1);
    vector<int> pre;
    for (int i = 1; i <= rowIndex; ++i)
    {
        pre = cur;
        cur.resize(i + 1);
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i; ++j)
            cur[j] = pre[j - 1] + pre[j];
    }
    return cur;
}