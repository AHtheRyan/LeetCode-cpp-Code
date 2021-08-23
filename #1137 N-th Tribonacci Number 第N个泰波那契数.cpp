/*
    与斐波那契数相同，按照动态规划将每个数字记录即可
*/

int tribonacci(int n)
{
    if (n < 2)
        return n;
    if (n == 2)
        return 1;

    int a = 0;
    int b = 1;
    int c = 1;
    int d;
    for (int i = 3; i <= n; ++i)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}