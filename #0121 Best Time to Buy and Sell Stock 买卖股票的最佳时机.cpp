/*
    the max profit is prices_max - prices_min, but we should keep in mind that prices_max should come after prices_min,
    which means we can get the result from finding prices_min and prices_max by its right hand, and find their difference,
    we can create 2 variables, recording prices_min and current profit,
    we can get max profit after travesing the array.
*/
/*
    �������Ϊ prices_max - prices_min������Ҫע��������ǣ��� max ֵ������ min ֵ����֮��
    ��Ҳ����ζ�������ҵ� prices_min �����Ҳ�� prices_max ���ɣ�
    ����������������������ֱ��¼ prices �ĵ�ǰ��Сֵ�͵�ǰ������ֵ cur��֮��������鼴���ҵ����ֵ���� prices_min �� cur ��������������
*/

int maxProfit(vector<int>& prices)
{
    int min = prices[0];
    int porfit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        int cur = prices[i] - min;
        porfit = porfit > cur ? porfit : cur;
        min = min > prices[i] ? prices[i] : min;
    }
    return porfit;
}