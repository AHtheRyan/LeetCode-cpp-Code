### 复数乘法
### Complex Number Multipication

> `复数`可以用字符串表示，遵循 `"实部+虚部i"` 的形式，并满足下述条件：  
> - `实部`是一个整数，取值范围是 `[-100, 100]`  
> - `虚部`也是一个整数，取值范围是 `[-100, 100]`  
> - `i^2 == -1`  
>   
> 给你两个字符串表示的复数 `num1` 和 `num2`，请你遵循复数表示形式，返回表示它们乘积的字符串。  

> A `complex number` can be represented as a string on the form `"real+imaginaryi"` where:  
> - `real` is the real part and is an integer in the range `[-100, 100]`.  
> - `imaginary` is the imaginary part and is an integer in the range `[-100, 100]`.  
> - `i^2 == -1`.  
> 
> Given two complex numbers `num1` and `num2` as strings, return *a string of the complex number that represents their multiplications*.  

----------

#### I 模拟

将字符串中的实部虚部分开，再进行乘法运算后加和即可  

```cpp
class Solution 
{
public:
    string complexNumberMultiply(string num1, string num2) 
    {
        auto [r1, i1] = element(num1);
        auto [r2, i2] = element(num2);
        int real = r1 * r2 - i1 * i2;
        int img = r1 * i2 + r2 * i1;
        string ret;
        ret += to_string(real);
        ret += '+';
        ret += to_string(img);
        ret += 'i';
        return ret;
    }

    pair<int, int> element(string& num)
    {
        int ptr = 0;
        bool realFlag = true;
        bool imgFlag = true;
        if(num[ptr] == '-')
        {
            ++ptr;
            realFlag = false;
        }
        int real = 0;
        while(num[ptr] != '+')
            real = real * 10 + num[ptr++] - '0';
        ++ptr;
        if(num[ptr] == '-')
        {
            ++ptr;
            imgFlag = false;
        }
        int img = 0;
        while(num[ptr] != 'i')
            img = img * 10 + num[ptr++] - '0';
        real = realFlag ? real : -real;
        img = imgFlag ? img : -img;
        return {real, img};
    }
};
```

#### II 正则表达式

利用C++11的正则表达式可更快实现匹配

```cpp
class Solution 
{
public:
    string complexNumberMultiply(string num1, string num2) 
    {
        regex re("\\+|i"); 
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
};
```
