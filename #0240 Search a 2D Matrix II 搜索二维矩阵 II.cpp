/*
    ���������һ��Сtrick���Ǿ���ѡ��һ�����ʵ�������������������Ӷ����⣬
    һ��ѡ����������ĸ�λ�ã����ϡ����¡����ϡ�����
    1. �������Ϻ����£������Ǹ�λ����ߣ��ұߣ������ϱߣ��±ߣ������ֶ�С�ڣ����ڣ���λ�õ����֣��������ж�����
    2. �������º����ϣ�ѡ���ұߣ���ߣ����λ�õ����ֱ����С����ѡ���ϱߣ��±ߣ����λ�õ����ֱ���С����
    ��ˣ�ѡ�����»���������Ϊ�����㣬���԰��� target ���ֵĴ�С���е�����Ĳ��ң����������˲���Ч��
*/

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            --col;
        else
            ++row;
    }
    return false;
}