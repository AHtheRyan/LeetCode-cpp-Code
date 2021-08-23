/*
    ��Ϊ��ĸһ��ֻ��26������˿�������һ����ĸ��ϣ����ÿһ����ĸ���ֵĴ������м�¼�����γ�һ������Ϊ26���ַ�����
    �������⣬���ĳ������������ĸ��λ�ʣ������ǵ���ĸ��ϣ�ַ���Ӧ������ͬ�ģ�
    ��ˣ�ÿ�ó�һ���ַ������ͽ��������һ����ϣ����
    1. ����ù�ϣ�����ظ����������е��ַ�������λ����Ӹõ��ʵ��±�
    2. ����ù�ϣ��δ��ѯ�����򴴽�һ���µ��ַ�������������Ӹõ��ʵ��±�
    �������Թ�ϣ����±�洢Ϊ��λ��˳����ӵ���Ҫ���ص��ַ����м���
    ��Ҫע�⣺�����һλ��0������Ҫ��ȥ
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    int size = strs.size();
    unordered_map<string, vector<int>> mp;
    vector<int> index(26);
    int count = 0;
    for (auto str : strs)
    {
        fill(index.begin(), index.end(), 0);
        for (int i = 0; i < str.size(); ++i)
            ++index[str[i] - 'a'];
        string cur = "";
        for (int j = 0; j < 26; ++j)
            cur += to_string(index[j]) + ' ';
        if (mp.find(cur) == mp.end())
            mp[cur] = { count++ };
        else
            mp[cur].push_back(count++);
    }
    vector<vector<string>> ret;
    for (auto ele : mp)
    {
        vector<string> cur;
        for (int i = 0; i < ele.second.size(); ++i)
            cur.push_back(strs[ele.second[i]]);
        ret.push_back(cur);
    }
    return ret;
}

