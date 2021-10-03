### 分数到小数
### Fraction to Recurring Decimal

> 给定两个整数，分别表示分数的分子 `numerator` 和分母 `denominator`，以**字符串形式返回小数**。  
> 如果小数部分为循环小数，则将循环的部分括在括号内。  
> 如果存在多个答案，只需返回**任意一个**。  

> Given two integers representing the `numerator` and `denominator` of a fraction, return *the fraction in string format*.  
> If the fractional part is repeating, enclose the repeating part in parentheses.  
> If multiple answers are possible, return **any of them**.  

----------

#### I 模拟

本题的难点在于确定循环小数的起始位置  
既然要知道从哪里开始循环，则肯定要把后面出现的数字和前面已经除出来的数字做对比，  
那么由于每次都需要对数字进行比较，那么最简单的方式就是比较做完除法的余数（即下一次的被除数）是否为已经出现的，  
例如，考虑 `2` 除以 `15` 的小数，开始的被除数为 `2`，第一位商为 `1`，下次被除数为 `5`，第二位商为 `3`，下次被除数为 `5`，  
由于出现了相同的被除数，说明后面再出现的商也都是和前面某次除法出现的一样了，可以以此找到循环起点，  
对于需要记忆和查找的数字，利用**哈希表**进行记录  
1. 首先考虑能否整除，对于能整除的数字，直接返回整除结果即可
2. 考虑正负号，如果除数和被除数有且仅有一个负数，则在返回结果添加负号
3. 考虑小数，首先在结果的尾端增加小数点`'.'`，然后按照上述规则进行小数点后的除法计算，利用哈希表进行记录
   - 对于可以除尽的小数，则直接返回小数结果
   - 对于不能除尽的小数，则先将不循环部分添加到返回的字符串末尾，再依次添加`'('`，循环部分，`')'`即可

```cpp
string fractionToDecimal(int numerator, int denominator) 
{
    long num = (long) numerator;
    long den = (long) denominator;
    //整数直接除尽
    if(num % den == 0)
        return to_string(num / den);
    string ret = "";
    //负数加负号
    if(num < 0 ^ den < 0)
        ret += '-';
    //考虑小数
    num = abs(num);
    den = abs(den);
    ret += to_string(num / den);
    num %= den;
    ret += '.';
    map<int, int> hash;
    int pos = 0;
    long ini = num;
    while(hash.find(num) == hash.end() && num)
    {
        hash[num] = pos++;
        num = num * 10 % den;
    }
    //可以除尽的小数
    if(!num)
    {
        for(int i = 0; i < ini; ++i)
        {
            ret += ini * 10 / den + '0';
            ini = ini * 10 % den;
        }
        return ret;
    }
    //不能除尽的小数
    int noloop = (hash.find(num))->second;
    int n = 0;
    for(; n < noloop; ++n)
    {
        ret += ini * 10 / den + '0';
        ini = ini * 10 % den;
    }
    if(num)
    {
        ret += '(';
        for(; n < pos; ++n)
        {
            ret += ini * 10 / den + '0';
            ini = ini * 10 % den;
        }
        ret += ')';
    }
    return ret;
}
```
