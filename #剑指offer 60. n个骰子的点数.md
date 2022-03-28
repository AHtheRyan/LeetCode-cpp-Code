### n个骰子的点数

> 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。  
> 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。  

----------

#### I 动态规划

从只有一个骰子开始进行分析，可以看到，后续增加一个骰子，会对可能性的数目造成影响，  
并且，基于上一次的基础，每个骰子的增加会对当前数字可能性加上 `1~6` 的范围内的可能性造成影响  
可基于此构造动态规划方程  

```cpp
vector<double> dicesProbability(int n) 
{
    vector<double> ret(6, 1.0 / 6.0);
    for(int i = 2; i <= n; ++i)
    {
        vector<double> cur(5 * i + 1);
        for(int j = 0; j < ret.size(); ++j)
            for(int k = 0; k < 6; ++k)
                cur[j + k] += ret[j] / 6.0;
        ret = cur;
    }
    return ret;
}
```
