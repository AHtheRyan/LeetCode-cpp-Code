### 表示数值的字符串

> 请实现一个函数用来判断字符串是否表示**数值**（包括整数和小数）。  
> **数值**（按顺序）可以分成以下几个部分：
> 1. 若干空格  
> 2. 一个**小数**或者**整数**  
> 3. （可选）一个 `'e'` 或 `'E'`，后面跟着一个**整数**  
> 4. 若干空格  
> 
> **小数**（按顺序）可以分成以下几个部分：  
> 1. （可选）一个符号字符（`'+'` 或 `'-'`）  
> 2. 下述格式之一：  
>    - 至少一位数字，后面跟着一个点 `'.'`  
>    - 至少一位数字，后面跟着一个点 `'.'`，后面再跟着至少一位数字  
>    - 一个点 `'.'`，后面跟着至少一位数字  
> 
> **整数**（按顺序）可以分成以下几个部分：  
> 1. （可选）一个符号字符（`'+'` 或 `'-'`）  
> 2. 至少一位数字  
> 
> 部分**数值**列举如下：
> - `["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]`  
> 
> 部分**非数值**列举如下：  
> - `["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]`  

----------

#### I 确定有限状态自动机

可由图获得状态转移的全部效果  
![自动机图示](https://user-images.githubusercontent.com/46887748/159115984-1e0b38fa-5c74-4616-95b5-8d5c47cff1bc.png)  
领会精神  

```cpp
class Solution 
{
public:
    //状态集，分为初始状态、正负号、整数、小数点、无符号小数点、小数、指数、指数后的符号、指数数字、结束几种状态  
    enum State 
    {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    //字符集，分为数字、指数、点、符号、空格、非法字符集中不同字符  
    enum CharType 
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    //将字符转化为字符集中的表示方式  
    CharType toCharType(char ch) 
    {
        if (ch >= '0' && ch <= '9')
            return CHAR_NUMBER;
        else if (ch == 'e' || ch == 'E')
            return CHAR_EXP;
        else if (ch == '.')
            return CHAR_POINT;
        else if (ch == '+' || ch == '-')
            return CHAR_SIGN;
        else if (ch == ' ')
            return CHAR_SPACE;
        else
            return CHAR_ILLEGAL;
    }

    bool isNumber(string s) 
    {
        unordered_map<State, unordered_map<CharType, State>> transfer
        {
            {
                STATE_INITIAL, 
                {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, 
            {
                STATE_INT_SIGN, 
                {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, 
            {
                STATE_INTEGER, 
                {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END}
                }
            }, 
            {
                STATE_POINT,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, 
            {
                STATE_POINT_WITHOUT_INT, 
                {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, 
            {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, 
            {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, 
            {
                STATE_EXP_SIGN, 
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, 
            {
                STATE_EXP_NUMBER, 
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE, STATE_END}
                }
            }, 
            {
                STATE_END, 
                {
                    {CHAR_SPACE, STATE_END}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;
        for (int i = 0; i < len; i++) 
        {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) 
                return false;
            else 
                st = transfer[st][typ];
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};
```
