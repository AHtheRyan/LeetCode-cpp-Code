### 航班预订统计
### Corporate Flight Bookings

> 这里有 `n` 个航班，它们分别从 `1` 到 `n` 进行编号。  
> 有一份航班预订表 `bookings` ，表中第 `i` 条预订记录 `bookings[i] = [firsti, lasti, seatsi]` 意味着在从 `firsti` 到 `lasti` （包含 `firsti` 和 `lasti` ）的 每个航班 上预订了 `seatsi` 个座位。  
> 请你返回一个长度为 `n` 的数组 `answer`，其中 `answer[i]` 是航班 `i` 上预订的座位总数。  

> There are `n` flights that are labeled from `1` to `n`.  
> You are given an array of flight bookings `bookings`, where `bookings[i] = [firsti, lasti, seatsi]` represents a booking for flights `firsti` through `lasti` (**inclusive**) with `seatsi` seats reserved for **each flight** in the range.  
> Return an array `answer` of length `n`, where `answer[i]` is the total number of seats reserved for flight `i`.  

----------

#### I 差分数组

暴力法如何解题一目了然，但如果想缩减时间复杂度，那么差分数组是一个很好的选择，  
首先遍历整个预订数组 `bookings`，将预订的航班区间差分数组建立起来，  
之后遍历差分数组，将每个航班的总座位数求出即可  

```cpp
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
    vector<int> answer(n + 1);
    for(auto& booking : bookings)
    {
        answer[booking[0] - 1] += booking[2];
        answer[booking[1]] -= booking[2];
    }
    vector<int> ret(n, answer[0]);
    for(int i = 1; i < n; ++i)
        ret[i] = answer[i] + ret[i - 1];
    return ret;
}
```
