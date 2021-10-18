### 二叉搜索树中第K小的元素
### Kth Smalest Element in a BST

> 给定一个二叉搜索树的根节点 `root`，和一个整数 `k`，请你设计一个算法查找其中第 `k` 个最小元素（从 1 开始计数）。  

> Given the `root` of a binary search tree, and an integer `k`, return *the `kth` smallest value (**1-indexed**) of all the values of the nodes in the tree*.  

----------

#### I DFS + 排序

利用数组记录整棵树，DFS遍历整个树并进行排序

```cpp
int kthSmallest(TreeNode* root, int k) 
{
    vector<int> rec;
    dfs(root, rec);
    sort(rec.begin(), rec.end());
    return *(rec.begin() + k - 1);
}

void dfs(TreeNode* root, vector<int>& rec)
{
    if(!root)
        return ;
    rec.push_back(root->val);
    dfs(root->left, rec);
    dfs(root->right, rec);
}
```

#### II 中序遍历

利用二叉搜索树的性质，通过中序遍历直接返回第k个元素

```cpp
int kthSmallest(TreeNode* root, int k) 
{
    int ret = 0;
    int cnt = 0;
    ldr(root, k, cnt, ret);
    return ret;
}

void ldr(TreeNode* root, int k, int& cnt, int& ret)
{
    if(!root)
        return ;
    ldr(root->left, k, cnt, ret);
    if(++cnt == k)
    {
        ret = root->val;
        return ;
    }
    ldr(root->right, k, cnt, ret);
}
```
