/*
    the maximum profit is the sum of prices_max - prices_min in each interval,
    but the problem that needs to be noted is that each prices_max must be after prices_min appears,
    this means that we find the difference between prices_min and the temporary prices_max on his right, and can get the result by summing the results each time,
    we can create two variables to store the total amount of stocks held (k) or not held (nk) each day,
    the total amount of each day can be determined according to whether it is held or not held the previous day and whether it is held or not held today,
    in the end, the result is the money you have when you don��t own stocks
*/
/*
    �������Ϊÿ�������� prices_max - prices_min �ĺͣ�����Ҫע��������ǣ�ÿһ�� max ֵ������ min ֵ����֮��
    ��Ҳ����ζ�������ҵ� prices_min �����Ҳ���ʱ�� prices_max ������ÿ�εĽ����ͼ��ɣ�
    �������������������洢ÿһ����� (k) ���߲����� (nk) ��Ʊ���ϵ��ܶÿ����ܶ���Ը���ǰһ���Ƿ���кͲ������Լ�������л򲻳��о�����ȡ�ϴ��ߣ�
    ��󲻳��й�Ʊʱ����Ǯ����ʱ�����׬Ǯ����ʱ��
*/

int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    int nk = 0;
    int k = -prices[0];
    int max = 0;
    for (int i = 1; i < size; ++i)
    {
        nk = nk > k + prices[i] ? nk : k + prices[i];
        k = k > nk - prices[i] ? k : nk - prices[i];
        max = nk > max ? nk : max;
    }
    return max;
}