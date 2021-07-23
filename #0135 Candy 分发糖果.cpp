/*
    1. evety child has at least one candy, so we give every one a candy
    2. assure every child has correct number of candies compared to the one at his lefthad side,
       traverse the array from the left to the right, if right > left, right_candies = left_candies + 1
    3. assure every child has correct number of candies compared to the one at his righthand side,
       traverse the array from the right to the left, if  left > tighr and left_candies < right_candies, then left_candies = right_candies + 1,
       sum up all of the candies
*/
/*
    1. ��Ϊÿ��С����������һ���ǹ��������ȸ�ÿ���˷�һ����
    2. ��֤ÿ��С������Ƚ�������С����ӵ�е��ǹ�������ȷ���������ұ������飬����Ҳ������࣬��ô���Ҳ���ǹ�����Ϊ��� + 1
    3. ��֤ÿ��С������Ƚ����Ҳ��С����ӵ�е��ǹ�������ȷ����������������飬����������Ҳ࣬������ǹ����Ҳ��٣���ô�������ǹ�����Ϊ�Ҳ� + 1
    ���������ǹ���������
*/ 

int candy(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> candy(size, 1);
    for (int i = 0; i < size - 1; ++i)
        if (ratings[i] < ratings[i + 1])
            candy[i + 1] = candy[i] + 1;
    for (int j = size - 1; j > 0; --j)
        if (ratings[j] < ratings[j - 1] && candy[j - 1] <= candy[j])
            candy[j - 1] = candy[j] + 1;
    return accumulate(candy.begin(), candy.end(), 0);
}
