/*
    the max profit is prices_max - prices_min, but we should keep in mind that prices_max should come after prices_min,
    which means we can get the result from finding prices_min and prices_max by its right hand, and find their difference,
    we can create 2 variables, recording prices_min and current profit,
    we can get max profit after travesing the array.
*/
/*
    最大利润为 prices_max - prices_min，但需要注意的问题是，此 max 值必须在 min 值出现之后，
    这也就意味着我们找到 prices_min 和他右侧的 prices_max 求差即可，
    本题可以引入两个变量，分别记录 prices 的当前最小值和当前的利润值 cur，之后遍历数组即可找到最大值更新 prices_min 和 cur 即可求出最大利润
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