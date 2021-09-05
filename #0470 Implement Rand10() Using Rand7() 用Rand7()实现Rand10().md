### 用Rand7()实现Rand10()
### Implement Rand10() Using Rand7()

> 已有方法 `rand7` 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 `rand10` 生成 1 到 10 范围内的均匀随机整数。  

> Given the **API** `rand7()` that generates a uniform random integer in the range `[1, 7]`, write a function `rand10()` that generates a uniform random integer in the range `[1, 10]`. You can only call the API `rand7()`, and you shouldn't call any other API. Please **do not** use a language's built-in random API.  
> Each test case will have one internal argument `n`, the number of times that your implemented function `rand10()` will be called while testing. Note that this is **not an argument** passed to `rand10()`.  

----------

#### I 取余法

将 `1~7` 转化为 `1~10` 的转化思路为概率转化，即原本为 **1/7** 的概率转化为 **1/10**，   
由于每次采样的结果都是 1\~7 中的数字，所以取十次想加，其结果必然为 1\*10\~7\*10 即 10\~70 之间的数字，  
分析可知，这些数字在末尾为 1/2/3/4/5/6/7/8/9/0 的概率分别为 1/10，  
所以直接对结果取余，以 **余数+1** 作为结果，其概率是相等的，此方法固定采用`Rand7()`的次数为10次  

```cpp
int rand10() 
{
    int sum = 0;
    for(int i = 0; i < 10; ++i)
        sum += rand7();
    return sum % 10 + 1;
}
```

#### II 独立事件概率相乘

根据上述方法可知，只要利用 `Rand7()` 制造出10个概率为 `1/10` 的事件即可  
考虑到如下情况：
1. 如果不取 7，那么 `Rand7()` 中的所有可能就是 1~6，奇数和偶数的可能性各为 **1/2**
2. 如果不取 6 和 7，那么 `Rand7()` 中所有可能就是 1~5，每个数字的可能性为 **1/5**
3. 如果奇数则只取 1~5，如果偶数则只取 6~10,（可以通过 1~5+5 获得），则每个数字概率都相等  

按此规律写出的算法对 `Rand7()` 的调用次数期望值为

```cpp
int rand10() 
{
    int a = rand7();
    while(a == 7)
        a = rand7();
    int cond = a % 2;
    int b = rand7();
    while(b > 5)
        b = rand7();
    return b + cond * 5;
}
```
