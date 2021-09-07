/*
    由于相连的城市 i 和 j 相互必然包含着 isConnected[i][j] == isConnected[j][i] == 1 的关系，
    因此，我们只要通过某种方式，确保遍历关系网络 isConnected 时不会重复遍历即可，
    这里有两种思路：
    1. 设置标志位，遍历过的城市记为 true，未遍历记为 false
    2. 将遍历过的相互城市关系从 1 改变为 0
    这样就可以利用深度优先搜索对每个省份的关系网络进行判断
*/

//设置标志位
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int size = isConnected.size();
        int ret = 0;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; ++i)
        {
            if (!visited[i])
            {
                mark(isConnected, visited, i);
                ++ret;
            }
        }
        return ret;
    }

    void mark(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
    {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j)
            if (isConnected[i][j] == 1 && !visited[j])
                mark(isConnected, visited, j);
    }
};


//改变方阵本身
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int size = isConnected.size();
        int ret = 0;
        for (int i = 0; i < size; ++i)
        {
            if (isConnected[i][i] == 1)
            {
                ++ret;
                mark(isConnected, i);
            }
        }
        return ret;
    }

    void mark(vector<vector<int>>& isConnected, int i)
    {
        for (int j = 0; j < isConnected.size(); ++j)
        {
            if (isConnected[i][j] == 1)
            {
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                if (i != j)
                    mark(isConnected, j);
            }
        }
    }
};
