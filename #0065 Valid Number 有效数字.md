### 有效数字
### Valid Number

> **有效数字**（按顺序）可以分成以下几个部分：  
> 1. 一个**小数**或者**整数**  
> 2. （可选）一个 `'e'` 或 `'E'`，后面跟着一个**整数**  
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
> 部分有效数字列举如下：`["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]`  
> 部分无效数字列举如下：`["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]`  
> 给你一个字符串 `s`，如果 `s` 是一个**有效数字**，请返回 `true`。  

> A **valid number** can be split up into these components (in order):  
> 1. A **decimal number** or an **integer**.  
> 2. (Optional) An `'e'` or `'E'`, followed by an **integer**.  
> 
> A **decimal number** can be split up into these components (in order):  
> 1. (Optional) A sign character (either `'+'` or `'-'`).  
> 2. One of the following formats:  
>    - One or more digits, followed by a dot `'.'`.  
>    - One or more digits, followed by a dot `'.'`, followed by one or more digits.  
>    - A dot `'.'`, followed by one or more digits.  
> 
> An **integer** can be split up into these components (in order):  
> 1. (Optional) A sign character (either `'+'` or `'-'`).  
> 2. One or more digits.  
> 
> For example, all the following are valid numbers: `["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]`, while the following are not valid numbers: `["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]`.  
> Given a string s, return true if s is a **valid number**.  

----------

#### I 确定有限状态自动机

见[表示数值的字符串](./%23剑指offer%2020.%20表示数值的字符串.md)  

```cpp
class Solution 
{
public:
    enum State
    {
        S_INITIAL,
        S_SIGNAL,
        S_NUMBER,
        S_POINT,
        S_POINT_WITHOUT_NUMBER,
        S_FRAC,
        S_eE,
        S_E_SIGNAL,
        S_E_NUMBER,
        S_END
    };

    enum CharType
    {
        CTP_NUM,
        CTP_ILG,
        CTP_PNT,
        CTP_eE,
        CTP_SIG,
    };

    CharType toCharType(char c)
    {
        if(c >= '0' &&c<= '9')
            return CTP_NUM;
        if(c == 'e' || c =='E')
            return CTP_eE;
        if(c == '.')
            return CTP_PNT;
        if(c == '+' || c == '-')
            return CTP_SIG;
        else
            return CTP_ILG;
    }

    unordered_map<State, unordered_map<CharType, State>> transfer
    {
        {S_INITIAL, {{CTP_NUM, S_NUMBER}, {CTP_PNT, S_POINT_WITHOUT_NUMBER}, {CTP_SIG, S_SIGNAL}}},
        {S_SIGNAL, {{CTP_NUM, S_NUMBER}, {CTP_PNT, S_POINT_WITHOUT_NUMBER}}},
        {S_NUMBER, {{CTP_NUM, S_NUMBER}, {CTP_eE,  S_eE},{CTP_PNT, S_POINT}}},
        {S_POINT, {{CTP_NUM, S_FRAC}, {CTP_eE, S_eE}}},
        {S_POINT_WITHOUT_NUMBER, {{CTP_NUM, S_FRAC}}},
        {S_FRAC, {{CTP_NUM, S_FRAC}, {CTP_eE, S_eE}}},
        {S_eE, {{CTP_NUM, S_E_NUMBER}, {CTP_SIG, S_E_SIGNAL}}},
        {S_E_SIGNAL, {{CTP_NUM, S_E_NUMBER}}},
        {S_E_NUMBER, {{CTP_NUM, S_E_NUMBER}}}
    };

    bool isNumber(string s) 
    {
        State state = S_INITIAL;
        for(int i = 0; i < s.size(); ++i)
        {
            CharType ctp = toCharType(s[i]);
            if(transfer[state].count(ctp) == 0)
                return false;
            state = transfer[state][ctp];
        }
        return state == S_NUMBER || state == S_FRAC || state == S_POINT || state == S_E_NUMBER;
    }
};
```
