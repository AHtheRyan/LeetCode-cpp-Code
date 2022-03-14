### Nim 游戏
### Nim Game

> 你和你的朋友，两个人一起玩 Nim 游戏：  
> 1. 桌子上有一堆石头。  
> 2. 你们轮流进行自己的回合，你作为先手。  
> 3. 每一回合，轮到的人拿掉 1 - 3 块石头。  
> 4. 拿掉最后一块石头的人就是获胜者。  
> 
> 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 `n` 的情况下赢得游戏。如果可以赢，返回 `true`；否则，返回 `false`。  

> You are playing the following Nim Game with your friend:  
> 1. Initially, there is a heap of stones on the table.  
> 2. You and your friend will alternate taking turns, and you **go first**.  
> 3. On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.  
> 4. The one who removes the last stone is the winner.  
> 
> Given `n`, the number of stones in the heap, return `true` *if you can win the game assuming both you and your friend play optimally, otherwise return* `false`.  

----------

#### I 数学

由于每次都采取最优解，因此，我们按照石头的数目进行简单分析：  
1. 拿走即可，赢
2. 拿走两块，赢
3. 拿走三块，赢
4. 不管拿走1/2/3块，剩下的小于3，必然不是自己拿走，输
5. 拿走一块，对面剩4块，赢
6. 拿走两块，对面剩4块，赢
7. 拿走三块，对面剩4块，赢
8. 不管拿走几块，对面都可以剩4块，输  

以此类推可见，最后的结果都落在 `1/2/3/4` 四种可能中，且剩 `1/2/3` 块必胜，剩 `4` 块必输  
所以直接将石头数目除以 `4` 计算余数即可  

```cpp
bool canWinNim(int n) 
{
    return (n % 4 != 0);
}
```
