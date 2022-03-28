### 把数组排成最小的数

> 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。  

----------

#### I 排序

首先可以确定的是，如果要获得最小的数字，那一定是要把最高位小的数字尽量往前提  
因此，可以基于排序解决问题，其次，在面对例如 `3` 和 `32` 谁排在前面这样的问题时，可以利用字符串加法和比较，两个数字的组合可能为 `332` 和 `323`，显然 `323` 更小一些，  
因此，排序时将 `32` 排在前面，我们可以利用内置的 `sort` 和lambda表达式解决排序问题  

```cpp
string minNumber(vector<int>& nums) 
{
    string ret = "";
    vector<string> str;
    for(auto& num : nums)
        str.emplace_back(to_string(num));
    sort(str.begin(), str.end(), [&](string a, string b){return a + b < b + a;});
    for(auto& s : str)
        ret += s;
    return ret;
}
```
