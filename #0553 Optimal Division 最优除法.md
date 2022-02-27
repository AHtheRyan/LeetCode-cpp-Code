### 最优除法
### Optimal Division

> 给定一组**正整数**，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4。  
> 但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到**最大的**结果，并且返回相应的字符串格式的表达式。**你的表达式不应该含有冗余的括号**。  

> You are given an integer array `nums`. The adjacent integers in `nums` will perform the float division.  
> - For example, for `nums = [2,3,4]`, we will evaluate the expression `"2/3/4"`.  
> 
> However, you can add any number of parenthesis at any position to change the priority of operations. You want to add these parentheses such the value of the expression after the evaluation is maximum.  
> Return *the corresponding expression that has the maximum value in string format*.  
> **Note**: your expression should not contain redundant parenthesis.  

----------

#### I 动态规划

显然，可以设置一个动态规划数组 `dp[i][j]` 表示从下标 `i` 到下标 `j` 的最大商  
但是这里有两个问题：
1. 如果要最大商，显然要**大数 / 小数**，换句话说，如果都是最大商，则无法进行动态规划的递进运算  
2. 需要返回的是字符串，即使找到最大值也没用  

因此，需要对动态规划数组进行扩充处理，分为两部分：
1. 记录最大商和最小商，以便进行除法运算和比较  
2. 记录最大商的字符串和最小商的字符串，以便于字符串操作和直接返回  

因此，需要将 `dp` 数组扩充为一个包含两个 `double` 和两个 `string` 结构的新数据结构  
利用 `struct` 进行构造  
接下来按照动态规划的顺序从长度为 `1` 开始递归即可  

```cpp
struct Node
{
    double maxVal;
    double minVal;
    string maxStr;
    string minStr;
    Node()
    {
        this->maxVal = 0.0;
        this->minVal = 10000.0;
    }
};

class Solution 
{
public:
    string optimalDivision(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<Node>> dp(n, vector<Node>(n));
        for(int i = 0; i < n; ++i)
        {
            dp[i][i].minVal = nums[i];
            dp[i][i].maxVal = nums[i];
            dp[i][i].minStr = to_string(nums[i]);
            dp[i][i].maxStr = to_string(nums[i]);
        }
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j + i < n; ++j)
            {
                for(int k = j; k < j + i; ++k)
                {
                    if(dp[j][j + i].minVal > dp[j][k].minVal / dp[k + 1][j + i].maxVal)
                    {
                        dp[j][j + i].minVal = dp[j][k].minVal / dp[k + 1][j + i].maxVal;
                        if(k + 1 == j + i)
                            dp[j][j + i].minStr = dp[j][k].minStr + '/' + dp[k + 1][j + i].maxStr;
                        else
                            dp[j][j + i].minStr = dp[j][k].minStr + "/(" + dp[k + 1][j + i].maxStr + ')';
                    }
                    if(dp[j][j + i].maxVal < dp[j][k].maxVal / dp[k + 1][j + i].minVal)
                    {
                        dp[j][j + i].maxVal = dp[j][k].maxVal / dp[k + 1][j + i].minVal;
                        if(k + 1 == j + i)
                            dp[j][j + i].maxStr = dp[j][k].maxStr + '/' + dp[k + 1][j + i].minStr;
                        else
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/(" + dp[k + 1][j + i].minStr + ')';
                    }
                }
            }
        }
        return dp[0][n - 1].maxStr;
    }
};
```

#### II 数学

如果所有数字都大于 `1`，则说明连续相除的结果是最小的  
可以直接在第二个数字到最后一个数字之间套上括号  

```cpp
string optimalDivision(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 1)
        return to_string(nums[0]);
    if(n == 2)
        return to_string(nums[0]) + '/' + to_string(nums[1]);
    string ret = to_string(nums[0]) + '/';
    ret += '(';
    for(int i = 1; i < n; ++i)
        ret += to_string(nums[i]) + '/';
    ret.pop_back();
    ret += ')';
    return ret;
}
```
