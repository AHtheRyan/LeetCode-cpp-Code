/*
    consider, respectively, how many trees there are with 1, 2, 3, 4, 5, ... as the root node,
    when n is the root node, the number of elements in the left subtree is n-1, and the number of elements in the right subtree is the total number-n,
    traverse in turn and add the probability of each left and right subtree distribution together
*/
/*
    分别考虑以 1,2,3,4,5，……为根节点的树有多少个，
    以 n 为根节点时，左子树的元素数目为 n - 1 个，右子树 的元素数目为 总数 - n 个，
    依次遍历将每一次左右子树分布的可能性加在一起即可
*/

int numTrees(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i] += dp[j - 1] * dp[i - j];
    return dp[n];
}
