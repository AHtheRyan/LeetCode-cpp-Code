/*
    ��Ϊ��ǰ k ��Ԫ�أ����ֱ�׵ķ�ʽ�����������ǰ k ����
    ���� C++ �� STL ֱ�ӱ�̼���
*/ 

I ����
vector<int> smallestK(vector<int>& arr, int k)
{
    sort(arr.begin(), arr.end());
    vector<int> ret(arr.begin(), arr.begin() + k);
    return ret;
}

/*
    ���������ʱ�临�Ӷ�Ϊ o(nlogn)��
    ����ԭ���飬ͬʱά��һ�������飬ʹ��һֱ�洢ǰ k ������֣������� o(n)ʱ���ڽ�����⣬
    �������ȶ��п���ʡȥ���������ڴ���ͱȽϵ��鷳
*/

II ���ȶ���
vector<int> smallestK(vector<int>& arr, int k)
{
    if (k == 0)
        return {};
    priority_queue<int> ret;
    for (int i = 0; i < k; ++i)
        ret.push(arr[i]);
    for (int i = k; i < arr.size(); ++i)
    {
        if (ret.top() > arr[i])
        {
            ret.pop();
            ret.push(arr[i]);
        }
    }
    vector<int> num;
    for (int i = 0; i < k; ++i)
    {
        num.push_back(ret.top());
        ret.pop();
    }
    return num;
}