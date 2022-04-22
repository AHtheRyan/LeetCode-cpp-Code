### 森林中的兔子
### Rabbits in Forest

> 森林中有未知数量的兔子。提问其中若干只兔子 **"还有多少只兔子与你（指被提问的兔子）颜色相同?"**，将答案收集到一个整数数组 `answers` 中，其中 `answers[i]` 是第 `i` 只兔子的回答。  
> 给你数组 `answers`，返回森林中兔子的最少数量。  

> There is a forest with an unknown number of rabbits. We asked n rabbits **"How many rabbits have the same color as you?"** and collected the `answers` in an integer array answers where `answers[i]` is the answer of the `ith` rabbit.  
> Given the array `answers`, return *the minimum number of rabbits that could be in the forest*.  

----------

#### I 贪心

如果报出数字 `num` 的兔子数目 `n` 小于等于 `num` 本身，即 `n <= num`，说明最好情况是每只兔子都是同一个颜色，此时该种颜色最多的兔子数目为 `num + 1`  
但是，如果 `n > num`，即报出数字 `num` 的兔子数目超过了所报的数字，说明必然存在不一样颜色的兔子，由于要最少的兔子，我们这里采用贪心  
即每当一个颜色满了才考虑另一个颜色的兔子，按此规律进行计算即可  

```cpp
int numRabbits(vector<int>& answers) 
{
    unordered_map<int, int> cnt;
    int ret = 0;
    for(auto& num : answers)
    {
        if(num + 1 == cnt[num])
        {
            ret += num + 1;
            cnt[num] = 1;
        }
        else
            ++cnt[num];
    }
    for(auto& p : cnt)
        ret += p.first + 1;
    return ret;
}
```
