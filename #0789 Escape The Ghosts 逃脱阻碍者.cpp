/*
    ������࿼�������پ��룺
    �������ܹ�ץס�㣬����һ��������ǰ�����յ㽫�����أ���ˣ�ֻ��Ҫ���굽�յ�ľ�����С���Ƿ�����㵽�յ�ľ��뼴��
    �þ���Ϊ�����پ���
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