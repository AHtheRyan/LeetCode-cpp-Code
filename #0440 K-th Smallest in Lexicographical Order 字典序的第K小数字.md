### 字典序的第K小数字
### K-th Smallest in Lexicographical Order

> 给定整数 `n` 和 `k`，返回 `[1, n]` 中字典序第 `k` 小的数字。  

> Given two integers `n` and `k`, return the `kth` *lexicographically smallest integer in the range* `[1, n]`.  

----------

#### I 模拟构建树

可以按照树的结构对所有数字进行遍历  
每次比较 `n` 的大小与根节点的大小，如果根节点比较大，则说明可以继续进入子树搜索节点数目，否则返回总子树数目即可  
每次找到某一节点的子树极限后，可在同一层取其下一个节点进行上述比较，直到找到最后的数字  

```cpp
class Solution 
{
public:
    int findKthNumber(int n, int k) 
    {
        int cur = 1;
        --k;
        while(k > 0)
        {
            int childrenNum = findChildrenNum(cur, n);
            if(childrenNum <= k)
            {
                k -= childrenNum;
                ++cur;
            }
            else
            {
                cur *= 10;
                --k;
            }
        }
        return cur;
    }

    int findChildrenNum(int cur, long n)
    {
        int childrenNum = 0;
        long first = cur;
        long last = cur;
        while(n >= first)
        {
            childrenNum += min(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        return childrenNum;
    }
};
```
