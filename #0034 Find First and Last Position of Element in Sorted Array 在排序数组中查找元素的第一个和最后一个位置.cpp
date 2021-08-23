/*
    ������Կ����� c++ �� upper_bound �� lower_bound ����������ʵ�ֹ��̣�
    ������Ѱ���ض���ֵ��������Ȼ���ַ�����ʵ�� o(log n)��ʱ�䣬
    ֱ�����ö��ַ����в��Ҽ���
*/

vector<int> searchRange(vector<int>& nums, int target)
{
    int size = nums.size();
    vector<int> ret(2, -1);
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target))
        {
            ret[0] = mid;
            break;
        }
        else if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (ret[0] == -1)
        return ret;
    left = ret[0];
    right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target && (mid == size - 1 || nums[mid + 1] > target))
        {
            ret[1] = mid;
            break;
        }
        else if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return ret;
}
