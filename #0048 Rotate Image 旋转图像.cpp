/*
    ���ݾ����֪ʶ����֪������ת�����ͬ���Ƚ�������� �Գ� + ת�� ������
    ��ˣ���������ԭ����Ԫ�ػ�������
*/

void rotate(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size / 2; ++j)
            swap(matrix[i][j], matrix[i][size - 1 - j]);
}

