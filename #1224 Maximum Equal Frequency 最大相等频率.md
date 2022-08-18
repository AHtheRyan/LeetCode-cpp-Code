### 最大相等频率
### Maximum Equal Frequency

> 给你一个正整数数组 `nums`，请你帮忙从该数组中找出能满足下面要求的**最长**前缀，并返回该前缀的长度：  
> - 从前缀中**恰好删除一个**元素后，剩下每个数字的出现次数都相同。  
> 
> 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。  

> Given an array `nums` of positive integers, return the longest possible length of an array prefix of `nums`, such that it is possible to remove **exactly one** element from this prefix so that every number that has appeared in it will have the same number of occurrences.  
> If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).  

----------

#### I 哈希表 + 分类讨论

遍历数组，基于前缀符合条件原理进行判断，可以分类如下：  
- 如果每个数字都只出现一次，则任意删除一个数字都符合，可以直接返回  
- 如果只有一个数字出现一次，则只需要其他数字出现的次数相同，此时删除那个出现了一次的数字即可满足每个数字出现的次数相同  
- 如果每个数字出现的次数相同，只有一个数字多出现一次，此时删除那个多出现的数字即可满足每个数字出现的次数相同  

按照此分类可知，我们需要知道每个数字出现的次数和每种次数出现的次数  
利用哈希表记录上述两个变量，进行分类讨论即可  

```cpp
int maxEqualFreq(vector<int>& nums) 
{
    int n = nums.size();
    int ret = 0;
    int maxFreq = 0;
    unordered_map<int, int> numCnt, freqCnt;
    for(int i = 0; i < n; ++i)
    {
        int cur = nums[i];
        ++numCnt[cur];
        maxFreq = max(maxFreq, numCnt[cur]);
        ++freqCnt[numCnt[cur]];
        if(numCnt[cur] != 1)
            --freqCnt[numCnt[cur] - 1];
        //所有数字都出现一次，直接满足条件
        if(maxFreq == 1)
            ret = i + 1;
        //只有一个数字出现一次，其他所有数字出现次数相同
        else if(freqCnt[maxFreq] * maxFreq == i && freqCnt[1] == 1)
            ret = i + 1;
        //只有一个数字出现多一次，其他所有数字出现次数相同
        else if(freqCnt[maxFreq] == 1 && freqCnt[maxFreq - 1] * (maxFreq - 1) + maxFreq == i + 1)
            ret = i + 1;
    }
    return ret;
}
```
