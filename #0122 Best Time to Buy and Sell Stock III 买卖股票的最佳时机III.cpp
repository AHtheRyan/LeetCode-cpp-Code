/*
    the 3rd stocks problem, immediately take it as a DP program,
    firstly ensure variables of state transition equation, because there are only 2 transactions,
    here we create 4 variables as buy_the_1st_time, sell_the_1st_time, buy_the_2nd_time, sell_the_2nd_time,
    buy_the_1st_time:  the profit must be negative number, so we just need to ensure that the minus number is the minimum,
    sell_the_1st_time: profit = current price - buy_the_1st_time, store the higher profit compared to the previous sell_the_1st_time,
    buy_the_2nd_time:  profit = profit_the_1st_time - current prices or the previous buy_the_second_time profit (take the higher one),
    sell_the_2nd_time: profit = current prices + buy_the_2nd_time or the previous sell_the_2nd_time (take the higher one)
    return the profit of sell_the_2nd_time in the last day
*/
/*
    ����Ⱥ��ϲ���ּ��Ĺ�Ʊ�������⣬ֱ�Ӱ��Ŷ�̬�滮��
    ����ȷ��״̬ת�Ƶļ�����������Ϊһ��ֻ�����������������������ǽ��������Ϊ��һ���򣬵�һ�������ڶ�����͵ڶ�������
    ��һ���򣺵�һ����һ���Ǵ�0���𵽸���������ֻҪ��֤���ʱ���ǿ������ٵľͿ���
    ��һ��������һ������ʱ������� = ����۸� - ��һ����ļ۸�����ü۸��֮ǰ����ļ۸�ߣ���ôȡ���ߵ�����
    �ڶ����򣺵ڶ������ʱ�������һ��Ϊ�ӵ�һ��׬��Ǯ��ȥĳһ���Ʊ�ļ۸񣬿϶��ǹ�Ʊ�۸�Խ��Խ�ã�����洢
    �ڶ��������ڶ�������ʱ������� = ����۸� + �ڶ������ļ۸�����ü۸��֮ǰ�洢�ļ۸�ߣ���ôȡ���ߵ�����
    �������һ��ڶ����������󼴿�
*/

int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    int hold = -prices[0];
    int hold2 = -prices[0];
    int nothold = 0;
    int nothold2 = 0;
    for (int i = 1; i < size; ++i)
    {
        hold = max(hold, -prices[i]);
        nothold = max(nothold, hold + prices[i]);
        hold2 = max(hold2, nothold - prices[i]);
        nothold2 = max(nothold2, hold2 + prices[i]);
    }
    return nothold2;
}