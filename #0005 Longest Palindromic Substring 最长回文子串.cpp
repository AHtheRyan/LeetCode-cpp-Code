/*
    since any palindrome string removed letter of the left and right sides must still be a palindrome string, so we can use DP,
    1. a single character must be a palindrome, which is regarded as the initialization of the dp array
    2. consider 2 consecutive characters, if the two characters are the same, it must be a palindrome, we can traverse the array with a length of 2
    3. consider 3 consecutive characters, if the left and right are the same, it must be a palindrome, we can traverse the array with a length of 3
    4. when the string length exceeds 3, compare the two characters on the left and right sides, if the two characters are the same as s[i] = s[j], then
        4.1 dp[i+1][j-1] is a palindrome string, it is also a palindrome string after expansion
        4.2 dp[i+1][j-1] is not a palindrome, then it is not a palindrome after expansion
    build the DP algorithm with the rules above
*/
/*
    由于任意回文串去掉左右两边的字母一定还是回文串，所以这里可以采用动态规划的方式求解，
    1. 单个字符一定是回文，所以直接确定其为回文串，视为 dp 数组的初始化
    2. 考虑连续两个字符，如果两字符一样，则一定是回文串，可以以长度为2进行遍历
    3. 考虑连续三个字符，如果左右一样，则一定是回文串，可以以长度为3进行遍历
    4. 字符串长度超过 3 时，比较左右两侧两个字符，如果两个字符相同如s[i] = s[j]，则
        4.1 dp[i+1][j-1]为回文串，则扩展后也是回文串
        4.2 dp[i+1][j-1]不为回文串，则扩展后不是回文串
    以此类推，构建动态规划算法
*/ 

string longestPalindrome(string s)
{
    int len = s.size();
    if (len < 2)
        return s;

    vector<vector<bool>> dp(len, vector<bool>(len));
    for (int i = 0; i < len; ++i)
        dp[i][i] = true;

    int max = 1;
    int start = 0;
    for (int substrLen = 2; substrLen <= len; ++substrLen)
    {
        for (int left = 0; left < len; ++left)
        {
            int right = left + substrLen - 1;
            if (right >= len)
                break;
            if (s[right] != s[left])
                dp[left][right] = false;
            else
            {
                if (right - left < 3)
                    dp[left][right] = true;
                else
                    dp[left][right] = dp[left + 1][right - 1];
            }
            if (dp[left][right] && right - left + 1 > max)
            {
                max = right - left + 1;
                start = left;
            }
        }
    }
    return s.substr(start, max);
}