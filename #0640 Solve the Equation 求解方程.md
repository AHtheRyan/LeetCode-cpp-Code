### 求解方程
### Solve the Equation

> 求解一个给定的方程，将`x`以字符串 `"x=#value"` 的形式返回。该方程仅包含 `'+'`，`'-'` 操作，变量 `x` 和其对应系数。  
> 如果方程没有解，请返回 `"No solution"`。如果方程有无限解，则返回 `“Infinite solutions”`。  
> 题目保证，如果方程中只有一个解，则 `'x'` 的值是一个整数。  

> Solve a given equation and return the value of `'x'` in the form of a string `"x=#value"`. The equation contains only `'+'`, `'-'` operation, the variable `'x'` and its coefficient. You should return `"No solution"` if there is no solution for the equation, or `"Infinite solutions"` if there are infinite solutions for the equation.  
> If there is exactly one solution for the equation, we ensure that the value of `'x'` is an integer.  

----------

#### I 合并同类项

按照一元一次方程的解法来解即可  

```cpp
class Solution 
{
public:
    string solveEquation(string equation) 
    {
        int eqt = 0;
        while(equation[eqt] != '=')
            ++eqt;
        int n = equation.size();
        string left = equation.substr(0, eqt);
        string right = equation.substr(eqt + 1, n - eqt - 1);
        pair<int, int> l, r;
        l = split(left);
        r = split(right);
        int xfac = l.first - r.first;
        int cons = r.second - l.second;
        if(xfac == 0 && cons != 0)
            return "No solution";
        if(xfac == 0 && cons == 0)
            return "Infinite solutions";
        return "x=" + to_string(cons / xfac);
    }

    pair<int, int> split(string& formula)
    {
        if(formula[0] != '-')
            formula = "+" + formula;
        pair<int, int> ret{0, 0};
        int index = 0;
        while(index < formula.size())
        {
            int fac = 1;
            int val = 0;
            if(formula[index] == '-')
                fac = -1;
            ++index;
            if(formula[index] == '0')
                index += 2;
            else
            {
                while(index < formula.size() && isdigit(formula[index]))
                {
                    val = val * 10 + formula[index] - '0';
                    ++index;
                }
                if(formula[index] == 'x')
                {
                    if(val == 0)
                        ret.first += fac;
                    else
                        ret.first += fac * val;
                    ++index;
                }
                else
                    ret.second += fac * val;
            }
        }
        return ret;
    }
};
```
