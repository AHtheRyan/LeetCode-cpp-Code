/*
    ����������ȵķ�ʽ������ÿһ���ڵ㣬���ǿ��Ը��ڵ����ֲ�ͬ�ı�ǣ�
    1. ���Ϊ 1��˵���ýڵ㰲ȫ
    2. ���Ϊ 0��˵���ýڵ�δ����
    3. ���Ϊ -1��˵���ýڵ����ڱ������ڻ��У�
    ��Ȼ���ݹ������������� -1 �ڵ㣬ֱ�ӽ��ó����ڵ��Ϊ -1������ false����������ڵ��Ϊ 1������true
    ��󣬵ݹ����lambda���ʽ������ᵼ�³�ʱ
*/

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int size = graph.size();
    vector<int> dp(size);

    function<bool(int)> checkSafe = [&](int index)
    {
        if (dp[index] == 1)
            return true;
        if (dp[index] == -1)
            return false;
        dp[index] = -1;
        for (auto num : graph[index])
            if (!checkSafe(num))
                return false;
        dp[index] = 1;
        return true;
    };

    vector<int> ret;
    for (int i = 0; i < size; ++i)
        if (checkSafe(i))
            ret.push_back(i);
    return ret;
}