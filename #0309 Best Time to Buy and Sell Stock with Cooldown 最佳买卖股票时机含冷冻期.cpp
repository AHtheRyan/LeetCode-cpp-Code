/*
    please refer to #122The Best Time to Buy and Sell Stocks II before solving this problem,
    similar to that question, the situation that we need to consider here can be divided into three categories:
    1. No stocks are held on that day, and it is a no-cooldown period
    2. Hold stocks on the day
    3. No stocks are held on the day, and it is the cooldown period
    the relationship between the maximum profit of each day and the state of the previous day is as follows:
    1. Do not hold stocks on the day + no-cooldown period, 
       which means that you must not hold stocks the day before (otherwise it will be the cooldown period), 
       so take the larger one between the cooldown and no-cooldown profit of the day;
    2. Holding the stock on the same day,
       which means that the previous day must not be in the cooldown period (otherwise it cannot be bought),
       so take the larger one between held-in-the-previous-day or  did-not-held-the-previous-day profit��
    3. Do not hold stocks on the day + cooldown period,
       which means that the stocks must be sold the day before,
       so the profit of the day is the profit of holding the stocks the day before + the money earned from selling the stocks the day
    traverse the array and take the maximum profit on the last day when you don��t hold stocks.
*/
/*
    ������֮ǰ���Ȳ��� #122������Ʊ�����ʱ��II��
    ��������ƣ�������������Ҫ���������Ϊ���ࣺ
    1. ���첻���й�Ʊ����Ϊ���䶳��
    2. ������й�Ʊ
    3. ���첻���й�Ʊ����Ϊ�䶳��
    ÿһ������������֮ǰһ���״̬��ϵ���£�
    1. ���첻���й�Ʊ + ���䶳�ڣ���ζ��ǰһ���Ȼ�ǲ����й�Ʊ�ģ�����һ�������䶳�ڣ�������ȡǰһ�첻���й�Ʊʱ�Ľϴ�����Ϊ�����������
    2. ������й�Ʊ����ζ��ǰһ���Ȼ�����䶳�ڣ��������򣩣�����ȡǰһ����е��������ǰһ�첻���е����컨Ǯ����֮���������ߵĽϴ�����
    3. ���첻���й�Ʊ + �䶳�ڣ���ζ��ǰһ���Ȼ���˹�Ʊ�����Ե��������Ϊǰһ����й�Ʊ��������ϵ���������Ʊ׬��Ǯ
    �������飬ȡ�����й�Ʊʱ���һ���������󼴿�
*/

int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    vector<vector<int>> dp(size, vector<int>(3));
    dp[0][0] = 0;   //not held + no-cooldown    //������ + ���䶳��
    dp[0][1] = -prices[0];  //held    //����
    dp[0][2] = 0;   //not held + cooldown   //������ + �䶳��
    for (int i = 1; i < size; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        dp[i][2] = dp[i - 1][1] + prices[i];
    }
    return max(dp[size - 1][0], dp[size - 1][2]);
}