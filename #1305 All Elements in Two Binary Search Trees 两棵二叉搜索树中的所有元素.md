### 两棵二叉搜索树中的所有元素
### All Elements in Two Binary Search Trees

> 给你 `root1` 和 `root2` 这两棵二叉搜索树。请你返回一个列表，其中包含**两棵树**中的所有整数并按**升序**排序。  

> Given two binary search trees `root1` and `root2`, return *a list containing all the integers from both trees sorted in **ascending** order*.  

----------

#### I 递归 + 排序

利用递归将两棵二叉搜索树放在数组中，再利用排序将数组整合即可  

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> vec1;
        vector<int> vec2;
        get(root1, vec1);
        get(root2, vec2);
        int n1 = vec1.size();
        int n2 = vec2.size();
        int index1 = 0;
        int index2 = 0;
        vector<int> ret(n1 + n2);
        for(int i = 0; i < n1 + n2; ++i)
        {
            int a = index1 < n1 ? vec1[index1] : INT_MAX;
            int b = index2 < n2 ? vec2[index2] : INT_MAX;
            if(a < b)
            {
                ret[i] = a;
                ++index1;
            }
            else
            {
                ret[i] = b;
                ++index2;
            }
        }
        return ret;
    }

    void get(TreeNode* root, vector<int>& vec)
    {
        if(!root)
            return;
        get(root->left, vec);
        vec.emplace_back(root->val);
        get(root->right, vec);
    }
};
```
