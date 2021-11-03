### 接雨水
### Trapping Rain Water

> 给定 `n` 个非负整数表示每个宽度为 `1` 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。  

> Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.  

----------

#### I 动态规划

根据题意，处在起始位置的柱子处是不可能有积水的，从左往右看分析每个位置，讨论每个位置能积水的量：  
1. 该位置的柱子比左侧的高，那么该位置必然无积水  
2. 该位置的柱子比左侧的低，那么该位置的积水为 左侧的积水 + 两柱子高的差值  

根据此分析，我们遍历整个数组，可以得到一个积水分布，  
但此处有个问题：在此情况下，最高的柱子右侧的积水始终与最高柱子平行，  
解决方法也很简单：从右往左再遍历一次数组，此时可以将最高柱子右侧的积水情况分析完，  
此时可以将两个积水分布在每个位置的最小值相加，结果就是最大积水量  

```cpp
int trap(vector<int>& height)
{
    int size = height.size();
    vector<int> dpl(size);
    vector<int> dpr(size);
    dpl[0] = 0;
    dpr[size - 1] = 0;
    for (int i = 1; i < size; ++i)
    {
        int delta = height[i - 1] - height[i];
        dpl[i] = dpl[i - 1] + delta > 0 ? dpl[i - 1] + delta : 0;
    }
    for (int j = size - 2; j >= 0; --j)
    {
        int delta = height[j + 1] - height[j];
        dpr[j] = dpr[j + 1] + delta > 0 ? dpr[j + 1] + delta : 0;
    }
    vector<int> rain(size);
    for (int k = 0; k < size; ++k)
        rain[k] = dpl[k] > dpr[k] ? dpr[k] : dpl[k];
    int sum = 0;
    for (auto water : rain)
        sum += water;
    return sum;
}
```

#### II 双指针

与动态规划同理，可以同时从左右进行遍历，来判断每个位置的接水量

```cpp
int trap(vector<int>& height) 
{
    int size = height.size();
    int left = 0;
    int right = size - 1;
    int sum = 0;
    int leftMax = height[left];
    int rightMax = height[right];
    while(left < right)
    {
        if(height[left] < height[right])
        {
            ++left;
            leftMax = leftMax > height[left] ? leftMax : height[left];
            sum += leftMax - height[left];
        }
        else
        {
            --right;
            rightMax = rightMax > height[right] ? rightMax : height[right];
            sum += rightMax - height[right];                
        }
    }
    return sum;
}
```

#### III 单调栈

利用单调栈也可以求出每个位置的接水量  
利用一个单调递减的栈，从左往右遍历整个数组，利用与动态规划类似的思路，可以实现接水量的计算  

```cpp
int trap(vector<int>& height) 
{
    int size = height.size();
    int sum = 0;
    stack<int> monoStack;
    for(int i = 0; i < size; ++i)
    {
        while(!monoStack.empty() && height[i] > height[monoStack.top()])
        {
            int top = monoStack.top();
            monoStack.pop();
            if(monoStack.empty())
                break;
            int left = monoStack.top();
            int w = i - left - 1;
            int h = min(height[i], height[left]) - height[top];
            sum += w * h;
        }
        monoStack.push(i);
    }
    return sum;
}
```
