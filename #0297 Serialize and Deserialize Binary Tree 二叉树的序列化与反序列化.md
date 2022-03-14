### 二叉树的序列化与反序列化
### Serialize and Deserialize Binary Tree

> 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。  
> 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。  

> Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.  
> Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.  

----------

#### I 先序遍历序列化 + 队列反序列化

见[序列化二叉树](./%23剑指offer%2037.%20序列化二叉树.md)  

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
