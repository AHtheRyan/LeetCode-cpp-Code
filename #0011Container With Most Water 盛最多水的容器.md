### 盛水最多的容器
### Container With Most Water

> 给你 `n` 个非负整数 `a1，a2，...，an`，每个数代表坐标中的一个点 `(i, ai)`。在坐标内画 `n` 条垂直线，垂直线 `i` 的两个端点分别为 `(i, ai)` 和 `(i, 0)`。找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。  

> Given `n` non-negative integers `a1, a2, ..., an`, where each represents a point at coordinate `(i, ai)`. `n` vertical lines are drawn such that the two endpoints of the line `i` is at `(i, ai)` and `(i, 0)`. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.  

----------

#### I 双指针

显然，从最外层开始，不断向内收缩容器的底的长度，比较相应的盛水量即可  
向内收缩策略为：比较两个壁的高度，将比较小的那个往内收缩  
如此可找到最大容量的情况  

```CPP
int maxArea(vector<int>& height) 
{
    int ret = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left < right)
    {
        int area = (right - left) * (min(height[left], height[right]));
        ret = max(ret, area);
        if(height[left] <= height[right])
            ++left;
        else
            --right;
    }
    return ret;
}
```
