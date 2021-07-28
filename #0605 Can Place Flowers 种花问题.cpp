/*
    the easiest greedy algorithm, is to consider every position, and add up all the positions that can be used to plant flowers
*/
/*
    ��򵥵�̰���㷨���ǣ�����ÿһ��λ���Ƿ����ֻ���������ֻ���λ���ۼӼ��ɣ�
    ���ַ�ʽ���н϶�ı߽������ж�
*/

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int size = flowerbed.size();
    if (size == 1)
    {
        if (flowerbed[0])
            return n == 0;
        else
            return n <= 1;
    }
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (i == 0 && flowerbed[i] == 0)
            if (flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                ++count;
            }
        if (i != 0 && i != size - 1 && flowerbed[i] == 0)
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                ++count;
            }
        if (i == size - 1 && flowerbed[i] == 0)
            if (flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                ++count;
            }
    }
    return count >= n;
}
