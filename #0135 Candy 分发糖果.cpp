/*
    1. evety child has at least one candy, so we give every one a candy
    2. assure every child has correct number of candies compared to the one at his lefthad side,
       traverse the array from the left to the right, if right > left, right_candies = left_candies + 1
    3. assure every child has correct number of candies compared to the one at his righthand side,
       traverse the array from the right to the left, if  left > tighr and left_candies < right_candies, then left_candies = right_candies + 1,
       sum up all of the candies
*/
/*
    1. 因为每个小朋友至少有一个糖果，所以先给每个人发一块糖
    2. 保证每个小朋友相比较于左侧的小朋友拥有的糖果数量正确，从左往右遍历数组，如果右侧大于左侧，那么给右侧的糖果数量为左侧 + 1
    3. 保证每个小朋友相比较于右侧的小朋友拥有的糖果数量正确，从右往左遍历数组，如果左侧大于右侧，且左侧糖果比右侧少，那么给左侧的糖果数量为右侧 + 1
    计算所有糖果总数即可
*/ 

int candy(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> candy(size, 1);
    for (int i = 0; i < size - 1; ++i)
        if (ratings[i] < ratings[i + 1])
            candy[i + 1] = candy[i] + 1;
    for (int j = size - 1; j > 0; --j)
        if (ratings[j] < ratings[j - 1] && candy[j - 1] <= candy[j])
            candy[j - 1] = candy[j] + 1;
    return accumulate(candy.begin(), candy.end(), 0);
}
