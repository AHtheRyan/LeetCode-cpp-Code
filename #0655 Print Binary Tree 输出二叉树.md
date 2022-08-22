### 输出二叉树
### Print Binary Tree

> 给你一棵二叉树的根节点 `root`，请你构造一个下标从**0**开始、大小为 `m x n` 的字符串矩阵 `res`，用以表示树的**格式化布局**。构造此格式化布局矩阵需要遵循以下规则：  
> - 树的**高度**为 `height`，矩阵的行数 `m` 应该等于 `height + 1`。  
> - 矩阵的列数 `n` 应该等于 `2^(height+1) - 1`。  
> - **根节点**需要放置在**顶行**的**正中间**，对应位置为 `res[0][(n-1)/2]`。  
> - 对于放置在矩阵中的每个节点，设对应位置为 `res[r][c]`，将其左子节点放置在 `res[r+1][c-2^(height-r-1)]`，右子节点放置在 `res[r+1][c+2^(height-r-1)]`。  
> - 继续这一过程，直到树中的所有节点都妥善放置。  
> - 任意空单元格都应该包含空字符串 `""`。  
> 
> 返回构造得到的矩阵 `res`。  

> Given the `root` of a binary tree, construct a **0-indexed** `m x n` string matrix `res` that represents a **formatted layout** of the tree. The formatted layout matrix should be constructed using the following rules:  
> - The **height** of the tree is `height` and the number of rows `m` should be equal to `height + 1`.  
> - The number of columns n should be equal to `2^(height+1 - 1)`.  
> - Place the **root node** in the **middle** of the **top row** (more formally, at location `res[0][(n-1)/2]`).  
> - For each node that has been placed in the matrix at position `res[r][c]`, place its **left child** at `res[r+1][c-2height-r-1]` and its **right child** at `res[r+1][c+2height-r-1]`.  
> - Continue this process until all the nodes in the tree have been placed.  
> - Any empty cells should contain the empty string `""`.  
> 
> Return *the constructed matrix `res`*.  

----------

#### I DFS + 递归构造

观察形成的矩阵，可以发现矩阵具有以下特征：  
1. 矩阵行数为树的深度  
2. 矩阵列数为 `2` 的行数次方减去 `1`  
3. 每行子节点与父节点的横向距离差值与 `2` 的幂有关  

按照三个特征，构建三个函数求出所需要的矩阵  

```cpp
//2022.08版本
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
private:
    int m, n;
    vector<vector<string>> ret;

public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        this->m = findHeight(root, 0) + 1;
        this->n = int(pow(2.0, m)) - 1;
        ret.resize(m, vector<string>(n));
        putString(root, 0, (n - 1) / 2);
        return ret;
    }

    int findHeight(TreeNode* root, int height)
    {
        int lheight = height;
        int rheight = height;
        if(root->left)
            lheight = findHeight(root->left, lheight + 1);
        if(root->right)
            rheight = findHeight(root->right, rheight + 1);
        return max(lheight, rheight);
    }

    void putString(TreeNode* root, int row, int col)
    {
        if(!root)
            return ;
        ret[row][col] = to_string(root->val);
        putString(root->left, row + 1, col - pow(2.0, m - 2 - row));
        putString(root->right, row + 1, col + pow(2.0, m - 2 - row));
    }
};
```
```cpp
//2021.07版本
class Solution
{
public:
    //主函数，构建最后需要表示的矩阵，初始化求出最终矩阵的相关系数
    vector<vector<string>> printTree(TreeNode* root)
    {
        int m = findDepth(root, 0);
        int n = 2 * pow(2, m - 1) - 1;
        vector<vector<string>> tree(m, vector<string>(n));
        int pos = n / 2;
        int space = pow(2, m - 1) / 2;
        getTree(tree, root, 0, pos, space);
        return tree;
    }

    //求出最终矩阵
    void getTree(vector<vector<string>>& tree, TreeNode* root, int m, int pos, int space)
    {
        if (!root)
            return;
        tree[m][pos] = to_string(root->val);
        if (root->left)
            getTree(tree, root->left, m + 1, pos - space, space / 2);
        if (root->right)
            getTree(tree, root->right, m + 1, pos + space, space / 2);
    }

    //找到所要求的的树的深度
    int findDepth(TreeNode* root, int depth)
    {
        if (!root)
            return 0;
        ++depth;
        int left;
        int right;
        if (!root->left)
            left = depth;
        else
            left = findDepth(root->left, depth);
        if (!root->right)
            right = depth;
        else
            right = findDepth(root->right, depth);
        int bigger = left > right ? left : right;
        depth = depth > bigger ? depth : bigger;
        return depth;
    }
};
```
