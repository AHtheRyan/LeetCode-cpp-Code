### 构造矩形
### Construct the Rectangle

> 作为一位web开发者， 懂得怎样去规划一个页面的尺寸是很重要的。 现给定一个具体的矩形页面面积，你的任务是设计一个长度为 L 和宽度为 W 且满足以下要求的矩形的页面。要求：  
> > 1. 你设计的矩形页面必须等于给定的目标面积。  
> > 2. 宽度 W 不应大于长度 L，换言之，要求 L >= W 。  
> > 3. 长度 L 和宽度 W 之间的差距应当尽可能小。
> 
> 你需要按顺序输出你设计的页面的长度 L 和宽度 W。  

> A web developer needs to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:  
> 1. The area of the rectangular web page you designed must equal to the given target area.  
> 2. The width `W` should not be larger than the length `L`, which means `L >= W`.  
> 3. The difference between length `L` and width `W` should be as small as possible.  
>  
>  Return *an array `[L, W]` where `L` and `W` are the length and width of the web page you designed in sequence*.  

----------

#### I 数学

从 1 开始按顺序求出每种可能的乘法组合，并返回长宽差值最小的组合即可

```cpp
vector<int> constructRectangle(int area) 
{
    int peri = sqrt(area);
    int delta = INT_MAX;
    vector<int> ret(2);
    for(int x = 1; x <= peri; ++x)
    {
        int y = area / x;
        if(area % x == 0 && delta > abs(x - y))
            ret = {y, x};
    }
    return ret;
}
```
