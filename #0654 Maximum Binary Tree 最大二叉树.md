### 最大二叉树
### Maximum Binary Tree

> 给定一个不重复的整数数组 `nums`。 最大二叉树 可以用下面的算法从 `nums` 递归地构建:  
> 1. 创建一个根节点，其值为 `nums` 中的最大值。  
> 2. 递归地在最大值**左边**的**子数组前缀上**构建左子树。  
> 3. 递归地在最大值**右边**的**子数组后缀上**构建右子树。  
> 
> 返回 *`nums` 构建的**最大二叉树***。  

> You are given an integer array `nums` with no duplicates. A **maximum binary tree** can be built recursively from `nums` using the following algorithm:  
> 1. Create a root node whose value is the maximum value in `nums`.  
> 2. Recursively build the left subtree on the **subarray prefix** to the **left** of the maximum value.  
> 3. Recursively build the right subtree on the **subarray suffix** to the **right** of the maximum value.  
> 
> Return *the **maximum binary tree** built from `nums`*.  

----------

#### I 递归

基于要求进行递归即可  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int n = nums.size();
        return build(nums, 0, n - 1);
    }

    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return nullptr;
        if(left == right)
            return new TreeNode(nums[left]);
        int rec = INT_MIN;
        int mid = left;
        for(int i = left; i <= right; ++i)
        {
            if(rec < nums[i])
            {
                rec = nums[i];
                mid = i;
            }
        }
        TreeNode* ret = new TreeNode(rec);
        ret->left = build(nums, left, mid - 1);
        ret->right = build(nums, mid + 1, right);
        return ret;
    }
};
```
