### 回旋镖的数量
### Number of Boomerangs

> 给定平面上 `n` 对 **互不相同** 的点 `points` ，其中 `points[i] = [xi, yi]` 。**回旋镖** 是由点 `(i, j, k)` 表示的元组 ，其中 `i` 和 `j` 之间的距离和 `i` 和 `k` 之间的距离相等（需要考虑元组的顺序）。  
> 返回平面上所有回旋镖的数量。  

> You are given `n` `points` in the plane that are all **distinct**, where `points[i] = [xi, yi]`. A **boomerang** is a tuple of points `(i, j, k)` such that the distance between `i` and `j` equals the distance between `i` and `k` (**the order of the tuple matters**).  
> Return *the number of boomerangs*.  

----------

#### I 哈希表

简单来说，题目就是分别求每个点跟其他点的距离，然后跟当前点距离相等的两个点组成一个回旋镖，  
我们采用哈希表记录每个点和当前点的距离，利用握手原则计算回旋镖的数目  
**注意**：由于考虑点的顺序，因此 `abc` 和 `cba` 这两种模式算两个回旋镖  

```cpp
int numberOfBoomerangs(vector<vector<int>>& points) 
{
    int num = points.size();
    int ret = 0;
    for(int i = 0; i < num; ++i)
    {
        unordered_map<int, int> dis;
        for(int j = 0; j < num; ++j)
        {
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            ++dis[x * x + y * y];
        }
        for(auto num : dis)
            ret += num.second * (num.second - 1);
    }
    return ret;
}
```
