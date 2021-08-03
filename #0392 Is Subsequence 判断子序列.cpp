/*
    ��Ȼ��Ŀ��һ������ı��壬��������Ϊ��������������һ�� ���ȸ����ִ�����ֵĸ����� ��Ϊ k��
    ���Ǹ����ض���������Ӱ�죬�ȽϺ��ѷ��֣�������߱Ƚϸߵ�����˵����ߵ͵���վ���κ�λ�ö�����Ӱ���� k ֵ��
    ��ˣ��������ǿ��Խ��������鰴����������� k ֵ�ϵ͵�����ǰ�棬Ȼ��ֱ�Ӹ��� k ֵ���в�ֵ����
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