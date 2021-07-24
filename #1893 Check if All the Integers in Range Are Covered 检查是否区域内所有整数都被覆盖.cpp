/*
    wse the range to construct a difference array:
    value of each left position is ranges[position] + 1, and value of each right position+1 is ranges[position + 1] - 1,
    for example, in array[2,3,4], [3,4,5]:
    original array: 1 2 3 4  5  6
    tag array:      0 1 1 0 -1 -1
    then record the value of each position as value of the position + summary value of the previous mark value:
    New new array:  0 1 2 2  1  0
    this clearly shows how many times each location has been covered,
    then take left as the starting point and right as the end point to check the value of the new new array at each position,
    if there is 0, return false, otherwise return true
*/
/*
    ���÷�Χ����������飬ÿ�����λ��+1��ÿ���ұ�λ�õ��ұ�λ��-1��
    ���������[2,3,4],[3,4,5]��[1,2,3,4,5,6]�У�
    ԭ�����飺1 2 3 4  5  6
    ������飺0 1 1 0 -1 -1
    Ȼ�󽫱����ÿ��λ�õ�ֵ����¼Ϊ��λ�ü���֮ǰ�ı��ֵ�ܺͣ�
    �������飺0 1 2 2  1  0
    ���������չʾ��ÿ��λ�ñ������˶��ٴΣ�
    ����leftΪ��㣬rightΪ�յ㣬�鿴ÿ��λ�����������ֵ���������0������false�����򷵻�true
*/ 

bool isCovered(vector<vector<int>>& ranges, int left, int right)
{
    int size = ranges.size();
    vector<int> diff(52);
    for (int i = 0; i < size; ++i)
    {
        ++diff[ranges[i][0]];
        --diff[ranges[i][1] + 1];
    }
    vector<int> diffsum(52);
    for (int j = 1; j < 52; ++j)
        diffsum[j] += diffsum[j - 1] + diff[j];
    for (int k = left; k <= right; ++k)
        if (diffsum[k] <= 0)
            return false;
    return true;
}