/*
    wse the range to construct a difference array:
    value of each left position is ranges[position] + 1, and value of each right position+1 is ranges[position + 1] - 1,
    for example, in array[2,3,4], [3,4,5]:
    original array: 1 2 3 4  5  6
    tag array:      0 1 1 0 -1 -1
    then record the value of each position as value of the position + summary value of the previous mark value:
    New new array:  0 1 2 2  1  0
    this clearly shows how many times each location has been covered,
    then take left as the starting point and right as the end point to check the value of the new new array at each position,
    if there is 0, return false, otherwise return true
*/
/*
    利用范围构建差分数组，每个左闭位置+1，每个右闭位置的右边位置-1，
    如对于数列[2,3,4],[3,4,5]在[1,2,3,4,5,6]中：
    原来数组：1 2 3 4  5  6
    标记数组：0 1 1 0 -1 -1
    然后将标记数每个位置的值都记录为该位置及其之前的标记值总和：
    新新数组：0 1 2 2  1  0
    这样就清楚展示了每个位置被覆盖了多少次，
    再以left为起点，right为终点，查看每个位置新新数组的值，如果存在0，返回false，否则返回true
*/ 

bool isCovered(vector<vector<int>>& ranges, int left, int right)
{
    int size = ranges.size();
    vector<int> diff(52);
    for (int i = 0; i < size; ++i)
    {
        ++diff[ranges[i][0]];
        --diff[ranges[i][1] + 1];
    }
    vector<int> diffsum(52);
    for (int j = 1; j < 52; ++j)
        diffsum[j] += diffsum[j - 1] + diff[j];
    for (int k = left; k <= right; ++k)
        if (diffsum[k] <= 0)
            return false;
    return true;
}