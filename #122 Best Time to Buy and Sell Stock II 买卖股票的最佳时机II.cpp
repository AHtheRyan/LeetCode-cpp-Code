/*
    the maximum profit is the sum of prices_max - prices_min in each interval,
    but the problem that needs to be noted is that each prices_max must be after prices_min appears,
    this means that we find the difference between prices_min and the temporary prices_max on his right, and can get the result by summing the results each time,
    we can create two variables to store the total amount of stocks held (k) or not held (nk) each day,
    the total amount of each day can be determined according to whether it is held or not held the previous day and whether it is held or not held today,
    in the end, the result is the money you have when you don’t own stocks
*/
/*
    最大利润为每个区间内 prices_max - prices_min 的和，但需要注意的问题是，每一个 max 值必须在 min 值出现之后，
    这也就意味着我们找到 prices_min 和他右侧暂时的 prices_max 求差，并将每次的结果求和即可，
    本题引入两个变量，存储每一天持有 (k) 或者不持有 (nk) 股票身上的总额，每天的总额可以根据前一天是否持有和不持有以及今天持有或不持有决定，取较大者，
    最后不持有股票时身上钱最多的时候就是赚钱最多的时候
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