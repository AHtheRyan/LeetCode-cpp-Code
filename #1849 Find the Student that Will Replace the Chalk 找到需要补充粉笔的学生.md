### 找到需要补充粉笔的学生
### Find the Student that Will Replace the Chalk

> 一个班级里有 `n` 个学生，编号为 `0` 到 `n - 1` 。每个学生会依次回答问题，编号为 `0` 的学生先回答，然后是编号为 `1` 的学生，以此类推，直到编号为 `n - 1` 的学生，然后老师会重复这个过程，重新从编号为 `0` 的学生开始回答问题。  
> 给你一个长度为 `n` 且下标从 `0` 开始的整数数组 `chalk` 和一个整数 `k` 。一开始粉笔盒里总共有 `k` 支粉笔。当编号为 `i` 的学生回答问题时，他会消耗 `chalk[i]` 支粉笔。如果剩余粉笔数量 **严格小于** `chalk[i]` ，那么学生 `i` 需要 **补充** 粉笔。  
> 请你返回需要 **补充** 粉笔的学生 **编号** 。  

> There are `n` students in a class numbered from `0` to `n - 1`. The teacher will give each student a problem starting with the student number `0`, then the student number `1`, and so on until the teacher reaches the student number `n - 1`. After that, the teacher will restart the process, starting with the student number `0` again.  
> You are given a **0-indexed** integer array `chalk` and an integer `k`. There are initially `k` pieces of chalk. When the student number `i` is given a problem to solve, they will use `chalk[i]` pieces of chalk to solve that problem. However, if the current number of chalk pieces is **strictly less** than `chalk[i]`, then the student number `i` will be asked to **replace** the chalk.  
> Return the **index** of the student that will **replace** the chalk.  

----------

#### I 除k取余法

简单的进制转换题  
分析可知，学生每一轮会用掉 `chalk` 数组之和个数量的粉笔，  
换句话说，只需要考虑最后一轮开始还剩多少个粉笔就可以，因此可以直接用 **总粉笔数 % 每轮消耗的粉笔数** 得到最后一轮剩下的粉笔，  
之后遍历数组递减，直到粉笔数不满足某个学生的需求即可  

```cpp
int chalkReplacer(vector<int>& chalk, int k) 
{
    int size = chalk.size();
    long long int sum = accumulate(chalk.begin(), chalk.end(), 0LL);
    int left = k % sum;
    for(int i = 0; i < size; ++i)
    {
        if(left < chalk[i])
            return i;
        left -= chalk[i];
    }
    return -1;
}
```

#### II 前缀和 + 二分查找

本方法本质上还是除k取余法  
首先求出 `chalk` 数组的前缀和，得到新的 `chalk` 数组，  
这样，就可以直接利用二分查找得出粉笔总量的下标位置  

```cpp
int chalkReplacer(vector<int>& chalk, int k) 
{
    if(chalk[0] > k)
        return 0;
    int size = chalk.size();
    for(int i = 1; i < size; ++i)
    {
        chalk[i] += chalk[i - 1];
        if(chalk[i] > k)
            return i;
    }    
    int left = k % chalk[size - 1];
    return upper_bound(chalk.begin(), chalk.end(), left) - chalk.begin();
}
```
