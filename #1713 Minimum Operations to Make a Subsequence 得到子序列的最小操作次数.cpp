/*
    we can take the numbersr that shown in target in arr into consideration, because the irrelevant numbers will not affect the order,
    the 1st step is mark elements in arr in a new methode associated with arr elements, which we take as index mark, so we get a index-marked array,
    the 2nd step is using binary search + insertion to get the longest common subsequence,
    the result will be the length of target array - length of longest common subsequence
*/
/*
    因为要target数组中的序列，所以可以直接忽略arr中那些不存在于target中的元素，
    忽略完之后，第一步就是将arr中的元素按照与target数组相关的方式重新标记，这里采用下标的方式，
    这样就可以获得一个按照下标排列的数组，
    利用二分查找+插入的方式，将更新之后的arr数组中与target最接近的公共子序列求出，存入新的数组，
    target数组的长度减去新的数组的长度即为我们所求的需要插入的次数
*/ 

int minOperations(vector<int>& target, vector<int>& arr)
{
    //get index array
    //处理获得下标哈希表
    int size = target.size();
    unordered_map<int, int> index;
    for (int i = 0; i < size; ++i)
        index[target[i]] = i;

    //se dichotomy to find the position of each number in the new array and return the largest common array
    //使用二分法查找每个数字在新数组中的位置并返回最大公共数组
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
    //结果是target数组和新数组的大小差
    return size - ret.size();
}