/*
    apprently, for digital strings of different lengths, the number that can be decoded is cumulative, so we adapt the methode of dynamic programming,
    the dirived relationship is as follows:
    current number       0           1               2               3               4               5               6               7               8               9
    precious number
           0             0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
           1          dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]
           2          dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]     dp[i-1]         dp[i-1]         dp[i-1]
           3             0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
           4             0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
           5             0        dp[i-1]         dp[i-1]         ......
           6             0        dp[i-1]         dp[i-1]         ......
           7             0        dp[i-1]         dp[i-1]         ......
           8             0        dp[i-1]         dp[i-1]         ......
           9             0        dp[i-1]         dp[i-1]         ......
    if the number cannot be coded jointly with the previous number, then the number simply adds one bit to the code,
        for example, in "78", the number 8 simply adds one bit to the code but there is no way to increase the code categories;
    if the number can be jointly encoded with the previous number, then the number adds a whole dp[i-2] to the encoding method,
        for example, in "12", the encoding method before the number 1 can be regarded as directly multiplied by 2;
    if the previous number is "1" or "2", and the current number is "0", then this number must be combined with the previous number,
        so the plan is reduced instead, and the number of plans in dp[i-2] is returned;
    if the number is "30" or higher, it cannot be decoded, so there are only 0 options
    follow this idea to build the dp array
*/
/*
    显然，对于不同长度的数字串，可以解码的数量是存在累加关系的，故直接采用动态规划的思路，
    对每个位置产生的新的解码方案数量，推导关系如下：
    当前数字    0           1               2               3               4               5               6               7               8               9
    前一数字        
      0        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
      1     dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]
      2     dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]     dp[i-1]         dp[i-1]         dp[i-1]
      3        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
      4        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
      5        0        dp[i-1]         dp[i-1]         ......
      6        0        dp[i-1]         dp[i-1]         ......
      7        0        dp[i-1]         dp[i-1]         ......
      8        0        dp[i-1]         dp[i-1]         ......
      9        0        dp[i-1]         dp[i-1]         ......
      如果数字不能和之前的数字联合编码，那么该数字单纯为编码增加了一位，比如"78"中，数字 8 单纯给编码加了一位但是没有增加编码的方式；
      如果数字能和之前的数字联合编码，那么该数字为编码方式增加了一整个 dp[i-2]，比如"12"中，在数字 1 之前的编码方式可以看做直接被乘 2；
      如果之前的数字为“1”或者“2”，当前数字为“0”，那么本数字必须与前一数字合在一起，所以反而使得方案减少了，退回 dp[i-2]时 的方案数目；
      如果形成的数字为"30"及以上的整十，那么无法解码，所以方案只有0种
      按此思路构建dp数组即可
*/

int numDecodings(string s)
{
    int size = s.size();
    if (size == 1)
        return !(s[0] == '0');
    vector<int> dp(size + 1);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < size + 1; ++i)
    {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        if (s[i - 2] != '0' && (s[i - 1] - '0' + (s[i - 2] - '0') * 10) <= 26)
            dp[i] += dp[i - 2];
    }
    return dp.back();
}

