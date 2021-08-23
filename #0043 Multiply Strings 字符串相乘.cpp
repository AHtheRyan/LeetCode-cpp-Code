/*
    1. 两个分别为 m 和 n 位的数字相乘，其积的位数不会超过 m + n 位
    2. 两个数字相乘可以看做某个数字的每一位分别与另一个数字相乘后求和
    利用上面两个性质，可以快速得出相乘的算法
    需要注意的是：
    1. 字符串中数字是高位到低位排列的
    2. 两个数字的第 i 位和第 j 位相乘，其结果应该位于第 i + j - 1 位
*/

string multiply(string num1, string num2)
{
    if (num1[0] == '0' || num2[0] == '0')
        return "0";
    int size1 = num1.size();
    int size2 = num2.size();
    vector<int> digit(size1 + size2);
    for (int i = size1 - 1; i >= 0; --i)
    {
        int a = num1[i] - '0';
        for (int j = size2 - 1; j >= 0; --j)
        {
            int b = num2[j] - '0';
            digit[i + j + 1] += a * b;
        }
    }
    for (int i = size1 + size2 - 1; i > 0; --i)
    {
        digit[i - 1] += digit[i] / 10;
        digit[i] = digit[i] % 10;
    }
    string ret;
    int start = digit[0] == 0 ? 1 : 0;
    for (; start < size1 + size2; ++start)
        ret += to_string(digit[start]);
    return ret;
}
