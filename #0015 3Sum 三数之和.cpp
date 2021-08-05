/*
    ��Ŀ�����ѣ�ֱ������left��mid��right����ָ�룬������������
    �ѵ����ڻ����������޵��������ν�Լ����ʱ�䣺
    1. left�ƶ��Ĺ����У���� left+1 �� left �±������һ��������ֱ��������midͬ��
    2. numsleft] + nums[mid] + nums[right]��ֵ�������0����ô����ֻ --right�����mid == right ���ߺ�С��0����ֱ��ѭ������
    3. ������̵�right���Ա�������Ϊ�ƶ� mid ָ���Ȼʹ��������������ֻҪ����С���ܵ� right ���㼴��
    �����;Ϳ��Խ�Լ���������ʱ��
*/

vector<vector<int>> threeSum(vector<int>& nums)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    for (int left = 0; left < size - 2; ++left)
    {
        if (left > 0 && nums[left] == nums[left - 1])
            continue;
        int target = -nums[left];
        int right = size - 1;
        for (int mid = left + 1; mid < size - 1; ++mid)
        {
            if (mid > left + 1 && nums[mid] == nums[mid - 1])
                continue;
            while (mid < right && nums[mid] + nums[right] > target)
                --right;
            if (mid == right)
                break;
            if (nums[mid] + nums[right] == target)
                ret.push_back({ nums[left], nums[mid], nums[right] });
        }
    }
    return ret;
}