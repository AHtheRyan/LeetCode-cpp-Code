### 根据二叉树创建字符串
### Construct String From Binary Tree

> 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。  
> 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。  

> Given the `root` of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.  
> Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.  

----------

#### I 递归

递归比较简单粗暴，按照题目要求进行操作即可  

```cpp
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
public:
    string tree2str(TreeNode* root) 
    {
        if(!root)
            return "";
        if(!root->left && !root->right)
            return to_string(root->val);
        if(!root->left && root->right)
            return to_string(root->val) + "()" + '(' + tree2str(root->right) +')';
        if(!root->right)
            return to_string(root->val) + '(' + tree2str(root->left) + ')';
            return to_string(root->val) + '(' + tree2str(root->left) + ')' + '(' + tree2str(root->right) + ')';
    }
};
```

#### II 迭代

基于栈进行前序遍历，这里额外增加一个哈希表记录每个节点，如果一个节点被遍历过则记录  
每当对节点进行操作，先判断其是否被记录过，如果记录过则直接在字符串后添加 `)` 并将节点出栈  
否则再对其进行左括号和数值的操作  

```cpp
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
public:
    string tree2str(TreeNode* root) 
    {
        string ret;
        stack<TreeNode* > stk;
        unordered_set<TreeNode* > checked;
        stk.push(root);
        while(!stk.empty())
        {
            auto cur = stk.top();
            if(checked.count(cur))
            {
                if(cur != root)
                    ret += ')';
                stk.pop();
            }
            else
            {
                checked.insert(cur);
                if(cur != root)
                    ret += '(';
                ret += to_string(cur->val);
                if(!cur->left && cur->right)
                    ret += "()";
                if(cur->right)
                    stk.push(cur->right);
                if(cur->left)
                    stk.push(cur->left);
            }
        }
        return ret;
    }
};
```
