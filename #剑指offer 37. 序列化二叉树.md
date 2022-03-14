### 序列化二叉树

> 请实现两个函数，分别用来序列化和反序列化二叉树。  
> 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。  

----------

#### I 前序遍历序列化 + 队列解码

可以利用前序遍历将原树转化为字符串，其中空指针记为 `'n,'`  
再利用队列，以序列化的次序为标准，解码即可  

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
class Codec 
{
public:
    void dfs(TreeNode* root, string& str)
    {
        if(!root)
            str += "n,";
        else
        {
            str += to_string(root->val) + ',';
            dfs(root->left, str);
            dfs(root->right, str);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string ret;
        dfs(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        queue<string> q;
        string cur;
        for(auto& c : data)
        {
            if(c == ',')
            {
                q.push(cur);
                cur = "";
            }
            else
                cur += c;
        }
        if(!cur.empty())
            q.push(cur);
        return rdfs(q);
    }

    TreeNode* rdfs(queue<string>& q)
    {
        string cur = q.front();
        if(cur == "n")
        {
            q.pop();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(cur));
        q.pop();
        root->left = rdfs(q);
        root->right = rdfs(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
