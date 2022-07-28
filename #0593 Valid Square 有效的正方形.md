### 有效的正方形
###　Valid Square

> 给定2D空间中四个点的坐标 `p1`, `p2`, `p3` 和 `p4`，如果这四个点构成一个正方形，则返回 `true`。  
> 点的坐标 `pi` 表示为 `[xi, yi]`。输入 不是 按任何顺序给出的。  
> 一个**有效的正方形**有四条等边和四个等角(90度角)。  

> Given the coordinates of four points in 2D space `p1`, `p2`, `p3` and `p4`, return true *if the four points construct a square*.  
> The coordinate of a point `pi` is represented as `[xi, yi]`. The input is **not** given in any order.  
> A **valid square** has four equal sides with positive length and four equal angles (90-degree angles).  

----------

#### I 数学

利用适量，求出以某个点出发的三个矢量，对三个矢量两两之间进行点乘操作  
由于正方形的此三个连线为两条边和一条对角线，所以必然满足以下两点：  
1. 其中有一对正交，乘机为 `0`  
2. 另外两对相等，且值为边的平方  

可以根据此性质求解  

```cpp
class Solution 
{
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p3 == p4 || p2 == p4)
            return false;
        int v1[2] = {p2[0] - p1[0], p2[1] - p1[1]};
        int v2[2] = {p3[0] - p1[0], p3[1] - p1[1]};
        int v3[2] = {p4[0] - p1[0], p4[1] - p1[1]};
        if(vecCalc(v1, v2) == 0 && vecCalc(v1, v3) == vecCalc(v2, v3) && vecCalc(v1, v3) == v1[0] * v1[0] + v1[1] * v1[1])
            return true;
        else if(vecCalc(v1, v3) == 0 && vecCalc(v1, v2) == vecCalc(v2, v3) && vecCalc(v1, v2) == v1[0] * v1[0] + v1[1] * v1[1])
            return true;
        else if(vecCalc(v2, v3) == 0 && vecCalc(v1, v3) == vecCalc(v1, v2) && vecCalc(v1, v3) == v2[0] * v2[0] + v2[1] * v2[1])
            return true;
        else
            return false;
    }

    int vecCalc(int a[2], int b[2])
    {
        return a[0] * b[0] + a[1] * b[1];
    }
};
```
