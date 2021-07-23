/*
    different child has different greed factor, we try giving small cookies to low greed-factor child,
    so sort the children and cookies from small to large:
    1. if cookie is smaller, change it into a bigger one and try again,
    2. if greed factor is smaller, give it to the child and change to the next child and cookie, and count the child,
    the number of content children is the number we counted
*/
/*
    ��Ϊÿ��С����θ�ڲ�ͬ�����Ǿ����ܽ�С�ı��ɸ�θ��С�ĺ��ӣ��ֽ�С��θ�ںͱ��ɳߴ簴��С��������
    ÿ�ζ�����С�ı��ɸ�θ����С��С����
    1. �������С�ˣ��ͻ��ɴ�һЩ�ı��ɣ�������ǰ������
    2. �������θ��С�ˣ���ô����ֱ��ι���ٿ�����һ�����Ӻ���һ�����ɣ�����������
    ����ӵ���������ι��������

*/ 

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int coNum = 0;
    while (coNum < s.size() && count < g.size())
    {
        if (g[count] <= s[coNum])
            ++count;
        ++coNum;
    }
    return count;
}