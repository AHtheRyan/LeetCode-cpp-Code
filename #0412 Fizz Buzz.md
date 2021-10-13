### Fizz Buzz

> 写一个程序，输出从 1 到 n 数字的字符串表示。  
> 1. 如果 n 是3的倍数，输出“Fizz”；  
> 2. 如果 n 是5的倍数，输出“Buzz”；
> 3. 如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

> Given an integer `n`, return *a string array `answer` **(1-indexed)** where*:  
> - `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.  
> - `answer[i] == "Fizz"` if `i` is divisible by `3`.  
> - `answer[i] == "Buzz"` if `i` is divisible by `5`.  
> - `answer[i] == i` if non of the above conditions are true.  

----------

#### I 简单模拟

根据题意简单模拟即可

```cpp
vector<string> fizzBuzz(int n) 
{
    vector<string> ret;
    for(int i = 1; i <= n; ++i)
    {
        if(i % 3 == 0 && i % 5 == 0)
            ret.push_back("FizzBuzz");
        else if(i % 3 == 0)
            ret.push_back("Fizz");
        else if(i % 5 == 0)
            ret.push_back("Buzz");
        else
            ret.push_back(to_string(i));
    }
    return ret;
}
```
