### 完美矩形
### Perfect Rectangle

> 给你一个数组 `rectangles`，其中 `rectangles[i] = [xi, yi, ai, bi]` 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 `(xi, yi)`，右上顶点是 `(ai, bi)`。  
> 如果所有矩形一起精确覆盖了某个矩形区域，则返回 `true`；否则，返回 `false`。  

> Given an array `rectangles` where `rectangles[i] = [xi, yi, ai, bi]` represents an axis-aligned rectangle. The bottom-left point of the rectangle is `(xi, yi)` and the top-right point of it is `(ai, bi)`.  
> Return `true` *if all the rectangles together form an exact cover of a rectangular region*.  

----------

#### I 哈希表顶点分析

**这里利用 `typedef` 的方法构建哈希表的技巧需要记住**  
对于一个组合图案，我们可以发现组成矩形具有如下三个要求：  
1. 最后形成的图案，除了四个定点之外，其他每个顶点都出现了两次  
1. 四个顶点所组成的矩形面积与小矩形的面积之和相等
2. 四个顶点都存在  

根据上述三个特性和要求，可以利用哈希表分析每个顶点出现的次数及是否存在，完成完美矩形的判断  

```cpp
class Solution 
{
public:
    typedef pair<int, int> Point;

    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        map<Point, int> mp;
        int size = 0;
        int minX = rectangles[0][0];
        int minY = rectangles[0][1];
        int maxX = rectangles[0][2];
        int maxY = rectangles[0][3];
        for(auto& rectangle : rectangles)
        {
            size += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            Point point1 = {rectangle[0], rectangle[1]};
            Point point2 = {rectangle[0], rectangle[3]};
            Point point3 = {rectangle[2], rectangle[1]};
            Point point4 = {rectangle[2], rectangle[3]};
            ++mp[point1];
            ++mp[point2];
            ++mp[point3];
            ++mp[point4];
            minX = minX < rectangle[0] ? minX : rectangle[0];
            minY = minY < rectangle[1] ? minY : rectangle[1];
            maxX = maxX > rectangle[2] ? maxX : rectangle[2];
            maxY = maxY > rectangle[3] ? maxY : rectangle[3]; 
        }
        if((maxX - minX) * (maxY - minY) != size)
            return false;
        if(!mp.count({minX, minY}) || !mp.count({minX, maxY}) || !mp.count({maxX, maxY}) || !mp.count({maxX, minY}))
            return false;
        mp.erase({minX, minY});
        mp.erase({minX, maxY});
        mp.erase({maxX, minY});
        mp.erase({maxX, maxY});
        for(auto cnt : mp)
            if(cnt.second % 2 == 1)
                return false;
        return true;
    }
};
```
