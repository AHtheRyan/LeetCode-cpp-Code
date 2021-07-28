/*
    a simple DP problem, just be aware of the boundary of variables
*/
/*
    一道简单的动态规划题目，注意边界条件维护即可
*/

int minimumTotal(vector<vector<int>>& triangle)
{
    int size = triangle.size();
    int best;
    for (int i = size - 2; i >= 0; --i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            best = triangle[i + 1][j];
            if (j < i + 1)
                best = min(best, triangle[i + 1][j + 1]);
            triangle[i][j] += best;
        }
    }
    return triangle[0][0];
}