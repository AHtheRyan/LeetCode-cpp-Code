### 二叉树的锯齿形层序遍历
### Binary Tree Zigzag Level Order Traversal

> 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。  

> Given the `root` of a binary tree, return the *zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

----------

#### I 广度优先搜索 with 栈

显然，如果以**层**为单位进行遍历，那么广度优先搜索是最佳解决方案，  
在一般的广度优先搜索中，每遍历到一个节点，就将该节点存储起来，  
和一般的广度优先搜索不同的是，这里的搜索顺序是Z字形的，  
我们采用 `vector` 模板存储每一层的值 `val`，  
如果节点A的子节点先存储，B的子节点后存储，则遍历到下一层的时候，需要先将B的子节点的值放入 `vector`，  
自然我们可以想到使用栈来进行这种 **先进后出** 的操作，但由于需要将一层的节点都处理完才能将子节点的值存入栈中，这里采用两个栈，  
一个是当前取出来分析节点的值，以及节点是否有左右子树的栈 `stk`，  
另一个是存储当前分析的层的节点的子树的栈 `stk2`，  
每次循环分析某个栈时，先查看其是否为空，为空则完成整棵树的遍历  

```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int>> ret;
    stack<TreeNode*> stk;
    stack<TreeNode*> stk2;
    if(!root)
        return ret;
    ret.push_back({root->val});

    if(root->left)
        stk.push(root->left);
    if(root->right)
        stk.push(root->right);
    while(true)
    {
        if(stk.empty())
            break;
        else
        {
            vector<int> cur;
            while(!stk.empty())
            {
                TreeNode* tmp = stk.top();
                cur.push_back(tmp->val);
                stk.pop();
                if(tmp->right)
                    stk2.push(tmp->right);
                if(tmp->left)
                    stk2.push(tmp->left);
            }
            ret.push_back(cur);
        }
        if(stk2.empty())
            break;
        else
        {
            vector<int> cur;
            while(!stk2.empty())
            {
                TreeNode* tmp = stk2.top();
                cur.push_back(tmp->val);
                stk2.pop();
                if(tmp->left)
                    stk.push(tmp->left);
                if(tmp->right)
                    stk.push(tmp->right);
            }
            ret.push_back(cur);
        }
    }
    return ret;
}
```

#### II 广度优先搜索 with 队列

在使用栈的方法中，我们之所以要用两个栈，一方面是因为 `vector` 只能高效单向插入，另一方面是因为 `stack` 只有一个出入口，  
如果采用一种能双向插入的模板，则可以减少模板的使用，因此，可以考虑双端队列 `deque`，这样就可以使用队列 `queue` 存储节点，  
另外，由于不同层 `deque` 的插入方向不同，因此需要设置标志位来提供插入的条件  

```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int>> ret;
    if(!root)
        return ret;
    queue<TreeNode*> node;
    node.push(root);
    bool flag = true;
    while(!node.empty())
    {
        deque<int> cur;
        int size = node.size();
        for(int i = 0; i < size; ++i)
        {
            auto tmp = node.front();
            node.pop();
            if(flag)
                cur.push_back(tmp->val);
            else
                cur.push_front(tmp->val);
            if(tmp->left)
                node.push(tmp->left);
            if(tmp->right)
                node.push(tmp->right);
        }
        ret.push_back(vector<int>{cur.begin(), cur.end()});
        flag = !flag;
    }
    return ret;
}
```
