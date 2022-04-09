### 复原IP地址
### Restore IP Address

> **有效 IP 地址**正好由四个整数（每个整数位于 `0` 到 `255` 之间组成，且不能含有前导 `0`），整数之间用 `'.'` 分隔。  
> - 例如：`"0.1.2.201"` 和 `"192.168.1.1"` 是**有效** IP 地址，但是 `"0.011.255.245"`、`"192.168.1.312"` 和 `"192.168@1.1"` 是**无效** IP 地址。  
> 
> 给定一个只包含数字的字符串 `s`，用以表示一个 IP 地址，返回所有可能的**有效 IP 地址**，这些地址可以通过在 `s` 中插入 `'.'` 来形成。你**不能**重新排序或删除 `s` 中的任何数字。  

> A **valid IP address** consists of exactly four integers separated by single dots. Each integer is between `0` and `255` (**inclusive**) and cannot have leading zeros.  
> - For example, `"0.1.2.201"` and `"192.168.1.1"` are **valid** IP addresses, but `"0.011.255.245"`, `"192.168.1.312"` and `"192.168@1.1"` are **invalid** IP addresses.  
> 
> Given a string `s` containing only digits, return *all possible valid IP addresses that can be formed by inserting dots into `s`*. You are **not** allowed to reorder or remove any digits in `s`.  

----------

#### I 回溯

显然此题可以利用回溯法进行判断，设计回溯函数，我们以 `'.'` 为分界线，即每次重新进行递归之前都在当前的字符串 `cur` 末尾加上一个 `'.'`：  
- 如果当前数字为 `0`，则此数字只能单独存在，直接在 `cur` 末尾加上 `"0."` 即可  
- 如果当前数字不为 `0`，则进入循环，只要取得值小于 `255`，就可以进行一次递归尝试  
- 如果已经划分了四个区域或字符串已经遍历完毕，则可以进行对递归过程进行收尾  

```cpp
class Solution 
{
private:
    vector<string> ret;
    string cur = "";
    int n;

public:
    vector<string> restoreIpAddresses(string s) 
    {
        this->n = s.size();
        if(n > 12 || n < 4)
            return {};
        backtrack(s, 0, 0);
        return ret;
    }

    void backtrack(string& s, int index, int pointCnt)
    {
        if(index >= n)
            return ;
        if(pointCnt == 3)
        {
            if(s[index] == '0' && index != n - 1)
                return ;
            int num = 0;
            for(int i = index; i < n; ++i)
            {
                num = num * 10 + (s[i] - '0');
                if(num > 255)
                    return ;
            }
            cur += to_string(num);
            ret.emplace_back(cur);
            return ;
        }
        if(s[index] == '0')
        {
            cur += "0.";
            backtrack(s, index + 1, pointCnt + 1);
            return ;
        }
        int num = 0;
        string tmp = cur;
        for(int i = index; i < index + 3; ++i)
        {
            num = num * 10 + (s[i] - '0');
            if(num <= 255)
            {
                cur += to_string(num);
                cur += '.';
                backtrack(s, i + 1, pointCnt + 1);
                cur = tmp;
            }
        }
    }
};
```
