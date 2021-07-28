/*
    basic idea is treat target-node as the root, store every node's parent node,
    then use DFS methode traverse the tree and store each suitable node
*/
/*
    ����˼·����target�����Ϊ���ĸ��ڵ㣬����һ����ϣ���¼ÿһ���ڵ��Լ��丸�ڵ㣬
    ����������ȵ�˼�뽫�����롰���ڵ㡱����Ϊk�Ľڵ��ֵ��¼����
*/

class Solution
{
    vector<int> ret;
    unordered_map<int, TreeNode*> parent;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        findParent(root);
        findNode(target, NULL, 0, k);
        return ret;
    }

    void findParent(TreeNode* root)
    {
        if (root->left)
        {
            parent[root->left->val] = root;
            findParent(root->left);
        }
        if (root->right)
        {
            parent[root->right->val] = root;
            findParent(root->right);
        }
    }

    void findNode(TreeNode* root, TreeNode* from, int depth, int k)
    {
        if (!root)
            return;
        if (depth == k)
        {
            ret.push_back(root->val);
            return;
        }
        if (root->left != from)
            findNode(root->left, root, depth + 1, k);
        if (root->right != from)
            findNode(root->right, root, depth + 1, k);
        if (parent[root->val] != from)
            findNode(parent[root->val], root, depth + 1, k);
    }
};