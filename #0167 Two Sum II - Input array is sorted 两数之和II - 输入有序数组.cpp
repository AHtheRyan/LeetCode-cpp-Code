/*
    采用双指针，分别在数组的最左和最右，依次求二者的和
    1. 如果和大于目标和，则说明数字偏大，将右侧指针前移
    2. 如果和小于目标和，则说明数字偏小，将左侧指针后移
    3. 如果和等于目标和，直接返回两个下标+1
*/ 

vector<int> twoSum(vector<int>& numbers, int target)
{
    int size = numbers.size();
    int left = 0;
    int right = size - 1;
    int sum = numbers[left] + numbers[right];
    while (sum != target)
    {
        if (sum > target)
            --right;
        else
            ++left;
        sum = numbers[left] + numbers[right];
    }
    return { left + 1, right + 1 };
}