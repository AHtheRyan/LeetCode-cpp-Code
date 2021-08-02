/*
    在垂序遍历中，二叉树的关键信息为其行列坐标，可以先使用哈希表将行列坐标保存起来，
    之后将各节点按照列坐标大小排序，这样就直接获得了排好序的结果，
    之后按照列是否变化将每个节点的值依次加入构建好的二维数组中即可
*/

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<tuple<int, int, int>> node;
    record(root, 0, 0, node);
    sort(node.begin(), node.end());
    vector<vector<int>> ret;
    int min = INT_MIN;
    for (auto [col, row, val] : node)
    {
        if (col != min)
        {
            min = col;
            ret.emplace_back();
        }
        ret.back().push_back(val);
    }
    return ret;
}

void record(TreeNode* root, int row, int col, vector<tuple<int, int, int>>& node)
{
    if (!root)
        return;
    node.emplace_back(col, row, root->val);
    record(root->left, row + 1, col - 1, node);
    record(root->right, row + 1, col + 1, node);
}