### 数组中数字出现的次数II

> 在一个数组 `nums` 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。  

----------

#### I 位运算

出现三次的数字，该位置累加后再对 `3` 取余，结果为 `0`  
出现一次的数字，该位置累加后再对 `3` 取余，结果为 `1`  
根据次性质可以按位复原出现一次的数字

```cpp
int singleNumber(vector<int>& nums) 
{
    int digit[32] = {0};
    for(auto& num : nums)
        for(int i = 0; i < 32; ++i)
        {
            digit[i] += (num & 1);
            num >>= 1;
        }
    int ret = 0;
    for(int i = 31; i >= 0; --i)
    {
        ret <<= 1;
        ret |= (digit[i] % 3);
    }
    return ret;
}
```

#### II 有限状态自动机位运算

![1648042899(1)](https://user-images.githubusercontent.com/46887748/159713183-e5a0faac-756d-4537-94dc-7e40dc46a309.png)  
基于[上图](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/)进行数字的运算，对于 `nums` 数组中 `num` 数字的任何一位，可以知道其对 `3` 取余只会有 `3` 中不同的状态：`0`/`1`/`2`  
在二进制中则为 `00`/`01`/`02`，因此，我们可以设置 `one` `two` 两个参数分别记录数字 `num` 每一位在这三个状态变化中到了第几位  
对于 `one`，如果输入为 `0`，则其必然不变，如果输入为 `1`，则（如果 `two` 为 `0` 则取反，如果 `two` 为 `1` 则取反），经过化简可得最终表达为 `one ^ num & ~two`  
对于 `two`，与上同理，可得表达式为 `two ^ num & ~two`  
最后返回 `one`，即状态为 `01` 的位的组合，即为只出现一次的数字  

```cpp
int singleNumber(vector<int>& nums) 
{
    int one = 0;
    int two = 0;
    for(auto& num : nums)
    {
        one = one ^ num & ~two;
        two = two ^ num & ~one;
    }
    return one;
}
```
