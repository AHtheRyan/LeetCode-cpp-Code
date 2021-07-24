/*
    traverse the whole string, if we find a suitable word at a certain index, we can mark at the following index,
    E.G. in string "leetcode", and dictionary "leet""code", mark index 0 as true, the analyse each index:
    l e e t c o d e
    1 0 0 0 1 0 0 0 1
    we can see that each index that be marked can be seen as a mark of a space,
    annther example:
    c a t s a n d o g
    1 0 0 1 1 0 0 1 0 0
    so we make it to store every word with a boolean algebra, and the last index directly show if its a completely searchable string
    traverse the whole string with the rules above
*/
/*
    ���������ַ��������ĳ��λ�õ�֮ǰ��λ�ô����˷��ϵĵ��ʣ���ô�ڸ�λ�ú����λ�ý��м�¼��
    ���磬�����ַ���"leetcode"�����ֵ�"leet""code"���ȱ�ǵ�һ��λ��Ϊtrue����������ÿ��λ�ý��з�����
    l e e t c o d e 
    1 0 0 0 1 0 0 0 1
    �ɼ���ÿһ����ǵ�λ�ö�������Ϊһ�����Բ��ҵ��ĵ��ʵ�ĩβ������˵��һ���ո񣬱�Ǳ�ʾ��ÿ���ո��λ�ã�
    �ٿ�"catsandog",���ֵ�"cats""dog""sand""and""cat"��
    c a t s a n d o g
    1 0 0 1 1 0 0 1 0 0
    ������ʵ����ʹ��һ��bool�������齫ÿ�����ʶ���ǣ������һλֱ��˵�����Ƿ��������Ŀɲ��ַ�����
    ������������������ַ�������
*/ 

bool wordBreak(string s, vector<string>& wordDict)
{
    unordered_set<string> wordStore;
    for (auto word : wordDict)
        wordStore.insert(word);
    int size = s.size() + 1;
    vector<bool> dp(size);
    dp[0] = true;
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (dp[j] && wordStore.find(s.substr(j, i - j)) != wordStore.end())
            {
                dp[i] = true;
                break;
            }
    }
    return dp[size - 1];
}