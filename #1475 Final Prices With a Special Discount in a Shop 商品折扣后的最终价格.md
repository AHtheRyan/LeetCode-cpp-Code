### 商品折扣后的最终价格
### Final Prices With a Special Discount in a Shop

> 给你一个数组 `prices`，其中 `prices[i]` 是商店里第 `i` 件商品的价格。  
> 商店里正在进行促销活动，如果你要买第 `i` 件商品，那么你可以得到与 `prices[j]` 相等的折扣，其中 `j` 是满足 `j > i` 且 `prices[j] <= prices[i]` 的**最小下标**，如果没有满足条件的 `j` ，你将没有任何折扣。  
> 请你返回一个数组，数组中第 `i` 个元素是折扣后你购买商品 `i` 最终需要支付的价格。  

> Given the array `prices` where `prices[i]` is the price of the `ith` item in a shop. There is a special discount for items in the shop, if you buy the `ith` item, then you will receive a discount equivalent to `prices[j]` where `j` is the **minimum** index such that `j > i` and `prices[j] <= prices[i]`, otherwise, you will not receive any discount at all.  
> *Return an array where the `ith` element is the final price you will pay for the `ith` item of the shop considering the special discount*.  

----------

#### I 单调栈

倒序遍历数组，构建一个单调递增的栈，即可记录从左往右依次最小的数字，然后逐个比较即可  

```cpp
vector<int> finalPrices(vector<int>& prices) 
{
    int n = prices.size();
    vector<int> ret(n);
    stack<int> stk;
    for(int i = n - 1; i >= 0; --i)
    {
        while(!stk.empty() && prices[i] < stk.top())
            stk.pop();
        if(stk.empty())
            ret[i] = prices[i];
        else
            ret[i] = prices[i] - stk.top();
        stk.push(prices[i]);
    }
    return ret;
}
```
