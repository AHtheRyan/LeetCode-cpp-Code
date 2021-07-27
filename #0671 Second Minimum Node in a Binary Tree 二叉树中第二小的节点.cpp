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
    �������⣬���ڵ��Ԫ�ر�ȻΪ��СԪ�أ���ô���Ҫ�ҵ��ڶ�С��Ԫ�أ�
    ֻ��Ҫ�����ν�ÿ���ӽڵ��ֵ����СԪ�رȽϣ�Ȼ��ȡ���ڸ��ڵ�ֵ����Сֵ���ɣ�
    ʹ�õݹ�ķ�������ÿ���ڵ���з�����
    1. ����ýڵ�Ϊ�գ���ֱ�ӷ���-1
    2. ����ýڵ��ֵ���ڸ��ڵ㣬��ֱ�ӷ��ظýڵ��ֵ
    3. ����ýڵ��ֵ���ڸ��ڵ㣬���������������
        3.1 �Ҹýڵ�������������������Сֵ
        3.2 �Ƚ�������Сֵ��������ڸ��ڵ㣬��ȡ��С���Ǹ������һ����һ��С��ȡ�ϴ���Ǹ�
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
