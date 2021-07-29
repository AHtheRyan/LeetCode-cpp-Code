/*
    observing the formed matrix, we can find that the matrix has the following characteristics:
    1. the number of rows in the matrix is ​​the depth of the tree
    2. the number of columns in the matrix is ​​2^(the number of rows) - 1
    3. the horizontal distance difference between the child node and the parent node in each row is related to the power of 2
    according to the three characteristics, construct three functions to find the required matrix
*/
/*
    观察形成的矩阵，可以发现矩阵具有以下特征：
    1. 矩阵行数为树的深度
    2. 矩阵列数为 2 的行数次方减去 1
    3. 每行子节点与父节点的横向距离差值与 2 的幂有关
    按照三个特征，构建三个函数求出所需要的矩阵
*/ 

class Solution
{
public:
    //main function, create the matrix and initialize the factors of the final matrix
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

    //get the final matrix
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

    //find the depth of the tree
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