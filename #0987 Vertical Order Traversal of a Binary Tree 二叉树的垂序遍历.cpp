/*
    �ڴ�������У��������Ĺؼ���ϢΪ���������꣬������ʹ�ù�ϣ���������걣��������
    ֮�󽫸��ڵ㰴���������С����������ֱ�ӻ�����ź���Ľ����
    ֮�������Ƿ�仯��ÿ���ڵ��ֵ���μ��빹���õĶ�ά�����м���
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