/*
    解决此题有一个小trick，那就是选择一个合适的索引出发点来解决复杂度问题，
    一般选择出发点有四个位置：左上、左下、右上、右下
    1. 对于左上和右下，无论是该位置左边（右边）还是上边（下边）的数字都小于（大于）该位置的数字，增加了判断条件
    2. 对于左下和右上，选择右边（左边）则该位置的数字比其大（小），选择上边（下边）则该位置的数字比其小（大）
    因此，选择左下或者右上作为出发点，可以按照 target 数字的大小进行单方向的查找，极大提升了查找效率
*/

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            --col;
        else
            ++row;
    }
    return false;
}