### 加一
### Plus One

> 给定一个由**整数**组成的**非空**数组所表示的非负整数，在该数的基础上加一。  
> 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。  
> 你可以假设除了整数 0 之外，这个整数不会以零开头。  

> You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.  
> Increment the large integer by one and return *the resulting array of digits*.  

----------

### 模拟

简单模拟加一过程即可：
1. 如果末位不为 `9`，则直接将末位加一即可
2. 如果末位为 `9`，从后往前找到第一个不为 `9` 的数字，将其加一，其后的数字都变为 `0`，如果该位置在最前，则所有数字变为 `0`，并增加一个前置 `1` 即可

```cpp
vector<int> plusOne(vector<int>& digits) 
{
    int size = digits.size();
    if(digits[size - 1] != 9)
        ++digits[size - 1];
    else
    {
        int i = size - 1;
        for(; digits[i] == 9 && i > 0; --i)
            digits[i] = 0;
        if(i == 0 && digits[i] != 9)
            ++digits[i];
        else
        {
            vector<int> ret(size + 1);
            ret[0] = 1;
            return ret;
        }
    }
    return digits;
}
```
