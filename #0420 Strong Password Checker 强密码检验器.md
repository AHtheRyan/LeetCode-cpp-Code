### 强密码检验器
### Strong Password Checker

> 如果一个密码满足下述所有条件，则认为这个密码是强密码：  
> - 由至少 `6` 个，至多 `20` 个字符组成。  
> - 至少包含**一个小写**字母，**一个大写**字母，和**一个数字**。  
> - 同一字符**不能**连续出现三次 (比如 `"...aaa..."` 是不允许的, 但是 `"...aa...a..."` 如果满足其他条件也可以算是强密码)。  
> 
> 给你一个字符串 `password`，返回*将 `password` 修改到满足强密码条件需要的最少修改步数。如果 `password` 已经是强密码，则返回 `0`*。  
> 在一步修改操作中，你可以：  
> - 插入一个字符到 `password`，  
> - 从 `password` 中删除一个字符，或  
> - 用另一个字符来替换 `password` 中的某个字符。  

> A password is considered strong if the below conditions are all met:  
> - It has at least `6` characters and at most `20` characters.  
> - It contains at least **one lowercase** letter, at least **one uppercase** letter, and at least **one digit**.  
> - It does not contain three repeating characters in a row (i.e., `"...aaa..."` is weak, but `"...aa...a..."` is strong, assuming other conditions are met).  
> 
> Given a string `password`, return *the minimum number of steps required to make `password` strong. if `password` is already strong, return `0`*.  
> In one step, you can:  
> - Insert one character to `password`,  
> - Delete one character from `password`, or  
> - Replace one character of `password` with another character.  

----------

#### I 模拟

对密码字符串长度 **小于6**、**大于20**或者**介于两者之间**三种情况进行分类讨论即可  
具体可见[力扣题解](https://leetcode-cn.com/problems/strong-password-checker/solution/qiang-mi-ma-jian-yan-qi-by-leetcode-solu-4fqx/)

```cpp
int strongPasswordChecker(string password) 
{
    int n = password.size();
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    for(auto& c : password)
    {
        if(isupper(c))
            hasUpper = true;
        if(islower(c))
            hasLower = true;
        if(isdigit(c))
            hasDigit = true;
    }
    int category = hasLower + hasDigit + hasUpper;
    if(n < 6)
        return max(6 - n, 3 - category);
    else if(n <= 20)
    {
        int cnt = 0;
        int ret = 0;
        char c = '#';
        for(auto& cur : password)
        {
            if(cur == c)
                ++cnt;
            else
            {
                ret += cnt / 3;
                cnt = 1;
                c = cur;
            }
        }
        ret += cnt / 3;
        return max(ret, 3 - category);
    }
    else
    {
        int replace = 0;
        int remove = n - 20;
        int remove2 = 0;
        int cnt = 0;
        char c = '#';
        for(auto& cur : password)
        {
            if(cur == c)
                ++cnt;
            else
            {
                if(remove > 0 && cnt >= 3) 
                {
                    if(cnt % 3 == 0) 
                    {
                        --remove;
                        --replace;
                    }
                    else if(cnt % 3 == 1)
                        ++remove2;
                }
                replace += cnt / 3;
                cnt = 1;
                c = cur;
            }
        }
        if(remove > 0 && cnt >= 3) 
        {
            if (cnt % 3 == 0) 
            {
                --remove;
                --replace;
            }
            else if(cnt % 3 == 1)
                ++remove2;
        }
        replace += cnt / 3;
        int use2 = min({replace, remove2, remove / 2});
        replace -= use2;
        remove -= use2 * 2;
        int use3 = min({replace, remove / 3});
        replace -= use3;
        remove -= use3 * 3;
        return (n - 20) + max(replace, 3 - category);
    }
}
```
