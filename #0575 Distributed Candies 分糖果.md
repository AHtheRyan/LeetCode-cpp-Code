### I 分糖果
### I Distributed Candies

> 给定一个**偶数**长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果**平均**分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。  

> Alice has `n` candies, where the `ith` candy is of type `candyType[i]`. Alice noticed that she started to gain weight, so she visited a doctor.  
> The doctor advised Alice to only eat `n / 2` of the candies she has (`n` is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.    
> Given the integer array `candyType` of length `n`, return *the **maximum** number of different types of candies she can eat if she only eats `n / 2` of them*.  

----------

#### I 贪心

假设共有 `x` 个糖果与 `y` 种糖果，则存在两种情况：
1. `x / 2 >= y`，则此时妹妹可获得 `y` 种糖果  
2. `x / 2 < y`，则此时妹妹可获得 `x / 2` 种糖果  

分别考虑两种情况，简单来说就是优先满足妹妹的糖果多样性，因此，只需要遍历求出糖果的种类总数和糖果总数即可  

```cpp
int distributeCandies(vector<int>& candyType) 
{
    set<int> st;
    int avg = candyType.size() / 2;
    int sis = 0;
    for(auto candy : candyType)
    {
        if(st.find(candy) == st.end())
        {
            st.insert(candy);
            ++sis;
        }
        if(sis == avg)
            break;
    }
    return sis;
}
```

#### II 贪心plus

基于上述贪心原理，利用列表，提升速度

```cpp
int distributeCandies(vector<int>& candyType) 
{
    bitset<200001> s;
    for(int x : candyType)
        if(!s[x + 100000])
            s.set(x + 100000);
    return min(candyType.size() / 2, s.count());
}
```
