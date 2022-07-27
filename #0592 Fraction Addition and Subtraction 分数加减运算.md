### Fraction Addition and Subtraction
### 分数加减运算

> 给定一个表示分数加减运算的字符串 `expression`，你需要返回一个字符串形式的计算结果。  
> 这个结果应该是不可约分的分数，即`最简分数`。 如果最终结果是一个整数，例如 `2`，你需要将它转换成分数形式，其分母为 `1`。所以在上述例子中, `2` 应该被转换为 `2/1`。  

> Given a string `expression` representing an expression of fraction addition and subtraction, return the calculation result in string format.  
> The final result should be an `irreducible fraction`. If your final result is an integer, change it to the format of a fraction that has a denominator `1`. So in this case, `2` should be converted to `2/1`.  

----------

#### I 模拟

基于 `'+'` 和 `'-'` 将分数挨个分离出来，对分数进行加减法运算即可，  
这里需要注意，默认情况下第一个数字是正数的话就没有 `'+'` 号，我们这里需要先处理在其前面加上，使算式中每个数字前面都有正负号
具体运算过程为：  
1. 将两个分数的分母相乘，分子乘以另一个分数的分母后相加  
2. 基于上述步骤将所有分数计算完毕后，利用**辗转相除法**求出最大公约数，将结果分数化简  
3. 特殊情况：如果分子为 `0`，则直接返回 `0/1` 即可  

```cpp
class Solution 
{
public:
    string fractionAddition(string expression) 
    {
        string exp;
        exp = expression[0] == '-' ? expression : '+' + expression;
        int n = exp.size();
        int index = 0;
        int retfz = 0;
        int retfm = 1;
        bool flag = true;
        while(index < n)
        {
            int fz = 0;
            int fm = 0;
            flag = exp[index++] == '+' ? true : false;
            while(exp[index] != '/')
            {
                fz = fz * 10 + (exp[index] - '0');
                ++index;
            }
            fz = flag ? fz : -fz;
            ++index;
            while(index < n && exp[index] != '+' && exp[index] != '-')
            {
                fm = fm * 10 + (exp[index] - '0');
                ++index;
            }
            int curfz = retfm * fz + fm * retfz;
            int curfm = retfm * fm;
            retfm = curfm;
            retfz = curfz;
        }
        if(retfz == 0)
            return "0/1";
        int div = retfz > retfm ? mod(retfz, retfm) : mod(retfm, retfz);
        return to_string(retfz / div) + '/' + to_string(retfm / div);
    }

    int mod(int a, int b)
    {
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        if(a == 1 || b == 1)
            return 1;
        while(a != 1 && b != 1 && a % b != 0)
        {
            int c = a % b;
            a = b;
            b = c;
        }
        return b;
    }
};
```
