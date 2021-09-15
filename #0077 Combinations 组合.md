### 组合
### Combinations

> 给定两个整数 `n` 和 `k`，返回范围 `[1, n]` 中所有可能的 `k` 个数的组合。  
> 你可以按 **任何顺序** 返回答案。  

> Given two integers `n` and `k`, return all possible combinations of `k` numbers out of the range `[1, n]`.  
> You may return the answer in **any order**.  

----------

#### I 回溯算法

一道典型的回溯算法题目  
为了解决这道题，我们首先注意到，其基本思路为：  
取 `1` 作为数组的第一个数字，之后依次取后面的数字加到目前的数组中，待数组大小为 `k` 后返回  

在这里，采用回溯的方法解决  
在回溯递归中，我们为每个大小为 `k` 的数组确定返回的边界条件，即当该数组已经填满时可以将其作为一个返回的数组  
处理数组的过程如下：
1. 将当前的数字填入当前数组的下标
2. 将下标位置 + 1
3. 利用递归填写下一个下标
4. 将下标状态还原  

以此构建回溯算法即可

```cpp
vector<vector<int>> combine(int n, int k) 
{
    vector<vector<int>> ret;
    vector<int> cur(k);
    backTrack(n, k, ret, cur, index, 1);
    return ret;
}

void backTrack(int n, int k, vector<vector<int>>& ret, vector<int>& cur, int index, int times)
{
    if(index == k)
    {
        ret.push_back(cur);
        return ;
    }
    for(int i = times; i <= n; ++i)
    {
        cur[index++] = i;
        backTrack(n, k, ret, cur, index, i + 1);
        --index;
    }
}
```
