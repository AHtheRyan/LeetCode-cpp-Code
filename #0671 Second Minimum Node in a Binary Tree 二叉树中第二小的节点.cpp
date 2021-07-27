/*
    according to the problem, the root element must be the minimum element, so to find the second minimum element,
    we need to compare each element to the minimum element in order, and return the minimum element of elements that bigger than the root element,
    use recursion methode, analyse each node:
    1. the node is empty, return -1 directly
    2. the node element < current element, return current element
    3. the node element = root element:
        3.1 find the minimum element of the left and right subtree
        3.2 compare these two numbers, if both > root value, return the smaller one, else return the bigger one
*/
/*
    根据题意，根节点的元素必然为最小元素，那么如果要找到第二小的元素，
    只需要将依次将每个子节点的值与最小元素比较，然后取大于根节点值的最小值即可，
    使用递归的方法，对每个节点进行分析：
    1. 如果该节点为空，则直接返回-1
    2. 如果该节点的值大于根节点，则直接返回该节点的值
    3. 如果该节点的值等于根节点，则分析两棵子树：
        3.1 找该节点左子树和右子树的最小值
        3.2 比较两个最小值如果都大于根节点，则取较小的那个；如果一个大一个小，取较大的那个
*/ 

int findSecondMinimumValue(TreeNode* root)
{
    return findVal(root, root->val);
}

int findVal(TreeNode* root, int val)
{
    if (!root)
        return -1;
    if (root->val > val)
        return root->val;
    int min1 = findVal(root->left, val);
    int min2 = findVal(root->right, val);
    if (min1 > val && min2 > val)
        return min(min1, min2);
    return max(min1, min2);
}
