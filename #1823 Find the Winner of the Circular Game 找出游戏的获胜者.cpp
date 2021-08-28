/*
    ���ö����Ƚ���������Կ��Կ��ٽ�����⣺
    ���ν�ÿ���˼�����У�֮��
    1. ���ü���λ count = 0
    2. ���ν�������ǰ���Ԫ�س��ӣ����� count ��һ
        2.1 ��� count != k���򽫳��ӵ�Ԫ�ؼӵ����е�ĩβ
        2.2 ��� count == k���� count ��Ϊ 0
    3. ������ֻʣһ��Ԫ�أ�����Ԫ�ط��ؼ���
*/ 

int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    int count = 0;
    while (q.size() > 1)
    {
        ++count;
        if (count == k)
        {
            count = 0;
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return q.front();
}