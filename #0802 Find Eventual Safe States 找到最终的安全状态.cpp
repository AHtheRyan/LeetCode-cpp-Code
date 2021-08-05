/*
    采用深度优先的方式，遍历每一个节点，我们可以给节点三种不同的标记：
    1. 标记为 1，说明该节点安全
    2. 标记为 0，说明该节点未遍历
    3. 标记为 -1，说明该节点正在遍历（在环中）
    显然，递归过程如果遇到了 -1 节点，直接将该出发节点记为 -1，返回 false，否则出发节点记为 1，返回true
    最后，递归采用lambda表达式，否则会导致超时
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