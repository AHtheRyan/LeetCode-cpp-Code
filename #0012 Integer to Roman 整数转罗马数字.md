### 整数转罗马数字
### Integer to Roman

> 罗马数字包含以下七种字符：`I`，`V`，`X`，`L`，`C`，`D` 和 `M`。  
> | 字符 | 数值 |
> | ---| --- |
> | I | 1 |
> | V | 5 |
> | X | 10 |
> | L | 50 |
> | C | 100 |
> | D | 500 |
> | M | 1000 |  
> 
> 例如， 罗马数字 2 写做 `II`，即为两个并列的 1。12 写做 `XII`，即为 `X` + `II`。 27 写做 `XXVII`, 即为 `XX` + `V` + `II`。  
> 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 `IIII`，而是 `IV`。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4。同样地，数字 9 表示为 `IX`。这个特殊的规则只适用于以下六种情况：
> - `I` 可以放在 `V` (5) 和 `X` (10) 的左边，来表示 4 和 9。  
> - `X` 可以放在 `L` (50) 和 `C` (100) 的左边，来表示 40 和 90。   
> - `C` 可以放在 `D` (500) 和 `M` (1000) 的左边，来表示 400 和 900。  
> 
> 给你一个整数，将其转为罗马数字。  

> Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.
> | Symbol | Value |
> | ---| --- |
> | I | 1 |
> | V | 5 |
> | X | 10 |
> | L | 50 |
> | C | 100 |
> | D | 500 |
> | M | 1000 |  
> 
> For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.  
> Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:  
> - `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.  
> - `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.  
> - `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.  
> 
> Given an integer, convert it to a roman numeral.  

----------

#### I 直接转化

仔细探究不难发现，对于任意一个数字，其罗马数字表示都是从低位到高位，  
即某个高位字母或字母组合不能表示确定位的数字时，才考虑下一个较小的字母或者字母组合，  
例如，对于数字 `952`，先考虑 `M` 表示 `1000`，显然大，则再考虑 `CM` 表示 `900`，可以表示，则原数减去 `900`，为 `52`，  
这时一直到 `L` 表示 `50`，则再减去 `50`，为 `2`，最后找到 `I`，循环减去两次 `1`，可得最终结果为 `CM + L + I + I = CMLII`  
依次规律将数字进行处理即可  

```cpp
string intToRoman(int num) 
{
    vector<int> value{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> func{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ret;
    int size = value.size();
    for(int i = 0; i < size; ++i)
    {
        while(num - value[i] >= 0)
        {
            ret += func[i];
            num -= value[i];
        }
    }
    return ret;
}
```
