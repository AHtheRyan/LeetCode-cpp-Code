### 给植物浇水II
### Watering Plants II

> Alice 和 Bob 打算给花园里的 `n` 株植物浇水。植物排成一行，从左到右进行标记，编号从 `0` 到 `n - 1`。其中，第 `i` 株植物的位置是 `x = i`。  
> 每一株植物都需要浇特定量的水。Alice 和 Bob 每人有一个水罐，**最初是满的**。他们按下面描述的方式完成浇水：  
> - Alice 按**从左到右**的顺序给植物浇水，从植物 `0` 开始。Bob 按**从右到左**的顺序给植物浇水，从植物 `n - 1` 开始。他们**同时**给植物浇水。  
> - 如果没有足够的水 完全 浇灌下一株植物，他 / 她会立即重新灌满浇水罐。  
> - 不管植物需要多少水，浇水所耗费的时间都是一样的。  
> - **不能**提前重新灌满水罐。  
> - 每株植物都可以由 Alice 或者 Bob 来浇水。  
> - 如果 Alice 和 Bob 到达同一株植物，那么当前水罐中水更多的人会给这株植物浇水。如果他俩水量相同，那么 Alice 会给这株植物浇水。  
> 
> 给你一个下标从 **0** 开始的整数数组 `plants`，数组由 `n` 个整数组成。其中，`plants[i]` 为第 `i` 株植物需要的水量。另有两个整数 `capacityA` 和 `capacityB` 分别表示 Alice 和 Bob 水罐的容量。返回两人浇灌所有植物过程中重新灌满水罐的**次数**。  

> Alice and Bob want to water `n` plants in their garden. The plants are arranged in a row and are labeled from `0` to `n - 1` from left to right where the `ith` plant is located at `x = i`.  
> Each plant needs a specific amount of water. Alice and Bob have a watering can each, **initially full**. They water the plants in the following way:  
> - Alice waters the plants in order from **left to right**, starting from the `0th` plant. Bob waters the plants in order from **right to left**, starting from the `(n - 1)th` plant. They begin watering the plants **simultaneously**.  
> - It takes the same amount of time to water each plant regardless of how much water it needs.  
> - Alice/Bob **must** water the plant if they have enough in their can to **fully** water it. Otherwise, they **first** refill their can (instantaneously) then water the plant.  
> - In case both Alice and Bob reach the same plant, the one with **more** water currently in his/her watering can should water this plant. If they have the same amount of water, then Alice should water this plant.  
> 
> Given a **0-indexed** integer array `plants` of `n` integers, where `plants[i]` is the amount of water the `ith` plant needs, and two integers `capacityA` and `capacityB` representing the capacities of Alice's and Bob's watering cans respectively, return *the **number of times** they have to refill to water all the plants*.  

----------

#### I 双指针模拟

基于 Bob 和 Alice 的行动规则进行模拟即可  

```cpp
int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
{
    int n = plants.size();
    int pos_A = 0;
    int pos_B = n - 1;
    int cnt = 0;
    int load_A = capacityA;
    int load_B = capacityB;
    while(pos_A < pos_B)
    {
        if(plants[pos_A] > load_A)
        {
            ++cnt;
            load_A = capacityA - plants[pos_A];
        }
        else
            load_A -= plants[pos_A];
        if(plants[pos_B] > load_B)
        {
            ++cnt;
            load_B = capacityB - plants[pos_B];
        }
        else
            load_B -= plants[pos_B];
        ++pos_A;
        --pos_B;
    }
    if(pos_A == pos_B)
    {
        if(load_A == load_B && load_A < plants[pos_A])
            ++cnt;
        if(load_A != load_B)
            cnt = max(load_A, load_B) >= plants[pos_A] ? cnt : cnt + 1;
    }
    return cnt;
}
```
