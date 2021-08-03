/*
    被覆盖子串中的主要参数有两个，一个是不同的字母，一个是不同字母出现的次数，
    因此，如果要处理长字符串，应该事先将被覆盖子串的这两个参数记录，这样可以方便对长字符串的处理，
    处理长字符串时，可以利用双指针，其中 left 先不动，right右移，直到能够完全覆盖被覆盖串，
    之后，将 left 指针向右移动，比较长字符串子串与记录的最短子串的长度，取较短者，直到取到最短，
    按照此思路遍历整个字符串即可
*/ 

string minWindow(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();
    int minleft = -1;
    int length = INT_MAX;
    int left = 0;
    int allcount = 0;
    vector<int> count(58);
    vector<bool> hash(58);
    for (int i = 0; i < tlen; ++i)
    {
        count[t[i] - 'A']++;
        hash[t[i] - 'A'] = true;
    }
    for (int right = 0; right < slen; ++right)
    {
        if (hash[s[right] - 'A'])
            if (--count[s[right] - 'A'] >= 0)
                ++allcount;
        while (allcount == tlen)
        {
            if (right - left + 1 < length)
            {
                length = right - left + 1;
                minleft = left;
            }
            if (hash[s[left] - 'A'] && ++count[s[left] - 'A'] > 0)
                --allcount;
            ++left;
        }
    }
    return length > slen ? "" : s.substr(minleft, length);
}