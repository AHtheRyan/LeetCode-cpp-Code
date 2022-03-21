### 排列序列
### Permutation Sequence

> 给出集合 `[1,2,3,...,n]`，其所有元素共有 `n!` 种排列。  
> 按大小顺序列出所有排列情况，并一一标记，当 `n = 3` 时, 所有排列如下：  
> 1. `"123"`  
> 2. `"132"`  
> 3. `"213"`  
> 4. `"231"`  
> 5. `"312"`  
> 6. `"321"`  
> 
> 给定 `n` 和 `k`，返回第 `k` 个排列。  

> The set `[1, 2, 3, ..., n]` contains a total of `n!` unique permutations.  
> By listing and labeling all of the permutations in order, we get the following sequence for `n = 3`:  
> 1. `"123"`  
> 2. `"132"`  
> 3. `"213"`  
> 4. `"231"`  
> 5. `"312"`  
> 6. `"321"`  
> 
> Given `n` and `k`, return the `kth` permutation sequence.  

----------

#### I 数学

对于从右往左数第 `i` 位的数字，其后面的 `i - 1` 个数字共有 `(i - 1)!` 种，因此，相当于每 `(i - 1)!` 次循环后第 `i` 位数字就加一  
这里我们可以直接利用此性质循环确定每一位的数字  
例如，对于数字 `1234` 的第 `9` 个排列  
当第一位是 `1` 时，后面的 `234` 共三个数字，可能有 `3! = 6` 种排列，因此第九个排列时，第一位数字已经变成了 `2`，我们可以由此确定排列数字为 `2XXX`  
此外，由于已经过去了 `9 / 6 * 6 = 6` 个序列，剩下应该求 `134` 的第 `9 % 6 = 3` 个排列  
这就可以按照之前一样的顺序确定每个数字  

```cpp
string getPermutation(int n, int k) 
{
    vector<int> facNum(n + 1, 1);
    for(int i = 1; i <= n; ++i)
        facNum[i] = facNum[i - 1] * i;
    string ret;
    vector<int> used(n + 1, 1);
    --k;
    for(int i = 1; i <= n; ++i)
    {
        int cur = k / facNum[n - i] + 1;
       for(int j = 1; j <= n; ++j)
       {
           cur -= used[j];
           if(!cur)
           {
               ret += (j + '0');
               used[j] = 0;
               break;
           }
       }
        k %= facNum[n - i];
    }
    return ret;
}
```
