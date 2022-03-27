### 柱状图中的最大矩形
### Largest Rectangle in Histogram

> 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。  
> 求在该柱状图中，能够勾勒出来的矩形的最大面积。  

> Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return *the area of the largest rectangle in the histogram*.  

----------

#### I 单调栈

我们针对每个未知的高 `heights[i]` 进行分析，可以看到最大面积一定是从该位置开始到其最左侧比他高的矩形位置 `left` 和最右侧比他比他高的矩形位置 `right` 距离作为底得到的矩形  
那剩下的任务就是找出到每个位置 `i` 比该位置高度`heights[i]` 低的最左侧第一个点位和最右侧第一个点位，可以考虑用单调栈解决该问题  
我们先设立一个数组 `left`，记录每个位置的最左侧比其低的第一个值  
再利用一个单调递增栈 `stk` 进行比较，比较过程如下：  
1. 如果栈非空且栈顶的位置的高度比当前位置高，则循环将栈顶记录的位置 `pop` 出去  
2. 如果栈为空或者栈顶位置的高度比当前位置低，则不进行操作  
3. 将当前位置的左侧最低位置记录，如果栈为空，则记录为 `-1`，说明当前位置左侧所有的矩形柱子都比他高，反之则记录为栈顶元素，说明直到该栈顶元素指定的矩形，柱子都比他高  
4. 遍历一次数组  

这样就可以获得以每个位置的高度为高的左边界，同理，从右往左遍历，获得每个位置高度为高的右边界  
再遍历一次两个数组，求出矩形大小并比较即可  

```cpp
int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size();
    int ret = 0;
    stack<int> stk;
    vector<int> left(n);
    vector<int> right(n);
    for(int i = 0; i < n; ++i)
    {
        while(!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    stk = stack<int>();
    for(int i = n - 1; i >= 0; --i)
    {
        while(!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    for(int i = 0; i < n; ++i)
        ret = max(ret, (right[i] - left[i] - 1) * heights[i]);
    return ret;
}
```
