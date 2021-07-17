//use hashmap to store every num(key) and its index(value) that firstly showed
//使用哈希表存储每个首次出现的数字，储存的内容为该数字及其在原数组中的下标
//if num_stored = target - num_current, return these two index
//如果target减去新数字的差（所表示的数字）在原哈希表中能查找到，那么可返回该数字和哈希表中存储的改数字的下标 
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

