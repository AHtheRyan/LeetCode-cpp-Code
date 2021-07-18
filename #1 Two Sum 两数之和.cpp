/*
    use hashmap to store every num(key) and its index(value) that firstly showed:
    {
        (number_x��number_x_index), (number_y��number_y_index), ...
    }
    if the new number, which named number_z = target - number_x, return number_z_index and number_x_index;
    else store number_z and number_z_index into the hashmap
*/
/*
    ʹ�ù�ϣ��洢ÿ���״γ��ֵ����֣����������Ϊ�����ּ�����ԭ�����е��±꣬����ϣ��ĸ�ʽΪ��
    {
        (���ֵ�����x��������x���±�), (���ֵ�����b��������b���±�), ...
    }
    ���㿪ʼ����ԭ���飬ÿһ�ζ�Ѱ�� ��target-��ǰ���֡� ����ʾ�������Ƿ���ڣ���ĳһ�������� ��3����Ŀ���� ��9������ô���Ǿ�Ѱ������ ��6���Ƿ�����ڹ�ϣ���У�
    1. �����ڣ���ô������ ��3�� �����±� ��x�� �洢�ڹ�ϣ���У�
    2. ���ڣ���ôֱ�ӷ��ص�ǰ���� ��3�� ���±�ʹ��ڹ�ϣ������Ǹ����ֵ��±� ��y��
    �����Ļ�������������֮ǰ�����ҵ���
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

