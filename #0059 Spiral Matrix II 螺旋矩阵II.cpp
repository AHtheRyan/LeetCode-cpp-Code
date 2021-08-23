/*
    1. ������ʼȫ��Ϊ 0 �Ķ�ά�������������
    2. ������->��->��->�ϵ�˳������֣��ʱ������������
        2.1 ��һ��Ҫ���λ���ϵ�����Ϊ 0
        2.2 ��ǰ�������������ڶ�ά����ķ�Χ��
    3. ���������������������������������˳��ת�䷽��
*/

vector<vector<int>> generateMatrix(int n)
{
    int row = 0;
    int col = 0;
    bool right = true;
    bool down = false;
    bool left = false;
    bool up = false;
    vector<vector<int>> ret(n, vector<int>(n));
    for (int i = 0; i < n * n; ++i)
    {
        if (right)
        {
            if (col < n - 1 && ret[row][col + 1] == 0)
                ret[row][col++] = i + 1;
            else
            {
                right = false;
                down = true;
                ret[row++][col] = i + 1;
            }
        }
        else if (down)
        {
            if (row < n - 1 && ret[row + 1][col] == 0)
                ret[row++][col] = i + 1;
            else
            {
                down = false;
                left = true;
                ret[row][col--] = i + 1;
            }
        }
        else if (left)
        {
            if (col > 0 && ret[row][col - 1] == 0)
                ret[row][col--] = i + 1;
            else
            {
                left = false;
                up = true;
                ret[row--][col] = i + 1;
            }
        }
        else if (up)
        {
            if (row > 0 && ret[row - 1][col] == 0)
                ret[row--][col] = i + 1;
            else
            {
                up = false;
                right = true;
                ret[row][col++] = i + 1;
            }
        }
    }
    return ret;
}