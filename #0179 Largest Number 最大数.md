### 最大数
### Largest Number

> 给定一组非负整数 `nums`，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数  
> 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。  

> Given a list of non-negative integers `nums`, arrange them such that they form the largest number and return it.  
> Since the result may be very large, so you need to return a string instead of an integer.  

----------

### I 排序

比较两个数字字符串组合后谁在前面比较大，可以直接比较两个字符串加起来的结果  
例如：`a = "30"` 和 `b= "3"`，比较时两者的和分别为 `a + b = "303"` 及 `b + a = "330"`，显然去后者，所以 `b` 在 `a` 的前面  
基于此对数组进行重新排序即可  

```cpp
string largestNumber(vector<int>& nums) 
{
    vector<string> s;
    for(auto& num : nums)
        s.push_back(to_string(num));
    sort(s.begin(), s.end(), [](string a, string b){return a + b > b + a;});
    string ret;
    for(auto& str : s)
        ret += str;
    return ret[0] == '0' ? "0" : ret;
}
```
