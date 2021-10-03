### 矩形面积
### Rectangle Area

> 给你**二维**平面上两个**由直线构成的**矩形，请你计算并返回两个矩形覆盖的总面积。  
> 每个矩形由其**左下**顶点和**右上**顶点坐标表示：  
> - 第一个矩形由其左下顶点 `(ax1, ay1)` 和右上顶点 `(ax2, ay2)` 定义。  
> - 第二个矩形由其左下顶点 `(bx1, by1)` 和右上顶点 `(bx2, by2)` 定义。

> Given the coordinates of two **rectilinear** rectangles in a 2D plane, return *the total area covered by the two rectangles*.  
> The first rectangle is defined by its **bottom-left** corner `(ax1, ay1)` and its **top-right** corner `(ax2, ay2)`.  
> The second rectangle is defined by its **bottom-left** corner `(bx1, by1)` and its **top-right** corner `(bx2, by2)`.

----------

#### I 模拟

利用矩形的对角线坐标可以很容易求出两个矩形的面积，因此，只需要求出矩形的重叠部分面积即可，方案如下：  
- 如果两个矩形在x轴方向上有重叠，那么左边的矩形的右横坐标必然大于右边矩形的左横坐标，但由于不确定哪个矩形在左侧，可以用 `两个矩形中较小的右横坐标 - 较大的左横坐标` 来确定，如果大于0，则存在重叠，否则不存在  
- 如果两个矩形在y轴方向上有重叠，那么下边的矩形的上纵坐标必然大于上边矩形的下纵坐标，但由于不确定哪个矩形在下侧，可以用 `两个矩形中较小的上纵坐标 - 较大的下纵坐标` 来确定，如果大于0，则存在重叠，否则不存在  

依此可求出重叠部分的边长，如果不存在则为0，将矩形面积求出后减去重叠面积即可  

```cpp
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
{
    int size1 = (ax2 - ax1) * (ay2 - ay1);
    int size2 = (bx2 - bx1) * (by2 - by1);
    int olwidth = min(ax2, bx2) - max(ax1, bx1);
    int ollength = min(ay2, by2) - max(ay1, by1);
    int overlap = max(olwidth, 0) * max(ollength, 0);
    return size1 + size2 - overlap;
}
```
