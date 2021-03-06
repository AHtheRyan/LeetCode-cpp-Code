### 不含连续1的非负整数
### Non-negative Integers without Consecutive Ones

> 给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 **连续的1** 的个数。  

> Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations **do not** contain consecutive ones.  

----------

#### I 动态规划 + 二进制树构建

因为题目的要求是二进制树，我们不妨把所有的数字都转化成二进制来看一看有什么规律：  
1位：`0`    `1`  
2位：`10`   `11`  
3位：`100`  `101`  `110`  `111`  
4位：`1000` `1001` `1010` `1011` `1100` `1101` `1110` `1111`  
以此类推  
换种格式可以将上面的塔转化为：  

| 位数 | 结果 | 结果 | 结果 | 结果 | 结果 | 结果 | 结果 | 结果 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1位 | 0000 | 0001 | 0000 | 0001 | 0000 | 0001 | 0000 | 0001 |
| 2位 | 0010 | 0011 | 0010 | 0011 | 0010 | 0011 | 0010 | 0011 |
| 3位 | 0100 | 0101 | 0110 | 0111 | 0100 | 0101 | 0110 | 0111 |
| 4位 | 1000 | 1001 | 1010 | 1011 | 1100 | 1101 | 1110 | 1111 |

从中我们发现，在考虑第 `n` 位的时候，第 `1` 到第 `n - 1` 位的情况也需要一并考虑进去，  
这样的操作会重复出现，因此，为了避免重复操作，我们可以采用动态规划的方式，来记录每次已经考虑过的结果  
更直观地，我们将此结果以树的形式表示出来：  
![1631539050(1)](https://user-images.githubusercontent.com/46887748/133090487-05a8a7bc-bb27-4c08-803c-0895cea2a697.png)  
**注意**：树的根部加上了 `0` 不影响数字的大小，但可以通过这种方式使得所有的数字都在一个树中表示出来  
很容易看到：  
1. 对于任意一个作为根的 `0` 节点，其左子树的左右子树都可以作为是否满足题目条件的判断  
2. 右子树由于值为 `1`，所以其右子树的右子树必然出现了连续的 `1`，不能作为判断条件  
3. 总结来说，就是任意根节点 `0`，其可以探索的有效路径的数目为左子树可以探索的有效路径数目和右子树的左子树的有效路径数目  

根据这个关系，我们可以设置当前的根为 `0` 的树的可探索路径数目为动态规划状态变量 `dp`，且`dp[i] = dp[i - 1] + dp[i - 2]`  
`dp[i]` 与 `dp[i - 1]` 和 `dp[i - 2]` 的关系如下图：  
![1631539659(1)](https://user-images.githubusercontent.com/46887748/133092034-8b64d64d-cf12-4ab1-bd73-28638145605f.png)  
其中，红色为 `dp[i]`，绿色为 `dp[i - 1]`，黄色为 `dp[i - 2]`  
初始条件为 `dp[0] = dp[1] = 1`，即高度为 `0` 或高度为 `1` 的数的可探索路径都为 `1`  
由于最大的数字为 `10^9`，该值小于 `2^30`，因此，我们的动态规划表只计算到树高度为 `30` 的情况  

接下来讨论针对具体的数字中的 `1` 的数目求法：  
首先设置变量 `pre` 和 `res`，分别记录当前数位前一位的数字和已经得到的 `1` 的数目总和，  
利用位运算 `&` 可以试出每一位上的数字是 `0` 还是 `1`，为了包括所有的路径，我们从最高位开始试，  
如果该位置为 `1`，那么，显然，可以探索的总路径数目一定包含比它小的所有数字，可以将其分为两类：  
1. 将该位置从 `1` 改成 `0` 后的数字，即上图中 `1` 节点的父节点的左子树中的所有数字，他们都比当前的节点取 `1` 之后的数字小,接下来考虑当前节点的父节点的值 `pre`:  
   - 如果其为 `1`，说明当前节点没有讨论的必要，因为必然包含连续的 `1`，路径都不可探索  
   - 如果其为 `0`，说明后面还可以讨论当前节点的子节点，路径都可探索，但探索前需要将 `pre` 标记设置为当前节点的值 `1`  
2. 该位置的左子节点所包含的数字能否满足需要进一步讨论，即可能比所要求的数字大也可能比其小  

如果该位置为 `0`，那么此时后面的值能否大于 `n` 是未知的，因此将 `pre` 设为 `0` 之后可以直接继续进行判断  
最后，如果比较到了根部的 `1`，则直接将结果加1，因为 `1` 必然满足条件  
将所有可探索的路径返回，即为结果  

```cpp
int findIntegers(int n) 
{
    vector<int> dp(31);
    dp[0] = dp[1] = 1;
    for(int i = 2; i < 31; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    int pre = 0, res = 0;
    for(int i = 29; i >= 0; --i) 
    {
        int val = 1 << i;
        if((n & val) != 0) 
        {
            res += dp[i + 1];
            if (pre == 1)
                break;
            pre = 1;
        } 
        else
            pre = 0;
        if(i == 0)
            ++res;
    }
    return res;
}
```
