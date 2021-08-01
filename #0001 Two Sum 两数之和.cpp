/*
    use hashmap to store every num(key) and its index(value) that firstly showed:
    {
        (number_x，number_x_index), (number_y，number_y_index), ...
    }
    if the new number, which named number_z = target - number_x, return number_z_index and number_x_index;
    else store number_z and number_z_index into the hashmap
*/
/*
    使用哈希表存储每个首次出现的数字，储存的内容为该数字及其在原数组中的下标，即哈希表的格式为：
    {
        (出现的数字x，该数字x的下标), (出现的数字b，该数字b的下标), ...
    }
    从零开始遍历原数组，每一次都寻找 “target-当前数字” 所表示的数字是否存在，如某一个数字是 “3”，目标是 “9”，那么我们就寻找数字 “6”是否存在于哈希表中：
    1. 不存在，那么将数字 “3” 和其下标 “x” 存储在哈希表中；
    2. 存在，那么直接返回当前数字 “3” 的下标和存在哈希表里的那个数字的下标 “y”，
    这样的话，遍历完数组之前即可找到答案
*/ 

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> hash;
    int size = nums.size();
    for(int i = 0; i < size; ++i)
    {
        if(hash.find(target - nums[i]) == hash.end())
            hash[nums[i]] = i;
        else
            return {hash[target - nums[i]], i};
    }
    return {};
}

