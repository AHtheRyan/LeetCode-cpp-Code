/*
    it's easy to consider how to solve this problem with DP,
    we directly make recursion in order, and the state function has already been given by the quiz
*/
/*
    �ö�̬�滮�ĽǶȿ��Ǵ���ͺܼ򵥣�ֱ�Ӱ�ÿ�е��Ƽ��ɣ�״̬�����Ѿ���������ǵ���Ŀ��������
*/

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ret(numRows);
    for (int i = 0; i < numRows; ++i)
    {
        ret[i].resize(i + 1);
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j)
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
    }
    return ret;
}