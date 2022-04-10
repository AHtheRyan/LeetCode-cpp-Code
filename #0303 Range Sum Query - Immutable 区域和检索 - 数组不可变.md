### 区域和检索 - 数组不可变
### Range Sum Query - Immutable

> 给定一个整数数组 `nums`，处理以下类型的多个查询:  
> 计算索引 `left` 和 `right` （包含 `left` 和 `right`）之间的 `nums` 元素的**和**，其中 `left <= right`  
> 实现 `NumArray` 类：  
> - `NumArray(int[] nums)` 使用数组 `nums` 初始化对象  
> - `int sumRange(int i, int j)` 返回数组 `nums` 中索引 `left` 和 `right` 之间的元素的**总和**，包含 `left` 和 `right` 两点（也就是 `nums[left] + nums[left + 1] + ... + nums[right]`)  

> Given an integer array `nums`, handle multiple queries of the following type:  
> Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.  
> Implement the `NumArray` class:  
> - `NumArray(int[] nums)` Initializes the object with the integer array `nums`.  
> - `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).  

----------

#### I 前缀和

简单前缀和

```cpp
class NumArray 
{
private:
    vector<int> nums;
    vector<int> sum;

public:
    NumArray(vector<int>& nums): nums(nums)
    {
        int n = nums.size();
        sum.resize(n);
        sum[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i)
            sum[i] = nums[i] + sum[i + 1];
        sum.push_back(0);
    }
    
    int sumRange(int left, int right) 
    {
        return sum[left] - sum[right + 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```
