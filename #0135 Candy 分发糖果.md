### 分发糖果
### Candy

> `n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。  
> 你需要按照以下要求，给这些孩子分发糖果：  
> - 每个孩子至少分配到 `1` 个糖果。  
> - 相邻两个孩子评分更高的孩子会获得更多的糖果。  
> 
> 请你给每个孩子分发糖果，计算并返回需要准备的**最少糖果数目**。  

> There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.  
> You are giving candies to these children subjected to the following requirements:  
> - Each child must have at least one candy.  
> - Children with a higher rating get more candies than their neighbors.  
> 
> Return *the minimum number of candies you need to have to distribute the candies to the children*.  

----------

#### I 贪心

1. 因为每个小朋友至少有一个糖果，所以先给每个人发一块糖  
2. 保证每个小朋友相比较于左侧的小朋友拥有的糖果数量正确，从左往右遍历数组，如果右侧大于左侧，那么给右侧的糖果数量为左侧 + 1  
3. 保证每个小朋友相比较于右侧的小朋友拥有的糖果数量正确，从右往左遍历数组，如果左侧大于右侧，且左侧糖果比右侧少，那么给左侧的糖果数量为右侧 + 1  

计算所有糖果总数即可  

```cpp
int candy(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> candy(size, 1);
    for (int i = 0; i < size - 1; ++i)
        if (ratings[i] < ratings[i + 1])
            candy[i + 1] = candy[i] + 1;
    for (int j = size - 1; j > 0; --j)
        if (ratings[j] < ratings[j - 1] && candy[j - 1] <= candy[j])
            candy[j - 1] = candy[j] + 1;
    return accumulate(candy.begin(), candy.end(), 0);
}
```
