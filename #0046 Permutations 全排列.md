### 全排列
### Permutations

> 给定一个不含重复数字的数组 `nums` ，返回其*所有可能的全排列*。你可以**按任意顺序**返回答案。  

> Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.  

----------

#### I 回溯法

经典回溯法题解，也是我接触的第一道回溯算法题，  
回溯法与其他搜索算法的不同之处在于，其在改变了操作的数组状态并进行完相应操作后，会撤销数组之前的改变，因此多出一步来  
在全排列中，我们的算法设计为将第 `1` 、 `2` 、 `3` 、 `...` 个数字依次与后面每个数字交换，交换到最后一位时将整个数组返回，  
利用递归的方式，完整获得每种排列  

```cpp
vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ret;
    backTrack(nums, 0, ret);
    return ret;
}

void backTrack(vector<int>& nums, int times, vector<vector<int>> &ret)
{
    if(times == nums.size() - 1)
    {
        ret.push_back(nums);
        return ;
    }
    for(int i = times; i < nums.size(); ++i)
    {
        swap(nums[i], nums[times]);
        backTrack(nums, times + 1, ret);
        swap(nums[i], nums[times]);
    }
}
```
