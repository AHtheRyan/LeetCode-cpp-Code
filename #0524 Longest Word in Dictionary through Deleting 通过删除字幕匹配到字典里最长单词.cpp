/*
    ���ڷ���ʱ��Ҫ�����ֵ����������ȶ��ַ�������sort���򣬸���������򣬻ᰴ�ճ������ֵ������У�
    ֮��Ƚ�ԭ�ַ�����ÿ�����ʵġ���ɾ������ԡ���
    1. ������ɻ�ã���ֱ������
    2. ����ɻ�ã��Ƚϵ��ʳ�����������󳤶�
        2.1 С�ڵ���������󳤶ȣ��򿼲���һ������
        2.2 ����������󳤶ȣ�������Ϊ�µĴ����ص���
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