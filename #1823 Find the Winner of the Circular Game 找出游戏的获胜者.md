### 找出游戏的获胜者
### Find the Winner of the Circular Game

> 共有 `n` 名小伙伴一起做游戏。小伙伴们围成一圈，按**顺时针顺序**从 `1` 到 `n` 编号。确切地说，从第 `i` 名小伙伴顺时针移动一位会到达第 `(i+1)` 名小伙伴的位置，其中 `1 <= i < n`，从第 `n` 名小伙伴顺时针移动一位会回到第 `1` 名小伙伴的位置。  
> 游戏遵循如下规则：  
> 1. 从第 `1` 名小伙伴所在位置 开始 。  
> 2. 沿着顺时针方向数 `k` 名小伙伴，计数时需要**包含**起始时的那位小伙伴。逐个绕圈进行计数，一些小伙伴可能会被数过不止一次。  
> 3. 你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。  
> 4. 如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的**顺时针下一位**小伙伴**开始**，回到步骤 `2` 继续执行。  
> 5. 否则，圈子中最后一名小伙伴赢得游戏。  
> 
> 给你参与游戏的小伙伴总数 `n`，和一个整数 `k`，返回游戏的获胜者。  

> There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.  
> The rules of the game are as follows:  
> 1. **Start** at the `1st` friend.  
> 2. Count the next `k` friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.  
> 3. The last friend you counted leaves the circle and loses the game.  
> 4. If there is still more than one friend in the circle, go back to step `2` **starting** from the friend **immediately clockwise** of the friend who just lost and repeat.  
> 5. Else, the last friend in the circle wins the game.  
> 
> Given the number of friends, `n`, and an integer `k`, return *the winner of the game*.  

----------

#### I 队列

利用队列先进后出的特性可以快速解决此题：  
依次将每个人加入队列，之后：  
1. 设置计数位 `count = 0`  
2. 依次将队列最前面的元素出队，并将 `count` 加一  
    - 如果 `count != k`，则将出队的元素加到队列的末尾  
    - 如果 `count == k`，则将 `count` 置为 `0`  
3. 当队列只剩一个元素，将该元素返回即可  

```cpp
int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    int count = 0;
    while (q.size() > 1)
    {
        ++count;
        if (count == k)
        {
            count = 0;
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return q.front();
}
```

#### II 数学

基于递推进行推导即可  

```cpp
int findTheWinner(int n, int k) 
{
    int ret = 1;
    for(int i = 2; i <= n; ++i)
        ret = (ret + k - 1) % i + 1;
    return ret;
}
```
