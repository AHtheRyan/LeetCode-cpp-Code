### 二叉搜索树的后序遍历序列.md

> 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 `true`，否则返回 `false`。假设输入的数组的任意两个数字都互不相同。  

----------

#### I 递归

二叉搜索树的一个性质为，左子树的元素都小于根节点，右子树的元素都大于根节点  
我们可以利用次性质，分治递归处理原数组，可将原数组分为三部分：左子树及其子树、右子树及其子树、根  
显然，左子树及其子树都小于跟，右子树及其子树都大于根，且三部分在数组中是按次序排列的  
因此，我们可以以数组最后的元素作为参考，比其小的构建左子树，比其大的构建右子树  
如果两个子树无法构建，或者数组不能被分成三部分，则数组存在问题，返回 `false`，否则返回 `true`  

```cpp
class Solution 
{
public:
    bool verifyPostorder(vector<int>& postorder) 
    {
        return recursion(postorder, 0, postorder.size() - 1);
    }

    bool recursion(vector<int>& postorder, int left, int right)
    {
        if(left >= right)
            return true;
        int index = left;
        while(postorder[index] < postorder[right])
            ++index;
        int child = index;
        while(postorder[index] > postorder[right])
            ++index;
        return index == right && recursion(postorder, left, child - 1) && recursion(postorder, child, right - 1);
    }
};
```

#### II 单调栈 + 遍历

倒序遍历整个数组，并创建一个单调递增栈 `stk`，对于遍历时递增的元素，我们每次都将其直接堆入栈中，此操作相当于在数组中构造右子节点  
如果遇到数字变小，说明应该为当前位置父节点的左子节点，可以循环判断，给原数的各个节点增加左子节点，并更新当前的最大值为最后被弹出的值（此值为当前处理的根节点）  
如此循环，如果遇到某个值大于当前根节点，说明不符合二叉搜索树的要求，返回 `false`，否则遍历结束，返回 `true`  

```cpp
bool verifyPostorder(vector<int>& postorder) 
{
    int n = postorder.size();
    stack<int> stk;
    int curmax = INT_MAX;
    for(int i = n - 1; i >= 0; --i)
    {
        if(postorder[i] > curmax)
            return false;
        while(!stk.empty() && stk.top() > postorder[i])
        {
            curmax = stk.top();
            stk.pop();
        }
        stk.push(postorder[i]);
    }
    return true;
}
```
