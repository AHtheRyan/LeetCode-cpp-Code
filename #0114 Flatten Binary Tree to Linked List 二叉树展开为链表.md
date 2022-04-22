### 二叉树展开为链表
### Flatten Binary Tree to Linked List

> 给你二叉树的根结点 `root`，请你将它展开为一个单链表：  
> - 展开后的单链表应该同样使用 `TreeNode`，其中 `right` 子指针指向链表中下一个结点，而左子指针始终为 `null`。 
> - 展开后的单链表应该与二叉树`先序遍历`顺序相同。  

> Given the `root` of a binary tree, flatten the tree into a "linked list":  
> - The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.  
> - The "linked list" should be in the same order as a `pre-order traversal` of the binary tree.  

----------

#### I 栈 + DFS

基于栈对整棵树进行深度优先遍历即可  
对于任意节点，由于要按照先序遍历的顺序将每个节点排列，因此，在遍历任意节点位置时：  
1. 如果该节点存在右子节点且不存在左子节点，则可以跳过，直接对其右子节点进行判断  
2. 上述步骤循环完之后，此时的节点至少满足“没有右子节点”和“有左子节点”其中一项：  
   - 如果该节点存在右子节点，则将其堆入栈中，等待处理完左边的节点再将其接入链表中（先序遍历要求）  
   - 如果该节点存在左子节点，则将其放在当前节点的右子节点，并将左子节点置为 `nullptr`  
3. 此时，我们完成了将当前节点的右子节点存储并将左子节点变为右子节点的任务，接下来对可能存在的新的右子节点进行处理：  
   - 如果存在新的右子节点，则直接进入下一次循环  
   - 如果不存在新的右子节点，则将栈中存储的节点作为右子节点放入栈中即可  
完成循环即可实现遍历的过程  

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
    void flatten(TreeNode* root) 
    {
        stack<TreeNode* > stk;
        TreeNode* cur = root;
        while(!stk.empty() || cur)
        {
            while(cur->right && !cur->left)
                cur = cur->right;
            if(cur->right)
                stk.push(cur->right);
            if(cur->left)
                cur->right = cur->left;
            cur->left = nullptr;
            if(!cur->right && !stk.empty())
            {
                cur->right = stk.top();
                stk.pop();
            }
            cur = cur->right;
        }
    }
};
```
