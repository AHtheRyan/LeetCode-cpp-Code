### 将有序数组转化为二叉搜索树
### Convert Sorted Array to Binary Search Tree

> 给你一个整数数组 `nums`，其中元素已经按**升序**排列，请你将其转换为一棵**高度平衡**二叉搜索树。  
> **高度平衡**二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。  

> Given an integer array `nums` where the elements are sorted in **ascending order**, convert *it to a **height-balanced** binary search tree*.  
> A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.  

----------

#### I 分治

由于要变成二叉搜索树，且数组本身为递增，因此，只需要每次选取数组最中间的数字作为根节点，并将数组一分为二进一步确定其左右子树，便可实现一棵二叉树的构建  

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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return select(nums, 0, nums.size() - 1);
    }

    TreeNode* select(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = select(nums, left, mid - 1);
        cur->right = select(nums, mid + 1, right);
        return cur;
    }
};
```
