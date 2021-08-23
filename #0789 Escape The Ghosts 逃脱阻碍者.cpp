/*
    本题变相考察曼哈顿距离：
    如果鬼魂能够抓住你，则鬼魂一定可以提前到达终点将你拦截，因此，只需要求鬼魂到终点的距离最小者是否大于你到终点的距离即可
    该距离为曼哈顿距离
*/

bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target)
{
    int min = INT_MAX;
    for (auto person : ghosts)
    {
        int dis = distance(person, target);
        min = min < dis ? min : dis;
    }
    int need = distance({ 0, 0 }, target);
    return need < min;
}

int distance(const vector<int>& person, vector<int> target)
{
    return abs(person[0] - target[0]) + abs(person[1] - target[1]);
}