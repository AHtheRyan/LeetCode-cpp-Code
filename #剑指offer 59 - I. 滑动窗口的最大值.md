### 滑动窗口的最大值

> 给定一个数组 `nums` 和滑动窗口的大小 `k`，请找出所有滑动窗口里的最大值。  

----------

#### 双端队列

见[滑动窗口最大值](./%230239%20Sliding%20Window%20Maximum%20滑动窗口最大值.md)  

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    if(k == 0)
        return {};
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
