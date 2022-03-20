### 二叉搜索树的最近公共祖先

> 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。  
> 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”  

----------

#### I 迭代

见[二叉搜索树的最近公共祖先](./%230235%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree%20二叉搜索树的最近公共祖先.md)  

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    int small = p->val > q->val ? q->val : p->val;
    int big = small == p->val ? q->val : p->val;
    while(true)
    {
        int num = root->val;
        if(num >= small && num <= big)
            return root;
        else if(num < small)
            root = root->right;
        else
            root = root->left;
    }
    return nullptr;
}
```
