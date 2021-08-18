/*
    分析字符串对于每个字母出现的次数可以分析得到：
    1. 偶数：该字母全部可以用于构建回文串
    2. 奇数
        2.1 该字母出现的次数最多：回文串允许出现一个奇数字母，因为正中间的字母可以作为回文中心
        2.2 该字母出现的次数不是最多：去掉一个该字母后数目变为偶数，可以按照偶数的情况分析
       这也就意味着，当出现奇数，除了某个出现最多次的字母外，其他的字母数目都需要减一后加到总数中
    因此，统计每个字母出现的次数并求和，如果存在奇数，则和加一，否则直接返回即可
*/

int longestPalindrome(string s)
{
    unordered_map<char, int> cnt;
    for (auto c : s)
        ++cnt[c];
    bool odd = false;
    int sum = 0;
    for (auto p : cnt)
    {
        int count = p.second;
        if (count % 2 == 1)
        {
            sum += count - 1;
            odd = true;
        }
        else
            sum += count;
    }
    return odd ? sum + 1 : sum;
}