### 字符串转换整数（atoi）
### String to Integer(atoi)

> 请你来实现一个 `myAtoi(string s)` 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 `atoi` 函数）。  
> 函数 `myAtoi(string s)` 的算法如下：  
> - 读入字符串并丢弃无用的前导空格  
> 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。  
> 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。  
> 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 `0`。必要时更改符号（从步骤 2 开始）。  
> 如果整数数超过 32 位有符号整数范围 `[−231,  231 − 1]`，需要截断这个整数，使其保持在这个范围内。具体来说，小于 `−2^31` 的整数应该被固定为 `−2^31`，大于 `2^31 − 1` 的整数应该被固定为 `2^31 − 1`。  
> 返回整数作为最终结果。  
>
> **注意**：  
> - 本题中的空白字符只包括空格字符 `' '`。  
> - 除前导空格或数字后的其余字符串外，**请勿忽略** 任何其他字符。  

> Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).  
> The algorithm for `myAtoi(string s)` is as follows:  
> 1. Read in and ignore any leading whitespace.  
> 2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.  
> 3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.  
> 4. Convert these digits into an integer (i.e. `"123" -> 123`, `"0032" -> 32`). If no digits were read, then the integer is `0`. Change the sign as necessary (from step 2).  
> 5. If the integer is out of the 32-bit signed integer range `[-231, 231 - 1]`, then clamp the integer so that it remains in the range. Specifically, integers less than `-2^31` should be clamped to `-2^31`, and integers greater than `2^31 - 1` should be clamped to `2^31 - 1`.  
> 6. Return the integer as the final result.  
> 
> **Note**:  
> - Only the space character `' '` is considered a whitespace character.  
> - **Do not ignore** any characters other than the leading whitespace or the rest of the string after the digits.  

----------

#### I 自动机

我们分别设置四个变量 `start` `signed` `in_number` `end`，分别表示所转换成的数字的 **开始（空格）、符号、数字以及结束**  
可以发现，遍历整个字符串，对于当前字符串对下一个字符串的影响，可以总结为表格如下：  
| 当前字符类型 | 空格位 | 符号位 | 数字位 | 结束位 |
| --- | --- | --- | --- | --- |
| start | start | signed | in_number | end |
| signed | end | end | in_number | end |
| in_number | end | end | in_number | end |
| end | end | end | end | end |

例如，如果当前字符为空格，下一字符为符号，则可以看行为 `start`，列为 `signed` 的对应状态，为 `signed`，则可以正常给当前转化的数字以符号  
若接下来字符仍为符号，则看行为 `signed`，列为 `signed` 的对应状态，为 `end`，说明可以直接结束转化  
因此，可以构建这样的类，直接将上表存储，进行所有的转化过程计算即可

```cpp
class Automation
{
    string state = "start";
    unordered_map<string, vector<string>> table
    {
        {"start"    , {"start", "signed", "in_number", "end"}},
        {"signed"   , {"end"  , "end"   , "in_number", "end"}},
        {"in_number", {"end"  , "end"   , "in_number", "end"}},
        {"end"      , {"end"  , "end"   , "end"      , "end"}}
    };

    int get_col(char c)
    {
        if(isspace(c))  return 0;
        if(c == '+' || c == '-')    return 1;
        if(isdigit(c))  return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c) 
    {
        state = table[state][get_col(c)];
        if (state == "in_number") 
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution 
{
public:
    int myAtoi(string s) 
    {
        Automation automation;
        for(auto c : s)
            automation.get(c);
        return automation.sign * automation.ans;
    }
};
```
