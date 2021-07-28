/*
    the easiest greedy algorithm, is to consider every position, and add up all the positions that can be used to plant flowers
*/
/*
    最简单的贪心算法就是，考虑每一个位置是否能种花，最后将能种花的位置累加即可，
    这种方式会有较多的边界条件判断
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
