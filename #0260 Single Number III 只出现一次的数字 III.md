### 只出现一次的数字III
### Single Number III

> 给定一个整数数组 `nums`，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按**任意顺序**返回答案。

> Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in **any order**.  

----------

#### I 位运算

利用异或，很容易找到两个单独的数字的异或结果，所以需要做的事是把两个数字分开  
对于两个数字异或的结果，必然有一二进制位一个为 `0`，一个为 `1`  
如果找到那个二进制位，则可以这样考虑：
1. 设置该二进制位为 `1`，其他各位置都为 `0` 的数字 `x`  
2. 将 `x` 与每个数字求**与**运算，这样该位置为 `1` 的数字和为 `0` 的数字分别表现为 `x` 和 `0`  
3. 表现为 `x` 和 `0` 的数字分别与两个单独数字的其中一个是有相同性质的，即某一位置数字为 `1` 或者 `0`  
4. 这样就可以将数字分为两组，分别求异或，得到最终的两个单独的数字  

```cpp
vector<int> singleNumber(vector<int>& nums) 
{
    int size = nums.size();
    int exor = 0;
    for(auto num : nums)
        exor ^= num;
    int lsb = (exor == INT_MIN) ? exor : exor & (-exor);
    int ret1 = 0;
    int ret2 = 0;
    for(auto num : nums)
    {
        if(num & lsb)
            ret1 ^= num;
        else
            ret2 ^= num;
    }
    return {ret1, ret2};
}
```
