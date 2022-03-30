### 自除数
### Self Dividing Numbers

> **自除数**是指可以被它包含的每一位数整除的数。  
> - 例如，`128` 是一个**自除数**，因为 `128 % 1 == 0`，`128 % 2 == 0`，`128 % 8 == 0`。  
> 
> **自除数**不允许包含 `0`。  
> 给定两个整数 `left` 和 `right`，返回一个列表，*列表的元素是范围 `[left, right]` 内所有的**自除数***。  

> A **self-dividing number** is a number that is divisible by every digit it contains.  
> - For example, `128` is a **self-dividing number** because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.  
> 
> A **self-dividing number** is not allowed to contain the digit zero.  
> Given two integers `left` and `right`, return *a list of all the **self-dividing numbers** in the range `[left, right]`*.  

----------

#### I 迭代

按照自除数的定义对范围内的数字进行迭代判断即可  

```cpp
vector<int> selfDividingNumbers(int left, int right) 
{
    vector<int> ret;
    for(int i = left; i <= right; ++i)
    {
        int x = i;
        bool can = true;
        while(x)
        {
            int cur = x % 10;
            if(cur == 0 || i % cur != 0)
                can = false;
            x /= 10;
        }
        if(can)
            ret.emplace_back(i);
    }
    return ret;
}
```
