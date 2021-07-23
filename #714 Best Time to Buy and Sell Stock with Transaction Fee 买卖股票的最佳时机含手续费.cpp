/*
    please refer to #122The Best Time to Buy and Sell Stocks II before solving this problem,
    similar to that question, the situation that we need to consider here can be divided into two categories:
    1. No hold stocks on that day
    2. Hold stocks on the day
    relationship between maximum profit of each day and the previous day is showed below:
    1. Not hold stocks on that day: larger one of profit of not hold stocks in the previous day and hold stocks then sell in the day
    2. Hold stocks on the day: larger one of profit of hold in the previous day and no hold stocks then buy in the day
    we create 4 variables to store the profits of hold and no hold in the day and the previous day,
    the maximum profits appears when we don't hold stocks in the last day
*/

/*
    ������֮ǰ���Ȳ��� #122������Ʊ�����ʱ��II��
    ��������ƣ�������������Ҫ���������Ϊ���ࣺ
    1. ���첻���й�Ʊ
    2. ������й�Ʊ
    ÿһ������������֮ǰһ���״̬��ϵ���£�
    1. ���첻���й�Ʊ��ǰһ�첻���й�Ʊ��ǰһ����е�������֮��Ľϴ���
    2. ������й�Ʊ��ǰһ����к�ǰһ�첻���е������֮��Ľϴ���
    ���������ĸ��������洢�����ǰһ����� (k) ���߲����� (nk) ��Ʊ���ϵ��ܶ��󲻳��й�Ʊʱ���ϵ�Ǯ�����������
*/

int maxProfit(vector<int>& prices, int fee)
{
    int size = prices.size();
    vector<vector<int>> dp(size, vector<int>(2));
    int nh = 0;
    int h = -prices[0];
    int pre_nh = nh;
    int pre_h = h;
    for (int i = 1; i < size; ++i)
    {
        nh = max(pre_nh, pre_h + prices[i] - fee);
        h = max(pre_nh - prices[i], pre_h);
        pre_h = h;
        pre_nh = nh;
    }
    return nh;
}