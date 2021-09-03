/*
    因为求前 k 个元素，最简单直白的方式就是排序后求前 k 个，
    利用 C++ 的 STL 直接编程即可
*/ 

I 排序
vector<int> smallestK(vector<int>& arr, int k)
{
    sort(arr.begin(), arr.end());
    vector<int> ret(arr.begin(), arr.begin() + k);
    return ret;
}

/*
    利用排序的时间复杂度为 o(nlogn)，
    遍历原数组，同时维护一个新数组，使其一直存储前 k 大的数字，即可在 o(n)时间内解决问题，
    采用优先队列可以省去在新数组内处理和比较的麻烦
*/

II 优先队列
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