### 煎饼排序
### Pancake Sorting

> 给你一个整数数组 `arr`，请使用**煎饼翻转**完成对数组的排序。  
> 一次煎饼翻转的执行过程如下：  
> - 选择一个整数 `k`，`1 <= k <= arr.length`  
> - 反转子数组 `arr[0...k-1]`（**下标从 0 开始**）  
> 
> 例如，`arr = [3,2,1,4]`，选择 `k = 3` 进行一次煎饼翻转，反转子数组 `[3,2,1]`，得到 `arr = [1,2,3,4]`。  
> 以数组形式返回能使 `arr` 有序的煎饼翻转操作所对应的 `k` 值序列。任何将数组排序且翻转次数在 `10 * arr.length` 范围内的有效答案都将被判断为正确。  

----------

#### I 冒泡翻转

最终结果是将整个数组按照从小到大的顺序排列  
可以这么理解：  
1. 找到当前最大值 `n`  
2. 将 `n` 翻转到数组第一个位置  
3. 将 `n` 翻转到最后一个位置  

以上过程利用两次翻转，使得最大数移动到了最后，接下来：  

4. 将最大值减一变为 `n'`
5. 找到 `n'`  
6. 将 `n'` 翻转到数组第一个位置  
7. 将 `n'` 翻转到倒数第二个位置
8. 以此类推，将每个数字按顺序翻转即可  

可以看到，整个过程类似于冒泡排序，都是找出当前最大数，将其处理  

```cpp
vector<int> pancakeSort(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> ret;
    while(n > 1)
    {
        int index = 1;
        while(arr[index - 1] != n)
            ++index;
        ret.push_back(index);
        ret.push_back(n);
        reverse(arr.begin(), arr.begin() + index);
        reverse(arr.begin(), arr.begin() + n);
        --n;
    }
    return ret;
}
```
