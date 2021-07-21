/*
    the algorithm is similar to #53 Maximum Subarray,
    difference is that multiplication involves condition of Negative Makes Positive, which results in bigger number,
    so the exceptional case is summary of subarray multiplies a negative number, and we get a minimum instead of maximum,
    so we need an additional array to store minimum of every subarray,
    so the elements of comparision are divided into 3:
    1. maximum �� current value
    2. minimum �� current value
    3 current value
    E.G. in array [2, -2, -2, 3, 5, -1], the maximum and minimum of the first position is 2, considering the scond position:
    1. maximum �� current value = 2 �� -2 = -4
    2. minimum �� current value = 2 �� -2 = -4
    3 current value = -2
    and we can update maximum to 8 and minimum to -2,
    thus we can get a new array of maximum subarray, ad we can return its maximum value.
*/
/*
    ����ⷨ������ #53�������ͣ�
    ��ͬ���ǣ������ǳ˻����ʱ�����ڡ�ż�����������������ʹ������������ĳ˻����Ը����������и������Ŀ��ܣ�
    ��ô��Ҫ���⿼�ǵ�����������������һ����������ʱ�õ���ֵ���ǡ�����ֵ�����ǡ���Сֵ�������Ǵ˼�Сֵ�ں����ĳ˷������У����ܳ����ٳ���һ�������Ӷ����������������
    ��ˣ����ڴ�����˵����Ҫ��������һ����������¼ÿ��λ�õ���С�˻�֮�ͣ�
    ��ô��ÿ��λ����Ҫ�Ƚϵ����ݱ���� 3 ����
    1. ���˻� �� ��ǰֵ
    2. ��С�˻� �� ��ǰֵ
    3. ��ǰֵ
    ����������[2, -2, -2, 3, 5, -1]�У���һ��λ�õ�������С�˻���Ϊ 2 �����ǵڶ���λ�ã�
    1. ���˻� �� ��ǰֵ = 2 �� -2 = -4
    2. ��С�˻� �� ��ǰֵ = 2 �� -2 = -4
    3. ��ǰֵ = -2
    ��ʱ���Ը������˻� -2����С�˻�Ϊ -4��
    ͬ��������λ�ÿ��Ը������˻�������Ϊ 8����С�˻�������Ϊ -2��
    �Դ����ƣ��õ�һ���µ����˻���ɵ����飬�����������ֵ����
*/ 

int maxProduct(vector<int>& nums)
{
    int size = nums.size();
    vector<int> max(size);
    vector<int> min(size);
    max[0] = min[0] = nums[0];
    for (int i = 1; i < size; ++i)
    {
        int curmax = max[i - 1] * nums[i];
        int curmin = min[i - 1] * nums[i];
        int maxcmp = curmax > nums[i] ? curmax : nums[i];
        int mincmp = curmin < nums[i] ? curmin : nums[i];
        max[i] = maxcmp > curmin ? maxcmp : curmin;
        min[i] = mincmp < curmax ? mincmp : curmax;
    }
    return *max_element(max.begin(), max.end());
}