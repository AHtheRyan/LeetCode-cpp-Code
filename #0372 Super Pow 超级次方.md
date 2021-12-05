### 超级次方
### Super Pow

> 你的任务是计算 `a^b` 对 `1337` 取模，`a` 是一个正整数，`b` 是一个非常大的正整数且会以数组形式给出。  

> Your task is to calculate `a^b` mod `1337` where `a` is a positive integer and `b` is an extremely large positive integer given in the form of an array.

----------

#### I 快速幂

简单来说，从低位到高位，依次利用快速幂进行求解并最终求积就可以了

```cpp
class Solution 
{
public:
    static constexpr int mod = 1337;

    int apow(int x, int n)
    {
        int ret = 1;
        while(n)
        {
            if(n % 2)
                ret = (ret * (x % mod)) % mod;
            x = (x % mod) * (x % mod) % mod;
            n /= 2;
        }
        return ret;
    }

    int superPow(int a, vector<int>& b) 
    {
        if(a == 1)
            return 1;
        int ret = 1;
        for(int i = b.size() - 1; i >= 0; --i)
        {
            ret *= apow(a, b[i]) % mod;
            ret %= mod;
            a = apow(a, 10);
        }
        return ret;
    }
};
```
