### 重建二叉树

> 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。  
> 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。  

----------

#### I 递归

对于中序遍历数组，需要明确一件事，即任意数字对应的位置左侧在树中的都在其左子树，右侧在树中都在其右子树  
我们先设置哈希表，记录中序遍历每个数字对应的下标位置，然后进行递归操作，具体操作如下：  
1. 首先，定义当前的根节点，其位置为 `preorder` 数组的第一个数字  
2. 记录下该节点在中序遍历中的下标位置，那么，该位置左侧的值都在其左子树中，右侧的值都在其右子树中  
3. 计算左右子树的大小，计算规则为：  
   - 左子树：`当前中序遍历下标位置 - 中序遍历的起始位置`    
   - 右子树：`中序遍历最后位置 - 当前中序遍历下标位置`  
4. 对左右子树进行上述的相同操作，注意左右字数重新设定的两个数组下标界限：  
   - 左子树：`preorder` 数组左侧界限加一，右侧界限为左子树大小，`inorder` 数组左侧界限不变，右侧界限为当前数字下标减一  
   - 右子树：`preorder` 数组左侧界限为左子树左侧加右侧界限，右侧界限不变，`inorder` 数组左侧界限为当前数字下标加一，右侧界限不变  
5. 最后确定返回条件：`inorder` 数组左下标大于右下标  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    unordered_map<int, int> index;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = preorder.size();
        for(int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        return recursion(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright)
    {
        if(inleft > inright)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preleft]);
        int rootIndex = index[preorder[preleft]];
        int leftSize = rootIndex - inleft;
        root->left = recursion(preorder, inorder, preleft + 1, leftSize, inleft, rootIndex - 1);
        int rightSize = inright - rootIndex;
        root->right = recursion(preorder, inorder, preleft + 1 + leftSize, preright, rootIndex + 1, inright);
        return root;
    }
};
```

#### II 迭代

递归过程的实现借助于DFS，因此可以用栈实现，  
可以将 `preorder` 的第一个数字作为根节点创建，然后将其堆入栈中，并设置中序遍历数组的下标 `inorderIndex`  
迭代过程可以理解如下：  
1. 确定当前 `preorder` 中的数字 `cur`  
2. 记录栈顶节点 `node`  
3. 判断当前栈顶节点的值与中序遍历节点的值是否相等  
   - 如果不等，说明当前的栈顶节点存在左子节点，将当前数字变为栈顶节点的左子节点，同时入栈  
   - 如果相等，说明当前的栈顶节点的左子节点“到底了”，可以循环比较栈顶节点和中序遍历的值，只要相等就弹出，直到不等之后，将不等的值作为最后一个弹出节点的右子节点，并入栈
4. 循环上述过程  

可以看到，迭代的实质就是通过 `preorder` 确定每个节点的左子节点，利用栈和 `inorder` 确定左子节点到底，再插入右子节点继续进行左子节点的判断  
简单来说，就是循环插入左子节点，没有就插入右子节点，在新节点中找左子节点，如果有就继续循环插入左子节点，如果一直没有就一直循环插入右子节点，直到所有节点都被插入为止  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.empty())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode* > stk;
        stk.push(root);
        int inorderIndex = 0;
        for(int i = 1; i < preorder.size(); ++i)
        {
            int cur = preorder[i];
            TreeNode* node = stk.top();
            if(node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(cur);
                stk.push(node->left);
            }
            else
            {
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(cur);
                stk.push(node->right);
            }
        }
        return root;
    }
};
```
