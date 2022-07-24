### 完全二叉树插入器
### Complete Binary Tree Inserter

> **完全二叉树**是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。  
> 设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。  
> 实现 `CBTInserter` 类:  
> - `CBTInserter(TreeNode root)` 使用头节点为 `root` 的给定树初始化该数据结构；  
> - `CBTInserter.insert(int v)`  向树中插入一个值为 `Node.val == val` 的新节点 `TreeNode`。使树保持完全二叉树的状态，**并返回插入节点 `TreeNode` 的父节点的值**；  
> - `CBTInserter.get_root()` 将返回树的头节点。  

> A **complete binary tree** is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.  
> Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.  
> Implement the `CBTInserter` class:  
> - `CBTInserter(TreeNode root)` Initializes the data structure with the `root` of the complete binary tree.  
> - `int insert(int v)` Inserts a `TreeNode` into the tree with value `Node.val == val` so that the tree remains complete, and returns the value of the parent of the inserted `TreeNode`.  
> - `TreeNode get_root()` Returns the root node of the tree.  

----------

#### I 队列+BFS

利用基于队列的BFS找到当前第一个子树不完整的节点，并将其记录在队列最前端  
之后，在插入的过程中更新队列即可记住需要插入子节点的那个节点  

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
class CBTInserter 
{
private:
    TreeNode* root;
    queue<TreeNode* > q;

public:
    CBTInserter(TreeNode* _root) 
    {
        this->root = _root;
        q.push(root);
        while(true)
        {
            TreeNode* cur = q.front();
            if(cur->left && cur->right)
            {
                q.pop();
                q.push(cur->left);
                q.push(cur->right);
            }
            else if(cur->left)
            {
                q.push(cur->left);
                break;
            }
            else
                break;
        }
    }
    
    int insert(int val) 
    {
        TreeNode* newNode = new TreeNode(val);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            if(!cur->left)
            {
                cur->left = newNode;
                q.push(cur->left);
                return cur->val;
            }
            else if(!cur->right)
            {
                q.pop();
                cur->right = newNode;
                q.push(cur->right);
                return cur->val;
            }
            else
                q.pop();
        }
        return -1;
    }
    
    TreeNode* get_root() 
    {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
```
