/*
    we can take the numbersr that shown in target in arr into consideration, because the irrelevant numbers will not affect the order,
    the 1st step is mark elements in arr in a new methode associated with arr elements, which we take as index mark, so we get a index-marked array,
    the 2nd step is using binary search + insertion to get the longest common subsequence,
    the result will be the length of target array - length of longest common subsequence
*/
/*
    ��ΪҪtarget�����е����У����Կ���ֱ�Ӻ���arr����Щ��������target�е�Ԫ�أ�
    ������֮�󣬵�һ�����ǽ�arr�е�Ԫ�ذ�����target������صķ�ʽ���±�ǣ���������±�ķ�ʽ��
    �����Ϳ��Ի��һ�������±����е����飬
    ���ö��ֲ���+����ķ�ʽ��������֮���arr��������target��ӽ��Ĺ�������������������µ����飬
    target����ĳ��ȼ�ȥ�µ�����ĳ��ȼ�Ϊ�����������Ҫ����Ĵ���
*/ 

int minOperations(vector<int>& target, vector<int>& arr)
{
    //get index array
    //�������±��ϣ��
    int size = target.size();
    unordered_map<int, int> index;
    for (int i = 0; i < size; ++i)
        index[target[i]] = i;

    //se dichotomy to find the position of each number in the new array and return the largest common array
    //ʹ�ö��ַ�����ÿ���������������е�λ�ò�������󹫹�����
    vector<int> ret;
    for (int val : arr)
    {
        if (index.find(val) != index.end())
        {
            auto it = lower_bound(ret.begin(), ret.end(), index[val]);
            if (it != ret.end())
                *it = index[val];
            else
                ret.push_back(index[val]);
        }
    }

    //result = targetarray_size - new_array
    //�����target�����������Ĵ�С��
    return size - ret.size();
}