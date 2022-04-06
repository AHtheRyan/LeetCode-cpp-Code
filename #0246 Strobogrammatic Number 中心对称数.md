### 中心对称数
### Strobogrammatic Number

> 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。  
> 请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。  

> Given a string `num` which represents an integer, return *`true` if `num` is a **strobogrammatic number***.  
> A **strobogrammatic number** is a number that looks the same when rotated `180` degrees (looked at upside down).  

----------

#### I 哈希表

可单独为中心对称的数字为 `0``1``8`，可成对为中心对称的数字为 `6` 和 `9`，利用哈希表进行记录并按位判断即可  

```cpp
class Solution 
{
private:
    unordered_map<char, char> pair
    {
        {'8', '8'}, {'6', '9'}, {'9', '6'}, {'1', '1'}, {'0', '0'}
    };

public:
    bool isStrobogrammatic(string num) 
    {
        int n = num.size();
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            if(pair.count(num[left] == 0))
                return false;
            else if(pair[num[left]] != num[right])
                return false;
            ++left;
            --right;
        }
        if(left == right)
            return num[left] == '8' || num[left] == '1' || num[left] == '0';
        return true;
    }
};
```
