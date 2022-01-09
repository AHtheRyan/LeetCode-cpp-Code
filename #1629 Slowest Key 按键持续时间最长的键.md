### 按键持续时间最长的键
### Slowest Key

> LeetCode 设计了一款新式键盘，正在测试其可用性。测试人员将会点击一系列键（总计 `n` 个），每次一个。  
> 给你一个长度为 `n` 的字符串 `keysPressed`，其中 `keysPressed[i]` 表示测试序列中第 `i` 个被按下的键。`releaseTimes` 是一个升序排列的列表，其中 `releaseTimes[i]` 表示松开第 `i` 个键的时间。字符串和数组的**下标**都从 **0** 开始 。第 `0` 个键在时间为 `0` 时被按下，接下来每个键都**恰好**在前一个键松开时被按下。  
> 测试人员想要找出按键**持续时间最长**的键。第 `i` 次按键的持续时间为 `releaseTimes[i] - releaseTimes[i - 1]`，第 `0` 次按键的持续时间为 `releaseTimes[0]`。  
> 注意，测试期间，同一个键可以在不同时刻被多次按下，而每次的持续时间都可能不同。  
> 请返回按键 **持续时间最长** 的键，如果有多个这样的键，则返回 **按字母顺序排列最大** 的那个键。  

> A newly designed keypad was tested, where a tester pressed a sequence of `n` keys, one at a time.  
> You are given a string `keysPressed` of length `n`, where `keysPressed[i]` was the `ith` key pressed in the testing sequence, and a sorted list `releaseTimes`, where `releaseTimes[i]` was the time the `ith` key was released. Both arrays are **0-indexed**. The `0th` key was pressed at the time `0`, and every subsequent key was pressed at the **exact** time the previous key was released.  
> The tester wants to know the key of the keypress that had the **longest duration**. The `ith` keypress had a **duration** of `releaseTimes[i] - releaseTimes[i - 1]`, and the `0th` keypress had a duration of `releaseTimes[0]`.  
> Note that the same key could have been pressed multiple times during the test, and these multiple presses of the same key **may not** have had the same **duration**.  
> *Return the key of the keypress that had the **longest duration**. If there are multiple such keypresses, return the lexicographically largest key of the keypresses.*  

----------

#### I 直接遍历

按顺序遍历每个按键的按键市场，并将最长时间的按键记录更新即可  

```cpp
char slowestKey(vector<int>& releaseTimes, string keysPressed) 
{
  char curLongest = keysPressed[0];
  int former = 0;
  int curmax = 0;
  for(int i = 0; i < releaseTimes.size(); ++i)
  {
      int cur = releaseTimes[i] - former;
      former = releaseTimes[i];
      if(cur > curmax)
      {
          curmax = cur;
          curLongest = keysPressed[i];
      }
      else if(cur == curmax && keysPressed[i] > curLongest)
          curLongest = keysPressed[i];
  }
  return curLongest;
}
```
