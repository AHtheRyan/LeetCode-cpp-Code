### 通过翻转子数组使两个数组相等
### Make Two Arrays Equal by Reversing Sub-arrays

> 给你两个长度相同的整数数组 `target` 和 `arr`。每一步中，你可以选择 `arr` 的任意**非空子数组**并将它翻转。你可以执行此过程任意次。  
> *如果你能让 `arr` 变得与 `target` 相同，返回 `True`；否则，返回 `False`*。  

> You are given two integer arrays of equal length `target` and `arr`. In one step, you can select any **non-empty sub-array** of `arr` and reverse it. You are allowed to make any number of steps.  
> Return *`true` if you can make `arr` equal to `target` or `false` otherwise*.  

----------

#### I 排序比较

根据数学归纳法易得只要两个数组元素相同则一定可以通过翻转变换  
因此只需要对比数组中的元素是否相同即可  

```cpp
bool canBeEqual(vector<int>& target, vector<int>& arr) 
{
    sort(arr.begin(), arr.end());
    sort(target.begin(), target.end());
    return arr == target;
}
```
