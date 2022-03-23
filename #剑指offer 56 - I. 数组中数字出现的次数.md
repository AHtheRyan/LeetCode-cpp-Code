### 数组中数字出现的次数

> 一个整型数组 `nums` 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。  

----------

#### I 位运算

利用异或运算对所有数字操作，可得到单独两个数字的异或结果  
根据异或的性质，该数字 `cand` 的最低位的 `1` 是两个数字第一个不同的位置，  
因此，可以利用该性质，将数组中的数字进行区分，找到两个不同的数字  

```cpp
vector<int> singleNumbers(vector<int>& nums) 
{
    int cand = 0;
    for(auto& num : nums)
        cand ^= num;
    int mark = cand & (-cand);
    int tmp = cand;
    for(auto& num : nums)
        if(num & mark)
            tmp ^= num;
    return {tmp, tmp ^ cand};
}
```
