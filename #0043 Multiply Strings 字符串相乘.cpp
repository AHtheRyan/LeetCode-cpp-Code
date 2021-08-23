/*
    1. �����ֱ�Ϊ m �� n λ��������ˣ������λ�����ᳬ�� m + n λ
    2. ����������˿��Կ���ĳ�����ֵ�ÿһλ�ֱ�����һ��������˺����
    ���������������ʣ����Կ��ٵó���˵��㷨
    ��Ҫע����ǣ�
    1. �ַ����������Ǹ�λ����λ���е�
    2. �������ֵĵ� i λ�͵� j λ��ˣ�����Ӧ��λ�ڵ� i + j - 1 λ
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
