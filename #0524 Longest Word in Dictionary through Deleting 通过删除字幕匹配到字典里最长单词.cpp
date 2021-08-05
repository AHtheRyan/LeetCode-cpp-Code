/*
    由于返回时需要考虑字典序，所以首先对字符串进行sort排序，根据排序规则，会按照长度与字典序排列，
    之后比较原字符串与每个单词的“可删除获得性”：
    1. 如果不可获得，则直接跳过
    2. 如果可获得，比较单词长度与现有最大长度
        2.1 小于等于现有最大长度，则考察下一个单词
        2.2 大于现有最大长度，则将其作为新的待返回单词
*/

string findLongestWord(string s, vector<string>& dictionary)
{
    int slen = s.size();
    int num = dictionary.size();
    sort(dictionary.begin(), dictionary.end());
    int maxn = -1;
    string ret = "";
    for (auto word : dictionary)
    {
        int sptr = 0;
        int wptr = 0;
        while (sptr < slen)
        {
            if (s[sptr] == word[wptr])
                ++wptr;
            ++sptr;
            if (wptr == word.size() && wptr > maxn)
            {
                maxn = wptr;
                ret = word;
                break;
            }
        }
    }
    return ret;
}