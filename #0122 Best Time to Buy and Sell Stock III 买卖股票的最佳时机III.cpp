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
    人民群众喜闻乐见的股票买卖问题，直接安排动态规划，
    首先确定状态转移的几个变量，因为一共只进行两次买卖，在这里我们将变量设计为第一次买，第一次卖，第二次买和第二次卖：
    第一次买：第一次买一定是从0本金到负数，所以只要保证买的时候是亏的最少的就可以
    第一次卖：第一次卖的时候的利润 = 当天价格 - 第一次买的价格，如果该价格比之前储存的价格高，那么取更高的利润
    第二次买：第二次买的时候的利润一定为从第一次赚的钱减去某一天股票的价格，肯定是股票价格越低越好，将其存储
    第二次卖：第二次卖的时候的利润 = 当天价格 + 第二次卖的价格，如果该价格比之前存储的价格高，那么取更高的利润
    返回最后一天第二次卖的利润即可
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
