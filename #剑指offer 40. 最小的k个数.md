### 最小的k个数

> 输入整数数组 `arr`，找出其中最小的 `k` 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。  

----------

#### I 排序

使用 `sort` 排序结束后直接取前k个元素即可  

```cpp
vector<int> getLeastNumbers(vector<int>& arr, int k) 
{
    sort(arr.begin(), arr.end());
    vector<int> ret;
    for(int i = 0; i < k; ++i)
        ret.push_back(arr[i]);
    return ret;
}
```

#### II 堆

维护一个共有 `k` 个元素的大顶堆即可  

```cpp
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        priority_queue<int> q;
        if(k == 0)
            return {};
        for(int i = 0; i < k; ++i)
            q.push(arr[i]);
        for(int j = k; j < arr.size(); ++j)
        {
            if(q.top() > arr[j])
            {
                q.pop();
                q.push(arr[j]);
            }
        }
        vector<int> ret;
        for(int i = 0; i < k; ++i)
        {
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
```
