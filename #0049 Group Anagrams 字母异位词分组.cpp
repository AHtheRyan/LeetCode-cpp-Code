/*
    因为字母一共只有26个，因此可以设置一个字母哈希表，对每一个字母出现的次数进行记录，并形成一个长度为26的字符串，
    根据题意，如果某两个单词是字母异位词，则他们的字母哈希字符串应该是相同的，
    因此，每得出一个字符串，就将其存在另一个哈希表中
    1. 如果该哈希表有重复，则在已有的字符串索引位置添加该单词的下标
    2. 如果该哈希表未查询到，则创建一个新的字符串索引，并添加该单词的下标
    将单词以哈希表的下标存储为单位，顺序添加到需要返回的字符串中即可
    需要注意：如果第一位是0，则需要舍去
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

