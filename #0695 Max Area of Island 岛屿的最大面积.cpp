/*
    ��Ȼ������ÿ��λ�õ�½�أ����Էֱ���������������Ƿ�Ϊ½�أ�����ǣ���������������Ϊ���ļ���������
    ���մ�˼·д����������������㷨���ɣ�
    ��Ҫע�⣺
    1. �߽���������½��λ�ò��ܳ�����Χ������߽磩
    2. �����Ѿ���������½�أ������ִ���ʽ
        2.1 ��ϣ��洢
        2.2 ���������½������Ϊ��½�أ��� 1 ��� 0
       ���ǲ��õڶ��ַ�ʽ����
*/

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int max = 0;
    int wid = grid.size();
    int len = grid[0].size();
    for (int i = 0; i < wid; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (grid[i][j] == 1)
            {
                int cur = accArea(grid, i, j, wid, len);
                max = max > cur ? max : cur;
            }
        }
    }
    return max;
}

int accArea(vector<vector<int>>& grid, int x, int y, int& wid, int& len)
{
    int cur = 1;
    grid[x][y] = 0;
    if (x - 1 >= 0 && grid[x - 1][y] == 1)
        cur += accArea(grid, x - 1, y, wid, len);
    if (y + 1 < len && grid[x][y + 1] == 1)
        cur += accArea(grid, x, y + 1, wid, len);
    if (y - 1 >= 0 && grid[x][y - 1] == 1)
        cur += accArea(grid, x, y - 1, wid, len);
    if (x + 1 < wid && grid[x + 1][y] == 1)
        cur += accArea(grid, x + 1, y, wid, len);
    return cur;
}