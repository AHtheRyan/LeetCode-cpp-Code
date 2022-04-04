### 区域和检索 - 数组可修改
### Range Sum Query - Mutable

> 给你一个数组 `nums`，请你完成两类查询。  
> 1. 其中一类查询要求**更新**数组 `nums` 下标对应的值  
> 2. 另一类查询要求返回数组 `nums` 中索引 `left` 和索引 `right` 之间（**包含**）的nums元素的**和**，其中 `left <= right`  
> 
> 实现 `NumArray` 类：  
> - `NumArray(int[] nums)` 用整数数组 `nums` 初始化对象  
> - `void update(int index, int val)` 将 `nums[index]` 的值 更新 为 `val`  
> - `int sumRange(int left, int right)` 返回数组 `nums` 中索引 `left` 和索引 `right` 之间（**包含**）的nums元素的**和**（即，`nums[left] + nums[left + 1], ..., nums[right]`）  

> Given an integer array `nums`, handle multiple queries of the following types:  
> 1. **Update** the value of an element in `nums`.  
> 2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.  
> 
> Implement the `NumArray` class:  
> - `NumArray(int[] nums)` Initializes the object with the integer array `nums`.  
> - `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.  
> - `int sumRange(int left, int right)` Returns the **sum** of the elements of nums between indices left and right **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).  

----------

#### I 线段树

线段树是将数组模拟为二叉树，其中，根节点表示左右子树节点的和， 叶子结点表示数组每个下标对应的数字  
可以发现此二叉树也可以用数组表示，且对每个节点 `index` 其左右子树的下标为 `left = 2 * index + 1` `right = 2 * index +2`  
可根据此规则构造线段树  
每次更新数字时可以对线段树进行递归更新，只需要找到更新的叶子结点即可  
求区间和时可以利用线段树将数组二分的性质递归查找  

```cpp
class NumArray 
{
private:
    vector<int> segmentTree;
    int n;

    void create(int node, int left, int right, vector<int>& nums)
    {
        if(left == right)
        {
            segmentTree[node] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        create(2 * node + 1, left, mid, nums);
        create(2 * node + 2, mid + 1, right, nums);
        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
    }

    void change(int node, int left, int right ,int index, int val)
    {
        if(left == right)
        {
            segmentTree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if(index <= mid)
            change(2 * node + 1, left, mid, index, val);
        else
            change(2 * node + 2, mid + 1, right, index, val);
        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
    }

    int sum(int left, int right, int start, int end, int node)
    {
        if(left == start && right == end)
            return segmentTree[node];
        int mid = start + (end - start) / 2;
        if(right <= mid)
            return sum(left, right, start, mid, node * 2 + 1);
        else if(left > mid)
            return sum(left, right, mid + 1, end, node * 2 + 2);
        else
            return sum(left, mid, start, mid, node * 2 + 1) + sum(mid + 1, right, mid + 1, end, node * 2 + 2);
    }

public:
    NumArray(vector<int>& nums): n(nums.size()), segmentTree(nums.size() * 4)
    {
        create(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) 
    {
        change(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) 
    {
        return sum(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```

#### II 树状数组

树状数组的理解可以见[B站视频](https://www.bilibili.com/video/BV1pE41197Qj?spm_id_from=333.1007)  

```cpp
class NumArray 
{
private:
    vector<int> nums;
    vector<int> tree;

    int lowbit(int x)
    {
        return x & (-x);
    }

    void add(int x, int index)
    {
        while(index < tree.size())
        {
            tree[index] += x;
            index += lowbit(index);
        }
    }

    int preSum(int index)
    {
        int ret = 0;
        while(index > 0)
        {
            ret += tree[index];
            index -= lowbit(index);
        }
        return ret;
    }

public:
    NumArray(vector<int>& nums): nums(nums), tree(nums.size() + 1)
    {
        for(int i = 0; i < nums.size(); ++i)
            add(nums[i], i + 1);
    }
    
    void update(int index, int val) 
    {
        int delta = val - nums[index];
        add(delta, index + 1);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) 
    {
        return preSum(right + 1) - preSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```
