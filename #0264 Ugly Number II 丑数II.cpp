/*
    the factors of ugly numbers are 2, 3, or 5, therefore, each ugly number should be 2, 3, 5 or their product,
    therefore, we can use 2/3/5 as the base to multiply each previous ugly number in turn, and take the smallest ugly number as the next ugly number in turn,
    finding the nth ugly number is the result we require
*/
/*
    丑数的因数为 2、3或者5，因此，每个丑数都应该是2、3、5或者他们之间的乘积，
    因此可以用2/3/5作为基底依次乘以每一个前面的丑数，依次取最小的丑数作为下一位的丑数，
    求到第 n 个丑数即为我们所要求的的结果
*/

int nthUglyNumber(int n)
{
    vector<int> dp(n + 1);
    int pos2 = 1;
    int pos3 = 1;
    int pos5 = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        int num2 = dp[pos2] * 2;
        int num3 = dp[pos3] * 3;
        int num5 = dp[pos5] * 5;
        dp[i] = min(num2, min(num3, num5));
        if (dp[i] == num2)   ++pos2;
        if (dp[i] == num3)   ++pos3;
        if (dp[i] == num5)   ++pos5;
    }
    return dp[n];
}