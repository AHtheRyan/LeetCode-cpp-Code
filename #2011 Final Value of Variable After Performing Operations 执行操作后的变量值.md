### 执行操作后的变量值
### Final Value of Variable After Performing Operations

> 存在一种仅支持 4 种操作和 1 个变量 `X` 的编程语言：  
> - `++X` 和 `X++` 使变量 `X` 的值 **加 `1`**  
> - `--X` 和 `X--` 使变量 `X` 的值 **减 `1`**    
>
> 最初，`X` 的值是 `0`  
> 给你一个字符串数组 `operations`，这是由操作组成的一个列表，返回执行所有操作后，`X`的**最终值**。  

> There is a programming language with only **four** operations and one variable `X`:  
> - `++X` and `X++` **increments** the value of the variable `X` by `1`.  
> - `--X` and `X--` **decrements** the value of the variable `X` by `1`.  
>  
>  Initially, the value of `X` is `0`.  
>  Given an array of strings operations containing a list of `operations`, return *the **final** value of `X` after performing all the operations*.  

----------

#### I 模拟

由于每次操作都为 `*-*` 或者 `*+*`，因此，中间的操作符号是固定的，  
因此，基于中间的字符判断每次的加建情况即可  

```cpp
int finalValueAfterOperations(vector<string>& operations) 
{
    int ret = 0;
    for(auto op : operations)
        ret += op[1] == '-' ? -1 : 1;
    return ret;
}
```
