/*
    显然题目是一种排序的变体，具体在于为数字排序增加了一个 “比该数字大的数字的个数” 记为 k，
    考虑该因素对身高排序的影响，比较后不难发现，对于身高比较高的人来说，身高低的人站在任何位置都不会影响其 k 值，
    因此，首先我们可以将整个数组按照身高排序，且 k 值较低的排在前面，然后直接根据 k 值进行插值即可
*/

bool isSubsequence(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();
    int sptr = 0;
    int tptr = 0;
    while (sptr < slen && tptr < tlen)
    {
        if (t[tptr] == s[sptr])
            ++sptr;
        ++tptr;
    }
    return slen == sptr;
}

bool isSubsequence(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();
    vector<vector<int>> dp(tlen + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; ++i)
        dp[tlen][i] = tlen;
    for (int i = tlen - 1; i >= 0; --i)
        for (int j = 0; j < 26; ++j)
            dp[i][j] = (t[i] == j + 'a') ? i : dp[i + 1][j];

    int add = 0;
    for (int i = 0; i < slen; i++)
    {
        if (dp[add][s[i] - 'a'] == tlen)
            return false;
        add = dp[add][s[i] - 'a'] + 1;
    }
    return true;
}