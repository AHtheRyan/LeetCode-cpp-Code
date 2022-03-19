### 滑动窗口最大值
### Sliding Window Maximum

> 给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。  
> 返回*滑动窗口中的最大值*。  

> You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.  
> Return *the max sliding window*.  

----------

#### I 双端队列

可以利用双端队列解决问题，在整个遍历的过程中，原则是**保持合法最大值的位置存在于队列的 `front` 端**  
对于一个滑动的窗口，可以设置从 `front` 到 `back` 单调递减的队列  
初始化的过程中，先对前 `k` 个数字进行处理，将符合单调递减顺序的数字存储在双端队列中  
之后，遍历整个数组，判断过程如下：  
1. 如果当前数字始终大于队列 `back` 端的数字，则将队列 `back` 端的数字弹出，知道可以将其放在队列末端  
   值得注意的是，此步骤保证了最后队列中的数字至多比 `k` 多 `1`，如果数列数字多出一个，则根据我们的规则，必然是滑动窗口最左端将要被抛弃的数字  
2. 如果队列开头的数字是将要抛弃的数字，则将其弹出  
3. 将队列 `front` 端的数字记录在返回数组中  
4. 完成遍历  

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    deque<int> dq;
    vector<int> ret{};
    for(int i = 0; i < k; ++i)
    {
        while(!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    ret.emplace_back(nums[dq.front()]);
    for(int i = k; i < nums.size(); ++i)
    {
        while(!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() == i - k)
            dq.pop_front();
        ret.push_back(nums[dq.front()]);
    }
    return ret;
}
```
