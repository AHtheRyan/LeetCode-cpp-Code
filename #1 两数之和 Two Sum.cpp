//use hashmap to store every num(key) and its index(value) that firstly showed
//ʹ�ù�ϣ��洢ÿ���״γ��ֵ����֣����������Ϊ�����ּ�����ԭ�����е��±�
//if num_stored = target - num_current, return these two index
//���target��ȥ�����ֵĲ����ʾ�����֣���ԭ��ϣ�����ܲ��ҵ�����ô�ɷ��ظ����ֺ͹�ϣ���д洢�ĸ����ֵ��±� 
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

